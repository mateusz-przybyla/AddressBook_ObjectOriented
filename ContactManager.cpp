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

void ContactManager::showNumberOfSearchedContacts(int numberOfContacts)
{
    if (numberOfContacts == 0)
        cout << endl << "There are no contacts with indicated data." << endl;
    else
        cout << endl << "Number of searched contacts in Address Book: " << numberOfContacts << endl << endl;
}

void ContactManager::showContactData(Contact contact)
{
    cout << endl << "Id:               " << contact.getId() << endl;
    cout << "First name:       " << contact.getFirstName() << endl;
    cout << "Surname:          " << contact.getSurname() << endl;
    cout << "Phone number:     " << contact.getPhoneNumber() << endl;
    cout << "Email:            " << contact.getEmail() << endl;
    cout << "Address:          " << contact.getAddress() << endl;
}

void ContactManager::searchByFirstName()
{
    string firstNameToFind = "";
    int numberOfContacts = 0;

    system("cls");
    if (!contacts.empty())
    {
        cout << ">>> SEARCH BY FIRST NAME <<<" << endl << endl;

        cout << "Search contacts by first name: ";
        firstNameToFind = AuxiliaryMethods::readLine();
        firstNameToFind = AuxiliaryMethods::replaceFirstLetterToUpperCaseAndOtherToLowerCase(firstNameToFind);

        for (vector <Contact>::iterator  itr = contacts.begin(); itr != contacts.end(); itr++)
        {
            if (itr -> getFirstName() == firstNameToFind)
            {
                showContactData(*itr);
                numberOfContacts++;
            }
        }
        showNumberOfSearchedContacts(numberOfContacts);
    }
    else
    {
        cout << endl << "Address Book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void ContactManager::showAllContacts()
{
    system("cls");
    if (!contacts.empty())
    {
        cout << "             >>> CONTACTS <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Contact> :: iterator itr = contacts.begin(); itr != contacts.end(); itr++)
        {
            showContactData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "No contacts on the list." << endl << endl;
    }
    system("pause");
}
