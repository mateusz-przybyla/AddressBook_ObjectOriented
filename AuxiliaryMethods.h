#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string readLine();
    static char readChar();
    static string replaceFirstLetterToUpperCaseAndOtherToLowerCase(string text);
};

#endif
