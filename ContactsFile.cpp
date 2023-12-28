#include "ContactsFile.h"

int ContactsFile::getLastContactId()
{
    return lastContactId;
}

bool ContactsFile::writeNewContactInFile(Contact contact)
{
    string contactDataLine = "";
    fstream textFile;
    textFile.open(CONTACTS_FILENAME.c_str(), ios::out | ios::app);

    if (textFile.good())
    {
        contactDataLine = changeContactDataToLinesWithDataSeparatedVerticalDashes(contact);

        if (checkIfFileIsEmpty(textFile))
        {
            textFile << contactDataLine;
        }
        else
        {
            textFile << endl << contactDataLine;
        }
        lastContactId++;
        textFile.close();
        return true;
    }
    return false;
}

bool ContactsFile::checkIfFileIsEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);

    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string ContactsFile::changeContactDataToLinesWithDataSeparatedVerticalDashes(Contact contact)
{
    string contactDataLine = "";

    contactDataLine += AuxiliaryMethods::convertIntToString(contact.getId()) + '|';
    contactDataLine += AuxiliaryMethods::convertIntToString(contact.getUserId()) + '|';
    contactDataLine += contact.getFirstName() + '|';
    contactDataLine += contact.getSurname() + '|';
    contactDataLine += contact.getPhoneNumber() + '|';
    contactDataLine += contact.getEmail() + '|';
    contactDataLine += contact.getAddress() + '|';

    return contactDataLine;
}

vector <Contact> ContactsFile::loadContactsFromFile(int loggedInUserId)
{
    Contact contact;
    vector <Contact> contacts;
    string contactDataSeparatedVerticalDashes = "";
    string lastContactDataInFile = "";
    fstream textFile;
    textFile.open(CONTACTS_FILENAME.c_str(), ios::in);

    if (textFile.good())
    {
        while (getline(textFile, contactDataSeparatedVerticalDashes))
        {
            if (loggedInUserId == readUserIdFromDataSeparatedVerticalDashes(contactDataSeparatedVerticalDashes))
            {
                contact = readContactData(contactDataSeparatedVerticalDashes);
                contacts.push_back(contact);
            }
        }
        lastContactDataInFile = contactDataSeparatedVerticalDashes;
        textFile.close();
    }

    if (lastContactDataInFile != "")
    {
        lastContactId = readContactIdFromDataSeparatedVerticalDashes(lastContactDataInFile);
    }
    return contacts;
}

Contact ContactsFile::readContactData(string contactDataSeparatedVerticalDashes)
{
    Contact contact;
    string singleContactData = "";
    int numberOfSingleContactData = 1;

    for (size_t signPosition = 0; signPosition < contactDataSeparatedVerticalDashes.length(); signPosition++)
    {
        if (contactDataSeparatedVerticalDashes[signPosition] != '|')
        {
            singleContactData += contactDataSeparatedVerticalDashes[signPosition];
        }
        else
        {
            switch(numberOfSingleContactData)
            {
            case 1:
                contact.setId(atoi(singleContactData.c_str()));
                break;
            case 2:
                contact.setUserId(atoi(singleContactData.c_str()));
                break;
            case 3:
                contact.setFirstName(singleContactData);
                break;
            case 4:
                contact.setSurname(singleContactData);
                break;
            case 5:
                contact.setPhoneNumber(singleContactData);
                break;
            case 6:
                contact.setEmail(singleContactData);
                break;
            case 7:
                contact.setAddress(singleContactData);
                break;
            }
            singleContactData = "";
            numberOfSingleContactData++;
        }
    }
    return contact;
}

int ContactsFile::readUserIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes)
{
    int beginingPositionOfUserId = contactDataSeparatedVerticalDashes.find_first_of('|') + 1;
    int userId = AuxiliaryMethods::convertStringToInt(readNumber(contactDataSeparatedVerticalDashes, beginingPositionOfUserId));

    return userId;
}

int ContactsFile::readContactIdFromDataSeparatedVerticalDashes(string contactDataSeparatedVerticalDashes)
{
    int beginingPositionOfContactId = 0;
    int contactId = AuxiliaryMethods::convertStringToInt(readNumber(contactDataSeparatedVerticalDashes, beginingPositionOfContactId));

    return contactId;
}

string ContactsFile::readNumber(string text, int signPosition)
{
    string number = "";
    while (isdigit(text[signPosition]))
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

void ContactsFile::deleteSelectedLineInFile(int contactIdToBeDeleted)
{
    fstream readTextFile, tempTextFile;
    string readLine = "", nameOfContactsTempFile = "contacts_temp.txt";
    int numberOfReadLine = 1;

    readTextFile.open(CONTACTS_FILENAME.c_str(), ios::in);
    tempTextFile.open(nameOfContactsTempFile.c_str(), ios::out | ios::app);

    if (readTextFile.good() && contactIdToBeDeleted != 0)
    {
        while (getline(readTextFile, readLine))
        {
            if (contactIdToBeDeleted == readContactIdFromDataSeparatedVerticalDashes(readLine)) {}
            else if (numberOfReadLine == 1 && numberOfReadLine != contactIdToBeDeleted)
                tempTextFile << readLine;
            else if (numberOfReadLine == 2 && contactIdToBeDeleted == 1)
                tempTextFile << readLine;
            else if (numberOfReadLine > 2 && contactIdToBeDeleted == 1)
                tempTextFile << endl << readLine;
            else if (numberOfReadLine > 1 && contactIdToBeDeleted != 1)
                tempTextFile << endl << readLine;
            numberOfReadLine++;
        }
        readTextFile.close();
        tempTextFile.close();

        deleteFile(CONTACTS_FILENAME);
        renameFile(nameOfContactsTempFile, CONTACTS_FILENAME);
    }

    if (contactIdToBeDeleted == lastContactId)
        readLastContactIdFromFile();
}

void ContactsFile::readLastContactIdFromFile()
{
    string contactDataSeparatedVerticalDashes = "";
    string lastContactDataInFile = "";
    fstream textFile;
    textFile.open(CONTACTS_FILENAME.c_str(), ios::in);

    if (textFile.good())
    {
        while (getline(textFile, contactDataSeparatedVerticalDashes)) {}
            lastContactDataInFile = contactDataSeparatedVerticalDashes;
            textFile.close();
    }

    if (lastContactDataInFile != "")
        lastContactId = readContactIdFromDataSeparatedVerticalDashes(lastContactDataInFile);
    else
        lastContactId = 0;
}

void ContactsFile::updateContactDataInFile(Contact contact)
{
    fstream readTextFile, tempTextFile;
    string readLine  = "", nameOfContactsTempFile = "contacts_temp.txt";
    int numberOfReadLine = 1;

    readTextFile.open(CONTACTS_FILENAME.c_str(), ios::in);
    tempTextFile.open(nameOfContactsTempFile.c_str(), ios::out | ios::app);

    if (readTextFile.good())
    {
        while (getline(readTextFile, readLine))
        {
            if (contact.getId() == readContactIdFromDataSeparatedVerticalDashes(readLine))
            {
                if (contact.getId() == 1)
                    tempTextFile << changeContactDataToLinesWithDataSeparatedVerticalDashes(contact);
                else if (contact.getId() > 1)
                    tempTextFile << endl << changeContactDataToLinesWithDataSeparatedVerticalDashes(contact);

                cout << endl << "Data was updated." << endl << endl;
            }
            else
            {
                if (numberOfReadLine == 1)
                    tempTextFile << readLine;
                else if (numberOfReadLine > 1)
                    tempTextFile << endl << readLine;
            }
            numberOfReadLine++;
        }
        readTextFile.close();
        tempTextFile.close();

        deleteFile(CONTACTS_FILENAME);
        renameFile(nameOfContactsTempFile, CONTACTS_FILENAME);
    }
}

void ContactsFile::deleteFile(string filenameWithExtention)
{
    if (remove(filenameWithExtention.c_str()) == 0) {}
    else
        cout << "Failed to delete file." << filenameWithExtention << endl;
}

void ContactsFile::renameFile(string oldName, string newName)
{
    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Failed to rename file." << oldName << endl;
}
