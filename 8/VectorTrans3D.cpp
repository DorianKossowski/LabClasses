#include "VectorTrans3D.h"
#include "Vector3D.h"

#include <iostream>

VectorTrans3D::VectorTrans3D(int x, int y, int z) : _x(x), _y(y), _z(z), _dimension(3)
{}

void VectorTrans3D::SetX(int x)
{	_x = x;
}
void VectorTrans3D::SetY(int y)
{	_y = y;
}
void VectorTrans3D::SetZ(int z)
{	_z = z;
}
int VectorTrans3D::GetX() const
{	return _x;
}
int VectorTrans3D::GetY() const
{	return _y;
}
int VectorTrans3D::GetZ() const
{	return _z;
}

void VectorTrans3D::Print() const
{
	std::cout << _x << "\n" << _y << "\n" << _z << std::endl;
}

Vector3D* VectorTrans3D::Times(const Vector3D& vec)
{
	Vector3D* tempMatrix = new Vector3D[_dimension];

	int tempX, tempY, tempZ;

	tempX = _x * vec.GetX();
	tempY = _x * vec.GetY();
	tempZ = _x * vec.GetZ();
	tempMatrix[0] = Vector3D (tempX, tempY, tempZ);

	tempX = _y * vec.GetX();
	tempY = _y * vec.GetY();
	tempZ = _y * vec.GetZ();
	tempMatrix[1] = Vector3D (tempX, tempY, tempZ);

	tempX = _z * vec.GetX();
	tempY = _z * vec.GetY();
	tempZ = _z * vec.GetZ();
	tempMatrix[2] = Vector3D (tempX, tempY, tempZ);

	return tempMatrix;
}