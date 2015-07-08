#include "GraphicsFramework.h"

namespace engine
{
	GraphicsFramework *GraphicsFramework::gFInstance = 0;
	
	void GraphicsFramework::setInstance(GraphicsFramework *gf){
		gFInstance = gf;
	}

	void GraphicsFramework::_render(){
		gFInstance->render();
	}

	void GraphicsFramework::_resize(int w, int h){
		gFInstance->resize(w,h);
	}

	void GraphicsFramework::_update(){
		gFInstance->update();
	}

	void GraphicsFramework::start(int argc, char *argv[]){
		glutInit(&argc,argv);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

		glutInitWindowSize(400, 400);
		glutCreateWindow("2D Engine");
		glutReshapeFunc(_resize);
		glutDisplayFunc(_render);
		//glutKeyboardFunc(keyboard);
		//glutMouseFunc( mouse );
		
		//init();
		glutIdleFunc(_update);
		glutMainLoop();
	}


	void GraphicsFramework::render(void)
	{

		glClearColor( 1.0, 1.0, 1.0, 0.0 );

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		glFlush();
		glutSwapBuffers();
	}

	void GraphicsFramework::resize(int w, int h)
	{
		W = w;
		H = h;

/*		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		gluPerspective(45.0, w/h, 0, 1000); 

		gluLookAt( 0,0,10,

				0,0,0,

				0,1,0);

		glMatrixMode(GL_MODELVIEW);
*/
	}
/*
	void mouse(int button, int button_state, int x, int y )
	{
		if(button == GLUT_LEFT_BUTTON && button_state == GLUT_UP){
		}
	}

	void keyboard(unsigned char key, int x, int y){

		switch(key){
			case 'q': exit(0);

		}
		glutPostRedisplay();
	}
*/
}
