#include <iostream>
#include "Menu.h"
using namespace std;
int main(int argc, const char * argv[]) {
    AUC_MENU auc;
    course_menu cm;
    student_menu sm;
    professor_menu pm;
    section_menu secm;
    auc.auc_menu_display(cm, sm, pm, secm);
    return 0;
}
