#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "ContactManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    ContactManager *contactManager;
    const string CONTACTS_FILENAME;

public:
    AddressBook(string usersFilename, string contactsFilename) : userManager(usersFilename), CONTACTS_FILENAME(contactsFilename)
    {
        contactManager = NULL;
    };

    ~AddressBook()
    {
        delete contactManager;
        contactManager = NULL;
    };

    bool checkIfUserLoggedIn();
    char selectAnOptionFromMainMenu();
    char selectAnOptionFromUserMenu();
    void registerUser();
    void loginUser();
    void showAllUsers();
    void logoutUser();
    void addContact();
    void showAllContacts();
    void changeLoggedInUserPassword();
};

#endif
