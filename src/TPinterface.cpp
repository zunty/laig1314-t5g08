#include "TPinterface.h"

TPinterface::TPinterface()
{
	testVar=0;
}

void TPinterface::initGUI()
{
	
	addCheckbox("Light0",NULL,100)->set_int_val(1);
	addCheckbox("Light1",NULL,101)->set_int_val(1);
	addCheckbox("Light2",NULL,102)->set_int_val(1);
	addCheckbox("Light3",NULL,103)->set_int_val(1);
	addButton("Relogio",104);
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{

	/*printf ("GUI control id: %d\n  ",ctrl->user_id);
	
	switch (ctrl->user_id)
	{

		case 104:
		{
			((LightingScene *) scene)->clock1->changeState();
			break;
		};

		case 100:
		{
			if(	((LightingScene *) scene)->light0_state)
			{
				((LightingScene *) scene)->light0_state=false;
				((LightingScene *) scene)->light0->disable();
			}
			else{
				((LightingScene *) scene)->light0_state=true;
				((LightingScene *) scene)->light0->enable();
			}
			break;
		};
			case 101:
		{
			if(	((LightingScene *) scene)->light1_state)
			{
				((LightingScene *) scene)->light1_state=false;
				((LightingScene *) scene)->light1->disable();
			}
			else{
				((LightingScene *) scene)->light1_state=true;
				((LightingScene *) scene)->light1->enable();
			}
			break;
		};

		case 102:
		{
			if(	((LightingScene *) scene)->light2_state)
			{
				((LightingScene *) scene)->light2_state=false;
				((LightingScene *) scene)->light2->disable();
			}
			else{
				((LightingScene *) scene)->light2_state=true;
				((LightingScene *) scene)->light2->enable();
			}
			break;
		};

		case 103:
		{
			if(	((LightingScene *) scene)->light3_state)
			{
				((LightingScene *) scene)->light3_state=false;
				((LightingScene *) scene)->light3->disable();
			}
			else{
				((LightingScene *) scene)->light3_state=true;
				((LightingScene *) scene)->light3->enable();
			}
			break;
		};



		case 1:
		{
			printf ("New Val 1(interface): %d\n",testVar);
			break;
		};

		case 2:
		{
			printf ("New Val 2(scene): %d\n",((LightingScene*) scene)->sceneVar);
			break;
		};
	};*/
}

