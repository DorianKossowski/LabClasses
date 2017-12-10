#pragma once

class VectorTrans3D;
class Vector3D;

//class containing matrix 3x3
class Matrix3
{
public:
	//initialization of matrix
	Matrix3(Vector3D* matrix);
	//free memory
	~Matrix3();
	//print matrix
	void Print() const;
	//times matrix with vector
	VectorTrans3D Times(const VectorTrans3D& vec);
	//times matrix with matrix
	Matrix3 Times(const Matrix3& vec);

private:
	Vector3D* _matrix;
	int _dimension;
};