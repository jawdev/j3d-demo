/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* demo/demo.h
*******************************************************************************/
#ifndef __DEMO_DEMO_H__
#define __DEMO_DEMO_H__

/*******************************************************************************
* DEMO
*******************************************************************************/

class Demo : public Scene {
public:
	Demo();
	~Demo();

protected:
	void load();
	void unload();
	void update();

private:
	float m_time_agg;
	unsigned int m_counter;

	Layer *mp_l1;
	Camera *mp_cam;
	ShaderProgram *mp_shader;
	Cube *mp_cube;
	Cube *mp_cube2;
};

#endif
