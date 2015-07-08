#ifndef WORLD_H
#define WORLD_H

#include "Serializable.h"
#include "Object.h"
#include "Box2D/Render.h"

#include <Box2D/Box2D.h>

namespace engine
{
	struct Settings
{
	Settings()
	{
		viewCenter.Set(0.0f, 20.0f);
		hz = 60.0f;
		velocityIterations = 8;
		positionIterations = 3;
		drawShapes = 1;
		drawJoints = 1;
		drawAABBs = 1;
		drawContactPoints = 0;
		drawContactNormals = 0;
		drawContactImpulse = 0;
		drawFrictionImpulse = 0;
		drawCOMs = 0;
		drawStats = 0;
		drawProfile = 0;
		enableWarmStarting = 1;
		enableContinuous = 1;
		enableSubStepping = 0;
		enableSleep = 1;
		pause = 0;
		singleStep = 0;
	}

	b2Vec2 viewCenter;
	float32 hz;
	int32 velocityIterations;
	int32 positionIterations;
	int32 drawShapes;
	int32 drawJoints;
	int32 drawAABBs;
	int32 drawContactPoints;
	int32 drawContactNormals;
	int32 drawContactImpulse;
	int32 drawFrictionImpulse;
	int32 drawCOMs;
	int32 drawStats;
	int32 drawProfile;
	int32 enableWarmStarting;
	int32 enableContinuous;
	int32 enableSubStepping;
	int32 enableSleep;
	int32 pause;
	int32 singleStep;
};

	class World : public Serializable {
		private:
			DebugDraw debugDraw;

			float timeStep;
			int velocityIterations;
			int positionIterations;
		public:
			b2World *world;
			b2Vec2 gravity;

			World(){ world = NULL; }
			~World(){};

			void read(boost::property_tree::ptree);
			
			void init();
			void step();
			void draw();
			void addObject(Object*);
	};
}

#endif
