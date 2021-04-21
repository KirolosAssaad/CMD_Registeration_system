#pragma once
#include<iostream>
#include<vector>
#include "section.h"
#include "course_menu.h"
#include "Student_menu.h"
#include "porfessor_menu.h"
using namespace std;


//__________________section_menu________________________________________________________________________________________//
 class section_menu{
private:
    vector <section> sections;
public:
    void add_section (course_menu & cm, professor_menu & pm );
    void modify_section (course_menu & cm);
    void delete_section(course_menu & cm);
    void register_student(course_menu & cm, student_menu & sm);
    void unregister_student (course_menu & cm, student_menu & sm);
    void list_all_students (course_menu &cm);
    friend std::ostream& operator<<(std::ostream& output, const section& section);
    void section_menu_display(course_menu & cm,student_menu & sm, professor_menu& pm);
     bool check_sec_no(course c, int id);
     float get_index(course c,int id);
     section & get_section (int index){return sections[index];}

    
    
};

ostream& operator<<(std::ostream& output,section& section){
    int count =0;
    for (auto i=(section.get_students()).begin();i!=(section.get_students()).end();i++)
    {output<<"Student ("<<count<<"): ";
        output<<*i<<endl;
        count++;
    }

  output << "\n";
  return output;
}

void section_menu::add_section(course_menu & cm, professor_menu & pm){
    string id, prof_name;

    int sec_no,days, time_of_class;
    section sektion;
    if(  cm.check_id(id)==true)//check for the existance of the given course
    {sektion.set_course_id(id);

        cout<<endl<<"please enter the section number"<<endl;
        cin>>sec_no;
        sektion.set_section_no(sec_no);
        float x=cm.get_index(id);
        (cm.get_course(x)).set_sec(sec_no);

        cout<<endl<<"Please enter the day the course is offered"<<endl;
            do{  cout<<"please enter the days offered"<<endl<<"1.  UW"<<endl<<"2.  MR"<<endl;
            cin>>days;
                switch (days){//using switch set the days
                    case 1:  sektion.set_day("UW");
                    case 2:  sektion.set_day("MR");
                }}while ((days!=1)&&(days!=2));
            do{ cout<<"please enter the starting time of the lecture in the hhmm format without a colon ";
            cin>>time_of_class;
                sektion.set_time(time_of_class);}
            while ((time_of_class<0000)||(time_of_class>2359));//while loop to make sure that the class takes time during the day
  
        if (pm.check_name(prof_name)==true)
        {
            sektion.set_professor(prof_name);
        }
        else cout<<"this professor doesn't exist";

        sections.push_back(sektion);
        float i=cm.get_index(id);
        (cm.get_course(i)).add_section(sektion);
    }
    else
       { cout<<"course doesn't exist";}
    }

void section_menu::modify_section(course_menu & cm){
    string id, prof_name;
    int choice, sec_no,days, time_of_class;
    char yn;
    float z;
    auto y = sections.begin();

    cout<<"please enter the course's ID ";
    cin>>id;
if(  cm.check_id(id)==true)
{cout<<"Please enter the section ";
        cin>>sec_no;
        for ( ; y !=  sections.end(); y++)
        {
          if ((*y).get_section_no() == sec_no)
          {z=distance(sections.begin(),y);
        cout<<"what do you want to modify"<<endl<<"1.  section number"<<endl<<"2. day offered"<<endl<<"3.  professor"<<endl<<"4.  time"<<endl;
        cin>>choice;
        switch (choice){
            case 1:cout<<"please enter the new section number"<<endl;
                cin>>sec_no;
                (sections[z]).set_section_no(sec_no);
                cout<<"do you want to modify anything else  (y/n)"<<endl;
                 cin>>yn;
                 if((yn=='y')||(yn=='y'))
                modify_section(cm);
            case 2:
                cout<<endl<<"please choose the new offered days"<<endl;
                do{  cout<<"please enter the days offered"<<endl<<"1.  UW"<<endl<<"2.  MR"<<endl;
                cin>>days;
                    switch (days){
                case 1:  (sections[z]).set_day("UW");
                case 2:  (sections[z]).set_day("MR");
                    }}while ((days!=1)||(days!=2));
                cout<<"do you want to modify anything else  (y/n)"<<endl;
                 cin>>yn;
                 if((yn=='y')||(yn=='y'))
                modify_section(cm);
            case 3:
                cout<<endl<<"please choose the name of the new professor"<<endl;
                cin.ignore();
                getline(cin,prof_name);
                (sections[z]).set_professor(prof_name);
                cout<<"do you want to modify anything else  (y/n)"<<endl;
                 cin>>yn;
                 if((yn=='y')||(yn=='y'))
                modify_section(cm);
            case 4:
                cout<<endl<<"Please enter the new time of the beginning of the section"<<endl;
                cin>>time_of_class;
                (sections[z]).set_time(time_of_class);
                cout<<"do you want to modify anything else  (y/n)"<<endl;
                 cin>>yn;
                 if((yn=='y')||(yn=='y'))
                modify_section(cm);
            default:return;
        }}}
}
    else cout<<"course doesn't exist";
}

void section_menu::delete_section(course_menu & cm){
     string id;
     int sec_no;
     char choice;
     float z;
        auto y = sections.begin();

        cout<<"please enter the course's ID modify";
        cin>>id;
        if(  cm.check_id(id)==true)
        {cout<<"Please enter the section ";
            cin>>sec_no;
            for ( ; y !=  sections.end(); y++)
            {
              if ((*y).get_section_no() == sec_no)
              {z=distance(sections.begin(),y);
                  {cout<<"are you sure you want to do delete it?"<<endl;
                   cin>>choice;
                   if ((choice=='y')||(choice =='Y'))
                   {
                      sections.erase(sections.begin()+z);
                      cout<<"Course deleted";
                   }
                   else{ cout<<"course not deleted";
                       return;}}}}}
                  else
                  {cout<<"course doesn't exist";}
            }

void section_menu::register_student(course_menu & cm, student_menu & sm){
    
    string id;
    int  sec_no, st_ID;

    if(  cm.check_id(id)==true)
    {cout<<"Please enter the section ";
        cin>>sec_no;
      float a=  cm.get_index(id);
        if(check_sec_no(cm.get_course(a), sec_no)==true)
        { cout<<"please enter the student's ID";
              cin>>st_ID;
     if(sm.check_id(st_ID))//check the existance of a section inside of a course
       { float k= get_index(cm.get_course(a), sec_no);
            get_section(k).set_student(st_ID);
           cout<<"course registered";return;}
                else cout<<"student ID not found";
       }
          else cout<<"section dooesn't exist";
          }
    else cout<<"course doesn't exist";
}

void section_menu::unregister_student(course_menu & cm, student_menu & sm){
        string id;
        int  sec_no, st_ID;
        float z;
        auto y = sections.begin();
        auto x = (sm.get_all_students()).begin();
        cout<<"please enter the course's ID ";
        cin>>id;
        if(  cm.check_id(id)==true)
        {cout<<"Please enter the section ";
            cin>>sec_no;
            for ( ; y !=  sections.end(); y++)
            {
              if ((*y).get_section_no() == sec_no)
              {
                  z=distance(sections.begin(),y);
        auto b= sections[z].get_students();
        auto a=(find( b.begin(),b.end(),st_ID));
//    (find( b.begin(),b.end(),st_ID)!=b.end())
        float w ;
                      w= distance(b.begin(), a);
                  cout<<"please enter the student's ID";
                  cin>>st_ID;
                  for ( ; x !=  (sm.get_all_students()).end(); x++)
                  {
                    if ((*x).get_ID() == st_ID)
                    {           b.erase(b.begin()+w);
;
                        cout<<"course unregistered";}
                    else cout<<"student ID not found";
                      
                      unregister_student(cm,sm);
                  }}
              else cout<<"section dooesn't exist";
            }}
        else cout<<"course doesn't exist";
    }

void section_menu::list_all_students(course_menu & cm){
    string id;
    float z;
    int sec_no;
    auto y = sections.begin();
    cout<<"Please enter the course's string";
    cin>>id;
    if(  cm.check_id(id)==true){
            {cout<<"Please enter the section ";
            cin>>sec_no;
            for ( ; y !=  sections.end(); y++)
            {
              if ((*y).get_section_no() == sec_no)
              {z=distance(sections.begin(),y);
                  cout<<sections[z];
              }}
        }}}

void section_menu::section_menu_display(course_menu & cm,student_menu & sm, professor_menu & pm){
    while (true) {int choice;
    cout<<"what operation do you want to perform"<<endl<<endl<<"1.  create section"<<endl<<"2.  modify section"<<"3. delete section"<<endl<<"4.  register student"<<endl<<"5.  unregister student"<<endl<<"6.  list all students"<<endl<<"7.  back";
    
    cin>>choice;
    section sc;
    switch (choice){
        case 1: add_section(cm,pm);break;
            
        case 2: modify_section(cm); break;
            
        case 3:delete_section(cm);break;
            
        case 4: register_student(cm,sm);break;
            
        case 5:unregister_student(cm,sm);break;
            
        case 6:list_all_students(cm); break;
        case 7: return;
        default: return;
            
    }
    }
    
}

bool section_menu::check_sec_no(course c, int id){
    cout<<"Please enter the section no"<<endl;
        cin>>id;
    if(find( c.get_sec_no().begin(),c.get_sec_no().end(),id)!=c.get_sec_no().end())
    {
        return true;
    }

    else
        return false;
}
float section_menu::get_index(course c, int id){
   vector<int>::iterator it = find(c.get_sec_no().begin(), c.get_sec_no().end(), id);
    
    float index = std::distance(c.get_sec_no().begin(), it);
    
    return index;
}
