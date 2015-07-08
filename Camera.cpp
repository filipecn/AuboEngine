#include "Camera.h"

namespace engine
{
	Camera::Camera(){}

	void setOrthographicProjection(double xmin, double xmax, double ymin, double ymax){
		
	}

	void Camera::lookAt(double x, double y){
		lookPoint.x = x;
		lookPoint.y = y;

		double r = (1.0/zoom)*radius/2.0;
		gluOrtho2D(lookPoint.x-r,lookPoint.x+r,lookPoint.y-r,lookPoint.y+r);
	}

	void Camera::look(){
		double r = (1.0/zoom)*radius/2.0;
		gluOrtho2D(lookPoint.x-r,lookPoint.x+r,lookPoint.y-r,lookPoint.y+r);
	}

	void Camera::read(boost::property_tree::ptree pt){
		using boost::property_tree::ptree;

		_2D = pt.get<bool>("<xmlattr>._2D");	
		// LOOK
		lookPoint.x = pt.get<double>("look.x");
		lookPoint.y = pt.get<double>("look.y");
		if(!_2D)
			lookPoint.z = pt.get<double>("look.z");
		// POS
		if(!_2D){
			// UP
			// POS
		}
		
		// RADIUS
		radius = pt.get<double>("radius");
		// ZOOM
		zoom = pt.get<double>("zoom");
	}

	void Camera::init(){
		
		glMatrixMode(GL_PROJECTION);
		
		glLoadIdentity();

		if(_2D){
			double r = (1.0/zoom)*radius/2.0;
			gluOrtho2D(lookPoint.x-r,lookPoint.x+r,lookPoint.y-r,lookPoint.y+r);
		}
		else{
		
		}

		glMatrixMode(GL_MODELVIEW);
	}

}
