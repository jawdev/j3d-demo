/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* demo.h
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

	Object *mp_box;
	ShaderProgram *mp_shader;
	Camera *mp_cam;
	vec3 m_vec3;
	vec2 m_vec2;
	vec4 m_vec4;
	
};

#endif
