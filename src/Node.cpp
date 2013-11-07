#include "Node.h"

Node::Node(string id, string appearanceref_id, vector<string> noderefs, vector<Scale*> scales, vector<Translate*> translations, vector<Rotation*> rotations,  vector<Patch*> patches, vector<Plane*> planes,  vector<Rectangle*> rectangles, vector<Triangle*> triangles, vector<Cylinder*> cylinders, vector<Shpere*> spheres, vector<Torus*> torus, vector<Transform*> transforms, bool display_list)
{
		this->id = id;
		this->appearanceref = appearanceref;
		this->noderefs = noderefs;
		this->scales = scales;
		this->transforms = transforms;
		this->translations = translations;
		this->rotations = rotations;
		this->patches = patches;
		this->planes = planes;
		this->rectangles = rectangles;
		this->triangles = triangles;
		this->cylinders = cylinders;
		this->spheres = spheres;
		this->torus = torus;
		this->display_list = display_list;
}

std::string Node::getId()
{
   return id;
}

std::string Node::getAppearancesref()
{
	return appearanceref;
}

vector<string> Node::getNoderefs()
{
  return noderefs;
}

vector<Scale*> Node::getScales()
{
   return scales;
}

vector<Transform*> Node::getTransforms()
{
	return transforms;
}

vector<Translate*> Node::getTranslations()
{
  return translations;
}

vector<Rotation*> Node::getRotations()
{
   return rotations;
}

vector<Patch*> Node::getPatches()
{
	return patches;
}

vector<Plane*> Node::getPlanes()
{
	return planes;
}

vector<Rectangle*> Node::getRectangles()
{
   return rectangles;
}

vector<Triangle*> Node::getTriangles()
{
	return triangles;
}

vector<Cylinder*> Node::getCylinders()
{
   return cylinders;
}

vector<Shpere*> Node::getSpheres()
{
   return spheres;
}

vector<Torus*> Node::getTorus()
{
	return torus;
}

bool Node::getDisplayList()
{
	return display_list;
}

void Node::print()
{
	cout << "NODE" << endl << endl;

	cout << "ID: " << id << endl;

	cout << "Appearancesref: " << appearanceref << endl;

	cout << "Nodesref: " << endl;

	for(unsigned int i = 0; i < noderefs.size(); i++)
	{
		if(i == (noderefs.size() - 1))
		{
			cout << noderefs[i] << endl;
		}
		else
			cout << noderefs[i] << ",";
	}

	for(unsigned int i = 0; i < translations.size(); i++)
	{
		translations[i]->print();
	}

	for(unsigned int i = 0; i < rotations.size(); i++)
	{
		rotations[i]->print();
	}

	for(unsigned int i = 0; i < scales.size(); i++)
	{
		scales[i]->print();
	}

	for(unsigned int i = 0; i < patches.size(); i++)
	{
		patches[i]->print();
	}

	for(unsigned int i = 0; i < planes.size(); i++)
	{
		planes[i]->print();
	}

	for(unsigned int i = 0; i < rectangles.size(); i++)
	{
		rectangles[i]->print();
	}

	for(unsigned int i = 0; i < triangles.size(); i++)
	{
		triangles[i]->print();
	}

	for(unsigned int i = 0; i < cylinders.size(); i++)
	{
		cylinders[i]->print();
	}

	for(unsigned int i = 0; i < spheres.size(); i++)
	{
		spheres[i]->print();
	}

	for(unsigned int i = 0; i < torus.size(); i++)
	{
		torus[i]->print();
	}
}



