/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /debug.h
******************************************************************************/
#ifndef J3D_DEBUG_H_
#define J3D_DEBUG_H_
namespace j3d {
namespace debug {

	enum class debug_flush_t { FLUSH };
	static const debug_flush_t flush = debug_flush_t::FLUSH;

	class DebugStream {
	public:
		DebugStream( const char* color, const char* label, bool is_fatal = false );
		~DebugStream() {}

		template<class T>
		DebugStream& operator<<( const T& t ) { m_stream << t; return *this; }

		DebugStream& operator<<( const debug_flush_t& t ) { flush(); return *this; }
		DebugStream& operator<<( const std::nullptr_t& t ) { flush(); return *this; }

		void flush();

	private:
		char m_prefix[20];
		ostringstream m_stream;
		bool m_fatal;
	};

	static DebugStream ok( "\033[0;92m", "OK" );
	static DebugStream info( "\033[0;36m", "INFO" );
	static DebugStream code( "\033[0;34m", "CODE" );
	static DebugStream note( "\033[0;35m", "NOTE" );
	static DebugStream warn( "\033[0;93m", "WARN" );
	static DebugStream error( "\033[0;91m", "ERROR" );
	static DebugStream fatal( "\033[1;91m", "FATAL", true );

}
}
#endif
