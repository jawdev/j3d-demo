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

	void onKeyDown(unsigned char);
	void onKeyUp(unsigned char);
	void onMouseUp(int, int, int);

private:
	float m_timer;
	int m_dir[2];
	float m_rot[2];

	Layer *mp_l1;
	Camera *mp_cam;
	ShaderProgram *mp_shader;
	Cube *mp_cube;

	Mesh *mp_ray_mesh;
	Object *mp_ray_obj;
};

#endif
