/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/debug.h
*******************************************************************************/
#ifndef __J3D_DEBUG_H__
#define __J3D_DEBUG_H__
namespace j3d {

struct debug_settings {
	static int level;
	static bool colorize;
};

}

#define J3D_DEBUG_LEVEL_ALL		1
#define J3D_DEBUG_LEVEL_INFO	2
#define J3D_DEBUG_LEVEL_TODO	3
#define J3D_DEBUG_LEVEL_OK		10
#define J3D_DEBUG_LEVEL_WARN	20
#define J3D_DEBUG_LEVEL_ERROR	21
#define J3D_DEBUG_LEVEL_FATAL	22

#define J3D_DEBUG(s, c, t, m) do {\
	std::stringstream ss;\
	s << std::left << std::dec << std::setfill('.') ;\
	if (j3d::debug_settings::colorize)\
		s << "\033[0;92m\033[100m";\
	s << " J3D ";\
	if (j3d::debug_settings::colorize)\
		s << "\033[0m\033[0;90m";\
	ss << "[" << __FUNCTION__ << ":" << __FILE__ << ":" << __LINE__ << "]";\
	s << std::setw(50) << ss.str();\
	s << std::setw(20) << std::right << t << " | ";\
	if (j3d::debug_settings::colorize)\
		s << "\033[" << c << "m";\
	s << m;\
	if (j3d::debug_settings::colorize)\
		s << "\033[0m";\
	s << std::endl;\
} while (0)

#define J3D_DEBUG_INFO(m) do {\
	if (J3D_DEBUG_LEVEL_INFO >= j3d::debug_settings::level)\
		J3D_DEBUG(std::cout, "0;97", "INFO", m);\
} while (0)

#define J3D_DEBUG_TODO(m) do {\
	if (J3D_DEBUG_LEVEL_TODO >= j3d::debug_settings::level)\
		J3D_DEBUG(std::cout, "0;90", "TODO", m << " ...");\
} while (0)

#define J3D_DEBUG_OK(m) do {\
	if (J3D_DEBUG_LEVEL_OK >= j3d::debug_settings::level)\
		J3D_DEBUG(std::cout, "0;92", "OK", m);\
} while (0)

#define J3D_DEBUG_WARN(m) do {\
	if (J3D_DEBUG_LEVEL_WARN >= j3d::debug_settings::level)\
		J3D_DEBUG(std::cerr, "0;93", "WARN", m);\
} while (0)

#define J3D_DEBUG_ERROR(m) do {\
	if (J3D_DEBUG_LEVEL_ERROR >= j3d::debug_settings::level)\
		J3D_DEBUG(std::cerr, "0;91", "ERROR", m);\
} while (0)

#define J3D_DEBUG_FATAL(m) do {\
	if (J3D_DEBUG_LEVEL_ERROR >= j3d::debug_settings::level)\
		J3D_DEBUG(std::cerr, "0;31", "FATAL", " " << m << " ");\
	exit(1);\
} while (0)

#define J3D_DEBUG_EXTRA(k, m) do {\
	J3D_DEBUG(std::cout, "0;94", k, m);\
} while (0)

namespace j3d {

void debug(int level = J3D_DEBUG_LEVEL_WARN, bool colorize = true);

}
#endif
