#include "Matrix3.h"
#include "VectorTrans3D.h"
#include "Vector3D.h"

#include <iostream>

Matrix3::Matrix3(Vector3D* matrix) : _matrix(matrix), _dimension(3) 
{}

Matrix3::~Matrix3()
{
	delete[] _matrix;
}

void Matrix3::Print() const
{
	for(int row=0; row<_dimension; row++)
	{
		_matrix[row].Print();
	}
}

VectorTrans3D Matrix3::Times(const VectorTrans3D& vec)
{
	VectorTrans3D tempVector;
	int result = 0;

	for(int row=0; row<_dimension; row++)
	{
		result = _matrix[row].Times(vec);
		if(row == 0)
			tempVector.SetX(result);
		else if(row == 1)
			tempVector.SetY(result);
		else
			tempVector.SetZ(result);

		result = 0;
	}

	return tempVector;
}

Matrix3 Matrix3::Times(const Matrix3& secondMatrix)
{
	Vector3D* tempArray = new Vector3D[_dimension];
	Matrix3 tempMatrix(tempArray);
	VectorTrans3D tempVector;
	int row;

	for(row=0; row<_dimension; row++)
	{
		tempVector.SetX(secondMatrix._matrix[0].GetX());
		tempVector.SetY(secondMatrix._matrix[1].GetX());
		tempVector.SetZ(secondMatrix._matrix[2].GetX());
		tempMatrix._matrix[row].SetX(_matrix[row].Times(tempVector));
	}

	for(row=0; row<_dimension; row++)
	{
		tempVector.SetX(secondMatrix._matrix[0].GetY());
		tempVector.SetY(secondMatrix._matrix[1].GetY());
		tempVector.SetZ(secondMatrix._matrix[2].GetY());
		tempMatrix._matrix[row].SetY(_matrix[row].Times(tempVector));
	}

	for(row=0; row<_dimension; row++)
	{
		tempVector.SetX(secondMatrix._matrix[0].GetZ());
		tempVector.SetY(secondMatrix._matrix[1].GetZ());
		tempVector.SetZ(secondMatrix._matrix[2].GetZ());
		tempMatrix._matrix[row].SetZ(_matrix[row].Times(tempVector));
	}

	return tempMatrix;
}