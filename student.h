#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

 class student {
private:
    string name;
    int ID;
    float GPA;
public:
    void set_name (string st_name){name=st_name;}
    void set_ID(int st_ID){ID=st_ID;}
    void set_GPA(float st_gpa){GPA=st_gpa;}
    
    string get_name(){return name;}
    int get_ID (){return ID;}
    float get_GPA(){return GPA;}
};


