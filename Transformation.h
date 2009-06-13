



/*
 *  Transformation.h
 *  Transformation
 *
 *  Created by Dominik Lazarek on 18.05.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Vec4f.h"
#include "Matrix4f.h"
#include <math.h>


class Transformation
	{
	private:
		Matrix4f transformationMatrix;
		Matrix4f inverseMatrix;
		
		void recalculateInverse();
		
		Vec4f rotZ(Vec4f point, float theta);
		Vec4f rotX(Vec4f point, float theta);
		Vec4f rotY(Vec4f point, float theta);
		
	public:
		Transformation();
		
		void applyTransformation(Matrix4f matrixB);
		
		void translate(float tx, float ty, float tz);
		void rotate(float rx, float ry, float rz, float theta);
		void scale(float sx, float sy, float sz);
		
		Vec4f transformPoint(Vec4f point);
		Vec4f transformNormal(Vec4f normal);
		
		
		
		void loadIdentityMatrix(void);
		
		void print();
		
	};

#endif