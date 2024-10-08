#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <openssl/sha.h>

// Function to calculate the SHA-256 hash of a string
std::string sha256(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class Block {
public:
    Block(int index, const std::string& data) : index(index), data(data), timeStamp(time(nullptr)) {
        nonce = 0;
        hash = calculateHash();
    }

    std::string getHash() const {
        return hash;
    }

    std::string getPrevHash() const {
        return prevHash;
    }

    void setPrevHash(const std::string& prevHash) {
        this->prevHash = prevHash;
    }

    void mineBlock(int difficulty) {
        std::string target(difficulty, '0');
        while (hash.substr(0, difficulty) != target) {
            nonce++;
            hash = calculateHash();
        }
        std::cout << "Block mined: " << hash << std::endl;
    }

private:
    int index;
    std::string data;
    std::time_t timeStamp;
    int nonce;
    std::string hash;
    std::string prevHash;

    std::string calculateHash() const {
        std::stringstream ss;
        ss << index << timeStamp << data << nonce << prevHash;
        return sha256(ss.str());
    }
};

#endif
