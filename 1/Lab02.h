#ifndef LAB02_H
#define LAB02_H
#include <iostream>
#include <cstring>

//add new student to list
void AddStudent(int* numberOfStudents,char*** namesList,char*** surnamesList,int** yearsList,const char* firstName,const char* secondName,const char* surname,int year);
//print names of student
void PrintListContent(int numberOfStudents,char** list);
//print years of student
void PrintListContent(int numberOfStudents,int* list);
//print everything
void PrintListContent(int numberOfStudents,char** namesList,char** surnamesList, int* yearsList);
//free memory
void ClearStudents (int* numberOfStudents,char*** namesList,char*** surnamesList,int** yearsList);

#endif