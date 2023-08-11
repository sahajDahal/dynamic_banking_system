#include "sd0985Project3_header.h"


void groupMembers() //displays group member info
{
    cout << "GROUP MEMBER INFO: "<<endl;
    cout << "Name: Sahaj Dahal, Remington Smenner, Meetika Kanumukula"<<endl;
    cout << "EUID: sd0985, rss0210, mk1156"<<endl;
    cout << "E-mail: SahajDahal@my.unt.edu, RemingtonSmenner@my.unt.edu, MeetikaKanumukula@my.unt.edu"<<endl;
    cout << "Department Name: Computer Science and Engineering"<<endl;
    cout << "Course Number: CSCE1030"<<endl;
    cout<<endl;
}

int getNumber()
{
	ifstream fin;
	fin.open("student.dat");
	if (fin.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}
	int count=0;
	string line;
	while(!fin.eof())
	{
		getline(fin, line);
		++count;
	}
	
	fin.close();
	return(count);
	
}

void add_Student(Student std) 
{
    ofstream fout;
    string fname;
    string lname;
    string dummy;
    int numOfTests;

    cout<<"What is the students first name?: ";
    cin>>fname;
    cout<<"What is the students last name?: ";
    cin>>lname;
    std.name=lname+","+fname;
    cout<<"What is the student ID: ";
    cin>>std.id;

    
    

    cout<<"Number of tests?: ";
    cin>>std.studentNumTest;
    
    
    std.testScorePtr=new int[std.studentNumTest];

    for(int i=0;i<std.studentNumTest;++i)
    {
        cout<<"what was the score for test #"<<i+1<<": ";
        cin>>std.testScorePtr[i];
    }

     fout.open("student.dat",ios::app);
     
     if(fout.fail())
    {
        cout<<"Could not open output file\n";
        exit(1);
    }
    fout<<endl;
    fout<<std.name<<",";
    fout<<std.id<<",";
    fout<<std.studentNumTest<<",";          //adding new student data
    for(int i=0;i<std.studentNumTest;++i)
    {
        fout<<std.testScorePtr[i]<<",";
    }
    
    fout.close();
    delete [] std.testScorePtr;
    
}


void remove_Student(int id)
{
    int numStd=getNumber();
    Student* stdList;
    stdList=new Student[numStd];
    ifstream fin;
    string fname;
    string lname;
    bool idFound=false;
    int idFoundIndex;
    fin.open("student.dat");
    if(fin.fail())
    {
        cout<<"file failure in remove_student function\n";
        exit(1);
    }

    for(int i=0;i<numStd;++i) //reading in student data from file
    {
        getline(fin,lname,',');
        getline(fin,fname,',');
        stdList[i].name=lname+","+fname;
        fin>>stdList[i].id;
        if(stdList[i].id==id)
        {
            idFound=true;
            idFoundIndex=i;
        }
        fin.ignore(256,',');
        fin>>stdList[i].studentNumTest;
        fin.ignore(256,',');
        stdList[i].testScorePtr=new int[stdList[i].studentNumTest];
        for(int j=0;j<stdList[i].studentNumTest;++j)
        {
            fin>>stdList[i].testScorePtr[j];
            fin.ignore(256,',');
        }
    }

    ofstream fout;
    fout.open("student.dat");
    if(fout.fail())
    {
        cout<<"fout failed in remove_Student function\n";
        exit(1);
    }

    if(idFound)
    {
        for(int i=0;i<numStd;++i)   //display struct values if id found
        {
            if(i != idFoundIndex)
            {
                fout<<stdList[i].name<<","<<stdList[i].id<<","<<stdList[i].studentNumTest<<",";
                for(int j=0;j<stdList[i].studentNumTest;++j)
                {
                    fout<<stdList[i].testScorePtr[j]<<",";
                }
                cout<<endl;
            }
        }

    }
    else
    {
        cout<<"that ID does not exist\n";
    }

    //deallocate testscoreptr from each array of structures
    for(int i=0;i<numStd;++i)
    {
        delete [] stdList[i].testScorePtr;
    }
    //deallocate stdList
    delete [] stdList;
    fin.close();
    fout.close();
}

void display()
{
    int numStd=getNumber();
    Student* stdList;
    stdList=new Student[numStd];
    string fname;
    string lname;
    ifstream fin;
     fin.open("student.dat");
    if(fin.fail())
    {
        cout<<"file failure in remove_student function\n";
        exit(1);
    }

    for(int i=0;i<numStd;++i)   //displays student info formatted to the console
    {
        getline(fin,lname,',');
        getline(fin,fname,',');
        stdList[i].name=lname+","+fname;
        fin>>stdList[i].id;
        fin.ignore(256,',');
        fin>>stdList[i].studentNumTest;
        fin.ignore(256,',');
        stdList[i].testScorePtr=new int[stdList[i].studentNumTest];
        for(int j=0;j<stdList[i].studentNumTest;++j)
        {
            fin>>stdList[i].testScorePtr[j];
            fin.ignore(256,',');
        }
    }

    for(int i=0;i<numStd;++i)
    {
        cout<<setw(30)<<left<<stdList[i].name<<setw(15)<<left<<stdList[i].id;
        for(int j=0;j<stdList[i].studentNumTest;++j)
        {
            cout<<setw(5)<<left<<stdList[i].testScorePtr[j];
        }
        cout<<endl;
    }



    for(int i=0;i<numStd;++i)
    {
        delete [] stdList[i].testScorePtr;
    }
    delete [] stdList;
    fin.close();
}

void search(int id)
{
    Student* ptrStd;
    ptrStd=new Student;
    int numStd=getNumber();
    bool idFound=false;
    int idFoundIndex;
    string fname;
    string lname;
    ifstream fin;
    fin.open("student.dat");
    if(fin.fail())
    {
        cout<<"fin failed in search function\n";
        exit(1);
    }

    while((!idFound)&&(!fin.eof())) //searches for ID
    {
        getline(fin,lname,',');
        getline(fin,fname,',');
        ptrStd->name=lname+","+fname;
        fin>>ptrStd->id;
        fin.ignore(256,',');
        fin>>ptrStd->studentNumTest;
        fin.ignore(256,',');
        ptrStd->testScorePtr=new int[ptrStd->studentNumTest];
        for(int j=0;j<ptrStd->studentNumTest;++j)
        {
            fin>>ptrStd->testScorePtr[j];
            fin.ignore(256,',');
        }
        if(ptrStd->id==id)
        {
            idFound=true;
        }
    }

    if(idFound==true)   //displays student info if id found
    {
        cout<<setw(30)<<left<<ptrStd->name<<setw(15)<<left<<ptrStd->id;
        for(int j=0;j<ptrStd->studentNumTest;++j)
        {
            cout<<setw(5)<<left<<ptrStd->testScorePtr[j];
        }
        cout<<endl;
    }
    else
    {
        cout<<"this ID was not found\n";
    }


    //delete pointer member array
    delete [] ptrStd->testScorePtr;
    delete ptrStd;
    fin.close();
}

int findMinimum(int array[],int arraySize)
{
    int minScore;
    if(arraySize<5)
    {
        minScore=0;
    }
    else
    {
        minScore=array[0];
        for(int i=1;i<arraySize;++i)    //finds minimum test score
        {
            if(array[i]<minScore)
            {
                minScore=array[i];
            }
        }
    }
    return minScore;
}

void exportResults()
{
    int numStd=getNumber();
    Student* stdList;
    stdList=new Student[numStd];
    string fname;
    string lname;
    ifstream fin;
     fin.open("student.dat");
    if(fin.fail())
    {
        cout<<"file failure in exportResults function\n";
        exit(1);
    }

    for(int i=0;i<numStd;++i)
    {
        getline(fin,lname,',');
        getline(fin,fname,',');
        stdList[i].name=lname+","+fname;
        fin>>stdList[i].id;
        fin.ignore(256,',');
        fin>>stdList[i].studentNumTest;
        fin.ignore(256,',');
        stdList[i].testScorePtr=new int[stdList[i].studentNumTest];
        for(int j=0;j<stdList[i].studentNumTest;++j)
        {
            fin>>stdList[i].testScorePtr[j];
            fin.ignore(256,',');
        }
    }
    
    ofstream fout;
    fout.open("averages.dat");
    if(fout.fail())
    {
        cout<<"fout failed in Display function\n";
        exit(1);
    }

    double sum;
    int minScore;
    double avg;
    for(int i=0;i<numStd;++i)   //exports student ID and averages adjusting for minimum score dropped 
    {
        sum=0;
        minScore=findMinimum(stdList[i].testScorePtr,stdList[i].studentNumTest);
        for(int j=0;j<stdList[i].studentNumTest;++j)
        {
            sum+=stdList[i].testScorePtr[j];
        }
        fout<<"student id: "<<stdList[i].id;
        sum=sum-minScore;
        if(minScore>0)
        {
            avg=sum/(stdList[i].studentNumTest-1);
        }
        else
        {
            avg=sum/stdList[i].studentNumTest;
        }
        fout<<" average: "<<fixed<<showpoint<<setprecision(1)<<avg<<endl;

    }

    for(int i=0;i<numStd;++i)
    {
        delete [] stdList[i].testScorePtr;
    }
    delete [] stdList;
    fin.close();
    fout.close();
}