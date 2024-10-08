# Simple Blockchain in C++

This project is a simple implementation of a blockchain using C++. It demonstrates basic concepts such as:

- **Block creation**: Blocks are created with an index, data, and a timestamp.
- **Hashing**: Each block is hashed using SHA-256.
- **Mining**: Blocks are mined using a simple Proof-of-Work algorithm.
- **Blockchain**: The blockchain is a chain of blocks, where each block has a reference to the hash of the previous block.

## Requirements

- CMake
- OpenSSL library (for SHA-256 hashing)
