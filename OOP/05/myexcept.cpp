#include "myexcept.h"

void myexcept::handler(const char* info)
{
	try
	{
		throw;
	}
	catch(const numerical_exception& exc)
	{
		std::cout << "plik: " << exc.getFile() << " linia: " << exc.getLine() << " kontekst: (" << info << ") " << exc.getName() << ": "
			<< exc.what() << std::endl;
	}
	catch(const std::runtime_error& exc)
	{
		std::cout << "kontekst: (" << info << ") runtime_error:"
			<< exc.what() << std::endl;
	}
}