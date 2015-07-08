#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>

#include "Serializable.h"
#include "Utils.h"

namespace engine
{
	class Camera : Serializable {
		private:
			bool _2D;
			utils::Vec3<double> pos;
			utils::Vec3<double> lookPoint;
			utils::Vec3<double> up;
			double radius;
			double zoom;
		public:
			Camera();
			
			void init();

			void setOrthographicProjection(double,double,double,double);
			void lookAt(double,double);
			void look();
			
			void read(boost::property_tree::ptree);
	};
}

#endif

