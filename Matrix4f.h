/*
 *  Matrix4f.h
 *  Transformation
 *
 *  Created by Dominik Lazarek on 18.05.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MATRIX4F_H
#define MATRIX4F_H

#include "Vec4f.h"

#include<GLUT/GLUT.h>


class Matrix4f
{
public:
	Matrix4f();
	Matrix4f(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4,
			 float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4);
		
	
	void setValue(int column, int row, float value);
	float getValue(int column, int row);
	

	Matrix4f operator + (Matrix4f matrixB);
	Matrix4f operator - (Matrix4f matrixB);
	Matrix4f operator * (Matrix4f matrixB);
	Matrix4f operator += (Matrix4f matrixB);
	Matrix4f operator -= (Matrix4f matrixB);
	Matrix4f operator *= (Matrix4f matrixB);
	Matrix4f operator * (float scalarB);
	Vec4f operator * (Vec4f vectorB);
	
	
	Matrix4f transpose(void);
	void loadIdentityMatrix(void);
	Matrix4f calculateInverse(void);
	
	void print(void);
	
	
private:
	
	float fields[4][4];
	
	
};



#endif
