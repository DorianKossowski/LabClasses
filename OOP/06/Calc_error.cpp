#include "Calc_error.h"

Calc_error::Calc_error(std::runtime_error* err, const std::string& info, const std::string& file, int line): std::runtime_error(info), m_err(err), m_file(file), m_line(line)
{}

void Calc_error::print() const
{
	std::cout << what() << ", [plik = " << m_file << ", linia = " << m_line << "]" << std::endl;
}
void Calc_error::handler()
{
	try
	{
		throw;
	}
	catch(std::runtime_error* err)
	{
		std::cout << " Zlapano wyjatek:" << std::endl;
		while(err)
		{
			Calc_error* presentErr = dynamic_cast<Calc_error*>(err);
			if(presentErr)
			{
				std::cout << "-- z powodu: ";
				presentErr->print();
				err = presentErr->m_err;
				delete presentErr;
			}
			else
			{
				std::cout << "-- z powodu: " << err->what() << std::endl;
				delete err;
				err = 0;
			}
		}
	}

}