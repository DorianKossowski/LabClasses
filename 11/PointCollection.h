#pragma once

class Point3D;

//class containing collection of points
class PointCollection
{
public:
	//creating new collection
	PointCollection(int size);
	//creating new collection with content of other
	PointCollection(const PointCollection& toCopy);
	//free memory
	~PointCollection();

	//printing collection
	void Print() const;

	//overloading [] - return reference to pointer on proper point
	Point3D*& operator[] (const unsigned int index);
	
private:
	Point3D** _array;
	int _size;
};