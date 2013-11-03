#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;


class Transform
{
	string type;

public:
	Transform(string type);

	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual float getZ() = 0;

	virtual string getAxis() = 0;
	virtual float getAngle() = 0;

	string getType(){ return type; }
};

class Translate: public Transform
{
	float x, y, z;

public:

	Translate(float x, float y, float z, string type);

	float getX();
	float getY();
	float getZ();

	string getAxis();
	float getAngle();

	void print();
};

class Rotation: public Transform
{
	string axis;
	float angle;

public:

	Rotation(string axis, float angle, string type);

	string getAxis();
	float getAngle();

	float getX();
	float getY();
	float getZ();

	void print();

};

class Scale: public Transform
{
	float x, y, z;

public:

	Scale(float x, float y, float z,string type);

	float getX();
	float getY();
	float getZ();

	string getAxis();
	float getAngle();

	void print();

};

#endif