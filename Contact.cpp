#include "Contact.h"

void Contact::setId(int newId)
{
    if (id >= 0)
        id = newId;
}

void Contact::setUserId(int newUserId)
{
    userId = newUserId;
}

void Contact::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}

void Contact::setSurname(string newSurname)
{
    surname = newSurname;
}

void Contact::setPhoneNumber(string newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

void Contact::setEmail(string newEmail)
{
    email = newEmail;
}

void Contact::setAddress(string newAddress)
{
    address = newAddress;
}

int Contact::getId()
{
    return id;
}

int Contact::getUserId()
{
    return userId;
}

string Contact::getFirstName()
{
    return firstName;
}


string Contact::getSurname()
{
    return surname;
}

string Contact::getPhoneNumber()
{
    return phoneNumber;
}

string Contact::getEmail()
{
    return email;
}

string Contact::getAddress()
{
    return address;
}
