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
    int loggedInUserId;
    vector <User> users;
    UsersFile usersFile;

    User enterNewUserData();
    int readNewUserId();
    bool checkUsername(string username);

public:
    UserManager(string usersFilename) : usersFile(usersFilename)
    {
        loggedInUserId = 0;
        users = usersFile.loadUsersFromFile();
    };

    void registerUser();
    void showAllUsers();
    void loginUser();
    void logoutUser();
    void changeLoggedInUserPassword();
    bool checkIfUserLoggedIn();

    int getLoggedInUserId();
};

#endif
