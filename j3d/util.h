/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /util.h
******************************************************************************/
#ifndef J3D_UTIL_H_
#define J3D_UTIL_H_
namespace j3d { namespace util {

template<class T>
struct is_pointer { static const bool value = false; };
template<class T>
struct is_pointer<T*> { static const bool value = true; };

static inline char* file_get_contents( const char* filename, bool zero_term = false ) {
	ifstream in( filename, ios::in|ios::binary );
	if( !in ) debug::fatal << "(util::file_get_contents) file could not be found: " << filename << debug::flush;
	in.seekg( 0, ios::end );
	unsigned int len = (unsigned int)in.tellg();
	char* contents = new char[len+1];
	in.seekg( 0, ios::beg );
	in.read( contents, len );
	in.close();
	if( zero_term ) contents[len] = 0;
	return contents;
};

} }
#endif
