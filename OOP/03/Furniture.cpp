#include "Furniture.h"

Furniture::Furniture(const unsigned id): Product::Product(id)
{}
void Furniture::SetPrice(const unsigned price)
{
	Product::SetPrice(price);
}
void Furniture::Sit() const
{
	std::cout << "You sit down on a chair. Nothing happens." << std::endl;
}
void Furniture::Print() const
{
	std::cout << "This is chair with ID=" << Product::Id() << std::endl;
}

