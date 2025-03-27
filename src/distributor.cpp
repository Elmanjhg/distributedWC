#include <zmq.hpp>
#include <string>
#include "lib.hpp"

using namespace std;
using namespace zmq;

// Constants for configuration
const int NUM_SERVERS = 8;
const int FIRST_PORT = 5555;
const int RESULTS_PORT = 5550;

int main(int argc, char *argv[]) {
    if(argc < 2){
        perror("Format: ./distributor <File.txt>");
        return 1;
    }

    vector<std::string> vec; // empty Vector


    // Read the file into vector
    processFile(argv[1], vec);


    // Initialize the ZMQ context
    context_t context(1);


    // store sockets in vector
    vector<socket_t> sockets;

    // Create a PULL socket to receive results
    socket_t results_socket(context, socket_type::pull);
    results_socket.bind("tcp://*:" + to_string(RESULTS_PORT));


    int count = 0;

    // Request-Reply cycle with workers
    for (int i = 0; i < NUM_SERVERS; i++) {
        int port = FIRST_PORT + i;
        string address = "tcp://localhost:" + to_string(port);

        // Create a request socket and store it in the vector
        sockets.emplace_back(context, socket_type::req);
        sockets[i].connect(address);

        // Send chunks to workers
        for (int j = 0; j < vec.size() / NUM_SERVERS; j++) {
            if (count < vec.size()) {
                string message = vec[count];
                sockets[i].send(buffer(message), send_flags::none);
                count++;

                // Receive reply before sending the next message
                message_t reply;
                sockets[i].recv(reply, recv_flags::none);
            }
        }
    }


    // Send END message to all servers
    for (int i = 0; i < NUM_SERVERS; i++) {
        string message = "END";
        sockets[i].send(buffer(message), send_flags::none);

        //Receive reply before proceeding
        message_t reply;
        sockets[i].recv(reply, recv_flags::none);
    }

    // Receive and merge results from workers
    unordered_map<string, int> total_word_count;
    int received_results = 0;

    while (received_results < NUM_SERVERS) {
        message_t result_message;
        results_socket.recv(result_message, recv_flags::none);

        string result_str(static_cast<char*>(result_message.data()), result_message.size());
        istringstream result_stream(result_str);
        string result_line;

        while (getline(result_stream, result_line)) {
            if (!result_line.empty()) {
                update_word_count(total_word_count, result_line);
            }
        }

        received_results++;
    }

    // Print results
    print_results(total_word_count);


    return 0;
}