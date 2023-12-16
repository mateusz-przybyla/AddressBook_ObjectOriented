#include "ContactManager.h"

void ContactManager::setLoggedUserId(int newLoggedUserId)
{
    loggedUserId = newLoggedUserId;
}

void ContactManager::getLastContactId()
{
    lastContactId = contactsFile.getLastContactId();
}

void ContactManager::addContact()
{
    Contact contact;

    system("cls");
    cout << " >>> ADDING NEW CONTACT <<<" << endl << endl;
    contact = enterNewContactData();

    contacts.push_back(contact);
    contactsFile.writeNewContactInFile(contact);
}

Contact ContactManager::enterNewContactData()
{
    Contact contact;
    string firstName, surname, phoneNumber, email, address;

    contact.setId(++lastContactId);
    contact.setUserId(loggedUserId);

    cout << "Enter first name: ";
    cin >> firstName;
    contact.setFirstName(firstName);
    //contact.firstName = zamienPierwszaLitereNaDuzaAPozostaleNaMale(contact.firstName);

    cout << "Enter surname: ";
    cin >> surname;
    contact.setSurname(surname);
    //contact.surname = zamienPierwszaLitereNaDuzaAPozostaleNaMale(contact.surname);

    cout << "Enter phone number: ";
    cin >> phoneNumber;
    contact.setPhoneNumber(phoneNumber);

    cout << "Enter email: ";
    cin >> email;
    contact.setEmail(email);

    cout << "Enter address: ";
    cin >> address;
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

void ContactManager::clearContactsInMemory()
{
    contacts.clear();
}

void ContactManager::getContactsFromFile(int loggedUserId)
{
    contacts = contactsFile.getContactsFromFile(loggedUserId);
}
