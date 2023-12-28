#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile
{
    const string FILENAME;

public:
    TextFile(string filename) : FILENAME(filename) {};

    bool checkIfFileIsEmpty(fstream &textFile);

    string getFilename();
};

#endif
