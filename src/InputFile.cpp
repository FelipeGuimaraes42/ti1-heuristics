#include "include/InputFile.hpp"

void InputFile::printVector(const vector<pair<double, double>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << graph.at(i).first << " " << graph.at(i).second << endl;
    }
}

void InputFile::readLines(vector<string> &lines, int &numLines, int &numColumns)
{
    ifstream file;
    file.open(this->fileName);
    string line;
    string stringColumns;
    file >> stringColumns;
    string stringLines;
    file >> stringLines;

    while (getline(file, line))
    {
        lines.push_back(line);
    }
    lines.erase(lines.begin());

    numLines = stoi(stringLines);
    numColumns = stoi(stringColumns);

    // printVector(lines);
}

InputFile::InputFile(string fileName)
{
    this->fileName = fileName;
}

InputFile::~InputFile() {}

vector<pair<double, double>> InputFile::getFileContent(string &name, string &dimension, string &weightType)
{
    vector<pair<double, double>> graph;

    ifstream file;
    file.open(this->fileName);
    string word;
    string number;
    double x, y;

    while (file >> word)
    {
        if (word == "NODE_COORD_SECTION")
            while (file >> number)
            {
                if (number == "EOF") {
                    break;
                }
                string doubleString;
                file >> doubleString;
                x = stod(doubleString);
                file >> doubleString;
                y = stod(doubleString);
                graph.push_back({x, y});
            }
        if (word == "NAME:")
            file >> name;
        if (word == "DIMENSION:")
            file >> dimension;
        if (word == "EDGE_WEIGHT_TYPE:")
            file >> weightType;
    }

    cout << name << " " << dimension << " " << weightType << endl;

    for (int i = 0; i < graph.size(); i++)
    {
        cout << graph.at(i).first << " " << graph.at(i).second << endl;
    }

    printVector(graph);

    return graph;
}