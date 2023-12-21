#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("users.txt", "contacts.txt");
    char choice;

    while (true)
    {
        if (!addressBook.checkIfUserLoggedIn())
        {
            choice = addressBook.selectAnOptionFromMainMenu();

            switch (choice)
            {
            case '1': addressBook.registerUser(); break;
            case '2': addressBook.loginUser(); break;
            case '9': exit(0); break;
            default:
                cout << endl << "No such an option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = addressBook.selectAnOptionFromUserMenu();

            switch (choice)
            {
            case '1': addressBook.addContact(); break;
            case '4': addressBook.showAllContacts(); break;
            case '7': addressBook.changeLoggedInUserPassword(); break;
            case '8': addressBook.logoutUser(); break;
            }
        }
    }
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
