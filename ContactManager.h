#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <vector>

#include "Contact.h"
#include "ContactsFile.h"

using namespace std;

class ContactManager
{
    const int LOGGED_IN_USER_ID;
    vector <Contact> contacts;
    ContactsFile contactsFile;

    Contact enterNewContactData();

public:
    ContactManager(string contactsFilename, int loggedInUserId) : contactsFile(contactsFilename), LOGGED_IN_USER_ID(loggedInUserId)
    {
        contacts = contactsFile.loadContactsFromFile(LOGGED_IN_USER_ID);
    };

    void addContact();
    void showAllContacts();
};

#endif
