#include "Main.h"

using namespace std;

void set_student(const char first_letter_name,const char first_letter_surname,const int grade,Student* name)
{
	//assign data
	name->first_name = first_letter_name;
	name->first_surname = first_letter_surname;
	name->grade = grade;
	//successor is null
	name->attached = 0;
}
void print(Student name)
{
	cout<<"Initials: "<<name.first_name<<". "<<name.first_surname<<". grade: "<<name.grade<<endl;
}
void attach_back (Student* name1,Student* name2)
{
	//create new student and assign data
	Student* toAttach = new Student;
	toAttach->first_name = name2->first_name;
	toAttach->first_surname = name2->first_surname;
	toAttach->grade = name2->grade;
	toAttach->attached = 0;

	//create temporary pointer on student to attach new student on the end of list
	Student* tempName;
	tempName = name1;
	while(tempName->attached)
	{
		tempName = tempName->attached;
	}
	tempName->attached = toAttach;
}
void print_all (Student* name)
{
	//create temporary pointer on student to print everybody
	Student* temp;
	temp = name;
	while(temp)
	{
		cout<<"Initials: "<<temp->first_name<<". "<<temp->first_surname<<". grade: "<<temp->grade<<endl;
		temp = temp->attached;
	}
}
void clear_all (Student* name)
{
	//create temporary pointer on student to remove everybody except first one
	Student* tempName;
	tempName = name->attached;
	if(tempName)
	{
		clear_all(tempName);
		tempName->attached = 0;
	}
	delete tempName;
	name->attached = 0;
}