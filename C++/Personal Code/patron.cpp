#include "patron.h"
#include <iostream>
#include <string>
using namespace std;

Patron::Patron() {
    firstName = "fail";
    lastName = "failure";
    patronNumber = -1;
    tickets = -2;
}

Patron::Patron(string newFirstName, string newLastName, 
int newPatronNumber, int newTickets) {
    firstName = newFirstName;
    lastName = newLastName;
    patronNumber = newPatronNumber;
    tickets = newTickets;
}

Patron::Patron(const Patron& old) {
    firstName = old.firstName;
    lastName = old.lastName;
    patronNumber = old.patronNumber;
    tickets = old.tickets;
}

int Patron::getPatronNumber(){
    return patronNumber;
}

void Patron::setPatronNumber(int newPatronNumber){
    patronNumber = newPatronNumber;
}

int Patron::getTickets(){
    return tickets;
}

void Patron::setTickets(int newTickets){
    tickets = newTickets;
}

string Patron::getFirstName(){
    return firstName;
}

void Patron::setFirstName(string newFirstName){
    firstName = newFirstName; 
}

string Patron::getLastName(){
    return lastName;
}

void Patron::setLastName(string newLastName){
    lastName = newLastName;
}
