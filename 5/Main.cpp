// Nazwa pliku wykonywalnego: Simpsons

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie podanej na poczatku tego pliku. Program nalezy kompilowac
// z flagami -Wall -Wextra -pedantic -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include "Main.h"
#include "Main.h"

#include<iostream>

int main ()
{
  std::cout<<"--- MAGGIE ---\n";
  Student maggie;
  const char first_letter_name = 'M';
  const char first_letter_surname = 'S';
  const int grade = 5;
  set_student(first_letter_name, first_letter_surname, grade, &maggie);
  print(maggie);		// Initials: M. S. 	grade: 5

  std::cout<<"\n--- BART ---\n";
  Student bart;
  set_student ('B', 'S', 2, &bart);
  set_student ('B', 'S', 2, &bart);
  print (bart);			// Initials: B. S. 	grade: 2

  std::cout<<"\n--- LISA ---\n";
  Student lisa;
  set_student ('L', 'S', 6, &lisa);
  print (lisa);			// Initials: L. S. 	grade: 6

  std::cout<<"\n--- NEXT 1 ---\n";
  attach_back (&maggie, &bart);
  print_all (&maggie);		// Initials: M. S. 	grade: 5
                                // Initials: B. S. 	grade: 2


  std::cout<<"\n--- NEXT 2 ---\n";
  attach_back (&maggie, &lisa);
  print_all (&maggie);		// Initials: M. S. 	grade: 5
                                // Initials: B. S. 	grade: 2
                                // Initials: L. S. 	grade: 6


  std::cout<<"\n--- BART CHANGE ---\n";
  bart.grade = 4;
  print(bart);			// Initials: B. S. 	grade: 4

  std::cout<<"\n--- ALL  AFTER CHANGE---\n";
  print_all (&maggie);		// Initials: M. S. 	grade: 5
                                // Initials: B. S. 	grade: 2
                                // Initials: L. S. 	grade: 6


  std::cout<<"\n--- ALL AFTER CLEAR---\n";
  clear_all (&maggie);
  print_all (&maggie);		// Initials: M. S. 	grade: 5

  return 0;
}
/* wynik dzialania programu:
--- MAGGIE ---
Initials: M. S. 	grade: 5

--- BART ---
Initials: B. S. 	grade: 2

--- LISA ---
Initials: L. S. 	grade: 6

--- NEXT 1 ---
Initials: M. S. 	grade: 5
Initials: B. S. 	grade: 2

--- NEXT 2 ---
Initials: M. S. 	grade: 5
Initials: B. S. 	grade: 2
Initials: L. S. 	grade: 6

--- BART CHANGE ---
Initials: B. S. 	grade: 4

--- ALL  AFTER CHANGE---
Initials: M. S. 	grade: 5
Initials: B. S. 	grade: 2
Initials: L. S. 	grade: 6

--- ALL AFTER CLEAR---
Initials: M. S. 	grade: 5
*/
