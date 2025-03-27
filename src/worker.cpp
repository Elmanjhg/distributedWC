#include <zmq.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <unordered_map>
#include "lib.hpp"

using namespace std;
using namespace zmq;


void worker_thread(int port) {

    context_t context(1);

    // REP socket to receive messages from the distributor
    socket_t socket(context, socket_type::rep);
    socket.bind("tcp://*:" + to_string(port));

    // Create a new PUSH socket to send results to distributor
    socket_t results_socket(context, socket_type::push);
    results_socket.connect("tcp://localhost:5550");


    // buffer for incoming message
    message_t request;

    unordered_map<string, int> word_count;

    while (true) {
        // Receive message
        socket.recv(request, zmq::recv_flags::none);
        string message(static_cast<char*>(request.data()), request.size());

        // Process the line
        processLine(message, word_count);

        // Respond to keep REQ-REP cycle valid
        string response = "ACK";  // Dummy acknowledgment
        socket.send(buffer(response), send_flags::none);

        if (message == "END") {
            // Prepare results for sending
            stringstream result_stream;
            for (const auto& pair : word_count) {
                result_stream << pair.first << " " << pair.second << "\n";
            }
            string result_str = result_stream.str();

            // Send results via PUSH socket
            results_socket.send(buffer(result_str), send_flags::none);
            break;
        }
    }
}


int main() {
    const int NUM_THREADS = 8; // create 8 worker threads

    const int FIRST_PORT = 5555;

    // Vector to hold our threads
    vector<thread> worker_threads;

    // Create and start the worker threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int port = FIRST_PORT + i;
        worker_threads.emplace_back(worker_thread, port);
    }

    // Join the threads with the main thread
    for (auto &t : worker_threads) {
        t.join();
    }

    return 0;

}