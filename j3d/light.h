/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/light.h
*******************************************************************************/
#ifndef __J3D_LIGHT_H__
#define __J3D_LIGHT_H__
namespace j3d {

enum class light_t {
	DIRECTIONAL,
	POINT,
	SPOT
};

struct LightProps {
	vec3 &diffuse;
	vec3 &ambient;
	vec3 &dir;
	float &cos;
};

/*******************************************************************************
* LIGHT
*******************************************************************************/

class Light : public base::Entity {
public:
	Light(light_t);
	Light(const vec3 &dif, const vec3 &amb, const vec3 &dir,
			light_t = light_t::DIRECTIONAL);
	Light(const vec3 &dif, light_t = light_t::POINT);
	Light(const vec3 &dif, const vec3 &amb, const vec3 &dir,
			const float &cos, light_t = light_t::SPOT);
	virtual ~Light();

	void render();

	LightProps props();
	Light *assignDiffuseUniform(const string &);
	Light *assignAmbientUniform(const string &);
	Light *assignDirUniform(const string &);
	Light *assignCosUniform(const string &);

	Light *diffuse(const vec3 &);
	Light *ambient(const vec3 &);
	Light *dir(const vec3 &);
	Light *cos(const float &);

	const vec3 &diffuse() const;
	const vec3 &ambient() const;
	const vec3 &dir() const;
	const float &cos() const;

private:
	light_t m_type;
	vec3 m_diffuse;
	vec3 m_ambient;
	vec3 m_dir;
	float m_cos;

};

}
#endif
