#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "patron.h"
//#include "ride.h" maybe? idk if it goes in here or in patron.cpp or patron.h

//Function Prototypes
void displayMenuOption();

int getMenuOption();

void printFileNotFound();

void displayModOptions();

void displayRideMenu();

int getModOptions();

//New function prototypes for checkpoint 2
Patron createNewPatron();

int readExistingPatrons(Patron, string);

void addPatron(Patron& patron);

void overwriteFile();

void modifyPatron();

void addTickets();

void editName();

void removePatron();

void addRide();


//Main function
int main(int argc, char* argv[]) 
{
    if(!argc == 2)
    {
        printFileNotFound();
        return 0;
    }
    int numPatrons = 0;
    Patron patronArr[10];
    string patronData = argv[1];
    //function to get the number of words and store file input into an array of strings
    //sumOfWords = getWords(LENGTH_ROWS, wordArray, argv[1]);
    //I will continued to be used for iteration thus must be reset to zero each time.
    //do while loop so it executes at least once, count letters function
    
    //ifstream file;
    //file.open("patronList.txt");
    //if(file.is_open())
    //{ 

        //Variable for first user input choice
        int choice;
        numPatrons = readExistingPatrons(patronArr, patronData);
        do
        {
            //displayMenuOption();
            //cin >> choice;
            choice = getMenuOption();
            //Menu options
            
            switch (choice)
            {
                case 1:
                    cout << "testing other options" << endl;
                    //addPatron();
                    break;
                case 2: 
                    cout << "testing other options" << endl;
                    break;
                case 3: 
                    modifyPatron();
                    break;
                case 4: 
                    cout << "testing other options" << endl; 
                    break;
                case 0: 
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Error: Please pick an option 0-4." << endl;
                    break;
            }
        }while(choice != 0);
    //}else{
        //cout<<"Unable to open the file."<<endl;
    //}

    return 0;
}

//Taking the user input
int getMenuOption(){
    int choice;
    displayMenuOption();
    cin >> choice;
    return choice;

}

//Displaying the menu
void displayMenuOption(){
    cout << "1. Add Patron" << endl;
    cout << "2. Remove Patron" << endl;
    cout << "3. Modify Patron" << endl;
    cout << "4. View Patron" << endl;
    cout << "0. Exit" << endl;
}

//If the patron list file isn't entered on the command line
void printFileNotFound(){
    cout << "Patron file not found. Run the program again with the file name on command line 1." << endl;
}

//Displaying the modification options
void displayModOptions(){
    cout << "1. Add tickets" << endl;
    cout << "2. Purchase admittance to ride" << endl;
    cout << "3. Edit name" << endl;
    cout << "0. Exit to main menu" << endl;
}

//Displaying ride menu
void displayRideMenu(){
    cout << "Select the ride you'd like to add." << endl;
    cout << "Ride (Ticket Cost)" << endl;
    cout << "1. Teacups (3 tickets)" << endl;
    cout << "2. Magic Carpet (2 tickets)" << endl;
    cout << "3. World Tour (1 tickets)" << endl;
}

//Second user input choice labled choice2
int getModOptions(){
    int choice2;
    displayModOptions();
    cin >> choice2;
    cout << choice2 << endl;
    return choice2;
}

Patron createNewPatron() {
    string firstName, lastName;
    int patronNumber, tickets;
    //modify for file i/o?
    //It will need to be printed directly to the .txt file-- Let me get the args working (AJ)
    cout << "Enter the patron's first name: " << endl;
    cin >> firstName;
    cout << "Enter the patron's last name: " << endl;
    cin >> lastName;
    cout << "Enter the patron's number: " << endl;
    cin >> patronNumber;
    cout << "Enter the number of tickets: " << endl;
    cin >> tickets;
    Patron patron(firstName, lastName, patronNumber, tickets);
    return patron;
}

void addPatron(Patron& patron) {
    //needs more to be fleshed out
    createNewPatron();
}

int readExistingPatrons(Patron patronArr[], string patronData){
    /*
    String firstName;
    String lastName;
    int patronNumb;
    int ticketNumb;
    int ind = 0;
    Patron info;
    */
    ifstream file;
    file.open(patronData);
    if(file.is_open())
    {
        /*
            Suggested code:
            while(file >> firstName >> lastName >> patronNumb >> ticketNumb){
                info = (firstName, lastName, patronNumb, ticketNumb);
                patronArray[ind] = info;
                ind++;
            }
        */
        
    }else{
        cout<<"Unable to open the file."<<endl;
        //return ind;
    } 
    //return ind + 1;
}

void displayPatrons(Patron patronArr[], int numPatrons){
    int count = 1;
    for(int i = 0; i < numPatrons; i++){
        cout << count << ". " << patronArr[i].getFirstName()<< patronArr[i].getLastName() << endl;
        count++;
    }
}

void modifyPatron(){

    displayPatrons(patronArr[10], numPatrons);


}
//With respective menu choice that uses the Mod Menu functions, lable choice2 = getModOptions();
//Labled like this to not get it confused with the original choice var and makes it easier to read :)