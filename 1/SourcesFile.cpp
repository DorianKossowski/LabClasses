#include "Lab02.h"
using namespace std;

void AddStudent(int* numberOfStudents,char*** namesList,char*** surnamesList,int** yearsList,const char* firstName,const char* secondName,const char* surname,int year)
{
	//create new bigger arrays
	int* tempYearsList = new int[*numberOfStudents+1];
	char** tempNamesList = new char*[*numberOfStudents+1];
	char** tempSurnamesList = new char*[*numberOfStudents+1];

	//make space for both names
	size_t tempSizeOfBoth = strlen(firstName);	
	tempSizeOfBoth += 1; //place for space
	tempSizeOfBoth += strlen(secondName);
	tempSizeOfBoth += 1; //place for 'end of cstring'
	size_t tempSizeOfName = strlen(surname) + 1;

	//create temporary arrays for names
	char* bothNames = new char[tempSizeOfBoth];
	char* tempSurname = new char[tempSizeOfName];
	memset(bothNames, 0, tempSizeOfBoth);
	memset(tempSurname, 0, tempSizeOfName);

	//copy original names to temporary
	strcat(bothNames, firstName);
	strcat(bothNames, " ");
	strcat(bothNames, secondName);
	strcat(bothNames, "\0");
	strcat(tempSurname, surname);

	//copy content to new bigger arrays
	for(int i=0; i<*numberOfStudents; i++)
	{
		tempYearsList[i] = (*yearsList)[i];
		tempSurnamesList[i] = (*surnamesList)[i];
		tempNamesList[i] = (*namesList)[i];
	}

	//assign new content
	tempYearsList[*numberOfStudents] = year;
	tempSurnamesList[*numberOfStudents] = tempSurname;
	tempNamesList[*numberOfStudents] = bothNames;

	//delete previous arrays
	delete[] *yearsList;
	delete[] *surnamesList;
	delete[] *namesList;

	//allocate arrays again and make them point to new data
	*yearsList = tempYearsList;
	*surnamesList = tempSurnamesList;
	*namesList = tempNamesList;

	//increase number of students
	(*numberOfStudents)++;
}
void PrintListContent(int numberOfStudents,char** list)
{
	for(int i=0; i<numberOfStudents; i++)
	{
		cout<< list[i] << endl;
	}
}
void PrintListContent(int numberOfStudents,int* list)
{
	for(int i=0; i<numberOfStudents; i++)
	{
		cout<< list[i] << endl;
	}
}
void PrintListContent(int numberOfStudents,char** namesList,char** surnamesList, int* yearsList)
{
	for(int i=0; i<numberOfStudents; i++)
	{
		cout<< surnamesList[i] << ", " << namesList[i] << " - year " << yearsList[i] << endl;
	}
}
void ClearStudents (int* numberOfStudents,char*** namesList,char*** surnamesList,int** yearsList)
{
	for(int i=0; i<*numberOfStudents; i++)
	{
		delete[] (*namesList)[i];
		delete[] (*surnamesList)[i];
	}
	delete[] *namesList;
	delete[] *surnamesList;
	delete[] *yearsList;
	*numberOfStudents = 0;
}