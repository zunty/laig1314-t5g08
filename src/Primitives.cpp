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

Plane::Plane( unsigned int divisions )
{
	this->divisions = divisions;

	//Initialize control points
	this->crtlpoints[0][0] = 0.5;
	this->crtlpoints[0][1] = 0.0;
	this->crtlpoints[0][2] = 0.5;

	this->crtlpoints[1][0] = -0.5;
	this->crtlpoints[1][1] = 0.0;
	this->crtlpoints[1][2] = 0.5;

	this->crtlpoints[2][0] = 0.5;
	this->crtlpoints[2][1] = 0.0;
	this->crtlpoints[2][2] = -0.5;

	this->crtlpoints[3][0] = -0.5;
	this->crtlpoints[3][1] = 0.0;
	this->crtlpoints[3][2] = -0.5;

	//Initialize normal points
	this->nrmlcompon[0][0] = 0.0;
	this->nrmlcompon[0][1] = 1.0;
	this->nrmlcompon[0][2] = 0.0;

	this->nrmlcompon[1][0] = 0.0;
	this->nrmlcompon[1][1] = 1.0;
	this->nrmlcompon[1][2] = 0.0;

	this->nrmlcompon[2][0] = 0.0;
	this->nrmlcompon[2][1] = 1.0;
	this->nrmlcompon[2][2] = 0.0;

	this->nrmlcompon[3][0] = 0.0;
	this->nrmlcompon[3][1] = 1.0;
	this->nrmlcompon[3][2] = 0.0;

	//Initialize texture points

	this->textpoints[0][0] = 0.0;
	this->textpoints[0][1] = 0.0;

	this->textpoints[1][0] = 0.0;
	this->textpoints[1][1] = 1.0;

	this->textpoints[2][0] = 1.0;
	this->textpoints[2][1] = 0.0;

	this->textpoints[3][0] = 1.0;
	this->textpoints[3][1] = 1.0;
}

int Plane::getDivisions()
{
	return divisions;
}

void Plane::draw()
{

	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2, 0.0, 1.0, 6, 2, *crtlpoints);
	glMap2f(GL_MAP2_NORMAL, 0.0, 1.0, 3, 2, 0.0, 1.0, 6, 2, *nrmlcompon);
	glMap2f(GL_MAP2_TEXTURE_COORD_4, 0.0, 1.0, 2, 2, 0.0, 1.0, 4, 2, *textpoints);

	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	glEnable(GL_MAP2_TEXTURE_COORD_4);

	glMapGrid2f(divisions, 0.0, 1.0, divisions, 0.0, 1.0);

	//glEnable(GL_LIGHTING);
	glEvalMesh2(GL_LINE, 0, divisions, 0, divisions);
}

void Plane::print()
{
	cout << "Plane with " << divisions << " divisions" << endl << endl;
}

Patch::Patch(unsigned int order, unsigned int partsU, unsigned int partsV, string compute, vector<vector<float>> points)
{
	this->order = order,
	this->partsU = partsU;
	this->partsV = partsV;
	this->compute = compute;
	
	if(order == 1)
	{
		crtlpointsONE[0][0] = points[0][0];
		crtlpointsONE[0][1] = points[0][1];
		crtlpointsONE[0][2] = points[0][2];

		crtlpointsONE[1][0] = points[1][0];
		crtlpointsONE[1][1] = points[1][1];
		crtlpointsONE[1][2] = points[1][2];

		crtlpointsONE[2][0] = points[2][0];
		crtlpointsONE[2][1] = points[2][1];
		crtlpointsONE[2][2] = points[2][2];

		crtlpointsONE[3][0] = points[3][0];
		crtlpointsONE[3][1] = points[3][1];
		crtlpointsONE[3][2] = points[3][2];
	}

	if(order == 2)
	{
		crtlpointsTWO[0][0] = points[0][0];
		crtlpointsTWO[0][1] = points[0][1];
		crtlpointsTWO[0][2] = points[0][2];

		crtlpointsTWO[1][0] = points[1][0];
		crtlpointsTWO[1][1] = points[1][1];
		crtlpointsTWO[1][2] = points[1][2];

		crtlpointsTWO[2][0] = points[2][0];
		crtlpointsTWO[2][1] = points[2][1];
		crtlpointsTWO[2][2] = points[2][2];

		crtlpointsTWO[3][0] = points[3][0];
		crtlpointsTWO[3][1] = points[3][1];
		crtlpointsTWO[3][2] = points[3][2];

		crtlpointsTWO[4][0] = points[4][0];
		crtlpointsTWO[4][1] = points[4][1];
		crtlpointsTWO[4][2] = points[4][2];

		crtlpointsTWO[5][0] = points[5][0];
		crtlpointsTWO[5][1] = points[5][1];
		crtlpointsTWO[5][2] = points[5][2];

		crtlpointsTWO[6][0] = points[6][0];
		crtlpointsTWO[6][1] = points[6][1];
		crtlpointsTWO[6][2] = points[6][2];

		crtlpointsTWO[7][0] = points[7][0];
		crtlpointsTWO[7][1] = points[7][1];
		crtlpointsTWO[7][2] = points[7][2];

		crtlpointsTWO[8][0] = points[8][0];
		crtlpointsTWO[8][1] = points[8][1];
		crtlpointsTWO[8][2] = points[8][2];
	}

	if(order == 3)
	{
		crtlpointsTHREE[0][0] = points[0][0];
		crtlpointsTHREE[0][1] = points[0][1];
		crtlpointsTHREE[0][2] = points[0][2];

		crtlpointsTHREE[1][0] = points[1][0];
		crtlpointsTHREE[1][1] = points[1][1];
		crtlpointsTHREE[1][2] = points[1][2];

		crtlpointsTHREE[2][0] = points[2][0];
		crtlpointsTHREE[2][1] = points[2][1];
		crtlpointsTHREE[2][2] = points[2][2];

		crtlpointsTHREE[3][0] = points[3][0];
		crtlpointsTHREE[3][1] = points[3][1];
		crtlpointsTHREE[3][2] = points[3][2];

		crtlpointsTHREE[4][0] = points[4][0];
		crtlpointsTHREE[4][1] = points[4][1];
		crtlpointsTHREE[4][2] = points[4][2];

		crtlpointsTHREE[5][0] = points[5][0];
		crtlpointsTHREE[5][1] = points[5][1];
		crtlpointsTHREE[5][2] = points[5][2];

		crtlpointsTHREE[6][0] = points[6][0];
		crtlpointsTHREE[6][1] = points[6][1];
		crtlpointsTHREE[6][2] = points[6][2];

		crtlpointsTHREE[7][0] = points[7][0];
		crtlpointsTHREE[7][1] = points[7][1];
		crtlpointsTHREE[7][2] = points[7][2];

		crtlpointsTHREE[8][0] = points[8][0];
		crtlpointsTHREE[8][1] = points[8][1];
		crtlpointsTHREE[8][2] = points[8][2];

		crtlpointsTHREE[9][0] = points[9][0];
		crtlpointsTHREE[9][1] = points[9][1];
		crtlpointsTHREE[9][2] = points[9][2];

		crtlpointsTHREE[10][0] = points[10][0];
		crtlpointsTHREE[10][1] = points[10][1];
		crtlpointsTHREE[10][2] = points[10][2];

		crtlpointsTHREE[11][0] = points[11][0];
		crtlpointsTHREE[11][1] = points[11][1];
		crtlpointsTHREE[11][2] = points[11][2];

		crtlpointsTHREE[12][0] = points[12][0];
		crtlpointsTHREE[12][1] = points[12][1];
		crtlpointsTHREE[12][2] = points[12][2];

		crtlpointsTHREE[13][0] = points[13][0];
		crtlpointsTHREE[13][1] = points[13][1];
		crtlpointsTHREE[13][2] = points[13][2];

		crtlpointsTHREE[14][0] = points[14][0];
		crtlpointsTHREE[14][1] = points[14][1];
		crtlpointsTHREE[14][2] = points[14][2];

		crtlpointsTHREE[15][0] = points[15][0];
		crtlpointsTHREE[15][1] = points[15][1];
		crtlpointsTHREE[15][2] = points[15][2];
	}
}

unsigned int Patch::getOrder()
{
	return order;
}

unsigned int Patch::getPartsU()
{
	return partsU;
}

unsigned int Patch::getPartsV()
{
	return partsV;
}

string Patch::getCompute()
{
	return compute;
}

void Patch::draw()
{
	if(order == 1)
	{
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2, 0.0, 1.0, 6, 2, *crtlpointsONE);
		glEnable(GL_MAP2_VERTEX_3);
		glMapGrid2f(partsU, 0.0, 1.0, partsV, 0.0, 1.0);

		if(compute == "line")
		{
			glEvalMesh2(GL_LINE, 0, partsU, 0, partsV);
		}

		if(compute == "fill")
		{
			glEvalMesh2(GL_FILL, 0, partsU, 0, partsV);
		}

		if(compute == "point")
		{
			glEvalMesh2(GL_POINT, 0, partsU, 0, partsV);
		}
	}

	if(order == 2)
	{
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3, 0.0, 1.0, 9, 3, *crtlpointsTWO);
		glEnable(GL_MAP2_VERTEX_3);
		glMapGrid2f(partsU, 0.0, 1.0, partsV, 0.0, 1.0);

		if(compute == "line")
		{
			glEvalMesh2(GL_LINE, 0, partsU, 0, partsV);
		}

		if(compute == "fill")
		{
			glEvalMesh2(GL_FILL, 0, partsU, 0, partsV);
		}

		if(compute == "point")
		{
			glEvalMesh2(GL_POINT, 0, partsU, 0, partsV);
		}

	}

	if(order == 3)
	{
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 16, 4, *crtlpointsTHREE);
		glEnable(GL_MAP2_VERTEX_3);
		glMapGrid2f(partsU, 0.0, 1.0, partsV, 0.0, 1.0);

		if(compute == "line")
		{
			glEvalMesh2(GL_LINE, 0, partsU, 0, partsV);
		}

		if(compute == "fill")
		{
			glEvalMesh2(GL_FILL, 0, partsU, 0, partsV);
		}

		if(compute == "point")
		{
			glEvalMesh2(GL_POINT, 0, partsU, 0, partsV);
		}
	}
}

void Patch::print()
{
	cout << "NEW PATCH\n\n";
}
