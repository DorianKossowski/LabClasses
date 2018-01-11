#pragma once 

#include <iostream>

//class containing 3D point
class Point3D
{
public:
	enum pointUnit {X, Y, Z};

	//creating new point
	Point3D(double x, double y, double z);

	//return proper value of point
	double GetX()const {return _x;}
	double GetY()const {return _y;}
	double GetZ()const {return _z;}

	//overloading [] - return proper value of point
	double operator[] (pointUnit type) const;
	//overloading [] - return reference to proper value of point
	double& operator[] (pointUnit type);
private:
	double _x, _y, _z;					
};

//overloading << - printing Point3D object
std::ostream& operator<< (std::ostream& out, const Point3D& point);