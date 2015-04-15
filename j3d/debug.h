/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /debug.h
******************************************************************************/
#ifndef J3D_DEBUG_H_
#define J3D_DEBUG_H_
namespace j3d {

class Debug {
public:

	static void formatEcho( const char* type, const char* format, const char* message );

	static bool ok( const char* );
	static bool info( const char* );
	static bool code( const char* );
	static bool note( const char* );
	static bool warn( const char* );
	static bool error( const char* );
	static bool fatal( const char* );

};

}
#endif
