#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("users.txt", "contacts.txt");
    addressBook.showAllUsers();
    addressBook.registerUser();
    addressBook.showAllUsers();
    addressBook.loginUser();
    addressBook.showAllContacts();
    addressBook.addContact();
    addressBook.addContact();
    addressBook.showAllContacts();
    addressBook.logoutUser();
    addressBook.showAllContacts();
    addressBook.loginUser();
    addressBook.addContact();
    addressBook.addContact();
    addressBook.showAllContacts();
    addressBook.showAllUsers();
    addressBook.changeLoggedUserPassword();
    addressBook.showAllUsers();
    addressBook.logoutUser();

    return 0;
}
