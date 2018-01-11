#include "Point3D.h"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const Point3D& point)
{
	return out << "(" << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << ")";
}
Point3D::Point3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{}
double Point3D::operator[] (pointUnit type) const
{
	if(type == X)
		return _x;
	if(type == Y)
		return _y;
	return _z;
}
double& Point3D::operator[] (pointUnit type)
{
	if(type == X)
		return _x;
	if(type == Y)
		return _y;
	return _z;
}