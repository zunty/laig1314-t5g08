#ifndef _APPEARENCE_H_
#define _APPEARENCE_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#define NULL_STRING ""

using namespace std;

class Appearance
{	
protected:
	string id, texture_ref;
	vector<float> emissive, ambient, diffuse, specular;
	float shininess;
	int texlength_s;
	int texlenght_t;
public:

	//CONSTRUCTOR
	Appearance(string id, vector<float> emissive, vector<float> ambient, vector<float> diffuse, vector<float> specular, float shininess, string textureref, int texlength_s, int texlenght_t);
	Appearance(string id, vector<float> emissive, vector<float> ambient, vector<float> diffuse, vector<float> specular, float shininess);
	
	//SETS
	void setId(string id);
	void setTextureref(string texture_ref);
	void setEmissive(vector<float> emissive);
	void setAmbient(vector<float> ambient);
	void setDiffuse(vector<float> specular);
	void setSpecular(vector<float> diffuse);
	void setShininess(float shininess);
	void setTexlength_s(int texlenght_s);
	void setTexlenght_t(int texlenght_t);
	
	//GETS
	string getId();
	string getTextureref();
	vector<float> getEmissive();
	vector<float> getAmbient();
	vector<float> getDiffuse();
	vector<float> getSpecular();
	float getShininess();
	int getTexlength_s();
	int getTexlenght_t();
	

	//PRINT
	void print();

};

#endif