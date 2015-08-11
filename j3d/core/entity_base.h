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
class EntityBase {
public:
	EntityBase(bool locked = false)
	{
		o_locked = locked;
		o_attached = false;
		op_attachment = nullptr;
	}

	virtual ~EntityBase() {}

	///////////////////////////////////////
	// UPDATE

	virtual void syncAttachment()
	{
		if (o_locked || !o_attached)
			return;
		o_pos = op_attachment->pos() + o_pos_offset;
		o_rot = op_attachment->rot() + o_rot_offset;
	}

	virtual void update() {}
	
	virtual EntityBase<T> *move(const T &t)
	{
		if (!o_locked)
			o_pos += t;
		return this;
	}

	virtual EntityBase<T> *rotate(const T &t)
	{
		if (!o_locked)
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
		if (!o_locked)
			o_pos = t;
		return this;
	}

	virtual EntityBase<T> *rot(const T &t)
	{
		if (!o_locked)
			o_pos = t;
		return this;
	}

	virtual EntityBase<T> *attach(EntityBase<T> *ent, const T &p, const T &r)
	{
		op_attachment = ent;
		o_attached = (ent != nullptr);
		o_pos_offset = p;
		o_rot_offset = r;
		return this;
	}

	///////////////////////////////////////
	// GET

	virtual bool locked() const { return o_locked; }
	virtual const T &pos() const { return o_pos; }
	virtual const T &rot() const { return o_rot; }
	virtual bool attached() const { return o_attached; }
	virtual EntityBase<T> *attachment() const { return op_attachment; }

protected:
	bool o_locked;
	T o_pos;
	T o_rot;
	T o_pos_offset;
	T o_rot_offset;
	bool o_attached;
	EntityBase<T> *op_attachment;

};

} }
#endif
