#include <string>
#include <iostream>
#include <fstream>

int getRotation(std::string command) {
    std::string rotStr;
    int rotation = 0;
    int i = 1;
    while (i != command.size()) {
        rotStr += command.at(i);
        i++;
    }

    rotation = std::stoi(rotStr);

    if (command.at(0) == 'L') {
        return -rotation;
    }
    return rotation;
}

int main(int argc, char **argv) {
    /*sanity check*/
    if (!argv[1] || argc != 2){
        std::cerr << "Usage: ./SecretEntrance [input file.txt]" << std::endl;
        return 1;
    }

    std::string filepath = "../input/";
    std::string filename = argv[1];
    std::string file = filepath + filename;
    std::ifstream inputFile;
    inputFile.open(file);

    if(!inputFile.is_open()){
        std::cerr << "File " << argv[1] << " not found at input path." << std::endl;
        return 1;
    }
    /*end of sanity check*/

    int dial = 50;
    int zero_count = 0;
    char c;

    while (inputFile.get(c)) {
        if (c == 'R' || c == 'L') {
            std::string command;
            std::getline(inputFile, command);

            dial += getRotation(c + command);
            while (dial < 0) dial += 100;
            while (dial > 100) dial -= 100;
            if (dial == 0 || dial == 100) {
                zero_count++;
            }

        }
    }

    std::cout << zero_count << " times that zero is hit. " << dial << " is your final number." << std::endl;

    inputFile.close();
    return 0;
}