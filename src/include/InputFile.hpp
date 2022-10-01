#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class InputFile
{
private:
    string fileName;
    void readLines(vector<string> &lines, int &numLines, int &numColumns);
    void printVector(const vector<string> map);

public:
    InputFile(string fileName);
    ~InputFile();
    vector<pair<double, double>> getFileContent(string &name, string &dimension, string &weightType);
};