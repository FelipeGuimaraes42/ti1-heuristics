#include <iostream>
#include <string>
#include <vector>
#include "include/InputFile.hpp"

using namespace std;

int main(int argc, char **argv)
{
	string name, dimension, weightType, str;

    string fileName(argv[1]);
    InputFile inputFile(fileName);
    vector<pair<double, double>> graph = inputFile.getFileContent(name, dimension, weightType);

    return 0;
}