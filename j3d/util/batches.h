/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/batches.h
*******************************************************************************/
#ifndef __J3D_UTIL_BATCHES_H__
#define __J3D_UTIL_BATCHES_H__
namespace j3d { namespace util {

/*******************************************************************************
* BATCHES
*******************************************************************************/

typedef core::Batch batchobj;
typedef vector<batchobj *> batchgroup;
typedef unordered_map<string, batchgroup> batchmap;

class batches {
public:
	static void clear();
	static void add(string id, batchobj *);
	static void remove(string id, batchobj *);
	static batchgroup *get(string id);

private:
	static batchmap m_batches;
	
};

#define J3D_BATCH(_obj, _func, ...) do {\
	util::batchgroup *grp = util::batches::get(_obj::J3D_BATCH_ID);\
	if (grp != nullptr)\
		for (size_t i = 0; i < grp->size(); ++i)\
			((_obj *)grp->at(i))->_func( __VA_ARGS__ );\
} while (0)

} }
#endif
