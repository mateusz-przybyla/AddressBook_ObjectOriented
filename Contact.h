#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

class Contact
{
    int id, userId;
    string firstName, surname, phoneNumber, email, address;

public:
    Contact(int id = 0, int userId = 0, string firstName = "", string surname = "", string phoneNumber = "", string email = "", string address = "")
    {
        this->id = id;
        this->userId = userId;
        this->firstName = firstName;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->address = address;
    }

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
