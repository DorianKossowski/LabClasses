#include "Angle.h"
#include <cmath>

Angle::Angle(const double value, const angleUnit unit) : _value(value), _unit(unit)
{}
Angle::Angle(const Angle& angle) : _value(angle._value), _unit(angle._unit)
{}
Angle Angle::fromRadians(const double number)
{
	Angle newAngle(number, radians);
	newAngle.toCorrect();
	return newAngle;
}
Angle Angle::fromDegrees(const double number)
{
	Angle newAngle(number, degrees);
	newAngle.toCorrect();
	return newAngle;
}
void Angle::toCorrect()
{
	double number = _value;
	double border;

	if(_unit == radians)
		border = 2 * M_PI;
	else
		border = 360;

	if(number > border)
	{
		while(number > border)
			number -= border;
	}
	else if(number < 0)
	{
		while(number < 0)
			number += border;
	}

	_value = number;
}
double Angle::toRad() const
{
	if(_unit == radians)
		return _value;
	
	return _value * M_PI / 180;
}
double Angle::toDeg() const
{
	if(_unit == degrees)
		return _value;
	
	return _value * 180 / M_PI;
}
Angle& Angle::add(const Angle& angle)
{
	double number;
	
	if(_unit == radians)
		number = angle.toRad();
	else
		number = angle.toDeg();
	_value += number;

	this->toCorrect();
	return *this;
}
Angle Angle::distance(const Angle& firstAngle, const Angle& secondAngle)
{
	const double distance1 = secondAngle.toDeg() - firstAngle.toDeg();
	const double distance2 = firstAngle.toDeg() - secondAngle.toDeg();
	double bestDistance;

	distance1 < distance2 ? bestDistance = distance1 : bestDistance = distance2;

	Angle newAngle(bestDistance, degrees);
	newAngle.toCorrect();
	return newAngle;
}
Angle::	operator double() const
{
	return this->toDeg();
}