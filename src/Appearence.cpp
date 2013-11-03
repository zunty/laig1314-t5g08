#include "Appearence.h"

//Constructors

Appearance::Appearance(string id, vector<float> emissive, vector<float> ambient, vector<float> diffuse, vector<float> specular, float shininess, string textureref, int texlength_s, int texlenght_t)
{
	this->id = id;
	this->emissive = emissive;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
	this->texture_ref = texture_ref;
	this->texlength_s = texlength_s;
	this->texlenght_t = texlenght_t;
}

Appearance::Appearance(string id, vector<float> emissive, vector<float> ambient, vector<float> diffuse, vector<float> specular, float shininess)
{
	this->id = id;
	this->emissive = emissive;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
	this->texture_ref = NULL_STRING;
	this->texlength_s = NULL;
	this->texlenght_t = NULL;
}


//SETS

void Appearance::setId(string id)
{
	this->id = id;
}

void Appearance::setTextureref(string texture_ref)
{
	this->texture_ref = texture_ref;
}

void Appearance::setEmissive(vector<float> emissive)
{
	
	this->emissive = emissive;
}

void Appearance::setAmbient(vector<float> ambient)
{
	
	this->ambient = ambient;
}

void Appearance::setDiffuse(vector<float> diffuse)
{
	this->diffuse = diffuse;
}
void Appearance::setSpecular(vector<float> specular)
{
	this->specular = specular;
}

void Appearance::setShininess(float shininess)
{
	this->shininess = shininess;
}

void Appearance::setTexlength_s(int texlength_s)
{
	this->texlength_s = texlength_s;
}

void Appearance::setTexlenght_t(int texlength_t)
{
	this->texlenght_t = texlenght_t;
}


//GETS

string Appearance::getId()
{
	return id;
}

string Appearance::getTextureref()
{
	return texture_ref;
}

vector<float> Appearance::getEmissive()
{
	return emissive;
}

vector<float> Appearance::getAmbient()
{
	return ambient;
}

vector<float> Appearance::getDiffuse()
{
	return diffuse;
}

vector<float> Appearance::getSpecular()
{
	return specular;
}

float Appearance::getShininess()
{
	return shininess;
}

int Appearance::getTexlength_s()
{
	return texlength_s;
}

int Appearance::getTexlenght_t()
{
	return texlenght_t;
}



void Appearance::print()
{
	cout << "ID: " << id << endl;
	cout << "Emissive: " << emissive[0] << ", " << emissive[1] << ", " << emissive[2] << ", " << emissive[3] << endl;
	cout << "Ambient: " << ambient[0] << ", " << ambient[1] << ", " << ambient[2] << ", " << ambient[3] << endl;
	cout << "Diffuse: " << diffuse[0] << ", " << diffuse[1] << ", " << diffuse[2] << ", " << diffuse[3] << endl;
	cout << "Specular: " << specular[0] << ", " << specular[1] << ", " << specular[2] << ", " << specular[3] << endl;
	cout << "shininess: " << shininess << endl;
	cout << "Texture_ref: " << texture_ref << endl;
	cout <<	"Texlenght_s: " << texlength_s << endl;
	cout << "Texlenght_t: " << texlenght_t << endl << endl;
}