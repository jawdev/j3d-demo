/******************************************************************************
* JAW DEVELPMENT LLC
* J3D Demo
* github.com/jawdev/j3d-demo
* /scenes/scene_a.h
******************************************************************************/
#ifndef J3D_DEMO_SCENE_A_H_
#define J3D_DEMO_SCENE_A_H_

class SceneA : public j3d::Scene {
public:

	SceneA();
	~SceneA() { unload(); }

	void load();
	void unload();
	void update( float dtime );

private:
	float ang;
	float counter;
	float time_agg;
	j3d::ShaderProgram* mp_shaderProgram;
	j3d::Camera* mp_camera;
	vector<j3d::Object*> m_cubes;
};

#endif
