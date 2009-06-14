/*
 *  Matrix4f.cpp
 *  Transformation
 *
 *  Created by Dominik Lazarek on 18.05.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
 
#include "Matrix4f.h"
#include "Matrix.cpp"
 
#include <iostream>
using namespace std;
 

Matrix4f::Matrix4f()
{
	for(int x = 0; x < 4; x++)
		for(int y = 0; y < 4; y++)
			if(x == y)
				fields[x][y] = 1;
			else 
				fields[x][y] = 0;
}
 
 
 
Matrix4f::Matrix4f(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4,
     float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4)
{
  fields[0][0] = a1;
  fields[1][0] = a2;
  fields[2][0] = a3;
  fields[3][0] = a4;
  fields[0][1] = b1;
  fields[1][1] = b2;
  fields[2][1] = b3;
  fields[3][1] = b4;
  fields[0][2] = c1;
  fields[1][2] = c2;
  fields[2][2] = c3;
  fields[3][2] = c4;
  fields[0][3] = d1;
  fields[1][3] = d2;
  fields[2][3] = d3;
  fields[3][3] = d4;
}
 
 
 
Matrix4f Matrix4f::operator + (Matrix4f matrixB)
{
  Matrix4f returnMatrix;
  
  for(int x = 0; x < 4; x++)
    for(int y = 0; y < 4; y++)
      returnMatrix.setValue(x, y, fields[x][y] + matrixB.getValue(x, y));
    
  return returnMatrix;
}
 
 
 
Matrix4f Matrix4f::operator - (Matrix4f matrixB)
{
  Matrix4f returnMatrix;
  
  for(int x = 0; x < 4; x++)
    for(int y = 0; y < 4; y++)
      returnMatrix.setValue(x, y, fields[x][y] - matrixB.getValue(x, y));
    
  return returnMatrix;
}
 
 
 
Matrix4f Matrix4f::operator += (Matrix4f matrixB)
{
  *this = *this + matrixB;
  
  return *this;
}
 
Matrix4f Matrix4f::operator -= (Matrix4f matrixB)
{
  *this = *this - matrixB;
  
  return *this;
}
 
 
Vec4f Matrix4f::operator *(Vec4f vectorB)
{
  Vec4f returnVector;
  float newValue = 0;
  
  
  for(int mY = 0; mY < 4; mY++)
  {
    newValue = 0;
    for(int mX = 0; mX < 4; mX++)
    {
      newValue += fields[mX][mY] * vectorB.getValue(mX);
    }
    
    returnVector.setValue(mY, newValue);
  }
  
  return returnVector;
}
 
 
Matrix4f Matrix4f::operator * (float scalarB)
{
  
  Matrix4f returnMatrix;
  
  for(int x = 0; x < 4; x++)
    for(int y = 0; y = 4; y++)
        returnMatrix.setValue(x, y, fields[x][y] * scalarB);
  
  return returnMatrix;
}
 
 
 
Matrix4f Matrix4f::operator *= (Matrix4f matrixB)
{
  *this = (*this * matrixB);
  
  return *this;
}
 
 
Matrix4f Matrix4f::operator *(Matrix4f matrixB)
{
  Matrix4f returnMatrix;
  float newValue = 0;
  
  
  for(int nX = 0; nX < 4; nX++) //neue Matrix - Spalte
  { 
    for(int nY = 0; nY < 4; nY++)//neue Matrix - Zeile
    {
      newValue = 0;
      for(int y = 0; y < 4; y++)
      {
        newValue += fields[y][nY] * matrixB.getValue(nX,y);
      }
      
      returnMatrix.setValue(nX, nY, newValue);
    }
  }
              
               
 return returnMatrix;
  
}//end method
 
 
float Matrix4f::getValue(int column, int row)
{
  if(column < 4 && column >= 0 && row < 4 && row >= 0)
    return this->fields[column][row];
  
  else 
    return 0.0f;
}
 
void Matrix4f::setValue(int column, int row, float value)
{
  if(column < 4 && column >= 0 && row < 4 && row >= 0)
    this->fields[column][row] = value;
    
}
 
Matrix4f Matrix4f::transpose(void)
{
  Matrix4f transposedMatrix = *this;
  
  for(int x = 0; x < 4; x++)
    for(int y = 0; y < 4; y++)
      transposedMatrix.setValue(x,y,  this->fields[y][x]);
  
 
  
  return transposedMatrix;
}
 
 
void Matrix4f::print(void)
{
    
  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      cout << this->fields[x][y] << '\t' << '\t' << '\t';      
    }
    cout << endl;
    cout << endl;
 
  }
  
  cout << endl << endl << endl << endl;
}
