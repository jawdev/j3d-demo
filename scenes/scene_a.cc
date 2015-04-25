/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /scenes/scene_a.cc
******************************************************************************/
#include "scenes.h"

SceneA::SceneA() {
	mp_shaderProgram = nullptr;
}

void SceneA::load() {
	glClearColor( 1, 0, 1, 1 );
	mp_shaderProgram = new j3d::ShaderProgram;
	mp_shaderProgram->addFragmentShader( "assets/shaders/default.fs" );
	mp_shaderProgram->addVertexShader( "assets/shaders/default.vs" );
	mp_shaderProgram->link( { "m4_camera", "m4_model", "v4_color" } );
}

void SceneA::unload() {
	SAFE_DELETE( mp_shaderProgram );
	glClearColor( 0, 0, 0, 1 );
}

void SceneA::update( float dtime ) {
}
