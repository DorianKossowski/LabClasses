#pragma once

//class containing angle <0,2PI>
class Angle
{
public:
	//copy values to new object
	Angle(const Angle& angle);
	//static function converting double into radians
	static Angle fromRadians(const double number);
	//static function converting double into degrees
	static Angle fromDegrees(const double number);
	//return radians
	double toRad() const;
	//return degrees
	double toDeg() const;
	//adding two objects
	Angle& add(const Angle& angle);
	//return object which contains the smallest difference betwen two angles
	static Angle distance(const Angle& firstAngle, const Angle& secondAngle);
	//convert angle into double
	operator double() const;
private:
	//type of angle's unit
	enum angleUnit {radians, degrees};

	//private constructor, create new angle
	Angle(const double value, const angleUnit unit);
	//care about value from <0,2PI>
	void toCorrect();

	double _value;
	angleUnit _unit;
};