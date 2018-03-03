#include "PVec.h"

void IntWrapper::print(std::ostream& out) const
{
	out << _value << " ";
}
void FloatWrapper::print(std::ostream& out) const
{
	out << _value << " ";
}
void StringWrapper::print(std::ostream& out) const
{
	out << _text << " ";
}

//###########################################################//

PVec::~PVec()
{
	for(unsigned i=0; i<_size; i++)
	{
		delete _vec[i];
	}
	delete[] _vec;
}
void PVec::adding(Wrapper* new_object)
{
	Wrapper** temp = _vec;

	_vec = new Wrapper*[_size + 1];

	for(unsigned i=0; i<_size; i++)
		_vec[i] = temp[i];

	_vec[_size++] = new_object;

	if(temp)
		delete[] temp;
}
PVec& PVec::push_back(Wrapper* new_object)
{
	this->adding(new_object);

	return *this;
}
void PVec::operator<< (Wrapper* new_object)
{
	this->adding(new_object);
}
const Wrapper& PVec::operator[] (const unsigned index) const
{
	return *(_vec[index]);
}

//###########################################################//

std::ostream& operator<< (std::ostream& out, const PVec& vec)
{
	for(unsigned i=0; i<vec._size; i++)
	{
		vec._vec[i]->print(out);
	}

	return out;
}