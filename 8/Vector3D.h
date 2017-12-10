#pragma once

class VectorTrans3D;

//class containing vector 1x3
class Vector3D
{
public:
	//initialization of vector
	Vector3D(int x=0, int y=0, int z=0);
	//print vector
	void Print() const;
	//times vector with vector(3x1)
	int Times(const VectorTrans3D& vec);
	//times vector with vector(1x3)
	Vector3D Times(const Vector3D& vec);
	//setting x value
	void SetX(int x);
	//setting y value
	void SetY(int y);
	//setting z value
	void SetZ(int z);
	//getting x value
	int GetX() const;
	//getting y value
	int GetY() const;
	//getting z value
	int GetZ() const;
private:
	int _x;
	int _y;
	int _z;
};