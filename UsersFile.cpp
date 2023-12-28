#include "UsersFile.h"

void UsersFile::writeNewUserInFile(User user)
{
    string userDataLine = "";
    fstream textFile;
    textFile.open(getFilename().c_str(), ios::app);

    if (textFile.good())
    {
        userDataLine = changeUserDataToLinesWithDataSeparatedVerticalDashes(user);

        if (TextFile::checkIfFileIsEmpty(textFile))
        {
            textFile << userDataLine;
        }
        else
        {
            textFile << endl << userDataLine ;
        }
    }
    else
    {
        cout << "Failed to open a file " << getFilename() << " and write data." << endl;
    }
    textFile.close();
}

string UsersFile::changeUserDataToLinesWithDataSeparatedVerticalDashes(User user)
{
    string userDataLine = "";

    userDataLine += AuxiliaryMethods::convertIntToString(user.getId()) + '|';
    userDataLine += user.getUsername() + '|';
    userDataLine += user.getPassword() + '|';

    return userDataLine;
}

vector <User> UsersFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
    string userDataSeparatedVerticalDashes = "";
    fstream textFile;
    textFile.open(getFilename().c_str(), ios::in);

    if (textFile.good())
    {
        while (getline(textFile, userDataSeparatedVerticalDashes))
        {
            user = readUserData(userDataSeparatedVerticalDashes);
            users.push_back(user);
        }
    }
    textFile.close();
    return users;
}

User UsersFile::readUserData(string userDataSeparatedVerticalDashes)
{
    User user;
    string singleUserData = "";
    int numberOfSingleUserData = 1;

    for (size_t signPosition = 0; signPosition < userDataSeparatedVerticalDashes.length(); signPosition++)
    {
        if (userDataSeparatedVerticalDashes[signPosition] != '|')
        {
            singleUserData += userDataSeparatedVerticalDashes[signPosition];
        }
        else
        {
            switch (numberOfSingleUserData)
            {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setUsername(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numberOfSingleUserData++;
        }
    }
    return user;
}

void UsersFile::writeAllUsersInFile(vector <User> users)
{
    string userDataLine = "";
    vector <User>::iterator itrEnd = --users.end();
    fstream textFile;
    textFile.open(getFilename().c_str(), ios::out);

    if (textFile.good())
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            userDataLine = changeUserDataToLinesWithDataSeparatedVerticalDashes(*itr);

            if (itr == itrEnd)
            {
               textFile << userDataLine;
            }
            else
            {
                textFile << userDataLine << endl;
            }
            userDataLine = "";
        }
    }
    else
    {
        cout << "Failed to open a file " << getFilename() << endl;
    }
    textFile.close();
}
