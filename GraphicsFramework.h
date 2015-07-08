#ifndef GRAPHICSFRAMEWORK_H
#define GRAPHICSFRAMEWORK_H

#include <GL/glut.h>
#include <iostream>

namespace engine 
{
	class GraphicsFramework {
		protected:
			static GraphicsFramework *gFInstance;

			int W, H;
		public:
			static void setInstance(GraphicsFramework *);
			static void _render();
			static void _resize(int,int);
			static void _update();
			//static void _keyboard(unsigned char,int,int);
			
			void start(int, char**);

			virtual void update(){}
			virtual void render();
			virtual void resize(int,int);
			//virtual void keyboard(unsigned char,int,int);
	};
}

#endif
