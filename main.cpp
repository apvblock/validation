#include <iostream>
#include "Blockchain.h"

int main() {
    Blockchain myBlockchain;

    std::cout << "Mining block 1..." << std::endl;
    myBlockchain.addBlock(Block(1, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    myBlockchain.addBlock(Block(2, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    myBlockchain.addBlock(Block(3, "Block 3 Data"));

    return 0;
}
