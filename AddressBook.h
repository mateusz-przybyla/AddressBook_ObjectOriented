#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "ContactManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    ContactManager contactManager;

public:
    AddressBook(string USERSFILENAME, string CONTACTSFILENAME) : userManager(USERSFILENAME), contactManager(CONTACTSFILENAME)
    {
        userManager.loadUsersFromFile();
    }

    void registerUser();
    void loginUser();
    void logoutUser();
    void showAllUsers();
    void addContact();
    void showAllContacts();
    void changeLoggedUserPassword();
};

#endif
