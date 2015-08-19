/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/light.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* LIGHT
*******************************************************************************/

Light::Light(light_t type) :
		core::Entity()
{
	m_type = type;
}

Light::Light(const vec3 &dif, const vec3 &amb, const vec3 &dir,
		light_t type) :
		core::Entity()
{
	m_type = type;
	m_diffuse = dif;
	m_ambient = amb;
	m_dir = dir;
}

Light::Light(const vec3 &dif, light_t type) :
		core::Entity()
{
	m_type = type;
	m_diffuse = dif;
}

Light::Light(const vec3 &dif, const vec3 &amb, const vec3 &dir,
		const float &cos, light_t type) :
		core::Entity()
{
	m_type = type;
	m_diffuse = dif;
	m_ambient = amb;
	m_dir = dir;
	m_cos = cos;
}

Light::~Light() {}

////////////////////////////////////////
// UPDATE

void Light::render()
{
	bindUniforms();
}

////////////////////////////////////////
// PROPS

LightProps Light::props()
{
	return {
		m_diffuse,
		m_ambient,
		m_dir,
		m_cos
	};
}

Light *Light::assignDiffuseUniform(const string &s)
{
	assignUniform(s, &m_diffuse);
	return this;
}

Light *Light::assignAmbientUniform(const string &s)
{
	assignUniform(s, &m_ambient);
	return this;
}

Light *Light::assignDirUniform(const string &s)
{
	assignUniform(s, &m_dir);
	return this;
}

Light *Light::assignCosUniform(const string &s)
{
	//assignUniform(s, &m_cos);
	return this;
}

////////////////////////////////////////
// SET GET

Light *Light::diffuse(const vec3 &v) { m_diffuse = v; return this; }
Light *Light::ambient(const vec3 &v) { m_ambient = v; return this; }
Light *Light::dir(const vec3 &v) { m_dir = v; return this; }
Light *Light::cos(const float &f) { m_cos = f; return this; }

const vec3 &Light::diffuse() const { return m_diffuse; }
const vec3 &Light::ambient() const { return m_ambient; }
const vec3 &Light::dir() const { return m_dir; }
const float &Light::cos() const { return m_cos; }

}
