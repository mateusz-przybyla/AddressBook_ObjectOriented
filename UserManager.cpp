#include "UserManager.h"

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

void UserManager::registerUser()
{
    User user = enterNewUserData();

    users.push_back(user);
    usersFile.writeNewUserInFile(user);

    cout << endl << "Account created" << endl << endl;
    system("pause");
}

void UserManager::showAllUsers()
{
    for (size_t i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getUsername() << endl;
        cout << users[i].getPassword() << endl;
    }
}

User UserManager::enterNewUserData()
{
    User user;
    string username = "", password = "";

    user.setId(readNewUserId());

    do
    {
        cout << "Enter username: ";
        username = AuxiliaryMethods::readLine();
        user.setUsername(username);
    } while (checkUsername(user.getUsername()));

    cout << "Enter password: ";
    password = AuxiliaryMethods::readLine();
    user.setPassword(password);

    return user;
}

int UserManager::readNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::checkUsername(string username)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getUsername() == username)
        {
            cout << endl << "Such a username exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loginUser()
{
    User user;
    string enteredName = "", enteredPassword = "";

    cout << endl << "Enter username: ";
    enteredName = AuxiliaryMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getUsername() == enteredName)
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Enter password. Attempts left: " << attempt << ": ";
                enteredPassword = AuxiliaryMethods::readLine();

                if (itr -> getPassword() == enteredPassword)
                {
                    loggedInUserId = itr -> getId();
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "You have entered the wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with that login." << endl << endl;
    system("pause");
    return;
}

void UserManager::logoutUser()
{
    loggedInUserId = 0;
}

void UserManager::changeLoggedInUserPassword()
{
    string newPassword = "";
    cout << endl << "Enter new password: ";
    newPassword = AuxiliaryMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == getLoggedInUserId())
        {
            itr -> setPassword(newPassword);
            cout << "Password was changed." << endl << endl;
            system("pause");
        }
    }
    usersFile.writeAllUsersInFile(users);
}

bool UserManager::checkIfUserLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}
