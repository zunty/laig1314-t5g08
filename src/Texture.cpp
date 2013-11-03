//Texturas
#include "Texture.h"

Texture::Texture(string id, string file_name)
{
	this->id = id;
	this->file_name = file_name;
}

void Texture::setId(string id)
{
	this->id = id;
}

void Texture::setFileName(string file_name)
{
	this->file_name = file_name;
}

string Texture::getId()
{
	return id;
}

string Texture::getFileName()
{
	return file_name;
}

void Texture::print()
{
	cout << "Id: " << id << endl;
	cout << "File: " << file_name << endl << endl;
}