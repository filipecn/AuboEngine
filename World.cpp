#include "World.h"

namespace engine 
{
	void World::read(boost::property_tree::ptree pt){
		// GRAVITY
		gravity.Set(pt.get<float>("gravity.x"),pt.get<float>("gravity.y"));
	}
	
	void World::init(){
		world = new b2World(gravity);
		


		world->SetDebugDraw(&debugDraw);
		
		Settings* settings = new Settings();
		uint32 flags = 0;

		flags += settings->drawShapes* b2Draw::e_shapeBit;
		flags += settings->drawJoints* b2Draw::e_jointBit;
		flags += settings->drawAABBs* b2Draw::e_aabbBit;
		flags += settings->drawCOMs* b2Draw::e_centerOfMassBit;

		debugDraw.SetFlags(flags);
		
		timeStep = 1.0f / 60.0f;
		velocityIterations = 6;
		positionIterations = 2;
	}

	void World::draw(){
		world->DrawDebugData();
	}

	void World::step(){
		world->Step(timeStep, velocityIterations, positionIterations);
	}

	void World::addObject(Object* o){
		if(!world) 
			init();

		b2BodyDef bodyDef;
		bodyDef.position = o->body.position;
		bodyDef.type = o->body.type;
		bodyDef.angle = o->body.angle;
		bodyDef.userData = o;

		//b2Body *body 
		o->body.pBody = world->CreateBody(&bodyDef);

		for(unsigned int i = 0; i < o->body.fixtures.size(); i++){
			b2FixtureDef fixtureDef;
			b2PolygonShape shape;
			switch(o->body.fixtures[i].type){
				case CIRCLE: break;
				case RECTANGLE: 
					     shape.SetAsBox(o->body.fixtures[i].w,
							     o->body.fixtures[i].h,
							     o->body.fixtures[i].center,
							     o->body.fixtures[i].angle);
					     fixtureDef.shape = &shape;
					     break;
				case POLYGON: break;
				default: break;
			}
			// FIXTURE ATTRIBUTES
			fixtureDef.restitution = o->body.fixtures[i].restitution;
			fixtureDef.friction = o->body.fixtures[i].friction;
			fixtureDef.density = o->body.fixtures[i].density;

			o->body.pBody->CreateFixture(&fixtureDef);
		}
	}
}
