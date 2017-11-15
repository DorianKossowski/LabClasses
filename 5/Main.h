#ifndef MAIN_H
#define MAIN_H

#include <iostream>

//struct containing parameters of student
struct Student
{
	char first_name;
	char first_surname;
	int grade;
	Student* attached;
};

//assign data to student
void set_student(const char first_letter_name,const char first_letter_surname,const int grade,Student* name);
//print student's data
void print(Student name);
//add student to list
void attach_back (Student* name1,Student* name2);
//print all student in list
void print_all (Student* name);
//clear students from list except first
void clear_all (Student* name);

#endif