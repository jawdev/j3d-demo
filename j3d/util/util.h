/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/helpers.h
*******************************************************************************/
#ifndef __J3D_UTIL_HELPERS_H__
#define __J3D_UTIL_HELPERS_H__
namespace j3d { namespace util {

template<class T>
struct is_pointer { static const bool value = false; };
template<class T>
struct is_pointer<T *> { static const bool value = true; };

double now();

string ptr2str(void *);

char *file_get_contents(const char *filename, bool zero_term = false);

}}
#endif
