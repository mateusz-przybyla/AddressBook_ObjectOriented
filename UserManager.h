#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UsersFile usersFile;

    User enterNewUserData();
    int getNewUserId();
    bool checkUsername(string username);

public:
    UserManager(string usersFilename) : usersFile(usersFilename) {};
    void registerUser();
    void showAllUsers();
    void loginUser();
    void logoutUser();
    void changeLoggedUserPassword();
    void getUsersFromFile();

    void setLoggedUserId(int newLoggedUserId);
    int getLoggedUserId();
};

#endif
