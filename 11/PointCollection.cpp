#include "PointCollection.h"
#include "Point3D.h"

PointCollection::PointCollection(int size) : _size(size)
{
	_array = new Point3D*[_size];
}
PointCollection::PointCollection(const PointCollection& toCopy) : _size(toCopy._size)
{
	_array = new Point3D*[_size];
	for(int i=0; i<_size; i++)
	{
		const double x = (toCopy._array[i])->GetX();
		const double y = (toCopy._array[i])->GetY();
		const double z = (toCopy._array[i])->GetZ();

		_array[i] = new Point3D(x,y,z); 
	}
}
PointCollection::~PointCollection()
{
	for(int i=0; i<_size; i++)
	{
		delete _array[i];
	}
	delete[] _array;
}
void PointCollection::Print() const
{
	for(int i=0; i<_size; i++)
	{
		std::cout << *_array[i] << std::endl;
	}
}
Point3D*& PointCollection::operator[] (const unsigned int index)
{
	return _array[index];
}
