#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Globals
{

	vector<float> background;
	string drawmode;
	string shading;
	string cullface;
	string cullorder;

public:

	Globals(vector<float> background, string drawmode, string shading, string cullface, string cullorder);

	//SETS
	void setBackground(vector<float> background);
	void setDrawmode(string drawmode); 
	void setShading(string shading);
	void setCullface(string cullface); 
	void setCullorder(string cullorder);


	//GETS
	vector<float> getBackground();
	string getDrawmode(); 
	string getShading();
	string getCullface(); 
	string getCullorder();

	void print();
};