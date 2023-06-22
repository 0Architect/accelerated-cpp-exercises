#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream sourceFile(__FILE__);
    std::string line;

    if (sourceFile.is_open()) {
        while (std::getline(sourceFile, line)) {
            std::cout << line << std::endl;
        }
        sourceFile.close();
    }

    return 0;
}
