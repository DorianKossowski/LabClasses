#ifndef MAIN_H
#define MAIN_H

#include <iostream>

//struct containing data of qCPU
struct cpuStruct
{
	const char* Name;
	int NumberOfBits;
	int* qBitsTab;
	int NumberOfExperiments;
};
typedef cpuStruct TqCPU;

//create new qCPU
void qCPU_alloc(const char* name,int NqBits,TqCPU* MyQuantumCPU);
//evaluating qCPU state and saving results in tab
void Evaluate_qCPU_State(TqCPU* MyQuantumCPU,int NExp);
//printing qCPU state
void Print_qCPU_State(TqCPU MyQuantumCPU);
//free memory of qCPU tabs
void qCPU_delete(TqCPU* MyQuantumCPU);

#endif