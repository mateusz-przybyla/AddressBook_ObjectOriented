#include "TextFile.h"

string TextFile::getFilename()
{
    return FILENAME;
}

bool TextFile::checkIfFileIsEmpty(fstream &textFile)
{
    bool fileIsEmpty = true;
    textFile.seekg(0, ios::end);

    if (textFile.tellg() != 0)
        fileIsEmpty = false;

    return fileIsEmpty;
}
