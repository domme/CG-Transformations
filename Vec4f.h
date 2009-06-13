/*
 *  Vec4f.h
 *  Transformation
 *
 *  Created by Dominik Lazarek on 18.05.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VEC4F_H
#define VEC4F_H

class Vec4f
{
public:
	Vec4f();
	Vec4f(float _x, float _y, float _z);
	
	Vec4f operator + (Vec4f vectorB);
	Vec4f operator - (Vec4f vectorB);
	Vec4f operator += (Vec4f vectorB);
	Vec4f operator -= (Vec4f vectorB);
	Vec4f operator * (Vec4f vectorB);
	Vec4f operator * (float scalarB);
	Vec4f operator *=(Vec4f vectorB);
	Vec4f operator *=(float scalarB);
	
//	Vec4f dotProduct(Vec4f vectorB);
//	Vec4f dotProduct(float scalarB);
	
	Vec4f crossProduct(Vec4f vectorB);
	
	float getValue(int _index);
	
	void setValue(int _index, float _value);
	
	void setValues(float _x, float _y, float _z);
	
	void print(void);
	
		
private:
	float fields[4];
	
};


#endif