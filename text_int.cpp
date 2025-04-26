#include <iostream>
#include <fstream>
#include <string>
#include <cryptopp/integer.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;

int main() {
    // Step 1: Read the text file content into a string
    std::ifstream file("example.txt");
    std::string fileContents;
    
    if (file) {
        // Read the entire file content into the string
        fileContents.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }
    
    // Step 2: Convert the string to a Crypto++ Integer
    // This treats the string as a byte array and converts it into a large integer
    Integer integerFromFile((const byte*)fileContents.data(), fileContents.size());

    // Step 3: Display the integer value
    std::cout << "Integer from string in file: " << integerFromFile << std::endl;

    return 0;
}

