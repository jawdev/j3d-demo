/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/mesh_shapes.h
*******************************************************************************/
#ifndef __J3D_MESH_SHAPES_H__
#define __J3D_MESH_SHAPES_H__
namespace j3d {

/*******************************************************************************
* BoxMesh
*******************************************************************************/

class BoxMesh : public Mesh {
public:
	BoxMesh(const char *id, float s = 1.0f);
	BoxMesh(const char *id, float w, float l, float h);
	~BoxMesh();

private:
	void create();

public:
	float size() const;
	float width() const;
	float length() const;
	float height() const;

private:
	float m_width;
	float m_length;
	float m_height;

};

/*******************************************************************************
* FloorMesh
*******************************************************************************/

class FloorMesh : public Mesh {
public:
	FloorMesh(const char *id, float w, float l = 0);
	~FloorMesh();

	float width() const;
	float length() const;

private:
	float m_width;
	float m_length;

};

}
#endif
