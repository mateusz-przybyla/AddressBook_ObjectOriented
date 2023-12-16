#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string username, password;

public:
    void setId(int newId);
    void setUsername(string newUsername);
    void setPassword(string newPassword);

    int getId();
    string getUsername();
    string getPassword();
};

#endif
