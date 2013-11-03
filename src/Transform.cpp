#include "Transform.h"

Transform::Transform( string type )
{
	this->type = type;
}

Translate::Translate( float x, float y, float z, string type ): Transform(type)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Translate::getX()
{
	return x;
}

float Translate::getY()
{
   return y;
}

float Translate::getZ()
{
   return z;
}

float Translate::getAngle()
{
	return 0;
}

string Translate::getAxis()
{
	return "";
}

void Translate::print()
{
	cout << "Translation: " << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Z: " << z << endl << endl;
}

Rotation::Rotation( string axis, float angle, string type ): Transform(type)
{
	this->axis = axis;
	this->angle = angle;
}

std::string Rotation::getAxis()
{
		return axis;
}

float Rotation::getAngle()
{
	return angle;
}


float Rotation::getX()
{
	return 0;
}

float Rotation::getY()
{
   return 0;
}

float Rotation::getZ()
{
   return 0;
}

void Rotation::print()
{
   cout << "Rotation: " << endl;
   cout << "Axis: " << axis << endl;
   cout << "Angle: " << angle << endl << endl;
}

Scale::Scale( float x, float y, float z,string type ): Transform(type)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Scale::getX()
{
	return x;
}

float Scale::getY()
{
   return y;
}

float Scale::getZ()
{
   return z;
}

float Scale::getAngle()
{
	return 0;
}

string Scale::getAxis()
{
	return "";
}

void Scale::print()
{
	cout << "Scale: " << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Z: " << z << endl << endl;
}