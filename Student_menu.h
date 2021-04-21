#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "student.h"
using namespace std;

//__________________student_menu________________________________________________________________________________________//
 class student_menu {

private:
    vector <student> all_students;
    vector <int> all_st_id;
public:
    void add_student(student st);
    void delete_student();
    void list_students();
    vector <student> get_all_students(){return all_students;};
friend std::ostream& operator<<(std::ostream& output, const student& student);
    void student_menu_display();
     bool check_id(int id);

        };

ostream& operator<<(std::ostream& output,student& student){
  output<< "student's Name: "<<student.get_name()<< endl;
    output<<"Student's ID:"<<student.get_ID()<<endl;
    output<<"student's GPA:"<<student.get_GPA()<<endl;
  return output;
}

void   student_menu::add_student(student st){
         int id;
         string name;
         float gpa;
         cout<<"Please enter the student's ID";
         cin>>id;
         if(find( all_st_id.begin(),all_st_id.end(),id)!=all_st_id.end()){
             cout<<"Student already exists";}
         
         else {all_st_id.push_back(id);
             st.set_ID(id);
             cout<<endl<<"Please enter the student's name"<<endl;
             cin.ignore();
             getline(cin,name);
             st.set_name(name);
             cout<<endl<<"Please enter the student's GPA"<<endl;
             cin>>gpa;
             st.set_GPA(gpa);
             all_students.push_back(st);
             cout<<endl<<"Student added"<<endl;
         }
        }

void   student_menu::delete_student(){
    int id;
    float z;
    z =(find( all_st_id.begin(),all_st_id.end(),id)!=all_st_id.end());

    cout<<endl<<"Please enter the student's ID"<<endl;
    cin>>id;
    if(find( all_st_id.begin(),all_st_id.end(),id)!=all_st_id.end()){
        all_st_id.erase (all_st_id.begin()+z);
        all_students.erase(all_students.begin()+z);
    
    }
    else cout<<endl<<"student doesn't exist"<<endl;
}

void student_menu::list_students(){
for (auto j=all_students.begin();j!=all_students.end();j++)
{ cout<<endl<<"______________________________"<<endl;
cout<<*j;
    cout<<endl<<"______________________________"<<endl;
}}

void student_menu::student_menu_display(){
   while (true) {int choice;
    cout<<"what operation do you want to perform"<<endl<<endl<<"1.  add student"<<endl<<"2.  delete student"<<"3. list student"<<"4.  back";
    cin>>choice;
    student student;
    switch (choice){
        case 1:
            add_student(student);break;
        case 2:
            delete_student();break;
        case 3:list_students();break;
        case 4:return;
        default:return;
    }
}
    
}

bool student_menu::check_id(int id){
    cout<<"Please enter the course ID"<<endl;
        cin>>id;
    if(find( all_st_id.begin(),all_st_id.end(),id)!=all_st_id.end())
    {
        return true;
    }

    else
        return false;
}
