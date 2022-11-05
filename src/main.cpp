#include <bits/stdc++.h>
#include "../headers/student.h"
#include "../headers/ttm.h"
#include "../headers/slot.h"
#include "../headers/uc_class.h"
#include "../headers/class_schedule.h"

#define students_classes "../schedule/students_classes.csv"
#define classes "../schedule/classes.csv"
#define classes_per_uc "../schedule/classes_per_uc.csv"
using namespace std;

/*void menu ()
{
    int option;

    cout << "Selecione a opcao: " << endl;
    cout << "[1]: Ocupacao de turmas/ano/UC" << endl;
    cout << "[2]: Horario de determinado estudante" << endl;
    cout << "[3]: Estudantes em determinada turma/UC/ano" << endl;
    cout << "[4]: Estudantes com mais de n" << endl;

    cin >> option;

    switch (option) {
        case 1:
            cout << "Funcao 1";
            break;
        case 2:
            int num;
            cout << "Numero do estudante, etc. :";
            cin >> num;
            cout << "Funcao 2";
            break;
        case 3:
            cout << "Funcao 3";
            break;
        case 4:
            cout << "Funcao 4";
            break;
    }
}*/

int main() {

    TTM manage;
    manage.buildStudents(students_classes);
    manage.buildUCClasses(classes_per_uc);
    //manage.vsize();
    //manage.print_students_with_more_than_n_ucs(6);
    /*Student x = manage.getStudent("Abilio", "202040617");
    x.getSchedule();
    x.showSchedule();*/
    //manage.studentsInUC("L.EIC002", "name", '-');
    //cout << "----------------------" << endl;
    //manage.vsize();
    Student* tmp = manage.getStudent("Abilio", "202040617");
    UCClass ctemp("L.EIC011", "2LEIC10");
    UCClass ttemp("L.EIC011", "2LEIC13");
    //tmp->getSchedule();
    tmp->showSchedule();
    manage.changeClass(*tmp, ctemp, ttemp);
    tmp->showAllClasses();
    tmp->showSchedule();
    /*
    manage.removeClass(*tmp, ctemp);
    Student* x = manage.getStudent("Abilio", "202040617");
    x->showAllClasses();
    cout << "______________________________" << endl;
    manage.addClass(*tmp, ctemp);
    cout << "bungus" << endl;
    tmp->showAllClasses();
    tmp->showSchedule();
    //tmp.getSchedule();
    //tmp.showSchedule();
    // manage.studentsInClass("1LEIC03");
    // manage.studentsInYear('1');*/
}

/*
gestorHor h;
	h.lerficheiros();
	h.guardarpedidos();
	h.processarpedidos();
	h.listagens(); //usar ordernaçao e pesquisa
    */