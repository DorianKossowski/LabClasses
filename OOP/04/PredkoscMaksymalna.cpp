#include "PredkoscMaksymalna.h"


std::string operator<< (std::ostream& wyj, const PredkoscMaksymalna& obiekt)
{
	(void)wyj;
	return std::to_string(obiekt.getWart()) + "km/h";
}