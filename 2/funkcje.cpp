#include "lab02.h"

using namespace std;

ciag *tab;
rozmiarCiagu ilosc = 0;

ciag InicjalizujCiagGeometryczny(const rozmiarCiagu rozmiar, const float iloraz1)
{
	rozmiarCiagu pierwszyEle = 1;
	ciag NowyCiag = new float[rozmiar];
	for(int i=0; i<rozmiar; i++)
	{
		NowyCiag[i] = pierwszyEle;
		pierwszyEle *= iloraz1;
	}
	ciag *temp = new ciag[ilosc + 1];
	for(int i=0; i<ilosc; i++)
	{
		temp[i] = tab[i];
	}
	temp[ilosc] = NowyCiag;
	delete[] tab;
	tab = temp;
	ilosc++;	
	cout<< "liczba " << ilosc<<endl;
	return NowyCiag;
}
void Wypisz(const ciag geometryczny, const rozmiarCiagu rozmiar)
{
	cout<<"("<<geometryczny[0];
	for(int i=1; i< rozmiar; i++)
	{
		cout<<", "<<geometryczny[i];
	}
	cout<<")\n";
}
void WykonajIWypisz (operacja przeksztalc,const ciag geometryczny,const rozmiarCiagu rozmiar)
{
	return przeksztalc(geometryczny, rozmiar);
}
void Suma(const ciag geometryczny, const rozmiarCiagu rozmiar)
{
	float suma = 0;
	for(int i=0; i< rozmiar; i++)
	{
		suma += geometryczny[i];
	}
	cout<<"suma: "<<suma<<endl;
}
void Iloczyn(const ciag geometryczny, const rozmiarCiagu rozmiar)
{
	float iloczyn = 1;
	for(int i=0; i< rozmiar; i++)
	{
		iloczyn *= geometryczny[i];
	}
	cout<<"iloczyn: "<<iloczyn<<endl;
}
void Max(const ciag geometryczny, const rozmiarCiagu rozmiar)
{
	float max = 0;
	for(int i=0; i< rozmiar; i++)
	{
		if(max < geometryczny[i])
			max = geometryczny[i];
	}
	cout<<"maksimum: "<<max<<endl;
}
void Min(const ciag geometryczny, const rozmiarCiagu rozmiar)
{
	float min = geometryczny[0];
	for(int i=1; i< rozmiar; i++)
	{
		if(min > geometryczny[i])
			min = geometryczny[i];
	}
	cout<<"minimum: "<<min<<endl;
}
void UsunCiagi()
{
	for(int i=0; i<ilosc; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}