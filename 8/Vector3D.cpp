#include "Vector3D.h"
#include "VectorTrans3D.h"

#include <iostream>

Vector3D::Vector3D(int x, int y, int z) : _x(x), _y(y), _z(z)
{}

void Vector3D::SetX(int x)
{	_x = x;
}
void Vector3D::SetY(int y)
{	_y = y;
}
void Vector3D::SetZ(int z)
{	_z = z;
}
int Vector3D::GetX() const
{	return _x;
}
int Vector3D::GetY() const
{	return _y;
}
int Vector3D::GetZ() const
{	return _z;
}

void Vector3D::Print() const
{
	std::cout << "(" << _x << ", " << _y << ", " << _z << ")" << std::endl;
}
int Vector3D::Times(const VectorTrans3D& vec) 
{
	int result = _x*vec.GetX() + _y*vec.GetY() + _z*vec.GetZ();
	return result;
}
Vector3D Vector3D::Times(const Vector3D& vec)
{
	int tempX, tempY, tempZ;
	
	tempX = _x * vec._x + _y * vec._x + _z * vec._x;
	tempY = _x * vec._y + _y * vec._y + _z * vec._y;
	tempZ = _x * vec._z + _y * vec._z + _z * vec._z;

	return Vector3D(tempX, tempY, tempZ);
}