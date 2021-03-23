```cpp
#include <iostream>
#include <string>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

struct Student{
    int id;
    string name;
    int year;
    double gpa;
    Date dob;
};

bool isEligible(double gpa);

int main(){
    
    Student y;
    
    cout<<"Enter the student ID: ";
    cin>>y.id;
    cout<<"Enter the student name: ";
    cin.ignore();
    getline(cin,y.name);
    cout<<"Enter the student year: ";
    cin>>y.year;
    cout<<"Enter the student gpa: ";
    cin>>y.gpa;
    cout<<"Enter the date of birth (DD/MM/YY): ";
    cin>>y.dob.day >> y.dob.month >>y.dob.year;
    
    cout<<endl;
   
    cout<< "ID: "<< y.id<<endl;
    cout<< "Name: "<<y.name<<endl;
    cout<< "Year in school: " <<y.year<<endl;
    cout<<"GPA: "<<y.gpa<<endl;
    cout<<"DOB: "<<y.dob.day<<"/"<<y.dob.month<<"/"<<y.dob.year;
    
    cout<<endl;
    if(isEligible(y.gpa)){
        cout<< y.name<<" is eligible to apply for graduate school.";
    }else{
        cout<<y.name<<" is not eligible to apply for graduate school.";
    }
    return 0;
}

bool isEligible(double gpa){
    if(gpa >= 3)
        return true;
    else
        return false;
}
```