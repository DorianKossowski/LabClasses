// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac funkcje tworzace i operaujace na ciagach. Nalezy
// utworzyc ciagi geometryczne o pierwszym wyrazie 1 i zadanym
// ilorazie. Oprocz tego nalezy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy i najmniejszy element.

// Prosze zadbac o odbre zarzadzanie pamiecia.

// Pliku lab01.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab01. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wgrac na UPEL

#include "lab02.h"

int main ()
{
  const rozmiarCiagu rozmiar = 6;
  const float iloraz1 = 2;
  
  // pierwszy element ciagu to 1
  const ciag geometryczny1 = InicjalizujCiagGeometryczny (rozmiar, iloraz1);
  Wypisz(geometryczny1, rozmiar);
  
  const float iloraz2 = 3.;
  const ciag geometryczny2 = InicjalizujCiagGeometryczny (rozmiar, iloraz2);
  Wypisz(geometryczny2, rozmiar);

  Suma(geometryczny1, rozmiar);
  
  operacja przeksztalc [] = {Suma, Iloczyn, Max, Min};
  const int ileOperacji = sizeof(przeksztalc)/sizeof(operacja);
  for (int i = 0; i < ileOperacji; ++i)
    WykonajIWypisz (przeksztalc[i], geometryczny1, rozmiar);

  UsunCiagi();
}
/* wynik dzialania programu:
(1, 2, 4, 8, 16, 32)
(1, 3, 9, 27, 81, 243)
suma: 63
iloczyn: 32768
maksimum: 32
minimum: 1
*/
