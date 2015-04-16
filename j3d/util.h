/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /util.h
******************************************************************************/
#ifndef J3D_UTIL_H_
#define J3D_UTIL_H_
namespace j3d { namespace util {

template<typename T>
struct is_pointer { static const bool value = false; };
template<typename T>
struct is_pointer<T*> { static const bool value = true; };


} }
#endif
