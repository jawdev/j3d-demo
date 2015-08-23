/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/core/entity_base.h
*******************************************************************************/
#ifndef __J3D_CORE_ENTITY_BASE_H__
#define __J3D_CORE_ENTITY_BASE_H__
namespace j3d { namespace core {

/*******************************************************************************
* ENTITYBASE
*******************************************************************************/

template<class T>
class EntityBase : public Feature, public UniformBindings {
public:
	EntityBase()
	{
		constructor_core();
	}

	EntityBase(string shader_id) :
		UniformBindings(shader_id)
	{
		constructor_core();
	}

	virtual ~EntityBase() {}

private:
	void constructor_core()
	{
		o_locked = false;
		op_attachment = nullptr;
	}

public:

	///////////////////////////////////////
	// UPDATE

	virtual void update()
	{
		if (locked())
			return;
		if (attached())
			return syncAttachment();
		spatialize();
	}

	virtual void spatialize()
	{
		if (locked())
			return;
		o_pos += o_vel * util::cycle::delta();
		o_rot += o_rvel * util::cycle::delta();
	}

	virtual void syncAttachment()
	{
		if (locked() || !attached())
			return;
		//o_pos = o_pos_offset + op_attachment->pos();
		//o_rot = o_rot_offset + op_attachment->rot();
	}
	
	virtual EntityBase<T> *move(const T &t)
	{
		if (!locked())
			o_pos += t;
		return this;
	}

	virtual EntityBase<T> *rotate(const T &t)
	{
		if (!locked())
			o_rot += t;
		return this;
	}

	///////////////////////////////////////
	// SET
	
	virtual EntityBase<T> *lock(bool b = true)
	{
		o_locked = b;
		return this;
	}

	virtual EntityBase<T> *pos(const T &t)
	{
		if (!locked())
			o_pos = t;
		return this;
	}

	virtual EntityBase<T> *rot(const T &t)
	{
		if (!locked())
			o_pos = t;
		return this;
	}

	virtual EntityBase<T> *vel(const T &t)
	{
		if (!locked())
			o_vel = t;
		return this;
	}

	virtual EntityBase<T> *rvel(const T &t)
	{
		if (!locked())
			o_rvel = t;
		return this;
	}

	virtual EntityBase<T> *attach(EntityBase<T> *ent, const T &p, const T &r)
	{
		op_attachment = ent;
		o_pos_offset = p;
		o_rot_offset = r;
		return this;
	}

	virtual EntityBase<T> *aabb(const T &max)
	{
		o_aabb[0] = max;
		o_aabb[0] *= -1;
		o_aabb[1] = max;
		return this;
	}

	virtual EntityBase<T> *aabb(const T &min, const T &max)
	{
		o_aabb[0] = min;
		o_aabb[1] = max;
		return this;
	}

	///////////////////////////////////////
	// GET

	virtual bool locked() const { return o_locked; }
	virtual const T &pos() const { return o_pos; }
	virtual const T &rot() const { return o_rot; }
	virtual const T &vel() const { return o_vel; }
	virtual const T &rvel() const { return o_rvel; }
	virtual bool attached() const { return (op_attachment != nullptr); }
	virtual EntityBase<T> *attachment() const { return op_attachment; }

	virtual void aabb(T *min, T *max) const
	{
		min->assign(o_pos + o_aabb[0]);
		max->assign(o_pos + o_aabb[1]);
	}

protected:
	bool o_locked;
	T o_pos;
	T o_rot;
	T o_pos_offset;
	T o_rot_offset;
	T o_vel;
	T o_rvel;
	EntityBase<T> *op_attachment;
	T o_aabb[2];

};

} }
#endif
