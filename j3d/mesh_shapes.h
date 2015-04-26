/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /mesh_shapes.h
******************************************************************************/
#ifndef J3D_MESH_SHAPES_H_
#define J3D_MESH_SHAPES_H_
namespace j3d {

///////////////////////////////////////////////// BoxMesh

class BoxMesh : public Mesh {
public:
	BoxMesh( float s = 1.0f );
	BoxMesh( float w, float l, float h );
	~BoxMesh();

	void build();

	float size() { return m_width; }
	float width() { return m_width; }
	float length() { return m_length; }
	float height() { return m_height; }
private:
	float m_width;
	float m_length;
	float m_height;
};

///////////////////////////////////////////////// FloorMesh

class FloorMesh : public Mesh {
public:
	FloorMesh( float w, float l = 0 );
	~FloorMesh();

	float width() { return m_width; }
	float length() { return m_length; }
private:
	float m_width;
	float m_length;
};


}
#endif
