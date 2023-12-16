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
    AddressBook(string usersFilename, string contactsFilename) : userManager(usersFilename), contactManager(contactsFilename)
    {
        userManager.getUsersFromFile();
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
