/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /scene_test.h
******************************************************************************/
#ifndef J3D_DEMO_SCENE_TEST_H_
#define J3D_DEMO_SCENE_TEST_H_

class SceneTest : public j3d::Scene {
public:

	SceneTest();
	~SceneTest() { unload(); }

	void load();
	void unload();
	void update( float dtime );

	void onKeyDown( unsigned char key );
	void onKeyUp( unsigned char key ) { onKeyDown( key ); }

private:
	float move_x;
	float move_z;
	float counter;
	float time_agg;
	j3d::ShaderProgram* mp_shaderProgram;
	j3d::Camera* mp_camera;
	vector<j3d::Object*> m_cubes;
};

#endif
