#include "EvaluatorObject.h"
#include <GL/glut.h>


// DECLARACOES RELACIONADAS COM OS "EVALUATORS"
//   aten��o � ordem dos pontos que nao e' circular...
// Coordenadas dos 4 pontos de controlo (podem ser entendidas como
//   sendo as coordenadas dos cantos do pol�gono a visualizar):

GLfloat ctrlpoints[4][3] = {	{  1.0, 1.0, 0.0},
{  1.0, 8.0, 0.0}, 
{ 12.0, 1.0, 0.0},
{ 12.0, 8.0, 0.0} };


GLfloat nrmlcompon[4][3] = {	{  0.0, 0.0, 1.0},
{  0.0, 0.0, 1.0}, 
{  0.0, 0.0, 1.0},
{  0.0, 0.0, 1.0} };

// As cores a atribuir a cada ponto de controlo:
//   Nota: para uma boa percepcao do efeito de iluminacao, �
//         aconselh�vel usar, em alternativa, uma cor cinzenta
GLfloat colorpoints[4][4] = {	{ 0.0, 0.7, 0.7, 0},
{ 0.0, 0.0, 0.7, 0}, 
{ 0.0, 0.7, 0.0, 0},
{ 0.7, 0.0, 0.0, 0} };

GLfloat textpoints[4][2] = {	{ 0.0, 0.0},
{ 0.0, 1.0}, 
{ 1.0, 0.0},
{ 1.0, 1.0} };

EvaluatorObject::EvaluatorObject()
{
	myTexture=new CGFtexture("../data/evaltext.jpg");
}

EvaluatorObject::~EvaluatorObject()
{
	delete(myTexture);
}

void EvaluatorObject::draw(void)
{

	// INICIALIZACOES RELACIONADAS COM OS "EVALUATORS"

	// declaram-se quatro interpoladores, de coordenadas, de
	//     normais, de cores e de texturas:
	// o par�metro de controlo dos interpoladors varia de 0 a 1,
	//     tanto em U como em V
	// os strides (ordem de visita no array de dados final) s�o:
	//     3 e 6 para o interpol. de coord. (respectivamente U e V)
	//     3 e 6 para o interpol. de normais (respectivamente U e V)
	//     4 e 8 para o interpolador de cores (respectivamente U e V)
	//     2 e 4 para o interpolador de texturas (respectivamente U e V)
	// a interpola��o � linear (de grau 1) pelo que se coloca o
	//     valor "2" (grau + 1) nos quatro casos

	glColor3f(1.0,1.0,1.0);
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &ctrlpoints[0][0]);
	glMap2f(GL_MAP2_NORMAL,   0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &nrmlcompon[0][0]);
	glMap2f(GL_MAP2_COLOR_4,  0.0, 1.0, 4, 2,  0.0, 1.0, 8, 2,  &colorpoints[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textpoints[0][0]);

	// os interpoladores activam-se:
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	glEnable(GL_MAP2_COLOR_4);
	glEnable(GL_MAP2_TEXTURE_COORD_2);

	// para este conjunto de interpoladores:
	//    na direccao U, serao efectuadas divisoes em 40 passos
	//        quando a vari�vel U varia de 0 a 1
	//    na direccao V, serao efectuadas divisoes em 60 passos
	//        quando a vari�vel U varia de 0 a 1
	glMapGrid2f(10, 0.0,1.0, 15, 0.0,1.0); 


	// SEGUE-SE EXEMPLO DE UTILIZACAO DE "EVALUATORS"
	//glShadeModel(GL_FLAT);					// GL_FLAT, GL_SMOOTH
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	myTexture->apply();


	glEvalMesh2(GL_FILL, 0,10, 0,15);		// GL_POINT, GL_LINE, GL_FILL
	//glEvalMesh2(GL_FILL, 10,30, 20,40);	// poligono incompleto...
	//glEvalMesh2(GL_FILL, -10,50, -20,70);	// ...ou "transbordante"
	// NOTA: os 4 ultimos parametros da funcao glEvalMesh2() nao sao 
	//		 coordenadas mas sim indices de passos (do passo -10
	//		 ao passo 50; do passo -20 ao passo 70...

	// so' para referencia visual... onde estao os quatro pontos
	// de controlo:


	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < 4; i++)
	{
		glRasterPos3f(ctrlpoints[i][0],ctrlpoints[i][1],ctrlpoints[i][2]+0.5);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0'+i);
	}

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);


}