#include "Globals.h"

Globals::Globals(vector<float> background, string drawmode, string shading, string cullface, string cullorder)
{
	this->background = background;
	this->drawmode = drawmode;
	this->shading = shading;
	this->cullface = cullface;
	this->cullorder = cullorder;
}

//SETS

void Globals::setBackground(vector<float> background)
{
	this->background = background;
}

void Globals::setDrawmode(string drawmode)
{
	this->drawmode = drawmode;
}

void Globals::setShading(string shading)
{
	this->shading = shading;
}

void Globals::setCullface(string cullface)
{
	this->cullface = cullface;
}

void Globals::setCullorder(string cullorder)
{
	this->cullorder = cullorder;
}

//GETS

vector<float> Globals::getBackground()
{
	return background;
}

string Globals::getDrawmode()
{
	return drawmode;
}

string Globals::getShading()
{
	return shading;
}

string Globals::getCullface()
{
	return cullface;
}

string Globals::getCullorder()
{
	return cullorder;
}

void Globals::print()
{
	cout << "Background: " << background[0] << ", " << background[1] << ", " << background[2] << ", " << background[3] << endl;
	cout << "Drawmode: " << drawmode << endl;
	cout << "Shading: " << shading << endl;
	cout << "Cullface: " << cullface << endl;
	cout << "Cullorder: " << cullorder << endl;
	cout << endl;
}