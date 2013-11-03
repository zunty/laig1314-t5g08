#include "Primitives.h"

Rectangle::Rectangle( float x1, float y1, float x2, float y2 )
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

float Rectangle::getX1()
{
	return x1;
}

float Rectangle::getY1()
{
	return y1;
}

float Rectangle::getX2()
{
	return x2;	
}

float Rectangle::getY2()
{
	return y2;
}

void Rectangle::draw()
{
	glBegin(GL_QUADS);	

	glVertex3d(x1,y2,0);	
	//glTexCoord3f(x2,0,0);

	glVertex3d(x1,y1,0);
	//glTexCoord3f(x2,0,0);

	glVertex3d(x2,y1,0);
	glTexCoord3f(x1,0,0);

	glVertex3d(x2,y2,0);
	//glTexCoord3f(x1,0,0);	


	glEnd();
}

void Rectangle::print()
{
	cout << "Rectangle: " << endl << endl;

	cout << "P1: " << x1 << ", " << y1 << endl;
	cout << "P2: " << x2 << ", " << y2 << endl;
}

Triangle::Triangle( float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3 )
{
	this->x1 = x1;
	this->y1 = y1;
	this->z1 = z1;
	this->x2 = x2;
	this->y2 = y2;
	this->z2 = z2;
	this->x3 = x3;
	this->y3 = y3;
	this->z3 = z3;
}

float Triangle::getX1()
{
   return x1;
}

float Triangle::getY1()
{
   return y1;
}

float Triangle::getZ1()
{
   return z1;
}

float Triangle::getX2()
{
		return x2;
}

float Triangle::getY2()
{
   return y2;
}

float Triangle::getZ2()
{
   return z2;
}

float Triangle::getx3()
{
   return x3;
}

float Triangle::getY3()
{
   return y3;
}

float Triangle::getZ3()
{
   return z3;
}

void Triangle::draw()
{

}

void Triangle::print()
{
   cout << "Triangle: " << endl << endl;

   cout << "P1: " << x1 << ", " << y1 << ", " << z1 << endl;
   cout << "P2: " << x2 << ", " << y2 << ", " << z2 << endl;
   cout << "P3: " << x3 << ", " << y3 << ", " << z3 << endl;
}

Cylinder::Cylinder( float base, float top, float height, int slices, int stacks )
{
	this->base = base;
	this->top = top;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
}

float Cylinder::getBase()
{
  return base;
}

float Cylinder::getTop()
{
   return top;
}

float Cylinder::getHeight()
{
	return height;
}

int Cylinder::getSlices()
{
	return slices;
}

int Cylinder::getStacks()
{
   return stacks;
}

void Cylinder::draw()
{
	GLUquadric* qObj = gluNewQuadric();
	gluQuadricTexture(qObj, GLU_TRUE);
	gluCylinder(qObj, base, top, height, slices, stacks);
}

void Cylinder::print()
{
   cout << "Cylinder: " << endl << endl;

   cout << "Base: " << base << endl;
   cout << "Top: " << top << endl;
   cout << "Height: " << height << endl;
   cout << "Slices: " << slices << endl;
   cout << "Stacks: " << stacks << endl << endl;
}

Shpere::Shpere( float radius, int slices, int stacks )
{
   this->radius;
   this->slices;
   this->stacks;
}

float Shpere::getRadius()
{
 return radius;
}

int Shpere::getSlices()
{
   return slices;
}

int Shpere::getStacks()
{
   return stacks;
}

void Shpere::draw()
{
	GLUquadric* qObj = gluNewQuadric();
	gluQuadricTexture(qObj, GLU_TRUE);
	gluSphere(qObj,radius,slices,stacks);
}

void Shpere::print()
{
	cout << "Sphere: " << endl << endl;

	cout << "Radius: " << radius << endl;
	cout << "Slices: " << slices << endl;
	cout << "Stacks: " << stacks << endl << endl;
}

Torus::Torus( float inner, float outter, int slices, int loops )
{
   this->inner = inner;
   this->outter = outter;
   this->slices = slices;
   this->loops = loops;
}

float Torus::getInner()
{
   return inner;
}

float Torus::getOutter()
{
   return outter;
}

int Torus::getSlices()
{
		return slices;
}

int Torus::getLoops()
{
   return loops;
}

void Torus::draw()
{
   glutSolidTorus(inner, outter, slices, loops);
}

void Torus::print()
{
	cout << "Torus: " << endl << endl;

	cout << "Inner: " << inner << endl;
	cout << "Outter: " << outter << endl;
	cout << "Slices: " << slices << endl;
	cout << "Loops: " << loops << endl << endl;
}
