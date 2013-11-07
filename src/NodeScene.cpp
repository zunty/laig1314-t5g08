#include "NodeScene.h"

NodeScene::NodeScene(string id, vector<Appearance*> appearances, vector<Texture*> textures, vector<Node*> nodes)
{

	this->id == id;
	

	for(unsigned int i = 0; i < nodes.size(); i++)
	{
		if(id == nodes[i]->getId())
		{

			this->display_list = nodes[i]->getDisplayList();
			this->display_id = -1;

			//Create appearance

			app = false;

			for(unsigned int j = 0; j < appearances.size(); j++)
			{
				if(nodes[i]->getAppearancesref() == appearances[j]->getId())
				{
					if(appearances[j]->getTextureref() == NULL_STRING)
					{
						float ambient[4] = {appearances[j]->getAmbient()[0], appearances[j]->getAmbient()[1], appearances[j]->getAmbient()[2], appearances[j]->getAmbient()[3]};
						float diffuse[4] = {appearances[j]->getDiffuse()[0], appearances[j]->getDiffuse()[1], appearances[j]->getDiffuse()[2], appearances[j]->getDiffuse()[3]};
						float specular[4] = {appearances[j]->getSpecular()[0], appearances[j]->getSpecular()[1], appearances[j]->getSpecular()[2],appearances[j]->getSpecular()[3]};
						float shininess = appearances[j]->getShininess();

						appearance = new CGFappearance(ambient, diffuse, specular, shininess);
						app = true;
					}

					else
					{
						float ambient[4] = {appearances[j]->getAmbient()[0], appearances[j]->getAmbient()[1], appearances[j]->getAmbient()[2], appearances[j]->getAmbient()[3]};
						float diffuse[4] = {appearances[j]->getDiffuse()[0], appearances[j]->getDiffuse()[1], appearances[j]->getDiffuse()[2], appearances[j]->getDiffuse()[3]};
						float specular[4] = {appearances[j]->getSpecular()[0], appearances[j]->getSpecular()[1], appearances[j]->getSpecular()[2],appearances[j]->getSpecular()[3]};
						float shininess = appearances[j]->getShininess();

						appearance = new CGFappearance(ambient, diffuse, specular, shininess);

						app = true;

						for(unsigned int k = 0; k < textures.size(); k++)
						{
							if(appearances[j]->getTextureref() == textures[k]->getId())
							{
								string file = textures[k]->getFileName();
								int text_s = appearances[j]->getTexlength_s();
								int text_t = appearances[j]->getTexlenght_t();

								appearance->setTexture(file);
								appearance->setTextureWrap(text_s, text_t);							
							}
						}
					}
				}
			}

			//Primitives

			primitives.clear();

			for(unsigned int j = 0; j < nodes[i]->getPatches().size(); j++)
			{
				primitives.push_back(nodes[i]->getPatches()[j]);
			}

			for(unsigned int j = 0; j < nodes[i]->getPlanes().size(); j++)
			{
				primitives.push_back(nodes[i]->getPlanes()[j]);
			}

			for(unsigned int j = 0; j < nodes[i]->getRectangles().size(); j++)
			{
				primitives.push_back(nodes[i]->getRectangles()[j]);
			}

			for(unsigned int j = 0; j < nodes[i]->getTriangles().size(); j++)
			{
				primitives.push_back(nodes[i]->getTriangles()[j]);
			}

			for(unsigned int j = 0; j < nodes[i]->getCylinders().size(); j++)
			{
				primitives.push_back(nodes[i]->getCylinders()[j]);
			}

			for(unsigned int j = 0; j < nodes[i]->getTorus().size(); j++)
			{
				primitives.push_back(nodes[i]->getTorus()[j]);
			}

			for(unsigned int j = 0; j < nodes[i]->getSpheres().size(); j++)
			{
				primitives.push_back(nodes[i]->getSpheres()[j]);
			}

			//Transforms
			scene_transforms.clear();
			scene_transforms = nodes[i]->getTransforms();

			//Childs

			if(!nodes[i]->getNoderefs().empty())
			{
				for(unsigned int j = 0; j < nodes[i]->getNoderefs().size(); j++)
				{
					NodeScene* n = new NodeScene(nodes[i]->getNoderefs()[j], appearances, textures, nodes);
					child_nodes.push_back(n);
				}
			}
		}
	}
}

void NodeScene::generateGeometry()
{
	string tr = "translate";
	string rr = "rotate";
	string ss = "scale";

	glPushMatrix();

	if(app == true)
		appearance->apply();
	
	//Aplicar transformações
	for(unsigned int i = 0; i < scene_transforms.size(); i++){

		if(scene_transforms[i]->getType() == tr)
			glTranslatef(scene_transforms[i]->getX(), scene_transforms[i]->getY(), scene_transforms[i]->getZ());		

		if(scene_transforms[i]->getType() == rr){

			if(scene_transforms[i]->getAxis() == "x")
				glRotatef(scene_transforms[i]->getAngle(), 1, 0, 0);

			if(scene_transforms[i]->getAxis() == "y")
				glRotatef(scene_transforms[i]->getAngle(), 0, 1, 0);

			if(scene_transforms[i]->getAxis() == "z")
				glRotatef(scene_transforms[i]->getAngle(), 0, 0, 1);
		}			

		if(scene_transforms[i]->getType() == ss)
			glScalef(scene_transforms[i]->getX(), scene_transforms[i]->getY(), scene_transforms[i]->getZ());
	}	
	
	//Desenhar objectos
			
	for(unsigned int i = 0; i < primitives.size(); i++)
	{
		primitives[i]->draw();
		//cout << "Desenhou primitiva: " << endl;
	}

	for(unsigned int i=0;i< child_nodes.size();i++)
	{
		child_nodes[i]->draw();
		//cout << "Desenhou : " << endl;
	}
		
	glPopMatrix();
}

void NodeScene::setDisplayState(bool display_state)
{
	this->display_id = display_id;
}

void NodeScene::draw()
{
	if(this->display_list == true) {
		if (this->display_id == -1)
		{
			this->display_id = glGenLists(1);
			glNewList(this->display_id, GL_COMPILE);
				generateGeometry();
			glEndList();
		}
	 	glCallList(this->display_id);
	}
	else {
		generateGeometry();
	}
}

