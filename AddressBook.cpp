#include "AddressBook.h"

void AddressBook::registerUser()
{
    userManager.registerUser();
}

void AddressBook::loginUser()
{
    userManager.loginUser();
    contactManager.setLoggedUserId(userManager.getLoggedUserId());
    contactManager.getContactsFromFile(userManager.getLoggedUserId());
    contactManager.getLastContactId();
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
    contactManager.clearContactsInMemory();
}

void AddressBook::showAllUsers()
{
    userManager.showAllUsers();
}

void AddressBook::addContact()
{
    contactManager.addContact();
}

void AddressBook::showAllContacts()
{
    contactManager.showAllContacts();
}

void AddressBook::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}
