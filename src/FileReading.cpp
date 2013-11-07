#include "FileReading.h"
#include <math.h>

vector<float> make3Vector(string str)
{
	float str1, str2, str3; 
	stringstream s_str;
	vector<float> result;

	s_str << str;
	s_str >> str1 >> str2 >> str3;

	result.push_back(str1);
	result.push_back(str2);
	result.push_back(str3);

	return result;
}

vector<float> make4Vector(string str)
{
	float str1, str2, str3, str4;
	stringstream s_str;
	vector<float> result;

	s_str << str;
	s_str >> str1 >> str2 >> str3 >> str4;

	result.push_back(str1);
	result.push_back(str2);
	result.push_back(str3);
	result.push_back(str4);

	return result;
}

FileReading::FileReading(char *filename)
{

	// Read XML from file

	doc=new TiXmlDocument( filename );
	bool loadOkay = doc->LoadFile();


	if ( !loadOkay )
	{
		printf( "Could not load file '%s'. Error='%s'. Exiting.\n", filename, doc->ErrorDesc() );
		exit( 1 );
	}

	yafElement= doc->FirstChildElement( "yaf" );

	if (yafElement == NULL)
	{
		printf("Main yaf block element not found! Exiting!\n");
		exit(1);
	}	

	globalsElement = yafElement->FirstChildElement( "globals" );
	camerasElement = yafElement->FirstChildElement( "cameras" );
	lightingElement = yafElement->FirstChildElement( "lighting" );
	textsElement =  yafElement->FirstChildElement( "textures" );
	appsElement =  yafElement->FirstChildElement( "appearances" );
	nodesElement =  yafElement->FirstChildElement( "Nodes" );
	graphElement =  yafElement->FirstChildElement( "graph" );


	// Globals
	// An example of well-known, required nodes

	if (globalsElement == NULL)
		printf("Globals block not found!\n");
	else
	{
		Globals* gl = new Globals(make4Vector(globalsElement->Attribute("background")), globalsElement->Attribute("drawmode"), globalsElement->Attribute("shading"), globalsElement->Attribute("cullface"), globalsElement->Attribute("cullorder"));

		globals.push_back(gl);
	}

	// Cameras

	if (camerasElement == NULL)
		printf("Cameras block not found!\n");
	else
	{
		initial_camera = camerasElement->Attribute("initial");

		TiXmlElement *childs=camerasElement->FirstChildElement();
		
		while (childs)
		{ 
			if (strcmp(childs->Value(),"perspective")==0)
			{

				float near, far, angle;

				childs->QueryFloatAttribute("near", &near);
				childs->QueryFloatAttribute("far", &far);
				childs->QueryFloatAttribute("angle", &angle);

				Perspective* c1 = new Perspective(childs->Attribute("id"), near, far, angle, make3Vector(childs->Attribute("pos")), make3Vector(childs->Attribute("target")));
				cameras.push_back(c1);
			}

			if (strcmp(childs->Value(),"ortho")==0)
			{	 
				string id;
				float near, far, left, right, top, bottom;
				
				id = childs->Attribute("id");
				childs->QueryFloatAttribute("near", &near);
				childs->QueryFloatAttribute("far", &far);
				childs->QueryFloatAttribute("left", &left);
				childs->QueryFloatAttribute("right", &right);
				childs->QueryFloatAttribute("top", &top);
				childs->QueryFloatAttribute("bottom", &bottom);				

				Ortho* c2 = new Ortho(id, near, far, left, right, top, bottom);
				cameras.push_back(c2);

			}
			childs=childs->NextSiblingElement();
		}
	}

	// Lighting

	if (lightingElement == NULL)
		printf("Lighting block not found!\n");
	else
	{				
		doublesided = lightingElement->Attribute("doublesided");

		local = lightingElement->Attribute("local");

		enabled = lightingElement->Attribute("enabled");

		ambient.push_back(make4Vector(lightingElement->Attribute("ambient"))[0]);
		ambient.push_back(make4Vector(lightingElement->Attribute("ambient"))[1]);
		ambient.push_back(make4Vector(lightingElement->Attribute("ambient"))[2]);
		ambient.push_back(make4Vector(lightingElement->Attribute("ambient"))[3]);
		
		TiXmlElement *childs=lightingElement->FirstChildElement();

		while (childs)
		{
			if (strcmp(childs->Value(),"omni")==0)
			{	  
				Omni* l1 = new Omni(childs->Attribute("id"), childs->Attribute("enabled"),make4Vector(childs->Attribute("ambient")), make3Vector(childs->Attribute("location")), make4Vector(childs->Attribute("diffuse")), make4Vector(childs->Attribute("specular")), "Omni");

				lights.push_back(l1);
			}
			if (strcmp(childs->Value(),"spot")==0)
			{
				
				float angle, exponent;
				
				childs->QueryFloatAttribute("angle", &angle);
				childs->QueryFloatAttribute("exponent", &exponent);

				Spot* l2 = new Spot(childs->Attribute("id"), childs->Attribute("enabled"), make4Vector(childs->Attribute("ambient")), make3Vector(childs->Attribute("location")), make4Vector(childs->Attribute("diffuse")), make4Vector(childs->Attribute("specular")), "Spot", angle, exponent, make4Vector(childs->Attribute("direction")));				

				lights.push_back(l2);
			}
			childs=childs->NextSiblingElement();
		}
	}

	// Textures

	if (textsElement == NULL)
		printf("Textures block not found!\n");
	else
	{
		TiXmlElement *texts=textsElement->FirstChildElement();

		while (texts)
		{
			Texture* t1 = new Texture(texts->Attribute("id"), texts->Attribute("file"));

			textures.push_back(t1);

			texts=texts->NextSiblingElement();
		}
	}

	// Appearances

	if (appsElement == NULL)
		printf("Appearances block not found!\n");
	else
	{
		TiXmlElement *apps=appsElement->FirstChildElement();
		
		while (apps)
		{
			
			float shininess;
			apps->QueryFloatAttribute("shininess", &shininess);

			if(apps->Attribute("textureref")){
				
				int texlength_s;
				int texlenght_t;
				apps->QueryIntAttribute("texlength_s", &texlength_s);
				apps->QueryIntAttribute("texlength_t", &texlenght_t);
				
				Appearance* ap1 = new Appearance(apps->Attribute("id"), make4Vector(apps->Attribute("emissive")), make4Vector(apps->Attribute("ambient")), make4Vector(apps->Attribute("diffuse")), make4Vector(apps->Attribute("specular")), shininess, apps->Attribute("textureref"), texlength_s, texlenght_t);
			
				appearances.push_back(ap1);

			}
			else{

				Appearance* ap1 = new Appearance(apps->Attribute("id"), make4Vector(apps->Attribute("emissive")), make4Vector(apps->Attribute("ambient")), make4Vector(apps->Attribute("diffuse")), make4Vector(apps->Attribute("specular")), shininess);

				appearances.push_back(ap1);
			}

			apps=apps->NextSiblingElement();
		}
	}



	//Graph

	
	if (graphElement == NULL)
		printf("Graph block not found!\n");
	else
	{  
		root_node_id = graphElement->Attribute("rootid");

		TiXmlElement *node=graphElement->FirstChildElement();

		while (node)
		{

			string id, appearanceref;
			bool display_state;
			vector<Scale*> scales;
			vector<Transform*> transforms_order;
			vector<Translate*> translations;
			vector<Rotation*> rotations;
			vector<Plane*> planes;
			vector<Rectangle*> rectangles;
			vector<Triangle*> triangles;
			vector<Cylinder*> cylinders;
			vector<Shpere*> spheres;
			vector<Torus*> torus;
			vector<string> noderefs;

			id = node->Attribute("id");

			if(!node->Attribute("displaylist") || (node->Attribute("displaylist") == "false"))
				display_state = false;
			else
				display_state = true;			

			TiXmlElement *transforms=node->FirstChildElement();
			while(transforms)
			{
				if(strcmp(transforms->Value(),"appearanceref")==0)
				{
					appearanceref = transforms->Attribute("id");
				}
				if(strcmp(transforms->Value(),"transforms")==0)
				{
					
					TiXmlElement *transformschilds=transforms->FirstChildElement();
					while(transformschilds)
					{
						if(strcmp(transformschilds->Value(),"translate")==0)
						{
							string translate_s;
							float trans1, trans2, trans3;
							stringstream translate;

							translate_s = transformschilds->Attribute("to");

							translate << translate_s;
							translate >> trans1 >> trans2 >> trans3;

							Translate* trans = new Translate(trans1, trans2, trans3,  "translate");
							translations.push_back(trans);
							transforms_order.push_back(trans);
						}
						if(strcmp(transformschilds->Value(),"rotate")==0)
						{
							string axis;
							float angle;
							axis = transformschilds->Attribute("axis");
							transformschilds->QueryFloatAttribute("angle", &angle);

							Rotation* rt = new Rotation(axis, angle, "rotate");
							rotations.push_back(rt);
							transforms_order.push_back(rt);							
						}
						if(strcmp(transformschilds->Value(),"scale")==0)
						{
							string scale_s;
							float scale1, scale2, scale3;
							stringstream scale;

							scale_s = transformschilds->Attribute("factor");

							scale << scale_s;
							scale >> scale1 >> scale2 >> scale3;

							Scale* scl = new Scale(scale1, scale2, scale3, "scale");
							scales.push_back(scl);
							transforms_order.push_back(scl);
						}
						transformschilds=transformschilds->NextSiblingElement();
					}
				}
				if(strcmp(transforms->Value(),"children")==0)
				{
					
					TiXmlElement *childs=transforms->FirstChildElement();
					while(childs)
					{
						if(strcmp(childs->Value(),"plane")==0)
						{
							int div;
							childs->QueryIntAttribute("parts", &div);

							Plane* p = new Plane(div);
							planes.push_back(p);
						}
						
						if(strcmp(childs->Value(),"rectangle")==0)
						{
							string xy1_s, xy2_s;
							float x1, y1, x2, y2;
							stringstream xy1, xy2;
							xy1_s = childs->Attribute("xy1");
							xy2_s = childs->Attribute("xy2");

							xy1 << xy1_s;
							xy2 << xy2_s;

							xy1 >> x1 >> y1;
							xy2 >> x2 >> y2;

							Rectangle* rect = new Rectangle(x1, y1, x2, y2);
							rectangles.push_back(rect);							
						}
						if(strcmp(childs->Value(),"triangle")==0)
						{
							string xyz1_s, xyz2_s, xyz3_s;
							float x1, y1, z1, x2, y2, z2, x3, y3, z3;
							stringstream xyz1, xyz2, xyz3;
							xyz1_s = childs->Attribute("xyz1");
							xyz2_s = childs->Attribute("xyz2");
							xyz3_s = childs->Attribute("xyz3");


							xyz1 << xyz1_s;
							xyz2 << xyz2_s;
							xyz3 << xyz3_s;

							xyz1 >> x1 >> y1 >> z1;
							xyz2 >> x2 >> y2 >> z2;
							xyz3 >> x3 >> y3 >> z3;

							Triangle* tr = new Triangle(x1, y1, z1, x2, y2, z2, x3, y3, z3);
							triangles.push_back(tr);
							
						}
						if(strcmp(childs->Value(),"cylinder")==0)
						{
							float base, top, height;
							int slices, stacks;

							childs->QueryFloatAttribute("base", &base);
							childs->QueryFloatAttribute("top", &top);
							childs->QueryFloatAttribute("height", &height);
							childs->QueryIntAttribute("slices", &slices);
							childs->QueryIntAttribute("stacks", &stacks);

							Cylinder* cyl = new Cylinder(base, top, height, slices, stacks);
							cylinders.push_back(cyl);

							//printf("			- Cylinder: base='%s' top='%s' height='%s' slices='%s' stacks='%s' \n",childs->Attribute("base"),childs->Attribute("top"),childs->Attribute("height"),childs->Attribute("slices"),childs->Attribute("stacks"));
						}
						if(strcmp(childs->Value(),"sphere")==0)
						{
							float radius;
							int slices, stacks;

							childs->QueryIntAttribute("slices", &slices);
							childs->QueryIntAttribute("stacks", &stacks);
							childs->QueryFloatAttribute("radius", &radius);

							Shpere* sph = new Shpere(radius, slices, stacks);
							spheres.push_back(sph);

							//printf("			- Sphere: radius='%s' slices='%s' stacks='%s' \n",childs->Attribute("radius"),childs->Attribute("slices"),childs->Attribute("stacks"));
						}
						if(strcmp(childs->Value(),"torus")==0)
						{
							float inner, outter;
							int slices, loops;

							childs->QueryIntAttribute("slices", &slices);
							childs->QueryIntAttribute("loops", &loops);
							childs->QueryFloatAttribute("inner", &inner);
							childs->QueryFloatAttribute("outer", &outter);

							Torus* trs = new Torus(inner, outter, slices, loops);
							torus.push_back(trs);
							//printf("			- Torus: inner='%s' outer='%s' slices='%s' loops='%s' \n",childs->Attribute("inner"),childs->Attribute("outer"),childs->Attribute("slices"),childs->Attribute("loops"));
						}
						if(strcmp(childs->Value(),"noderef")==0)
						{
							string id;

							id = childs->Attribute("id");

							noderefs.push_back(id);
						}
						childs=childs->NextSiblingElement();
					}
				}

				transforms=transforms->NextSiblingElement();
			}

			Node* nd = new Node(id, appearanceref, noderefs, scales, translations, rotations, planes, rectangles, triangles, cylinders, spheres, torus, transforms_order, display_state);			

			nodes.push_back(nd);

			scales.clear();
			translations.clear();
			rotations.clear();
			planes.clear( );
			rectangles.clear();
			triangles.clear();
			cylinders.clear();
			spheres.clear();
			torus.clear();
			noderefs.clear();
			transforms_order.clear();

			node=node->NextSiblingElement();
		}		
	}
}

FileReading::~FileReading()
{
	delete(doc);
}

TiXmlElement *FileReading::findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val)
// Searches within descendants of a parent for a node that has an attribute _attr_ (e.g. an id) with the value _val_
// A more elaborate version of this would rely on XPath expressions
{
	TiXmlElement *child=parent->FirstChildElement();
	int found=0;

	while (child && !found)
		if (child->Attribute(attr) && strcmp(child->Attribute(attr),val)==0)
			found=1;
		else
			child=child->NextSiblingElement();

		return child;
}

void FileReading::print()
{
	cout << "YAF FILE CONTAINS:" << endl << endl;
	
	for(unsigned int i = 0; i < globals.size(); i++)
	{
	   globals[i]->print();
	}

	cout << "CAMERAS:" << endl << endl;

	cout << "Initial Camera: " << initial_camera << endl;

	for(unsigned int i = 0; i < cameras.size(); i++)
	{
		cameras[i]->print();
	}

	cout << "Camera - Globals:" << endl;
	cout << "Doublesided: " << doublesided << endl;
	cout << "Local: " << local << endl;
	cout << "Enabled: " << enabled << endl;
	cout << "Ambient: " << ambient[0] << ", " << ambient[1] << ", "	<< ambient[2] << ", " << ambient[3] << endl << endl;

	cout << "LIGHTS: " << endl << endl;

	for(unsigned int i = 0; i < lights.size(); i++)
	{
		lights[i]->print();	
	}

	cout << "TEXTURES: " << endl << endl;

	for(unsigned int i = 0; i < textures.size(); i++)
	{
		textures[i]->print();
	}

	cout << "APPEARENCES: " << endl << endl;

	for(unsigned int i = 0; i < appearances.size(); i++)
	{
		appearances[i]->print();
	}

	
}

void FileReading::printNodes()
{
   cout << "NODES: " << endl << endl;
	
	for(unsigned int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->print();
	}
	
}
