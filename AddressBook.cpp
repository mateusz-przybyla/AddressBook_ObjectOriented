#include "AddressBook.h"

void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::loginUser()
{
    userManager.loginUser();
    if (userManager.checkIfUserLoggedIn())
        {
            contactManager = new ContactManager(CONTACTS_FILENAME, userManager.getLoggedInUserId());
        }
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
    delete contactManager;
    contactManager = NULL;
}

void AddressBook::showAllUsers()
{
    userManager.showAllUsers();
}

void AddressBook::addContact()
{
    if (userManager.checkIfUserLoggedIn())
    {
        contactManager->addContact();
    }
    else
    {
        cout << "Log in before add new contact." << endl;
        system("pause");
    }
}

void AddressBook::showAllContacts()
{
    contactManager->showAllContacts();
}

void AddressBook::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}
