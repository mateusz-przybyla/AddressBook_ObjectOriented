#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class UsersFile : public TextFile
{
    string changeUserDataToLinesWithDataSeparatedVerticalDashes(User user);
    User readUserData(string userDataSeparatedVerticalDashes);

public:
    UsersFile(string usersFilename) : TextFile(usersFilename) {};

    void writeNewUserInFile(User user);
    vector <User> loadUsersFromFile();
    void writeAllUsersInFile(vector <User> users);
};

#endif
