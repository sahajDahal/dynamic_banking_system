#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

enum Choices{Add=1,Remove=2,Display=3,Search=4,Results=5,Quit=6};

struct Student{

    string name;
    int id;
    int studentNumTest;
    int* testScorePtr;
    double average;
};

const int NUM_TESTS=5;
void groupMembers();
int getNumber();
void add_Student(Student std);
void remove_Student(int id);
void display();
void search (int id);
int findMinimum(int array[],int arraySize);
void exportResults();