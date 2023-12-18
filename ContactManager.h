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
    vector <Contact> contacts;
    ContactsFile contactsFile;

    Contact enterNewContactData();

public:
    ContactManager(string CONTACTSFILENAME) : contactsFile(CONTACTSFILENAME) {};

    void addContact();
    void showAllContacts();
    void clearContactsInMemory();
    void loadContactsFromFile();

    void setLoggedUserId(int newLoggedUserId);
    int getLoggedUserId();
};

#endif
