#include "Car.h"

Car::Car(const unsigned id, const int passengers): Vehicle::Vehicle(id), m_passengers(passengers), m_pIds(0)
{}
Car::~Car()
{
	delete[] m_pIds;
}
void Car::SetPrice(const unsigned price)
{
	std::cout << "This car will be: " << price << std::endl;
	Product::SetPrice(price);
}
void Car::SetPassengersIds(const int* pIds, const unsigned size)
{
	if(m_pIds)
		delete[] m_pIds;
	
	m_pIds = new int[size];

	for(unsigned i=0; i<size; i++)
		m_pIds[i] = pIds[i];
}
void Car::Drive() const
{
	std::cout << "Driving the car with ID=" << Product::Id() << std::endl;
}
void Car::Print() const
{
	std::cout << "Car with id=" << Product::Id() << " has " << m_passengers << " passengers with following Ids: ";
	for(unsigned i=0; i<m_passengers-1; i++)
		std::cout << m_pIds[i] << ", "; 
	std::cout << m_pIds[m_passengers-1] << ". Max speed of the car is " << Vehicle::GetMaxSpeed() << std::endl;

}
void Car::Move() const
{
	this->Drive();
}
