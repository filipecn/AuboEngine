# Hello World examples
include_directories (${OPENGL_INCLUDE_DIR}
		     ${Box2D_SOURCE_DIR}
)

set(OPENGL_LIBRARIES GL GLU glut X11)

set(SRCS
	Constants.h
	Utils.cpp
	Utils.h
	Common.h
	Common.cpp
	Serializable.cpp
	Serializable.h
	GraphicsFramework.cpp
	GraphicsFramework.h
	Camera.cpp
	Camera.h
	Box2D/Render.cpp
	Box2D/Render.h
	World.cpp
	World.h
	Fixture.cpp
	Fixture.h
	Body.cpp
	Body.h
	Object.h
	SceneryObject.cpp
	SceneryObject.h
	SceneObject.cpp
	SceneObject.h
	Actor.cpp
	Actor.h
	GameState.h
	Game.cpp
	Game.h
	Level.cpp
	Level.h
	)

add_executable(main main.cpp ${SRCS})
target_link_libraries (main Box2D ${OPENGL_LIBRARIES})
