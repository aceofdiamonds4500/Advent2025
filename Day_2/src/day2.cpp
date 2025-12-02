#include <string>
#include <iostream>
#include <fstream>


int main(int argc, char **argv) {
    /*sanity check*/
    if (!argv[1] || argc != 2){
        std::cerr << "Usage: ./GiftShop [input file.txt]" << std::endl;
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

    std::cout << "Hello, World!\n" << argc << ", " << argv[1] << std::endl;
    return 0;
}