#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include"professor.h"
#include <algorithm>
typedef class professor_menu {
private:
    vector <professor> all_profs;
    vector <string> all_names;
    vector <int> all_prof_ID;
public:
    void add_professor(prof proff);
    void delete_professor();
    void list_professors();
    friend std::ostream& operator<<(std::ostream& output, const prof& proff);
    void professor_menu_display();
    vector <professor> get_profs (){return all_profs;}
    
    
    bool check_name(string name);
    float get_index(string name);
    string  get_prof (int index){return all_names[index];}

}professor_menu;

ostream& operator<<(std::ostream& output,prof& proff){//operator overload to be able to cout a prefossor
  output<< "Professors's Name: "<<proff.get_name()<< endl;
    output<<"Profesors's ID:"<<proff.get_ID()<<endl;
  return output;
}

void   professor_menu::add_professor(prof proff){
         int id;
         string name;
         cout<<"Please enter the Professor's ID"<<endl;
         cin>>id;
         if(find( all_prof_ID.begin(),all_prof_ID.end(),id)!=all_prof_ID.end()){
             cout<<"Professor already exists"<<endl;}
         
         else {all_prof_ID.push_back(id);
             proff.set_ID(id);
             cout<<endl<<"Please enter the Professor's name"<<endl;
             cin.ignore();
             getline(cin,name);
             proff.set_name(name);
             all_profs.push_back(proff);
             all_names.push_back(name);
             cout<<endl<<"Professor added"<<endl;
         }
        }

void   professor_menu::delete_professor(){
    int id;
    float z;
    z =(find( all_prof_ID.begin(),all_prof_ID.end(),id)!=all_prof_ID.end());

    cout<<endl<<"Please enter the Professor's ID"<<endl;
    cin>>id;
    if(find( all_prof_ID.begin(),all_prof_ID.end(),id)!=all_prof_ID.end()){
        all_prof_ID.erase (all_prof_ID.begin()+z);
        all_profs.erase(all_profs.begin()+z);
    
    }
    else cout<<endl<<"Professor doesn't exist"<<endl;
}

void professor_menu::list_professors(){
for (auto j=all_profs.begin();j!=all_profs.end();j++)
{ cout<<endl<<"______________________________"<<endl;
cout<<*j;
    cout<<endl<<"______________________________"<<endl;
}}

void professor_menu::professor_menu_display(){
   while (true){ int choice;
    cout<<"what operation do you want to perform"<<endl<<endl<<"1.  add professor"<<endl<<"2.  delete professor"<<"3. list professors"<<"4.  back";
    cin>>choice;
    prof proff;
    switch (choice){
        case 1:add_professor(proff);break;
        case 2:delete_professor();break;
        case 3:list_professors();break;
        case 4:return;
        default:return;
    }}
}


bool professor_menu::check_name(string name){
    cout<<"Please enter the professor's name"<<endl;
        cout<<endl<<"Please enter the professor's name"<<endl;
        cin.ignore();
        getline(cin,name);
    if(find( all_names.begin(),all_names.end(),name)!=all_names.end())
    {
        return true;
    }

    else
        return false;
}

float professor_menu::get_index(string name){
   vector<string>::iterator it = find(all_names.begin(), all_names.end(), name);

    float index = std::distance(all_names.begin(), it);

    return index;
}
