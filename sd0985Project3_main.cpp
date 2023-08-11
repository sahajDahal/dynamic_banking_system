#include "sd0985Project3_header.h"

int main()
{
    groupMembers(); //displays group member info
    Student std;
    ofstream fout;
    ifstream fin;
    bool correctInput;
    int id;

   
    
    
    
    
    
    int userChoice;
    userChoice=static_cast<Choices>(userChoice);
    while(userChoice != 6){ //loop runs unless user chooses quit
    cout<<"1.Add\n";
    cout<<"2.Remove\n";
    cout<<"3.Display\n";
    cout<<"4.Search\n";
    cout<<"5.Results\n";
    cout<<"6.Quit\n\n";

    cout<<"Make a menu choice(1-6): ";
    cin>>userChoice;
    
    switch(userChoice)
    {
        case Add:
            add_Student(std);
            break;

        case Remove:
            cout<<"What is the ID of the student: ";
            cin>>id;
            remove_Student(id);
            break;

        case Display:
            display();
            break;

        case Search:
            cout<<"What is the ID of the student: ";
            cin>>id;
            search(id);
            break;

        case Results:
            exportResults();
            break;
        
        case Quit:
            cout<<"you have exited the program\n";
            break;
        default:
            cout<<"error enter valid input:\n";
            break;
    }
    }
    return 0;
 
}



