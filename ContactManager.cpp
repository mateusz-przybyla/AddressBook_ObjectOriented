#include "ContactManager.h"

void ContactManager::addContact()
{
    Contact contact;

    system("cls");
    cout << " >>> ADDING NEW CONTACT <<<" << endl << endl;
    contact = enterNewContactData();

    contacts.push_back(contact);
    if (contactsFile.writeNewContactInFile(contact))
        cout << endl << "New contact was added." << endl << endl;
    else
        cout << "Error. Failed to add new contact to file." << endl;
    system("pause");
}

Contact ContactManager::enterNewContactData()
{
    Contact contact;
    string firstName = "", surname = "", phoneNumber = "", email = "", address = "";

    contact.setId(contactsFile.getLastContactId() + 1);
    contact.setUserId(LOGGED_IN_USER_ID);

    cout << "Enter first name: ";
    firstName = AuxiliaryMethods::readLine();
    firstName = AuxiliaryMethods::replaceFirstLetterToUpperCaseAndOtherToLowerCase(firstName);
    contact.setFirstName(firstName);

    cout << "Enter surname: ";
    surname = AuxiliaryMethods::readLine();
    surname = AuxiliaryMethods::replaceFirstLetterToUpperCaseAndOtherToLowerCase(surname);
    contact.setSurname(surname);

    cout << "Enter phone number: ";
    phoneNumber = AuxiliaryMethods::readLine();
    contact.setPhoneNumber(phoneNumber);

    cout << "Enter email: ";
    email = AuxiliaryMethods::readLine();
    contact.setEmail(email);

    cout << "Enter address: ";
    address = AuxiliaryMethods::readLine();
    contact.setAddress(address);

    return contact;
}

void ContactManager::showAllContacts()
{
    system("cls");
    if (!contacts.empty())
    {
        cout << "             >>> CONTACTS <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i = 0; i < contacts.size(); i++)
        {
            cout << endl << "Id:               " << contacts[i].getId() << endl;
            cout << "First name:       " << contacts[i].getFirstName() << endl;
            cout << "Surname:          " << contacts[i].getSurname() << endl;
            cout << "Phone number:     " << contacts[i].getPhoneNumber() << endl;
            cout << "Email:            " << contacts[i].getEmail() << endl;
            cout << "Address:          " << contacts[i].getAddress() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No contacts on the list." << endl << endl;
    }
    system("pause");
}
