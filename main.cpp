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
    addressBook.changeLoggedInUserPassword();
    addressBook.showAllUsers();
    addressBook.logoutUser();

    return 0;
}

//test ContactManager
#include "ContactManager.h"

int contactTest_main()
{
    ContactManager contactManager("contacts.txt", 1);
    contactManager.showAllContacts();
    contactManager.addContact();

    return 0;
}

//test ContactsFile
#include "ContactsFile.h"
#include "Contact.h"

int fileTest_main()
{
    ContactsFile contactsFile("contacts_test.txt");
    Contact contact(1, 5, "Mateusz", "Przybyla", "888 888 888", "mateusz@mateusz", "ul.AAA");
    contactsFile.writeNewContactInFile(contact);

    cout << contactsFile.getLastContactId() << endl;

    return 0;
}
