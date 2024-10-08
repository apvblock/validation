#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain() {
        chain.push_back(createGenesisBlock());
        difficulty = 4; // Proof-of-Work difficulty level
    }

    void addBlock(Block newBlock) {
        newBlock.setPrevHash(getLatestBlock().getHash());
        newBlock.mineBlock(difficulty);
        chain.push_back(newBlock);
    }

private:
    std::vector<Block> chain;
    int difficulty;

    Block createGenesisBlock() {
        return Block(0, "Genesis Block");
    }

    Block getLatestBlock() const {
        return chain.back();
    }
};

#endif
