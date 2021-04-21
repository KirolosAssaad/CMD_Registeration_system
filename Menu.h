#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "section_menu.h"
#include "course_menu.h"
#include "porfessor_menu.h"
#include "Student_menu.h"
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

typedef class AUC_MENU{
private:
    vector <string> ID;
public:
    void auc_menu_display(course_menu & cm,student_menu & sm, professor_menu &pm,section_menu & secm);
    void load_catalog (course_menu & cm, course & c);
    void store_courses (course_menu &cm);
}AUC;
void AUC::auc_menu_display(course_menu & cm,student_menu & sm, professor_menu &pm,section_menu & secm){
    while (true){int choose;
    cout<<"Welcome to the AUC"<<endl<<endl<<"1.  course menu"<<endl<<"2.  section menu"<<endl<<"3.  Professor Menu"<<endl<<"4.  student menu"<<endl<<"5.  list all courses"<<endl<<"6. load old catalog"<<endl<<"7.  store new courses"<<endl<<"exit"<<endl;
    cin>>choose;
        course c;
    switch (choose){
        case 1:{cm.course_menu_display();
            break;}
        case 2:{secm.section_menu_display(cm,sm,pm);
            break;}
        case 3:{pm.professor_menu_display();
            break;}
        case 4:{sm.student_menu_display();
            break;}
        case 5:{cm.list_all_courses();
            break;}
        case 6:load_catalog(cm, c);break;
        case 7: store_courses(cm);
        default:return;
    }
    }}
void AUC::load_catalog(course_menu & cm, course & c){
        ifstream infile;
   ifstream myfile("carta.rtf");
            if(infile.fail())
    {cerr << "Error: " << strerror(errno)<<endl;exit(1);
    }
    
    char* id = nullptr;
    char* name = nullptr;
    char* ch = nullptr;
    char* description = nullptr;
    char* prereqs = nullptr;
        
//        while (!infile.eof()){
//        infile>> id>>name>>ch>>description>>prereqs;
           while (infile>> id>>name>>ch>>description>>prereqs) {
    char* ID=  strtok(id, ":");
            c.set_courseID(ID);
            
            char* Name= strtok(name, ":");
            c.set_course_name(Name);
            
            char* CH= strtok(ch,":");
            int credits= atoi(CH);
            c.set_credit_hours(credits);
            
            char* Desc= strtok(description, ":");
            c.set_course_description(Desc);
            
            char* Pre= strtok(prereqs, ":");
            if (Pre==(char*)" ") c.set_prerequisits(" ");
            else c.set_prerequisits(Pre);
            return;
            cm.set_course(c);
           }}
void AUC_MENU::store_courses(course_menu &cm){
    int i;
    do{ cout<<"Do you want to store any new course"<<endl<<"1.  yes"<<endl<<"2.  No";
        cin>>i;
    }
    while ((i!=1)||(i!=2));
    if (i==1)
        cm.set_store(true);
       
   else
       cm.set_store(false);
       }
