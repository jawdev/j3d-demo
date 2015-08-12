/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/group.h
*******************************************************************************/
#ifndef __J3D_CORE_GROUP_H__
#define __J3D_CORE_GROUP_H__
namespace j3d { namespace core {

/*******************************************************************************
* GROUP
*******************************************************************************/

class Group {
public:
	Group(bool control_delete = true);
	virtual ~Group();

	virtual Group *add(Feature *f);
	virtual Group *add(initializer_list<Feature *>);
	virtual Group *remove(Feature *f);
	virtual Group *remove(initializer_list<Feature *>);
	virtual void destroy();

	virtual void update();
	virtual void preRender();
	virtual void render();
	virtual void postRender();
	virtual void updateRender();

	Group *controlDelete(bool b = true);
	Group *shaderProgram(const char *id);
	Group *shaderProgram(ShaderProgram *);

	bool controlDelete() const;
	ShaderProgram *shaderProgram() const;

private:
	bool m_control_delete;
	ShaderProgram *mp_shader_program;

protected:
	unordered_map<string, Feature *> o_features;
	bool o_pre_render;

};

/*******************************************************************************
* FEATUREGROUP
*******************************************************************************/

class FeatureGroup : public Group, public Feature {
public:
	FeatureGroup(bool control_delete = false)
			: Group(control_delete), Feature() {}
	virtual ~FeatureGroup() {}

};

} }
#endif
