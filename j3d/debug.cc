/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /lib/debug.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {

void Debug::formatEcho( const char* type, const char* format, const char* message ) {
	cout << "\033[" << format << "m[j3d:" << type << "] " << message << "\033[0m" << endl;
}

bool Debug::ok( const char* message ) {
	if( Settings::debug ) formatEcho( "OK", "0;32", message );
	return true;
}

bool Debug::info( const char* message ) {
	if( Settings::debug ) formatEcho( "INFO", "0;36", message );
	return true;
}

bool Debug::code( const char* message ) {
	if( Settings::debug ) formatEcho( "CODE", "0;34", message );
	return true;
}

bool Debug::note( const char* message ) {
	if( Settings::debug ) formatEcho( "NOTE", "0;35", message );
	return true;
}

bool Debug::warn( const char* message ) {
	formatEcho( "WARN", "0;33", message );
	return true;
}

bool Debug::error( const char* message ) {
	formatEcho( "ERROR", "0;31", message );
	return false;
}

bool Debug::fatal( const char* message ) {
	formatEcho( "FATAL", "0;91", message );
	Engine::quit( 1 );
	return false;
}

}
