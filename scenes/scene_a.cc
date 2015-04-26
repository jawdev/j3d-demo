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
	ang = M_PI/2.0f;
	counter = time_agg = 0;
}

void SceneA::load() {
	glClearColor( 0.1f, 0.1f, 0.1f, 1 );

	mp_shaderProgram = new j3d::ShaderProgram;
	mp_shaderProgram->addFragmentShader( "assets/shaders/default.fs" );
	mp_shaderProgram->addVertexShader( "assets/shaders/default.vs" );
	mp_shaderProgram->link( { "m4_camera", "m4_model", "v4_color" } );

	mp_camera = new j3d::Camera();
	mp_camera->position( j3d::vec3( 0, 2, 5 ) );

	j3d::Engine::loadMesh( "box", new j3d::BoxMesh() );
	j3d::Engine::loadMesh( "floor", new j3d::FloorMesh( 10 ) );

	unsigned int iter = 0;
	unsigned int max = 2000;
	unsigned int per = 5;
	float dist = 0;
	float r;
	for( unsigned int i = 0; i < max; i++ ) {
		r = (float)( iter%per )/(float)per;
		if( iter%per == 0 ) {
			iter = 0;
			dist += 2;
			per += 5;
		}
		j3d::Object* o = new j3d::Object( "box", j3d::vec4( r, 0, 1-r, 1 ) );
		o->position( j3d::vec3( dist*cos( r*2.0f*M_PI ), 0, dist*sin( r*2.0f*M_PI ) ) );
		m_cubes.push_back( o );
		iter++;
	}
	
}

void SceneA::unload() {
	for( unsigned int i = 0; i < m_cubes.size(); i++ ) SAFE_DELETE( m_cubes[i] );
	SAFE_DELETE( mp_camera );
	SAFE_DELETE( mp_shaderProgram );
	glClearColor( 0, 0, 0, 1 );
}

void SceneA::update( float dtime ) {
	if( j3d::trigger::reshape ) mp_camera->reshape();

	for( unsigned int i = 0; i < m_cubes.size(); i++ ) {
		mp_shaderProgram->bind( "v4_color", m_cubes[i]->color() );
		mp_shaderProgram->bind( "m4_model", m_cubes[i]->transform() );
		m_cubes[i]->render();
	}

	mp_camera->position( j3d::vec3( 20.0f*cos( ang ), 12.0f, 20.0f*sin( ang ) ) );
	mp_camera->look( j3d::vec3() );
	mp_shaderProgram->bind( "m4_camera", mp_camera->transform() );

	ang += dtime/2.0f;
	counter += 1;
	time_agg += dtime;
	if( ang >= 2.0*M_PI ) ang = 0;
	if( time_agg >= 1 ) {
		cout << (int)( counter/time_agg ) << endl;
		counter = 0;
		time_agg = 0;
	}
}
