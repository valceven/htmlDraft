#include <iostream>
#include "LinkedSentinel.h"
using namespace std;

int main(){

    Sentinel *myList = new LinkedSentinel();

    int choice, num, elem,pos,left,right;
    string name;

    cout << "Enter your name here: " ;
    getline(cin,name);

    do{
        myList->menuz("Ceven Gwapo");
        cout << "\nPlease select from (1-7): ";
        cin >> choice;

        switch (choice){

            case 1: cout << "Enter a number to add at Head: ";
                    cin >> num;
                    myList->addHead(num);
                    break;
            case 2: cout << "Enter a number to add at Tail: ";
                    cin >> num;
                    myList->addTail(num);
                    break;
            case 3: cout << "Enter the position to remove: ";
                    cin >> pos;
                    cout << "Succesfully removed: " << myList->removeAt(pos) << endl;
                    break;
           case 4:  cout << "Enter a number to remove: ";
                    cin >> num;
                    cout << "Succesfully removed: " << myList->removeNum(num) << endl;
                    break;
           case 5:  cout << "Enter a number: ";
                    cin >> num;
                    cout << "Succesfully removed: " << myList->retain(num) << endl;
                    break;
           case 6:  cout << "Succesfully removed: " << myList->removeRedundant() << " elements." << endl;
                    break;
           case 7:  cout << "Enter left: ";
                    cin >> left;
                    cout << "Enter right: ";
                    cin >> right;
                    cout << "Succesfully removed: " << myList->corner(left,right) << " elements." << endl;
                    break;                   
           case 8:  cout << "Here is your list: ";
                    myList->print();
                    break;
            default:cout << "Wrong selection. Please try again :)";
                    break; 
        }
    }while(choice != 0);

    return 0;
}

