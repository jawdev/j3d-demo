/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /lib/debug.cc
******************************************************************************/
#include "j3d.h"
namespace j3d {
namespace debug {

	DebugStream::DebugStream( const char* color, const char* label, bool is_fatal ) {
		sprintf( m_prefix, "%s[%s]\t", color, label );
		m_fatal = is_fatal;
	}
	
	void DebugStream::flush() {
		std::cout << m_prefix << m_stream.str() << "\033[0m" << std::endl;
		m_stream.str( "" );
		m_stream.flush();
		m_stream.clear();
		if( m_fatal ) j3d::Engine::quit( 1 );
	}

}
}
