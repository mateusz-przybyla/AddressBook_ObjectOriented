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
    void showNumberOfSearchedContacts(int numberOfContacts);
    void showContactData(Contact contact);

public:
    ContactManager(string contactsFilename, int loggedInUserId) :  LOGGED_IN_USER_ID(loggedInUserId), contactsFile(contactsFilename)
    {
        contacts = contactsFile.loadContactsFromFile(LOGGED_IN_USER_ID);
    };

    void addContact();
    void searchByFirstName();
    void searchBySurname();
    void showAllContacts();
};

#endif
