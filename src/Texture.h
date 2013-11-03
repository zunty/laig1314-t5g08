#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Texture{

	string id;
	string file_name;

public:
	Texture(string id, string file_name);

	//SETS

	void setId(string id);
	void setFileName(string file_name);

	//GETS
	string getId();
	string getFileName();

	void print();
};

#endif