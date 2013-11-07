#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "CGFobject.h"
#include "CGFtexture.h"

using namespace std;

class Patch: public CGFobject
{
	unsigned int order;
	unsigned int partsU;
	unsigned int partsV;
	string compute;	
	GLfloat crtlpointsONE[4][3];
	GLfloat crtlpointsTWO[9][3];
	GLfloat crtlpointsTHREE[16][3];

public:

	Patch(unsigned int order, unsigned int partsU, unsigned int partsV, string compute, vector<vector<float>> points);
	unsigned int getOrder();
	unsigned int getPartsU();
	unsigned int getPartsV();
	string getCompute();
	//GLfloat getControlPoints(); 

	void draw();
	void print();
};

class Plane: public CGFobject
{
	unsigned int divisions;
	CGFtexture* texture;

	GLfloat crtlpoints[4][3];
	GLfloat nrmlcompon[4][3];
	GLfloat textpoints[4][2];

public:

	Plane(unsigned int divisions);
	int getDivisions();
	void draw();
	void print();
};

class Rectangle: public CGFobject
{
	float x1, y1, x2, y2;

public:

	Rectangle(float x1, float y1, float x2, float y2);

	//GETS
	float getX1();
	float getY1();
	float getX2();
	float getY2();
	string getType() {return "rectangle";}

	void draw();
	void print();

};

class Triangle: public CGFobject
{
	float x1, y1, z1, x2, y2, z2, x3, y3, z3;

public:

	Triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);

	float getX1();
	float getY1();
	float getZ1();
	float getX2();
	float getY2();
	float getZ2();
	float getx3();
	float getY3();
	float getZ3();
	string getType() {return "triangle";}

	void draw();
	void print();
};

class Cylinder: public CGFobject
{
	float base, top, height;
	int slices, stacks;

public:

	Cylinder(float base, float top, float height, int slices, int stacks);

	float getBase();
	float getTop();
	float getHeight();
	int getSlices();
	int getStacks();
	string getType() {return "cylinder";}

	void draw();
	void print();
};

class Shpere: public CGFobject
{
	float radius;
	int slices, stacks;

public:

	Shpere(float radius, int slices, int stacks);

	float getRadius();
	int getSlices();
	int getStacks();
	string getType() {return "sphere";}

	void draw();
	void print();
};

class Torus: public CGFobject
{

	float inner, outter;
	int slices, loops;

public:

	Torus(float inner, float outter, int slices, int loops);

	float getInner();
	float getOutter();
	int getSlices();
	int getLoops();
	string getType() {return "torus";}

	void draw();
	void print();
}; 

#endif