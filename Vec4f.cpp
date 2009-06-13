/*
 *  Vec4f.cpp
 *  Transformation
 *
 *  Created by Dominik Lazarek on 18.05.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Vec4f.h"

#include <iostream>

using namespace std;

Vec4f::Vec4f()
{
	for(int x = 0; x < 4; x++)
		this->fields[x] = 0.0f;
}

Vec4f::Vec4f(float _x, float _y, float _z)
{
	
	fields[0] = _x;
	fields[1] = _y;
	fields[2] = _z;
	fields[3] = 1.0f; //homogener Parameter! ;)
}



Vec4f Vec4f::operator +(Vec4f vectorB)
{
	Vec4f returnVector;
	
	for(int i = 0; i < 4; i++)
	{
		returnVector.setValue(i, this->getValue(i) + vectorB.getValue(i));
	}
	
	return returnVector;
}


Vec4f Vec4f::operator -(Vec4f vectorB)
{
	Vec4f returnVector;
	
	for(int i = 0; i < 4; i++)
	{
		returnVector.setValue(i, this->getValue(i) - vectorB.getValue(i));
	}
	
	return returnVector;
}



Vec4f Vec4f::operator *(Vec4f vectorB)
{
	Vec4f returnVector;
	
	for(int i = 0; i < 4; i++)
		returnVector.setValue(i, this->getValue(i) * vectorB.getValue(i));
	
	
	return returnVector;
}



Vec4f Vec4f::operator * (float scalarB)
{
	Vec4f returnVector;
	
	for(int i = 0; i < 4; i++)
		returnVector.setValue(i, this->getValue(i) * scalarB);
	
	return returnVector;
}


Vec4f Vec4f::operator+=(Vec4f vectorB)
{
	*this = *this + vectorB;
	return *this;
}


Vec4f Vec4f::operator-=(Vec4f vectorB)
{
	*this = *this - vectorB;
	return *this;
}


Vec4f Vec4f::operator *=(Vec4f vectorB)
{
	*this = *this * vectorB;
	return *this;
}

Vec4f Vec4f::operator *=(float scalarB)
{
	*this = *this * scalarB;
	return *this;
}

void Vec4f::print(void)
{
	for(int x =0; x < 4; x++)
		cout << fields[x] << endl;
}


void Vec4f::setValue(int _index, float _value)
{
	if(_index < 4 && _index >= 0)
	{
		fields[_index] = _value;
	}
}


void Vec4f::setValues(float _x, float _y, float _z)
{
	fields[0] = _x;
	fields[1] = _y;
	fields[2] = _z;
}


float Vec4f::getValue(int _index)
{
	if(_index < 4 && _index >= 0)
		return fields[_index];
	else
		return fields[3];
		
}

Vec4f Vec4f::crossProduct(Vec4f vectorB)
{
	Vec4f returnVector;
	
	//a2b3 - a3b2
	returnVector.setValue(0, (this->getValue(1)*vectorB.getValue(2) - this->getValue(2) * vectorB.getValue(2)));
	//a3b1 - a1b3
	returnVector.setValue(1, (this->getValue(2)*vectorB.getValue(0) - this->getValue(0) * vectorB.getValue(2)));
	//a1b2 - a2b1
	returnVector.setValue(2, (this->getValue(0)*vectorB.getValue(1) - this->getValue(1) * vectorB.getValue(0)));
	//Homogene Koordinate ist null, da Vektor
	returnVector.setValue(3, 0);	

	return returnVector;
}
						 
			







 