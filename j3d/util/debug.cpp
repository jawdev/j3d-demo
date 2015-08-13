/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/util/debug.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d { namespace util {

/*******************************************************************************
* DEBUG
*******************************************************************************/

stringstream debug::m_ss;
int debug::m_level = J3D_DEBUG_LEVEL_WARN;
bool debug::m_colorize = true;
int debug::m_tier = 0;
int debug::m_last_w = 0;
size_t debug::m_last_fill = 0;


////////////////////////////////////////
// HELPERS

int debug::line_prefix()
{
	if (m_colorize)
		m_ss << "\033[0;92m\033[100m";
	m_ss << " J3D ";
	return 5;
}

void debug::line_postfix()
{
	if (m_colorize)
		m_ss << "\033[0m";
	m_ss << endl;
}

int debug::caller_info(string fi, string fu, int li)
{
	if (m_colorize)
		m_ss << "\033[0;90m";
	stringstream ss;
	ss << " [" << fu << ":" << fi << ":" << li << "] ";
	m_ss << left << setw(40) << setfill('.') << ss.str();
	return 40;
}

int debug::tier_prefix()
{
	int i;
	for (i = 0; i < m_tier; ++i)
		m_ss << "|   ";
	return (i * 4);
}

void debug::flush()
{
	cout << m_ss.str();
	m_ss.str("");
	m_ss.clear();
}

////////////////////////////////////////
// MAIN

void debug::write(string fi, string fu, int li, string co, string ti, string me,
		bool st)
{
	int w = 0;
	w += line_prefix();
	w += caller_info(fi, fu, li);
	m_ss << right << setw(10) << (string(" ") + ti) << "   ";
	w += 13;
	w += tier_prefix();

	struct winsize win;
	ioctl(0, TIOCGWINSZ, &win);
	int cols = win.ws_col;
	size_t fill = cols - w - 7;
	m_ss << "\033[" << co << "m" << left << setfill(st ? '.' : ' ');
	if (me.length() > fill) {
		for (size_t s = 0; s < me.length(); s += fill) {
			if (s > 0) {
				m_ss << "\n" << setw(w - 4) << "";
				m_ss << ">   ";
			}
			if (s + fill > me.length()) {
				m_ss << setw(fill);
				m_ss << me.substr(s, fill);
			} else
				m_ss << me.substr(s, fill);
		}
	} else {
		m_ss << setw(fill);
		m_ss << me;
	}

	if (!st)
		line_postfix();
	flush();
	m_last_w = w;
	m_last_fill = fill;
}

void debug::status(string co, string st)
{
	m_ss << " ";
	if (m_colorize)
		m_ss << "\033[" << co << "m";
	m_ss << right << setfill(' ') << setw(6) << st;
	line_postfix();
	flush();
}

void debug::status(string c1, string st, string c2, string me)
{
	m_ss << " ";
	if (m_colorize)
		m_ss << "\033[" << c1 << "m";
	m_ss << right << setfill(' ') << setw(6) << st;
	line_postfix();
	if (m_colorize)
		m_ss << "\033[" << c2 << "m";
	m_ss << right << setw(m_last_w) << ">   ";
	m_ss << me;
	line_postfix();
	flush();
}

////////////////////////////////////////
// TIERS

void debug::push_tier()
{
	++m_tier;
}
void debug::pop_tier()
{
	--m_tier;
}


////////////////////////////////////////
// SET GET

void debug::level(int i) { m_level = i; }
void debug::colorize(bool b) { m_colorize = b; }
void debug::tier(int i) { m_tier = i; }

int debug::level() { return m_level; }
bool debug::colorize() { return m_colorize; }
int debug::tier() { return m_tier; }

void debug(int l, bool c)
{
	debug::level(l);
	debug::colorize(c);
}

} }
