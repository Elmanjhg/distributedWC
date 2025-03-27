# Distributed Word Counter

## Overview
A C++ distributed word counting system using ZeroMQ for parallel text file processing
and trying communicating via sockets in c++ with zmq. As there is still a lot of room
for improvement it might be adjusted in the future.

## Requirements
- ZeroMQ library
- CMake
- C++17 compiler

## Build
```bash
mkdir build
cd build
cmake ..
make
```

## Usage
1. Start workers:
```bash
./worker
```

2. In another terminal, run distributor:
```bash
./distributor <input_file.txt>
```

## How It Works
1. Split file across workers
2. Process chunks concurrently
3. Merge word counts
4. Display results
