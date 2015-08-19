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

	Group *groupAdd(Feature *);
	Group *groupAdd(initializer_list<Feature *>);
	Group *groupRemove(Feature *);
	Group *groupRemove(initializer_list<Feature *>);
	void groupDelete();

	virtual Group *add(Feature *f) { return groupAdd(f); }
	virtual Group *add(initializer_list<Feature *> fs) { return groupAdd(fs); }
	virtual Group *remove(Feature *f) { return groupRemove(f); }
	virtual Group *remove(initializer_list<Feature *> fs) { return groupRemove(fs); }

	void groupUpdate();
	void groupPreRender();
	void groupRender();
	void groupPostRender();
	void groupUpdateRender();

	virtual void update() { groupUpdate(); }
	virtual void preRender() { groupPreRender(); }
	virtual void render() { groupRender(); }
	virtual void postRender() { groupPostRender(); }
	virtual void updateRender() { groupUpdateRender(); }

	Group *groupControlDelete(bool b = true);
	Group *groupShaderProgram(const char *id);
	Group *groupShaderProgram(ShaderProgram *);

	virtual Group *controlDelete(bool b = true) { return groupControlDelete(b); }
	virtual Group *shaderProgram(const char *id) { return groupShaderProgram(id); }
	virtual Group *shaderProgram(ShaderProgram *p) { return groupShaderProgram(p); }

	bool groupControlDelete() const;
	ShaderProgram *groupShaderProgram() const;

	virtual bool controlDelete() const { return groupControlDelete(); }
	virtual ShaderProgram *shaderProgram() const { return groupShaderProgram(); }

protected:
	virtual void onGroupAdd(Feature *) {}
	virtual void onGroupRemove(Feature *) {}

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
