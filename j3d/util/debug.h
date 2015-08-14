/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/debug.h
*******************************************************************************/
#ifndef __J3D_UTIL_DEBUG_H__
#define __J3D_UTIL_DEBUG_H__
namespace j3d { namespace util {

class debug {
private:
	static int line_prefix();
	static void line_postfix();
	static int caller_info(string, string, int);
	static int tier_prefix();
	static void flush();

public:
	static void write(string file, string func, int line, string color,
			string title, string message, bool status = false);
	static void status(string color, string status);
	static void status(string color, string status, string color2, string message);

	static void push_tier();
	static void pop_tier();
	
	static void level(int);
	static void colorize(bool);
	static void tier(int);

	static int level();
	static bool colorize();
	static int tier();

private:
	static stringstream m_ss;
	static int m_level;
	static bool m_colorize;
	static int m_tier;
	static int m_last_w;
	static size_t m_last_fill;

};

struct debug_settings {
	static int level;
	static bool colorize;
};

} }

#define J3D_DEBUG_LEVEL_ALL		1
#define J3D_DEBUG_LEVEL_INFO	2
#define J3D_DEBUG_LEVEL_TODO	3
#define J3D_DEBUG_LEVEL_OK		10
#define J3D_DEBUG_LEVEL_WARN	20
#define J3D_DEBUG_LEVEL_ERROR	21
#define J3D_DEBUG_LEVEL_FATAL	22

#define J3D_DEBUG(c, t, m, st) do {\
	stringstream ss; ss << m;\
	j3d::util::debug::write(__FILE__, __FUNCTION__, __LINE__, c, t, ss.str(), st);\
} while (0)

#define J3D_DEBUG_INFO(m) do {\
	if (J3D_DEBUG_LEVEL_INFO >= j3d::util::debug::level())\
		J3D_DEBUG("0;95", "INFO", m, false);\
} while (0)

#define J3D_DEBUG_TODO(m) do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::util::debug::level())\
		J3D_DEBUG("0;90", "TODO", m << " ", true);\
} while (0)

#define J3D_DEBUG_TODO_OK do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::util::debug::level())\
		j3d::util::debug::status("0;30m\033[102", "OK");\
} while (0)

#define J3D_DEBUG_TODO_WARN(m) do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::util::debug::level()) {\
		stringstream ss; ss << m;\
		j3d::util::debug::status("0;30m\033[103", "WARN", "0;93", ss.str());\
	}\
} while (0)

#define J3D_DEBUG_TODO_ERROR(m) do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::util::debug::level()) {\
		stringstream ss; ss << m;\
		j3d::util::debug::status("1;97m\033[101", "ERROR", "0;91", ss.str());\
	}\
} while (0)

#define J3D_DEBUG_TODO_FATAL(m) do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::util::debug::level()) {\
		stringstream ss; ss << m;\
		j3d::util::debug::status("1;97m\033[101", "FATAL", "0;91", ss.str());\
	}\
	exit(1);\
} while (0)

#define J3D_DEBUG_OK(m) do {\
	if (J3D_DEBUG_LEVEL_OK >= j3d::util::debug::level())\
		J3D_DEBUG("0;92", "OK", m, false);\
} while (0)

#define J3D_DEBUG_WARN(m) do {\
	if (J3D_DEBUG_LEVEL_WARN >= j3d::util::debug::level())\
		J3D_DEBUG("0;93", "WARN", m, false);\
} while (0)

#define J3D_DEBUG_ERROR(m) do {\
	if (J3D_DEBUG_LEVEL_ERROR >= j3d::util::debug::level())\
		J3D_DEBUG("0;91", "ERROR", m, false);\
} while (0)

#define J3D_DEBUG_FATAL(m) do {\
	if (J3D_DEBUG_LEVEL_ERROR >= j3d::util::debug::level())\
		J3D_DEBUG("0;91", "FATAL", m, false);\
	exit(1);\
} while (0)

#define J3D_DEBUG_EXTRA(k, m)\
	J3D_DEBUG("0;94", k, m, false);

#define J3D_DEBUG_PUSH(m) do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::util::debug::level()) {\
		J3D_DEBUG("0;96", "TIER", "+-- " << m, false);\
		j3d::util::debug::push_tier();\
	}\
} while (0)

#define J3D_DEBUG_POP do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::util::debug::level())\
		j3d::util::debug::pop_tier();\
} while (0)

namespace j3d { namespace util {

void debug(int level = J3D_DEBUG_LEVEL_WARN, bool colorize = true);

} }
#endif
