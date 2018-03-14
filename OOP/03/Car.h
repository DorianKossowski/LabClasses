#pragma once
#include "Vehicle.h"

// klasa opisujaca car, dzedziczy po vehicle
class Car: public Vehicle
{
 public:
 	// wywoluje konstruktor klasy bazowej z otrzymanym argumentem, przypisuje ilosc pasazerow
 	Car(const unsigned id, const int passengers);
 	// zwalnia pamiec po indeksach pasazerow
 	~Car();
 	// ustawia cene za posrednictwem metody klasy bazowej
 	void SetPrice(const unsigned price);
 	// ustawia poszczegolne id pasazerow
 	void SetPassengersIds(const int* pIds, const unsigned size);
 	// wypisuje informajce o id samochodu
 	void Drive() const;
 	// wypisuje informacje o samochodzie i pasazerach
 	void Print() const;
 	// wirtualna metoda, wywoluje Drive()
 	void Move() const;

 private:
 	const int m_passengers;
 	int* m_pIds;
};
