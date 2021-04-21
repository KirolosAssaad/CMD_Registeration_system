#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#include "section.h"
using namespace std;


 class course{
private:
    string course_ID; //unique for each course
    string course_name;
    int credit_hours;
    string course_description;
    vector <string> prerequisits;
    vector <section> all_sections;
     vector <int> sec_no;
public:
    void set_courseID (string ID){course_ID=ID;}
    void set_course_name(string name){course_name=name;}
    void set_credit_hours(int cr_hrs){credit_hours=cr_hrs;}
    void set_course_description (string description){course_description=description;}
    void set_prerequisits (string pre){prerequisits.push_back(pre);}
     void set_sec (int sec){sec_no.push_back(sec);}
    string get_courseID (){return course_ID;}
    string get_course_name (){return course_name;}
    int get_credit_hours (){return credit_hours;}
    string get_course_description (){return course_description;}
    vector <string> get_prerequisits (){return prerequisits;}
     vector <int> get_sec_no(){return sec_no;}
     void add_section(section sec){all_sections.push_back(sec);}
     void get_sections (){
         if (! all_sections.empty()){
             float z;
             for (auto i=all_sections.begin();i!=all_sections.end();i++)
             {z=distance(all_sections.begin(),i);
                 cout<<"section number: "<<all_sections[z].get_section_no()<<endl;
                 cout<<"section Day"<<all_sections[z].get_day()<<endl;
                 cout<<"section time"<<all_sections[z].get_time()<<endl;
                 cout<<"section professor"<<all_sections[z].get_professor()<<endl;

             }
         }
         
     }
};


