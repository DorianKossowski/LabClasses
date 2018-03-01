#include "SlopeFit.h"

using namespace std;

FitResult::FitResult(const string& name)
{
	_name = name;

	if(_name == "slope fit")
		_numberParams = 1;
	else 
		_numberParams = 2;

	_pNames[0] = 'a';
	_pNames[1] = 'b';

	_pValues[0] = 0;
	_pValues[1] = 0;
}
string FitResult::expression() const
{
	if(_name == "slope fit")
		return "y = a * x";
	
	return "y = a * x + b";
}
unsigned FitResult::nParams() const
{
	return _numberParams;
}
char FitResult::parameterName(const unsigned index) const
{
	return _pNames[index];
}
float FitResult::parameterValue(const unsigned index) const
{
	return _pValues[index];
}

//###############################################################################//

Fit::Fit(const string& name) : FitResult::FitResult(name)
{
	_counter = 0;
    _xxsum = 0;
    _xysum = 0;
    _xsum = 0;
	_ysum = 0;
}
void Fit::print() const
{
	cout << "This is " << _name << endl;
}
void Fit::appendPoint(const float x, const float y)
{
	_counter++;
	_xysum += x*y;
	_xxsum += x*x;
	_xsum += x;
	_ysum += y;
}
void Fit::appendPoint(const float x, const float y) const
{
	cout << "Cannot add point (" << x << ", " << y << "), to const object." << endl;
}
Fit& Fit::result()
{
	if (_name == "slope fit")
	{
		_pValues[0] = _xysum / _xxsum;
	}
	else if (_name == "line fit")
	{
		_pValues[0] = (_xysum - _xsum * _ysum / _counter) / (_xxsum - _xsum * _xsum / _counter);
		_pValues[1] = (_ysum - _pValues[0] * _xsum) / _counter;
	}

	return *this;
}

//###############################################################################//

SlopeFit::SlopeFit(string name) : Fit::Fit(name)
{}
