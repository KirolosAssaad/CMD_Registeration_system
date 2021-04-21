#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef class professor{
private:
    string name;
    int ID;
public:
    void set_name (string prof_name){name=prof_name;}
    void set_ID (int id){ID=id;}
    string get_name(){return name;}
    int get_ID (){return ID;}
}prof;


