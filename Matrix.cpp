/*
 *  Matrix.cpp
 *  Transformation
 *
 *  Created by Dominik Lazarek on 14.06.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MATRIX_WRAPPER
#define MATRIX_WRAPPER

#include "Matrix.cpp"
#include "Matrix4f.h"
#include "Vec4f.h"

namespace Matrix
{

static Matrix4f identity(void)
{
	Matrix4f identityMatrix;
	
	for(int x = 0; x < 4; x++)
		for(int y = 0; y < 4; y++)
			if(x == y)
				identityMatrix.setValue(x, y, 1.0f);
			else
				identityMatrix.setValue(x, y, 0.0f);
	
	return identityMatrix;
}



static Matrix4f zero(void)
{
	Matrix4f zeroMatrix;
	
	for(int x = 0; x < 4; x++)
		for(int y = 0; y < 4; y++)
			zeroMatrix.setValue(x, y, 0.0f);
	
	return zeroMatrix;
}



static Matrix4f calculateInverse(Matrix4f matrixB)
{
	Matrix4f thisMatrix = matrixB;
	Matrix4f inverseMatrix;
	inverseMatrix = identity();
		
	for(int y = 1; y < 4; y++)
	{
		//iterate the upper left triangle 
		for(int x = 0; x < y; x++)
		{
			
			float factor = thisMatrix.getValue(x, y) / thisMatrix.getValue(x, x);
			
			//iterate the line and calculate
			for(int lineX = 0; lineX < 4; lineX++)
			{
				thisMatrix.setValue(lineX, y, thisMatrix.getValue(lineX, y) 
									- (thisMatrix.getValue(lineX,x) * factor));
				
				inverseMatrix.setValue(lineX, y, inverseMatrix.getValue(lineX, y)
									   - (inverseMatrix.getValue(lineX, x) * factor));
				
			}//end for line
		}//end forX
	}//end forY
	
	//no
	for(int y = 3; y > -1; y--)
	{
		//im Dreieck laufen 
		for(int x = 3; x > y; x--)
		{
			float factor = thisMatrix.getValue(x, y) / thisMatrix.getValue(x, x);
			
			//Zeile durchlaufen und werte ausrechnen
			for(int lineX = 0; lineX < 4; lineX++)
			{
				thisMatrix.setValue(lineX, y, thisMatrix.getValue(lineX, y) 
									- (thisMatrix.getValue(lineX,x) * factor));
				
				inverseMatrix.setValue(lineX, y, inverseMatrix.getValue(lineX, y)
									   - (inverseMatrix.getValue(lineX, x) * factor));
				
			}//end for line
		}//end forX
	}//end forY
	
	
	//Jetzt noch jede zeile durchlaufen und auf 1 normalisieren
	
	for(int x = 0; x < 4; x++)
	{
		for(int y = 0; y < 4; y++)
		{
			if(x == y)
			{
				float factor = thisMatrix.getValue(x, y);
				
				if(factor != 0)
					for(int lineX = 0; lineX < 4; lineX++)
						inverseMatrix.setValue(lineX, y, inverseMatrix.getValue(lineX, y) / factor);
			}
		}
		
	}
	
	
	return inverseMatrix;  
	
}//end method
	
}

#endif



