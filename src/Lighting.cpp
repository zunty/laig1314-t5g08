#include "Lighting.h"

Lighting::Lighting(string id, string enabled, vector<float> ambient, vector<float> location, vector<float> diffuse, vector<float> specular, string type)
{
	
	this->id = id;
	this->enabled = enabled;
	this->location = location;
	this->ambient = ambient;		
	this->diffuse = diffuse;
	this->specular = specular;
	this->type = type;
}

Omni::Omni(string id, string enabled, vector<float> ambient, vector<float> location, vector<float> diffuse,	vector<float> specular, string type): Lighting(id, enabled, ambient, location, diffuse, specular, type){}

Spot::Spot(string id, string enabled, vector<float> ambient, vector<float> location, vector<float> diffuse, vector<float> specular, string type, float angle, float exponent, vector<float> direction): Lighting(id, enabled, ambient, location, diffuse, specular, type) {
	this->angle = angle;
	this->exponent = exponent;
	this->direction = direction;
}

string Lighting::getId()
{
	return id;
}

string Lighting::getEnabled()
{
	return enabled;
}

vector<float> Lighting::getAmbient()
{
	return ambient;
}

vector<float> Lighting::getLocation()
{
	return location;
}

vector<float> Lighting::getDiffuse()
{
	return diffuse;
}

vector<float> Lighting::getSpecular()
{
	return specular;
}

string Lighting::getType()
{
	return type;
}

float Omni::getAngle()
{
	return 0;
}

float Omni::getExponent()
{
	return 0;
}

vector<float> Omni::getDirection()
{
	vector<float> v;
	v.clear();
	return v;
}

float Spot::getAngle()
{
	return angle;
}

float Spot::getExponent()
{
	return exponent;
}

vector<float> Spot::getDirection()
{
	return direction;
} 

void Lighting::print(){}

void Omni::print(){
	
	cout << "Lighting Omni" << endl << endl;
	cout << "Id: " << getId() << endl;
	cout << "Enabled: " << getEnabled() << endl;
	cout << "Location: " << getLocation()[0] << ", " << getLocation()[1] << ", " <<getLocation()[2] << endl;
	cout << "Ambient: " << getAmbient()[0] << ", " << getAmbient()[1] << ", " << getAmbient()[2] << ", " << getAmbient()[3] << endl;	
	cout << "Diffuse: " << getDiffuse()[0] << ", " << getDiffuse()[1] << ", " << getDiffuse()[2] << ", " << getDiffuse()[3] << endl;
	cout << "Specular: " << getSpecular()[0] << ", " << getSpecular()[1] << ", " << getSpecular()[2] << ", " << getSpecular()[3] << endl << endl;
	
}

void Spot::print(){
	
	cout << "Lighting Spot" << endl << endl;
	cout << "Id: " << getId() << endl;
	cout << "Enabled: " << getEnabled() << endl;
	cout << "Location: " << getLocation()[0] << ", " << getLocation()[1] << ", " <<getLocation()[2] << endl;
	cout << "Ambient: " << getAmbient()[0] << ", " << getAmbient()[1] << ", " << getAmbient()[2] << ", " << getAmbient()[3] << endl;	
	cout << "Diffuse: " << getDiffuse()[0] << ", " << getDiffuse()[1] << ", " << getDiffuse()[2] << ", " << getDiffuse()[3] << endl;
	cout << "Specular: " << getSpecular()[0] << ", " << getSpecular()[1] << ", " << getSpecular()[2] << ", " << getSpecular()[3] << endl;;
	cout << "Angle: " << angle << endl;
	cout << "Exponent: " << exponent << endl;
	cout << "Direction: " << direction[0] << ", " << direction[1] << ", " << direction[2] << endl << endl;
	
}