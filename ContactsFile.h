#ifndef CONTACTSFILE_H
#define CONTACTSFILE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Contact.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ContactsFile
{
    int lastContactId;
    string contactsFilename;

    bool checkIfFileIsEmpty(fstream &textFile);
    string changeContactDataToLinesWithDataSeparatedVerticalDashes(Contact contact);
    Contact getContactData(string contactDataSeparatedVerticalDashes);
    int getUserIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes);
    int getContactIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes);
    string getNumber(string text, int signPosition);

public:
    ContactsFile(string CONTACTSFILENAME) : contactsFilename(CONTACTSFILENAME) {};

    void writeNewContactInFile(Contact contact);
    vector <Contact> getContactsFromFile(int loggedUserId);

    void setLastContactId(int newLastContactId);
    int getLastContactId();
};

#endif
