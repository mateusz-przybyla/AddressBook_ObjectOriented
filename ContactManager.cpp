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

void ContactManager::searchBySurname()
{
    string surnameToFind = "";
    int numberOfContacts = 0;

    system("cls");
    if (!contacts.empty())
    {
        cout << ">>> SEARCH BY SURNAME <<<" << endl << endl;

        cout << "Search contacts by surname: ";
        surnameToFind = AuxiliaryMethods::readLine();
        surnameToFind = AuxiliaryMethods::replaceFirstLetterToUpperCaseAndOtherToLowerCase(surnameToFind);

        for (vector <Contact>::iterator  itr = contacts.begin(); itr != contacts.end(); itr++)
        {
            if (itr -> getSurname() == surnameToFind)
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

int enterSelectedContactId()
{
    int idOfSelectedContact = 0;
    cout << "Podaj numer ID Adresata: ";
    idOfSelectedContact  = AuxiliaryMethods::readInteger();
    return idOfSelectedContact;
}

char ContactManager::selectAnOptionFromEditMenu()
{
    char choice;

    cout << endl << "   >>> EDIT MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Contact details for editing: " << endl;
    cout << "1 - First name" << endl;
    cout << "2 - Surname" << endl;
    cout << "3 - Phone number" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Address" << endl;
    cout << "6 - Go to user menu" << endl;
    cout << endl << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

void ContactManager::editContact()
{
    system("cls");
    int contactIdToBeEdited = 0;

    cout << ">>> EDITING SELECTED CONTACT <<<" << endl << endl;
    contactIdToBeEdited = enterSelectedContactId();

    char choice;
    bool contactFound = false;

    for (size_t i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].getId() == contactIdToBeEdited)
        {
            contactFound = true;
            choice = selectAnOptionFromEditMenu();

            switch (choice)
            {
            case '1':
                cout << "Enter new first name: ";
                contacts[i].setFirstName(AuxiliaryMethods::readLine());
                contacts[i].getFirstName() = AuxiliaryMethods::replaceFirstLetterToUpperCaseAndOtherToLowerCase(contacts[i].getFirstName());
                //zaktualizujDaneWybranegoAdresata(contacts[i], contactIdToBeEdited);
                break;
            case '2':
                cout << "Enter new surname: ";
                contacts[i].setSurname(AuxiliaryMethods::readLine());
                contacts[i].getSurname() = AuxiliaryMethods::replaceFirstLetterToUpperCaseAndOtherToLowerCase(contacts[i].getSurname());
                //zaktualizujDaneWybranegoAdresata(contacts[i], contactIdToBeEdited);
                break;
            case '3':
                cout << "Enter new phone number: ";
                contacts[i].setPhoneNumber(AuxiliaryMethods::readLine());
                //zaktualizujDaneWybranegoAdresata(contacts[i], contactIdToBeEdited);
                break;
            case '4':
                cout << "Enter new email: ";
                contacts[i].setEmail(AuxiliaryMethods::readLine());
                //zaktualizujDaneWybranegoAdresata(contacts[i], contactIdToBeEdited);
                break;
            case '5':
                cout << "Enter new address: ";
                contacts[i].setAddress(AuxiliaryMethods::readLine());
                //zaktualizujDaneWybranegoAdresata(contacts[i], contactIdToBeEdited);
                break;
            case '6':
                cout << endl << "Back to user menu." << endl << endl;
                break;
            default:
                cout << endl << "There is no such option! Back to user menu." << endl << endl;
                break;
            }
        }
    }
    if (contactFound == false)
    {
        cout << endl << "No contact with that ID on the list." << endl << endl;
    }
    system("pause");
}
