

/*
 *  Transformation.cpp
 *  Transformation
 *
 *  Created by Dominik Lazarek on 18.05.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
 
#include "Transformation.h"
#include "Matrix.cpp"
 
 
Transformation::Transformation()
{
	this->transformationMatrix = Matrix::identity();
  this->inverseMatrix = transformationMatrix;
}
 
 
 
Vec4f Transformation::transformPoint(Vec4f point)
{
  return ( this->transformationMatrix * point);
}
 
 
 
 
 
void Transformation::translate(float tx, float ty, float tz)
{
  Matrix4f translationMatrix;
  this->transformationMatrix = Matrix::identity();
  translationMatrix.setValue(3, 0, tx);
  translationMatrix.setValue(3, 1, ty);
  translationMatrix.setValue(3, 2, tz);
  
  this->transformationMatrix *= translationMatrix;
}
 
 
//this method will multiply the transformation matrix with composite transformations
//which transformes any given rotation axis (ry, ry, rz) into a coordinate axis, rotates and
//then reverses the composite transformations
void Transformation::rotate(float rx, float ry, float rz, float theta)
{
    throw "not yet implemented!";
}
 
 
Vec4f Transformation::rotZ(Vec4f point, float theta)
{
  Vec4f rotatedPoint;
 
  Matrix4f rotationMatrix;
	rotationMatrix = Matrix::identity();
  
  rotationMatrix.setValue(0, 0, (float)cos(theta));
  rotationMatrix.setValue(1, 0, (float)-sin(theta));
  rotationMatrix.setValue(0, 1, (float)sin(theta));
  rotationMatrix.setValue(1, 1, (float)cos(theta));
  
  rotatedPoint = rotationMatrix * point;
  
  return rotatedPoint;
    
}
 
Vec4f Transformation::rotY(Vec4f point, float theta)
{
  Vec4f rotatedPoint;
  
  Matrix4f rotationMatrix;
  rotationMatrix = Matrix::identity();
  
  rotationMatrix.setValue(0, 0, (float)cos(theta));
  rotationMatrix.setValue(2, 0, (float)sin(theta));
  rotationMatrix.setValue(0, 2, (float)-sin(theta));
  rotationMatrix.setValue(2, 2, (float)cos(theta));
  
  rotatedPoint = rotationMatrix * point;
  
  return rotatedPoint;
  
}
 
 
Vec4f Transformation::rotX(Vec4f point, float theta)
{
  Vec4f rotatedPoint;
  
  Matrix4f rotationMatrix;
  rotationMatrix = Matrix::identity();
  
  rotationMatrix.setValue(1, 1, (float)cos(theta));
  rotationMatrix.setValue(2, 1, (float)-sin(theta));
  rotationMatrix.setValue(1, 2, (float)sin(theta));
  rotationMatrix.setValue(2, 2, (float)cos(theta));
  
  rotatedPoint = rotationMatrix * point;
  
  return rotatedPoint;
  
}
 
 
 
void Transformation::scale(float sx, float sy, float sz)
{
  Matrix4f scaleMatrix;
	scaleMatrix = Matrix::identity();
  
  scaleMatrix.setValue(0, 0, sx);
  scaleMatrix.setValue(1, 1, sy);
  scaleMatrix.setValue(2, 2, sz);
  
  this->transformationMatrix *= scaleMatrix;
}
 
void Transformation::print()
{
  this->transformationMatrix.print();
}

