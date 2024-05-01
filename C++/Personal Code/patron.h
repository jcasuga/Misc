#include <string>
#ifndef PATRON_H
#define PATRON_H
using namespace std;
class Patron{
    int tickets, patronNumber;
    string firstName, lastName;
    public:
        Patron();
        Patron(string, string, int, int);
        Patron(const Patron&);
        int getPatronNumber();
        void setPatronNumber(int);
        int getTickets();
        void setTickets (int);
        string getFirstName();
        void setFirstName(string);
        string getLastName();
        void setLastName(string);
        //void displayPatronData();
};
#endif