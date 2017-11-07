#ifndef LAB02_H
#define LAB02_H

#include <iostream>

//zmiana nazwy typow 
typedef int rozmiarCiagu;
typedef float* ciag;
typedef void(*operacja)(const ciag, const rozmiarCiagu);

//stworzenie ciagu geometrycznego o podanym rozmiarze i ilorazie
ciag InicjalizujCiagGeometryczny(const rozmiarCiagu rozmiar, const float iloraz1);
//wypisanie ciagu geometrycznego o podanym rozmiarze
void Wypisz(const ciag geometryczny, const rozmiarCiagu rozmiar);
//wypisanie sumy el ciagu
void Suma(const ciag geometryczny, const rozmiarCiagu rozmiar);
//zwraca wybrana operacje
void WykonajIWypisz (operacja przeksztalc,const ciag geometryczny,const rozmiarCiagu rozmiar);
//wypisanie iloczynu el. ciagu
void Iloczyn(const ciag geometryczny, const rozmiarCiagu rozmiar);
//wypisanie max el. ciagu
void Max(const ciag geometryczny, const rozmiarCiagu rozmiar);
//wypisanie min el. ciagu
void Min(const ciag geometryczny, const rozmiarCiagu rozmiar);
//zwolnienie pamieci
void UsunCiagi();
#endif