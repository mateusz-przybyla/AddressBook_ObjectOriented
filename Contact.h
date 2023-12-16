#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

class Contact
{
    int id, userId;
    string firstName, surname, phoneNumber, email, address;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setFirstName(string newFirstName);
    void setSurname(string newSurname);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setAddress(string newAddress);

    int getId();
    int getUserId();
    string getFirstName();
    string getSurname();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
};

#endif
