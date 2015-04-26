/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /scenes/scene_test.cc
******************************************************************************/
#include "inc.h"

SceneTest::SceneTest() {
	mp_shaderProgram = nullptr;
	mp_camera = nullptr;
	move_x = move_z = 0;
	counter = time_agg = 0;
}

void SceneTest::load() {
	glClearColor( 0.1f, 0.1f, 0.1f, 1 );

	mp_shaderProgram = new j3d::ShaderProgram;
	mp_shaderProgram->addFragmentShader( "assets/shaders/default.fs" );
	mp_shaderProgram->addVertexShader( "assets/shaders/default.vs" );
	mp_shaderProgram->link( { "m4_camera", "m4_model", "v4_color" } );

	mp_camera = new j3d::Camera();
	mp_camera->position( j3d::vec3( 0, 12, 20 ) );

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

void SceneTest::unload() {
	for( unsigned int i = 0; i < m_cubes.size(); i++ ) SAFE_DELETE( m_cubes[i] );
	SAFE_DELETE( mp_camera );
	SAFE_DELETE( mp_shaderProgram );
	glClearColor( 0, 0, 0, 1 );
}

void SceneTest::update( float dtime ) {
	if( j3d::trigger::reshape ) mp_camera->reshape();

	for( unsigned int i = 0; i < m_cubes.size(); i++ ) {
		mp_shaderProgram->bind( "v4_color", m_cubes[i]->color() );
		mp_shaderProgram->bind( "m4_model", m_cubes[i]->transform() );
		m_cubes[i]->render();
	}
	
	mp_camera->move( j3d::vec3( 2*move_x*dtime, 0, 2*move_z*dtime ) );
	mp_camera->look( j3d::vec3() );
	mp_shaderProgram->bind( "m4_camera", mp_camera->transform() );

	counter += 1;
	time_agg += dtime;
	if( time_agg >= 1 ) {
		cout << (int)( counter/time_agg ) << endl;
		counter = 0;
		time_agg = 0;
	}
}

void SceneTest::onKeyDown( unsigned char key ) {
	move_x = ( j3d::Control::keyDown( 'a' ) ? -1 : 0 );
	move_x += ( j3d::Control::keyDown( 'd' ) ? 1 : 0 );
	move_z = ( j3d::Control::keyDown( 'w' ) ? -1 : 0 );
	move_z += ( j3d::Control::keyDown( 's' ) ? 1 : 0 );
}
