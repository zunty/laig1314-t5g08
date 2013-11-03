#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "CGFscene.h"

using namespace std;

class Lighting
{
	string type;
	string id;
	string enabled;
	vector<float> ambient;
	vector<float> location;
	vector<float> diffuse;
	vector<float> specular;

public:

	Lighting(string id, string enabled, vector<float> ambient, vector<float> location, vector<float> diffuse, vector<float> specular, string type);

	//GETS
	string getId();
	string getEnabled();
	vector<float> getAmbient();
	vector<float> getLocation();
	vector<float> getDiffuse();
	vector<float> getSpecular();
	string getType();

	//VIRTUAL
	virtual float getAngle() = 0;
	virtual float getExponent() = 0;
	virtual vector<float> getDirection() = 0;
	virtual void print();
};

class Omni: public Lighting
{
public:

	Omni(string id, string enabled, vector<float> ambient, vector<float> location, vector<float> diffuse, vector<float> specular, string type);

	float getAngle();
	float getExponent();
	vector<float> getDirection();

	void print();

};

class Spot: public Lighting
{
protected:
	float angle;
	float exponent;
	vector<float> direction;

public:

	Spot(string id, string enabled, vector<float> ambient, vector<float> location, vector<float> diffuse, vector<float> specular, string type, float angle, float exponent, vector<float> direction);
		
	float getAngle();
	float getExponent();
	vector<float> getDirection();

	void print();

};