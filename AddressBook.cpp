#include "AddressBook.h"

bool AddressBook::checkIfUserLoggedIn()
{
    return userManager.checkIfUserLoggedIn();
}

char AddressBook::selectAnOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "     >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Create an account" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. Close app" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

char AddressBook::selectAnOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << "     >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add new contact" << endl;
    cout << "2. Search by first name" << endl;
    cout << "3. Search by surname" << endl;
    cout << "4. Show all contacts" << endl;
    cout << "6. Edit contact" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Sign out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::loginUser()
{
    userManager.loginUser();
    if (checkIfUserLoggedIn())
        {
            contactManager = new ContactManager(CONTACTS_FILENAME, userManager.getLoggedInUserId());
        }
}

void AddressBook::showAllUsers()
{
    userManager.showAllUsers();
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
    delete contactManager;
    contactManager = NULL;
}

void AddressBook::addContact()
{
    if (checkIfUserLoggedIn())
    {
        contactManager->addContact();
    }
    else
    {
        cout << "Log in before add new contact." << endl;
        system("pause");
    }
}

void AddressBook::searchByFirstName()
{
    if (checkIfUserLoggedIn())
    {
        contactManager->searchByFirstName();
    }
    else
    {
        cout << "Log in before show contacts." << endl;
        system("pause");
    }
}

void AddressBook::searchBySurname()
{
    if (checkIfUserLoggedIn())
    {
        contactManager->searchBySurname();
    }
    else
    {
        cout << "Log in before show contacts." << endl;
        system("pause");
    }
}

void AddressBook::showAllContacts()
{
    if (checkIfUserLoggedIn())
    {
        contactManager->showAllContacts();
    }
    else
    {
        cout << "Log in before show contacts." << endl;
        system("pause");
    }
}

void AddressBook::editContact()
{
    if (checkIfUserLoggedIn())
    {
        contactManager->editContact();
    }
    else
    {
        cout << "Log in before edit contacts." << endl;
        system("pause");
    }
}

void AddressBook::changeLoggedInUserPassword()
{
    if (checkIfUserLoggedIn())
    {
        userManager.changeLoggedInUserPassword();
    }
    else
    {
        cout << "Log in before change password." << endl;
        system("pause");
    }
}
