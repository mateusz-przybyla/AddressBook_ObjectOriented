#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile
{
    const string usersFilename;

    bool checkIfFileIsEmpty(fstream &textFile);
    string changeUserDataToLinesWithDataSeparatedVerticalDashes(User user);
    User readUserData(string userDataSeparatedVerticalDashes);

public:
    UsersFile(string USERSFILENAME) : usersFilename(USERSFILENAME) {};

    void writeNewUserInFile(User user);
    vector <User> loadUsersFromFile();
    void writeAllUsersInFile(vector <User> users);
};

#endif
