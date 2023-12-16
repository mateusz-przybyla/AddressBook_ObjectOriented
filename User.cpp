#include "User.h"

void User::setId(int newId)
{
    if (id >= 0)
        id = newId;
}

void User::setUsername(string newUsername)
{
    username = newUsername;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

int User::getId()
{
    return id;
}

string User::getUsername()
{
    return username;
}

string User::getPassword()
{
    return password;
}
