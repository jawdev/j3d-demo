/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /scenes/scene_a.cc
******************************************************************************/
#include "scenes.h"

SceneA::SceneA() {
	mp_shaderProgram = nullptr;
	mp_camera = nullptr;
	mp_object = nullptr;
}

void SceneA::load() {
	glClearColor( 0.1f, 0.1f, 0.1f, 1 );

	mp_shaderProgram = new j3d::ShaderProgram;
	mp_shaderProgram->addFragmentShader( "assets/shaders/default.fs" );
	mp_shaderProgram->addVertexShader( "assets/shaders/default.vs" );
	mp_shaderProgram->link( { "m4_camera", "m4_model", "v4_color" } );

	mp_camera = new j3d::Camera();
	mp_camera->position( j3d::vec3( 0, 2, 5 ) );
	mp_camera->look( j3d::vec3( 0, 0, 0 ) );
	mp_shaderProgram->bind( "m4_camera", mp_camera->transform() );

	j3d::Engine::loadMesh( "box", new j3d::BoxMesh() );
	j3d::Engine::loadMesh( "floor", new j3d::FloorMesh( 10 ) );

	mp_object = new j3d::Object( "box", j3d::vec4( 0, 0, 1, 1 ) );
	mp_object->position( j3d::vec3( -2, 0, 0 ) );
	mp_object->spin( j3d::vec3( 0, 1, 0 ) );

	mp_object2 = new j3d::Object( "box", j3d::vec4( 0, 1, 0, 1 ) );
	mp_object2->position( j3d::vec3( 2, 0, 0 ) );
	mp_object2->spin( j3d::vec3( 0, -1, 0 ) );
	
}

void SceneA::unload() {
	SAFE_DELETE( mp_object );
	SAFE_DELETE( mp_object2 );
	SAFE_DELETE( mp_camera );
	SAFE_DELETE( mp_shaderProgram );
	glClearColor( 0, 0, 0, 1 );
}

void SceneA::update( float dtime ) {
	if( j3d::trigger::reshape ) {
		mp_camera->reshape();
		mp_shaderProgram->bind( "m4_camera", mp_camera->transform() );
	}

	mp_object->update( dtime );
	mp_object2->update( dtime );

	mp_shaderProgram->bind( "v4_color", mp_object->color() );
	mp_shaderProgram->bind( "m4_model", mp_object->transform() );
	mp_object->render();

	mp_shaderProgram->bind( "v4_color", mp_object2->color() );
	mp_shaderProgram->bind( "m4_model", mp_object2->transform() );
	mp_object2->render();
}
