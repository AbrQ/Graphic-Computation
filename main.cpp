//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Quezada Tapia Abraham		******//
//*************	 Proyecto Final Laboratorio				******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];

#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture img;

CTexture tree;
CTexture edificio;
CTexture esfera;
CTexture pino;
CTexture hoja;
CTexture esf1;
CTexture esf2;
CTexture esf3;
//Texturas de la mesa de ajedrez
CTexture fachada;
CTexture autoUno;
CTexture barrote;
CTexture numDos;
CTexture numOcho;
CTexture naranja;
CTexture pared;
CTexture ventanaB;
CTexture metalB;
CTexture dust;
CTexture roto;
CTexture black;
CTexture ventanal;
CTexture maceta;
CTexture rosas;
CTexture flores;
CTexture vent;
CTexture venta;
CTexture inter;
CTexture medidor;
CTexture blue;
CTexture respaldo;
CTexture yellow;

CFiguras cubo;
CFiguras sky;
CFiguras miobj;
CFiguras fachadaFrente; //Figura para fachada de frente del edificio
CFiguras auto1; //figura de reja y automovil versa
CFiguras num2; //figura del numero 2
CFiguras barrotes;
CFiguras naranjas;
CFiguras paredFachada;
CFiguras ventanaBaja;
CFiguras metalBarrote;
//END NEW//////////////////////////////////////////


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

//Figuras de 3D Studio
CModel kit;
CModel llanta;

void ciudad ()
{

		glPushMatrix(); //Camino1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Camino2
			glTranslatef(-16.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		//CASA DE MUESTRA

		//glPushMatrix(); //Casa01
		//	glTranslatef(0.0,3.0,-7.0);
		//	glRotatef(90,1,0,0);
		//	//glRotatef(180,0,0,1);
		//	glScalef(6,5.0,6);
		//	glDisable(GL_LIGHTING);
		//	fig5.prisma2(text6.GLindex, 0);
		//	glEnable(GL_LIGHTING);
		//glPopMatrix();

		
}



GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	fachada.LoadTGA("fachada.tga");
	fachada.BuildGLTexture();
	fachada.ReleaseImage();

	flores.LoadTGA("flores.tga");
	flores.BuildGLTexture();
	flores.ReleaseImage();

	pared.LoadTGA("pared.tga");
	pared.BuildGLTexture();
	pared.ReleaseImage();

	ventanaB.LoadTGA("ventana.tga");
	ventanaB.BuildGLTexture();
	ventanaB.ReleaseImage();

	roto.LoadTGA("roto.tga");
	roto.BuildGLTexture();
	roto.ReleaseImage();

	autoUno.LoadTGA("auto1.tga");
	autoUno.BuildGLTexture();
	autoUno.ReleaseImage();

	barrote.LoadTGA("barrotes.tga");
	barrote.BuildGLTexture();
	barrote.ReleaseImage();

	maceta.LoadTGA("maceta.tga");
	maceta.BuildGLTexture();
	maceta.ReleaseImage();

	ventanal.LoadTGA("ventanal.tga");
	ventanal.BuildGLTexture();
	ventanal.ReleaseImage();

	yellow.LoadTGA("yellow.tga");
	yellow.BuildGLTexture();
	yellow.ReleaseImage();

	metalB.LoadTGA("met.tga");
	metalB.BuildGLTexture();
	metalB.ReleaseImage();

	dust.LoadTGA("dust.tga");
	dust.BuildGLTexture();
	dust.ReleaseImage();

	naranja.LoadTGA("orange.tga");
	naranja.BuildGLTexture();
	naranja.ReleaseImage();

	inter.LoadTGA("inter.tga");
	inter.BuildGLTexture();
	inter.ReleaseImage();

	numDos.LoadTGA("dos.tga");
	numDos.BuildGLTexture();
	numDos.ReleaseImage();

	numOcho.LoadTGA("ocho.tga");
	numOcho.BuildGLTexture();
	numOcho.ReleaseImage();

	medidor.LoadTGA("medidor.tga");
	medidor.BuildGLTexture();
	medidor.ReleaseImage();

	black.LoadTGA("black.tga");
	black.BuildGLTexture();
	black.ReleaseImage();

	rosas.LoadTGA("rosas.tga");
	rosas.BuildGLTexture();
	rosas.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();


	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	venta.LoadTGA("venta.tga");
	venta.BuildGLTexture();
	venta.ReleaseImage();

	blue.LoadTGA("blue.tga");
	blue.BuildGLTexture();
	blue.ReleaseImage();

	respaldo.LoadTGA("respaldo.tga");
	respaldo.BuildGLTexture();
	respaldo.ReleaseImage();

	edificio.LoadTGA("edificio.tga");
	edificio.BuildGLTexture();
	edificio.ReleaseImage();

	img.LoadTGA("esfera.tga");
	img.BuildGLTexture();
	img.ReleaseImage();

	esfera.LoadTGA("esf.tga");
	esfera.BuildGLTexture();
	esfera.ReleaseImage();

	pino.LoadTGA("wood.tga");
	pino.BuildGLTexture();
	pino.ReleaseImage();

	hoja.LoadTGA("hedge.tga");
	hoja.BuildGLTexture();
	hoja.ReleaseImage();

	esf1.LoadTGA("esf1.tga");
	esf1.BuildGLTexture();
	esf1.ReleaseImage();

	vent.LoadTGA("vent.tga");
	vent.BuildGLTexture();
	vent.ReleaseImage();

	esf2.LoadTGA("esf2.tga");
	esf2.BuildGLTexture();
	esf2.ReleaseImage();

	esf3.LoadTGA("esf3.tga");
	esf3.BuildGLTexture();
	esf3.ReleaseImage();

	//Carga de Figuras
	kit._3dsLoad("kitt.3ds");
	//kit.VertexNormals();

	llanta._3dsLoad("k_rueda.3ds");


	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//CAMINO

		    glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					glCallList(ciudad_display_list);
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();


			//FACHADA DE EDIFICIO

			glPushMatrix();
			//FACHADA DE LA ESQUINA IZQ Y REFERENCIA!!
			glTranslatef(0.0,3.0,-5.0);
			glScalef(1.0,0.7,1.0);
			fachadaFrente.prisma(10,0.25,1,fachada.GLindex);

			//FACHADA IZQ PUERTA
			glPushMatrix();
			glTranslatef(10.0, 0.0, 0.0);
			fachadaFrente.prisma(10, 1.5, 1, fachada.GLindex);

			//NUMERO 28 PENDIENTE DE FOTO!
			glPushMatrix();
			glTranslatef(-0.55, 3.0, 0.3);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER,0.1f);
			num2.prisma(1, 0.3, 0.5, numDos.GLindex);
			glTranslatef(0.4, -0.5, 0.0);
			miobj.prisma(1, 0.3, 0.5, numOcho.GLindex);
			glDisable(GL_ALPHA_TEST);
			//INTERFON
			glTranslatef(0.5,-2,0);
			miobj.prisma(1.0, 0.5, 0.5, inter.GLindex);
			glPopMatrix();

			//MEDIDORES DE LUZ
			glPushMatrix();
			glTranslatef(14.0, 3.0, 0.27);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.prisma(0.2, 0.2, 0.5, medidor.GLindex);
			glTranslatef(0,-0.3,0);
			miobj.prisma(0.2, 0.2, 0.5, medidor.GLindex);
			glTranslatef(0, -0.3, 0);
			miobj.prisma(0.2, 0.2, 0.5, medidor.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			//MARCO DE LOS BARROTES DE PUERTA CON CILINDRO
			glTranslatef(1,-5,0);
			barrotes.cilindro(0.10,9.5,30,barrote.GLindex);
			//BARROTES HORIZONTALES
			glPushMatrix();
			glRotatef(90,0,0,1);
			glTranslatef(0.50, -2.6, 0);
			glScalef(1,0.28,1);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.2, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glPopMatrix();
			//BARROTES VERTICALES
			glTranslatef(0.90, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(0.90, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(0.90, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			
			glPopMatrix();


			//FACHADA DER PUERTA
			glPushMatrix();
			glTranslatef(14.0, 0.0, 0.0);
			fachadaFrente.prisma(10, 0.25, 1, fachada.GLindex);
			glPopMatrix();

			//FACHADA DE LA ESQ DERECHA 
			glPushMatrix();
			glTranslatef(24.0, 0.0, 0.0);
			fachadaFrente.prisma(11, 0.25, 1, fachada.GLindex);
			glPopMatrix();

			//TECHITO DEL PRIMER ESTACIONAMIENTO
			glPushMatrix();
			glTranslatef(4.6,5.3,0.0);
			fachadaFrente.prisma(0.5, 9.4, 1, fachada.GLindex);

			//ESCAPE NARANJA DEL PRIMER TECHO
			glTranslatef(0.0, 0.4, 0.50);
			glRotatef(-45,1,0,0);
			naranjas.prisma(0.35, 9.4, 0.30, naranja.GLindex);
			
			glPopMatrix();

			//TECHITO DE LA PUERTA
			glPushMatrix();
			glTranslatef(11.8,5.3,1.0);
			fachadaFrente.prisma(0.6,5,3,fachada.GLindex);
			

			//TECHITO DEL SEGUNDO ESTACIONAMIENTO
			glTranslatef(7.2,0.5,-1.0);
			fachadaFrente.prisma(0.5, 10.2, 1, fachada.GLindex);

			//BARROTES DEL SEGUNDO ESTACIONAMIENTO PARTE DE ARRIBA
			//BARROTES HORIZONTALES
			glPushMatrix();
			glRotatef(90,0,0,1);
			glTranslatef(-0.90, -4.8, 0.0);
			barrotes.cilindro(0.10, 9.6, 30, barrote.GLindex);
			glTranslatef(0.3, 0, 0.0);
			barrotes.cilindro(0.05, 9.6, 30, barrote.GLindex);
			glPopMatrix();
			//BARROTES VERTICALES
			glTranslatef(-4.0, -1, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			glTranslatef(1, 0, 0.0);
			barrotes.cilindro(0.06, 1, 30, barrote.GLindex);
			
			glPopMatrix();

			//PRIMER REJA CON AUTOMOVIL VERSA
			glTranslatef(5.0,0.0,0.0);
			glPushMatrix();
			//MARCO DE LOS BARROTES DE PUERTA CON CILINDRO
			glTranslatef(-4.6, -4.4, 0);
			glScalef(3.2, 0.93, 1);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			//BARROTES HORIZONTALES
			glPushMatrix();
			glRotatef(90, 0, 0, 1);
			glTranslatef(0.50, -2.6, 0);
			glScalef(1, 0.28, 1);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.2, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glPopMatrix();
			//BARROTES VERTICALES
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.28, 0, 0);
			barrotes.cilindro(0.065, 9.5, 30, barrote.GLindex);
			glPopMatrix();
			//auto1.prisma(10, 9.6, 0.5, autoUno.GLindex);


			//ESCAPE NARANJA DEL TECHO DE ENMEDIO
			glPushMatrix();
			glTranslatef(6.8, 5.8, 2.50);
			glRotatef(-45, 1, 0, 0);
			naranjas.prisma(0.35, 5.3, 0.30, naranja.GLindex);
			glPopMatrix();

			//ESCAPE NARANJA DEL TECHO DEL SEGUNDO ESTACIONAMIENTO
			glPushMatrix();
			glTranslatef(13.95, 6.3, 0.5);
			glRotatef(-45, 1, 0, 0);
			naranjas.prisma(0.35, 10.5, 0.30, naranja.GLindex);
			glPopMatrix();
			glPopMatrix();

			//BARROTES DEL SEGUNDO ESTACIONAMIENTO
			glPushMatrix();
			//MARCO DE LOS BARROTES DE PUERTA CON CILINDRO
			glTranslatef(14.2, 0, -4.8);
			glScalef(3.5,0.64,1);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			//BARROTES HORIZONTALES
			glPushMatrix();
			glRotatef(90, 0, 0, 1);
			glTranslatef(0.50, -2.6, 0);
			glScalef(1, 0.28, 1);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.1, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glTranslatef(1.2, 0, 0);
			barrotes.cilindro(0.10, 9.5, 30, barrote.GLindex);
			glPopMatrix();
			//BARROTES VERTICALES
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.26, 0, 0);
			barrotes.cilindro(0.02, 9.5, 30, barrote.GLindex);
			glTranslatef(0.28, 0, 0);
			barrotes.cilindro(0.065, 9.5, 30, barrote.GLindex);
			glPopMatrix();


			//COCHECITO DEL SEGUNDO ESTACIONAMIENTO

			glPushMatrix();
			//Para que el coche conserve sus colores
			glDisable(GL_COLOR_MATERIAL);
			glRotatef(90, 0, 1, 0);
			glScalef(0.3, 0.4, 0.3);



			glTranslatef(35, 0, 63);
			glRotatef(270,0,1,0);
			//Pongo aquí la carroceria del carro PARA CARGAR EN ESCENA
			kit.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
											   //PRIMER LLANTA PAPU
			glPushMatrix();
			glTranslatef(-6, -1, 7.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			//SEGUNDA LLANTA PAPU
			glPushMatrix();
			glTranslatef(6, -1, 7.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
			glRotatef(180, 0, 1, 0);
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			//TERCERA LLANTA PAPU
			glPushMatrix();
			glTranslatef(-6, -1, -9.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
									 //glRotatef(180, 0, 1, 0);
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			//CUARTA LLANTA PAPU
			glPushMatrix();
			glTranslatef(6, -1, -9.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
			glRotatef(180, 0, 1, 0);
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPopMatrix();
			

			//COCHECITO DEL PRIMER ESTACIONAMIENTO

			glPushMatrix();
			//Para que el coche conserve sus colores
			glDisable(GL_COLOR_MATERIAL);
			glRotatef(90, 0, 1, 0);
			glScalef(0.3, 0.4, 0.3);
			glTranslatef(36, 0, 15);
			glRotatef(270, 0, 1, 0);
			//Pongo aquí la carroceria del carro PARA CARGAR EN ESCENA
			kit.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
			glPushMatrix();
			glTranslatef(-6, -1, 7.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			//SEGUNDA LLANTA PAPU
			glPushMatrix();
			glTranslatef(6, -1, 7.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
			glRotatef(180, 0, 1, 0);
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			//TERCERA LLANTA PAPU
			glPushMatrix();
			glTranslatef(-6, -1, -9.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
			//glRotatef(180, 0, 1, 0);
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			//CUARTA LLANTA PAPU
			glPushMatrix();
			glTranslatef(6, -1, -9.5);
			//glRotatef(rot, 1, 0, 0); //PIVOTEEEEEE
			glRotatef(180, 0, 1, 0);
			llanta.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPopMatrix();


			//EDIFICIO SECCION DE LA DERECHA!!!!!!!
			glPushMatrix();
			glTranslatef(19,18,-33);
			glDisable(GL_LIGHTING);
			paredFachada.prisma(40.0f, 14.0f, 30, pared.GLindex);
			//glEnable(GL_LIGHTING);

			//PARED DE LA DERECHA
			glPushMatrix();
			glTranslatef(6, -15.6, 21);
			paredFachada.prisma(9.5f, 1.7f, 13, pared.GLindex);
			glPopMatrix();

			//VENTANA BAJA
			glPushMatrix();
			glTranslatef(0,-12,15);
			ventanaBaja.prisma(7,7,0.5,ventanaB.GLindex);

			//BARROTES DE LA VENTANA
			glTranslatef(-3.3, -3.5, 0.3);
			glScalef(2.5, 0.75, 1);
			//glDisable(GL_COLOR_MATERIAL);
			//glColor3f(0.5,0.5,0.5);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			//BARROTES HORIZONTALES
			glPushMatrix();
			glRotatef(90, 0, 0, 1);
			glTranslatef(0.50, -2.6, 0);
			glScalef(1, 0.28, 1);
			glTranslatef(1.2, 0, 0);
			
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(1.1, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(1.1, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(1.1, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(1.1, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(1.1, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(1.1, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(1.1, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glTranslatef(-9.3, 0, 0);
			metalBarrote.cilindro(0.10, 9.5, 30, metalB.GLindex);
			glPopMatrix();
			//BARROTES VERTICALES
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.26, 0, 0);
			metalBarrote.cilindro(0.02, 9.5, 30, metalB.GLindex);
			glTranslatef(0.28, 0, 0);
			metalBarrote.cilindro(0.065, 9.5,30, metalB.GLindex);
			//glEnable(GL_COLOR_MATERIAL);
			glPopMatrix();

			//VENTANA MEDIA SECCION DERECHA
			glPushMatrix();
			glTranslatef(0, 0, 15);
			ventanaBaja.prisma(7, 7, 0.5, ventanaB.GLindex);
			glPopMatrix();

			//VENTANA ALTA SECCION DERECHA
			glPushMatrix();
			glTranslatef(0, 13, 15);
			ventanaBaja.prisma(7, 7, 0.5, ventanaB.GLindex);
			glPopMatrix();


			//EDIFICIO SECCION IZQUIERDA
			glPushMatrix();
			glTranslatef(-13.8, 19.3, 5);
			//glDisable(GL_LIGHTING);
			paredFachada.prisma(1.5f, 14.0f, 40, pared.GLindex);
			glPopMatrix();

			//PARED IZQUIERDAAAAAAA ALTA
			glPushMatrix();
			glTranslatef(-20.5, 4.6, 4.9);
			paredFachada.prisma(27.8f, 0.7f, 40, pared.GLindex);

			//PARED IZQUIERDA BAJAAAAA
			glTranslatef(0.0, -19.3, 1.8);
			paredFachada.prisma(10.8f, 0.7f, 43.3, pared.GLindex);
			glPopMatrix();
			
			//PARED DE ENFRENTE
			glPushMatrix();
			glTranslatef(-13.5, 5.0, 24.0);
			paredFachada.prisma(28.3f, 13.7f, 0.7, pared.GLindex);
			glPopMatrix();

			//PARED TRASERA
			glPushMatrix();
			glTranslatef(-10, 0, -14);
			paredFachada.prisma(40.0f, 20.0f, 1.0, pared.GLindex);
			glPopMatrix();

			//PARED INTERNA
			glPushMatrix();
			glTranslatef(-7.0, 0, 19);
			paredFachada.prisma(40.0f, 1.0f, 10.0, pared.GLindex);
			glPopMatrix();


			//CUBO DE ARRIBA DEL EDIFICIO SECCION IZQUIERDAA
			glPushMatrix();
			glTranslatef(-9.2, 23, 5);
			paredFachada.prisma(7.0f, 5.0f, 40, pared.GLindex);

			//CUBO DE HASTA ARRIBA CON EL ROTOPLAS
			glTranslatef(0, 7, 0);
			paredFachada.prisma(7.0f, 5.0f, 5, pared.GLindex);

			//ROTOPLAS
			glTranslatef(0, 5, 0);
			miobj.prisma(3.0f, 3.0f, 3, roto.GLindex);
			glTranslatef(0, 1.5, 0);
			miobj.cilindro(1.0f, 2.0f, 30, black.GLindex);
	
			glPopMatrix();

			//VENTANAL BAJO
			glPushMatrix();
			glTranslatef(-15.5, -3, 24);
			glPushMatrix();
			glRotatef(180,0,0,1);
			glPopMatrix();
			miobj.prisma(10, 6.5, 1.0, ventanal.GLindex);
			//PISO DEL BALCON BAJO
			glPushMatrix();
			glTranslatef(0,-4.8,2);
			paredFachada.prisma(0.4f, 6.5f, 3.0, pared.GLindex);
			//ESCAPE DEL PISO DEL BALCON BAJO
			glTranslatef(0,0,1.5);
			glPushMatrix();
			glRotatef(20,1,0,0);
			glPopMatrix();
			naranjas.prisma(0.8, 6.8, 0.30, naranja.GLindex);
			//ESCAPE DEL PISO DEL BALCON BAJO PARTE IZQUIERDA
			glPushMatrix();
			glTranslatef(-3.3,0,-1.6);
			glRotatef(90,0,1,0);
			naranjas.prisma(0.8, 2.9, 0.30, naranja.GLindex);
			glPopMatrix();
			//ESCAPE DEL PISO DEL BALCON BAJO PARTE DERECHA
			glPushMatrix();
			glTranslatef(3.3, 0, -1.6);
			glRotatef(90, 0, 1, 0);
			naranjas.prisma(0.8, 2.9, 0.30, naranja.GLindex);
			glPopMatrix();
			glPopMatrix();


			//VENTANAL ALTO
			glPushMatrix();
			glTranslatef(0, 15, 0);
			//glRotatef(180, 0, 0, 1);
			miobj.prisma(10, 6.5, 1.0, ventanal.GLindex);
			//PISO DEL BALCON ALTO
			glPushMatrix();
			glTranslatef(0, -4.8, 2);
			paredFachada.prisma(0.4f, 6.5f, 3.0, pared.GLindex);
			//ESCAPE DEL PISO DEL BALCON ALTO
			glTranslatef(0, 0, 1.5);
			glPushMatrix();
			glRotatef(20, 1, 0, 0);
			glPopMatrix();
			naranjas.prisma(0.8, 6.8, 0.30, naranja.GLindex);
			//ESCAPE DEL PISO DEL BALCON ALTO PARTE IZQUIERDA
			glPushMatrix();
			glTranslatef(-3.3, 0, -1.6);
			glRotatef(90, 0, 1, 0);
			naranjas.prisma(0.8, 2.9, 0.30, naranja.GLindex);
			glPopMatrix();
			//ESCAPE DEL PISO DEL BALCON ALTO PARTE DERECHA
			glPushMatrix();
			glTranslatef(3.3, 0, -1.6);
			glRotatef(90, 0, 1, 0);
			naranjas.prisma(0.8, 2.9, 0.30, naranja.GLindex);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();


			glPopMatrix(); //FIN DE JERARQUIA DE BALCONES

			//BARROTES DE BALCON BAJO
			//BARROTES VERTICALES
			glPushMatrix();
			glTranslatef(-12.2, -5.65, 24.7);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glPushMatrix();
			glTranslatef(0, -0.75, 1.4);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIOZNTAL
			glTranslatef(0,1,0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIOZNTAL
			glTranslatef(0, 1.35, 0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			glPopMatrix();
			glTranslatef(0,0,2.8);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glPushMatrix();
			glTranslatef(-3.3, -0.75, 0);
			metalBarrote.prisma(0.25, 6.5, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1, 0);
			metalBarrote.prisma(0.25, 6.5, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1.35, 0);
			metalBarrote.prisma(0.25, 6.5, 0.25, metalB.GLindex);
			glPopMatrix();
			glTranslatef(-3.4, 0, 0);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			glTranslatef(-3.2, 0, 0);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glPushMatrix();
			glTranslatef(0, -0.75, -1.4);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1, 0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1.35, 0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//glPopMatrix();
			glPopMatrix();
			glTranslatef(0, 0, -2.8);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);


			//glPushMatrix();
			//BARROTES DE BALCON ALTO
			//BARROTES VERTICALES
			glPushMatrix();
			glTranslatef(6.6, 15, 0);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glPushMatrix();
			glTranslatef(0, -0.75, 1.4);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIOZNTAL
			glTranslatef(0, 1, 0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIOZNTAL
			glTranslatef(0, 1.35, 0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			glPopMatrix();
			glTranslatef(0, 0, 2.8);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glPushMatrix();
			glTranslatef(-3.3, -0.75, 0);
			metalBarrote.prisma(0.25, 6.5, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1, 0);
			metalBarrote.prisma(0.25, 6.5, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1.35, 0);
			metalBarrote.prisma(0.25, 6.5, 0.25, metalB.GLindex);
			glPopMatrix();
			glTranslatef(-3.4, 0, 0);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			glTranslatef(-3.2, 0, 0);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			//BARROTE HORIZONTAL
			glPushMatrix();
			glTranslatef(0, -0.75, -1.4);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1, 0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//BARROTE HORIZONTAL
			glTranslatef(0, 1.35, 0);
			metalBarrote.prisma(0.25, 0.25, 2.55, metalB.GLindex);
			//glPopMatrix();
			glTranslatef(0, -1.6, -1.15);
			metalBarrote.prisma(3.5, 0.25, 0.25, metalB.GLindex);
			glPopMatrix();
			
			glPopMatrix();
			glPopMatrix();

			//glPopMatrix(); //FIN DE BARROTES DE BALCONES

			//MACETASSSS

			//MACETA DEL BALCON BAJO
			glPushMatrix();
			glTranslatef(-17, -7.9, 26);
			miobj.cilindro(1, 2, 30, maceta.GLindex);

			//ARO 
			glPushMatrix();
			glTranslatef(0, 2, 0);
			miobj.cilindro(1.3, 0.2, 30, maceta.GLindex);
			glPopMatrix();

			// TRONCO DE MACETA
			glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(20,0,0,1);
			miobj.cilindro(0.15, 3, 30, pino.GLindex);

			//OTRA RAMA
			glPushMatrix();
			glTranslatef(0, 1, 0);
			glRotatef(-60, 0, 0, 1);
			miobj.cilindro(0.15, 2, 30, pino.GLindex);
			//FLORES
			glTranslatef(0,2,0);
			miobj.esfera(.9, 10, 10, flores.GLindex);
			glTranslatef(-1.5, 0.5, 0);
			miobj.esfera(1.1, 10, 10, flores.GLindex);
			glPopMatrix();

			//Flores
			glPushMatrix();
			glTranslatef(0,3,0);
			miobj.esfera(1.3, 10, 10, flores.GLindex);
			glPopMatrix();

			//LA SILLA AZUL DE LOLITA
			//primer para pivote delantera
			glPushMatrix();
			glTranslatef(2.0,-1,-0.8);
			glRotatef(-20,0,0,1);
			miobj.prisma(2.4,0.15,0.15,blue.GLindex);
			//SEGUNDA PATA DELANTERA
			glTranslatef(0,0,1.6);
			miobj.prisma(2.4, 0.15, 0.15, blue.GLindex);
			//TERCERA PATA TRACERA
			glTranslatef(1.5, 0, 0);
			miobj.prisma(2.4, 0.15, 0.15, blue.GLindex);
			//CUARTA PATA TRACERA
			glTranslatef(0, 0, -1.6);
			miobj.prisma(2.4, 0.15, 0.15, blue.GLindex);
			//ASIENTO
			glTranslatef(-.8, 1.1, 0.8);
			miobj.prisma(0.15, 1.8, 1.8, blue.GLindex);

			//RESPALDO
			glTranslatef(.9, 0.95, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.prisma(2.1, 0.05, 1.8, respaldo.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			glPopMatrix();


			//MACETA DEL BALCON ARRIBAAAAAA
			glPushMatrix();
			glTranslatef(0, 15, 0);
			miobj.cilindro(1, 2, 30, maceta.GLindex);

			//ARO 
			glPushMatrix();
			glTranslatef(0, 2, 0);
			miobj.cilindro(1.3, 0.2, 30, maceta.GLindex);
			glPopMatrix();

			// TRONCO DE MACETA
			glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(20, 0, 0, 1);
			miobj.cilindro(0.15, 3, 30, pino.GLindex);

			//OTRA RAMA
			glPushMatrix();
			glTranslatef(0, 1, 0);
			glRotatef(-60, 0, 0, 1);
			miobj.cilindro(0.15, 2, 30, pino.GLindex);
			//FLORES
			glTranslatef(0, 2, 0);
			miobj.esfera(.9, 10, 10, rosas.GLindex);
			glTranslatef(-1.5, 0.5, 0);
			miobj.esfera(1.1, 10, 10, rosas.GLindex);
			glPopMatrix();

			//Flores
			glPushMatrix();
			glTranslatef(0, 3, 0);
			miobj.esfera(1.3, 10, 10, rosas.GLindex);
			glPopMatrix();

			glPopMatrix();

			glPopMatrix();
			glPopMatrix();


			//VENTANAS DE LA CARA DERECHA DEL EDIFICIO
			glPushMatrix();
			glTranslatef(-6.6,-12,17);
			glRotatef(90,0,1,0);
			miobj.prisma(4, 2, 0.25, vent.GLindex);

			glPushMatrix();
			glTranslatef(-5, 0, 0);
			miobj.prisma(4, 2, 0.25, vent.GLindex);

			//VENTANA MEDIA
			glTranslatef(0, 12, 1);
			glRotatef(-30,0,1,0);
			miobj.prisma(4, 2, 0.25, venta.GLindex);


			glPushMatrix();
			//VENTANA MEDIA
			glTranslatef(4, 0, -3);
			glRotatef(30, 0, 1, 0);
			miobj.prisma(4, 2, 0.25, venta.GLindex);

			//VENTANA ALTA
			glTranslatef(0, 12, 0);
			//glRotatef(30, 0, 1, 0);
			miobj.prisma(4, 2, 0.25, venta.GLindex);

			//VENTANA ALTA
			glTranslatef(-5, 0, 0);
			glRotatef(-50, 0, 1, 0);
			miobj.prisma(4, 2, 0.25, venta.GLindex);

			glPopMatrix();

			glPopMatrix();
			glPopMatrix();


			//FOCO!
			glPushMatrix();
			glTranslatef(-15, 18, 24.7);
			miobj.esfera(0.2, 20, 20, yellow.GLindex);
			//BASE DEL FOCO
			glTranslatef(0, 0.5, 0);
			glRotatef(180,1,0,0);
			miobj.cono(0.5, 0.3, 20, black.GLindex);
			glPopMatrix();


			glPopMatrix();


			//glPushMatrix(); //Flecha
			//	glScalef(7,0.1,7);
			//	glDisable(GL_LIGHTING);
			//	fig3.prisma_anun(img.GLindex, 0); //ESFERA DEL DRAGON PRRO!!!!
			//	glEnable(GL_LIGHTING);
			//glPopMatrix();

			//glEnable ( GL_COLOR_MATERIAL );
			/*glPushMatrix();
				glTranslatef(-30, 0, 10);
				arbol();
			glPopMatrix();*/

			//ESFERA DEL PUMAAAA
			/*glPushMatrix();
				glTranslatef(17, 0, -10);
				glColor3f(1.0, 1.0, 1.0);
				fig1.esfera(4, 20, 20, text2.GLindex);
			glPopMatrix();*/

			//glPushMatrix();
			////miobj.cilindro(5.0f,10.0f,20,img.GLindex);
			////miobj.cono(10,5,20,img.GLindex);
			////AÑADIR CANAL ALFAAAAAAAAAAAAAAAAAAAAAAAAAAA
			///*glEnable(GL_ALPHA_TEST);
			//glAlphaFunc(GL_GREATER,0.1f);
			//glColor3f(1,0,0);
			//miobj.esfera(5, 20, 20, esfera.GLindex);
			//glDisable(GL_ALPHA_TEST);*/

			

			

			glColor3f(1.0,1.0,1.0);

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	
		fig3.text_izq-= 0.001;
		fig3.text_der-= 0.001;
		if(fig3.text_izq<-1)
			fig3.text_izq=0;
		if(fig3.text_der<0)
			fig3.text_der=1;


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (700, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("PROYECTO"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
