#include "Main.h"
int NEXPERIMENTS;

using namespace std;

void qCPU_alloc(const char* Name,int NqBits,TqCPU* MyQuantumCPU)
{
	//read sizeof name in the most basic way...
	int size = 0, i=0;
	while(Name[i])
	{
		size++;
		i++;
	}
	size++; //for "\0"

	//create tab for qCPU name
	char* qCpuName = new char[size];
	for(i=0; i<size; i++)
		qCpuName[i] = Name[i];

	//create tab for results
	int* tab = new int[NqBits];

	//assign new data
	MyQuantumCPU->Name = qCpuName;
	MyQuantumCPU->NumberOfBits = NqBits;
	MyQuantumCPU->qBitsTab = tab;
	MyQuantumCPU->NumberOfExperiments = 0;
}
void Evaluate_qCPU_State(TqCPU* MyQuantumCPU,int NExp)
{
	//assign number of experiments
	MyQuantumCPU->NumberOfExperiments = NExp;

	//main part of program - evaluating
	for(int i=0; i<MyQuantumCPU->NumberOfBits; i++)
	{
		int Counter = 0;
		int TempTab[2] = {0};
		while(Counter<NExp)
		{
			if(rand() % 2)
				TempTab[1]++;
			else
				TempTab[0]++;
			Counter++;
		}
		if(TempTab[0] > TempTab[1])
			MyQuantumCPU->qBitsTab[i] = 0;
		else
			MyQuantumCPU->qBitsTab[i] = 1;
	}
}
void Print_qCPU_State(TqCPU MyQuantumCPU)
{
	cout<<MyQuantumCPU.Name<<" CPU word ("<<MyQuantumCPU.NumberOfExperiments<<" experiments) :\t";
	for(int i=0; i<MyQuantumCPU.NumberOfBits; i++)
	{
		if(MyQuantumCPU.qBitsTab[i] == 0)
			cout<<" down ";
		else
			cout<<" up";
	}
	cout<<""<<endl;
}
void qCPU_delete(TqCPU* MyQuantumCPU)
{
	delete[] MyQuantumCPU->Name;
	delete[] MyQuantumCPU->qBitsTab;
}