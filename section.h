#pragma once

#include <iostream>
#include <algorithm>

using namespace std;


 class section{
private:
    int section_no;
    string day;
    int time;
    string course_id;
    string professor;
    vector <int> students_id;
public:
    void set_section_no (int section_number){section_no=section_number;}
    void set_day (string days){day=days;}
    void set_time (int times){time=times;}
    void set_course_id (string ID){course_id=ID;}
    void set_professor (string prof){professor=prof;}
    void set_student (int student){students_id.push_back(student);}

    int get_section_no (){return section_no;}
    string get_day (){return day;}
    int get_time () {return time;}
    string get_professor (){return professor;}
    string get_course_ID (){return course_id;}
    vector <int> get_students (){return students_id;}
};

