#ifndef CONTACTSFILE_H
#define CONTACTSFILE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Contact.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class ContactsFile : public TextFile
{
    int lastContactId;

    string changeContactDataToLinesWithDataSeparatedVerticalDashes(Contact contact);
    Contact readContactData(string contactDataSeparatedVerticalDashes);
    int readUserIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes);
    int readContactIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes);
    string readNumber(string text, int signPosition);
    void readLastContactIdFromFile();
    void deleteFile(string filenameWithExtention);
    void renameFile(string oldName, string newName);

public:
    ContactsFile(string contactsFilename) : TextFile(contactsFilename)
    {
        lastContactId = 0;
    };

    bool writeNewContactInFile(Contact contact);
    vector <Contact> loadContactsFromFile(int loggedInUserId);
    void updateContactDataInFile(Contact contact);
    void deleteSelectedLineInFile(int contactIdToBeDeleted);

    int getLastContactId();
};

#endif
