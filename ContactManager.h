#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <vector>

#include "Contact.h"
#include "ContactsFile.h"

using namespace std;

class ContactManager
{
    int loggedUserId;
    int lastContactId;
    vector <Contact> contacts;
    ContactsFile contactsFile;

    Contact enterNewContactData();

public:
    ContactManager(string contactsFilename) : contactsFile(contactsFilename) {};

    void addContact();
    void showAllContacts();
    void getContactsFromFile(int loggedUserId);
    void clearContactsInMemory();

    void setLoggedUserId(int newLoggedUserId);
    void getLastContactId();
};

#endif
