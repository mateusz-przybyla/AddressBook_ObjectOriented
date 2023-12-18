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
    const string contactsFilename;

    bool checkIfFileIsEmpty(fstream &textFile);
    string changeContactDataToLinesWithDataSeparatedVerticalDashes(Contact contact);
    Contact readContactData(string contactDataSeparatedVerticalDashes);
    int readUserIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes);
    int readContactIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes);
    string readNumber(string text, int signPosition);

public:
    ContactsFile(string CONTACTSFILENAME) : contactsFilename(CONTACTSFILENAME) {};

    void writeNewContactInFile(Contact contact);
    vector <Contact> loadContactsFromFile(int loggedUserId);

    void setLastContactId(int newLastContactId);
    int getLastContactId();
};

#endif
