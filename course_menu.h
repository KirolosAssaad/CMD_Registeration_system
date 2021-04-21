#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include "courses.h"
#include <fstream>
using namespace std;


//___________________course_and_course_menu______________________________//
 class course_menu{
private:
    vector <course> courses;
    vector <string> ID;
     bool store;

public:
//function prototypes
    void add_course (course kors);
    void modify_course ();
    void delete_course ();
    void list_all_courses ();
    friend std::ostream& operator<<(std::ostream& output, const course& course);
     void set_course (course kours){courses.push_back(kours);}
     void set_store (bool s){store =s;}
    string get_courseID();
    void course_menu_display ();
    void list_all_sections();
     bool check_id(string id);
     float get_index(string id);
     course & get_course (int index){return courses[index];}
};

ostream& operator<<(std::ostream& output,course& course){
    //overloading cout function to be able to cout a whole course and its details
  output<< "Course ID: "<<course.get_courseID() << endl;
    output<<"Course name"<<course.get_course_name()<<endl;
    output<<"Number of credits"<<course.get_credit_hours()<<endl;
    output<<"Prerequisits:";
    for (auto i=(course.get_prerequisits()).begin();i!=(course.get_prerequisits()).end();i++)
        output<<*i<<endl;
  output << "\n";
  return output;
}


void course_menu::add_course (course kors){
    string id, name, description, prerequisit;
    int no_of_pre, credits;
    ofstream outfile;
    outfile.open("cata.rtf");
    cout<<"Please enter the course ID add"<<endl;
    cin>>id;
if(find( ID.begin(),ID.end(),id)!=ID.end())//checks for the existance of the course using course id
{cout<<"Course already exists";}
else{ID.push_back(id);
    kors.set_courseID(id);
    if (store==true){
        outfile<<"Number:"<<id<<endl;
    }
    cout<<"please ener the course's name"<<endl;
    cin.ignore();
    getline(cin,name);
    kors.set_course_name(name);
    if (store==true){
           outfile<<"Name:"<<name<<endl;
       }
    cout<<endl<<"Please enter the number of credit hours"<<endl;
    cin>>credits;
    kors.set_credit_hours(credits);
    if (store==true){
           outfile<<"CH:"<<credits<<endl;
       }
    cout<<endl<<"please enetr the course's description"<<endl;
    cin.ignore();
    getline(cin,description);
    kors.set_course_description(description);
    cout<<endl<<"how many prerequisits are there for this course"<<endl;
    cin>>no_of_pre;
    if (no_of_pre==0)
    {cout<<endl<<"this course has no prerequisits"<<endl;
        if (store==true){
               outfile<<"Prereq: "<<endl;
           }
    }
    else{
    for (int i=1;i<=no_of_pre;i++)
    {
        cout<<"prerequisit ("<<i<<"):"<<endl;
        cin.ignore();
        getline(cin,prerequisit);
        kors.set_prerequisits(prerequisit);
        if (store==true){
               outfile<<"Prereq:"<<prerequisit<<endl;
           }
    }}
    courses.push_back(kors);
    cout<<"course is added"<<endl;
    }
}

void course_menu::modify_course(){
    string id, name,description, prerequisit;
    int choice,credits,no_of_pre;
    char yn;
    float y;
    y=find( ID.begin(),ID.end(),id)!=ID.end();
    cout<<"please enter the course's ID modify";
    cin>>id;
    if(find( ID.begin(),ID.end(),id)!=ID.end())
    {cout<<"what do you want to modify"<<endl<<"1.  name"<<endl<<"2. number of credit hours"<<endl<<"3.  course description"<<endl<<"4.  prerequisits"<<endl;
        cin>>choice;
    switch (choice){//a switch to take the choice and change the needed thing to changed
            case 1: {cout<<"please enter the course's new name";
                cin.ignore();
                getline(cin,name);
                (courses[y]).set_course_name(name);
                cout<<"do you want to modify anything else"<<endl;
                cin>>yn;
                if((yn=='y')||(yn=='y'))
                    modify_course();
                else break;
            }
            case 2:{cout<<"please enter the new number of credit hours";
        cin>>credits;
        (courses[y]).set_credit_hours(credits);
                cout<<"do you want to modify anything else"<<endl;
                 cin>>yn;
                 if((yn=='y')||(yn=='y'))
                modify_course();
                else break;

            }
            case 3:{cout<<"please enter the new description";
                cin>>description;
                cin.ignore();
                getline(cin,description);
                (courses[y]).set_course_description(description);
                cout<<"do you want to modify anything else"<<endl;
                 cin>>yn;
                 if((yn=='y')||(yn=='y'))
                      modify_course();
                     else break;

                     }
            case 4:{cout<<"please enter the total number of prerequisits  (old and new) or type -1 to go back";
                cin>>no_of_pre;
                if(no_of_pre==0)
                {((courses[y]).get_prerequisits()).clear();
                    cout<<"all prerequisits are removed";}
                else if (no_of_pre==-1){return;}
                else{
                for (int i=1;i<=no_of_pre;i++)
                {cout<<"prerequisit ("<<i<<"):"<<endl;
                    cin>>prerequisit;
                    (courses[y]).set_prerequisits(prerequisit);}}
                cout<<"do you want to modify anything else"<<endl;
                 cin>>yn;
                 if((yn=='y')||(yn=='y'))
                  modify_course();
                     else break;
            }
}}

    else
        cout<<"course doesn't exist";
    
}

void course_menu::delete_course(){
    string id;
    float z;
    char choice;
    z =(find( ID.begin(),ID.end(),id)!=ID.end());//checking for the existance of the course

    cout<<"please enter the course's ID delete";
       cin>>id;
    if(find( ID.begin(),ID.end(),id)!=ID.end())

    {cout<<"are you sure you want to do delete it?"<<endl;
        cin>>choice;
        if ((choice=='y')||(choice =='Y'))
        {
           ID.erase (ID.begin()+z);
           courses.erase(courses.begin()+z);
           cout<<"Course deleted";
        }
        else{ cout<<"course not deleted";
            return;}}
       else
       {cout<<"course doesn't exist";}

}

void course_menu::list_all_courses(){//uses the overloaded operator and couts all the courses
    for (auto j=courses.begin();j!=courses.end();j++)
    { cout<<endl<<"______________________________"<<endl;
    cout<<*j;
        cout<<endl<<"______________________________"<<endl;
    }}

void course_menu::list_all_sections(){
    string id;
    
    cout<< "please enter course id";
    cin>>id;
      if(check_id(id)==true)
    {
    float i=get_index(id);
    get_course(i).get_sections();
    }
       
       }

void course_menu::course_menu_display(){//uses a switch to call all the functions upon request
    while (true)
       {int choice;
    course kors;
    cout<<"what operation do you want to preform"<<endl<<"1.  add course"<<endl<<"2.  modify course"<<endl<<"3. delete course"<<endl<<"4.  list all courses"<<endl<<"5.  back"<<endl;
    cin>>choice;
    
   switch (choice){
        case 1:add_course(kors);break;
        
        case 2: modify_course();break;

        case 3:
            delete_course();break;

        case 4: list_all_sections();break;

        case 5: return;
        default: break;
    }}
    
}

bool course_menu::check_id(string id){//check for the existance of acourse
    cout<<"Please enter the course ID"<<endl;
        cin>>id;
    if(find( ID.begin(),ID.end(),id)!=ID.end())
    {
        return true;
    }

    else
        return false;
}

float course_menu::get_index(string id){//gets the index of a course in a large vector of strings
   vector<string>::iterator it = find(ID.begin(), ID.end(), id);
    
    float index = std::distance(ID.begin(), it);
    
    return index;
}
