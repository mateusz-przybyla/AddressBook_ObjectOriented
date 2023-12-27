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
            case '2': addressBook.searchByFirstName(); break;
            case '4': addressBook.showAllContacts(); break;
            case '7': addressBook.changeLoggedInUserPassword(); break;
            case '8': addressBook.logoutUser(); break;
            }
        }
    }
    return 0;
}
