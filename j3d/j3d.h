/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/j3d.h
*******************************************************************************/
#ifndef __J3D_J3D_H__
#define __J3D_J3D_H__

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <signal.h>
#include <unistd.h>
#include <cinttypes>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <initializer_list>
using namespace std;

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

namespace j3d {
	class engine;
	namespace util {
		class control;
	}
}

#include "debug.h"
#include "util/util.h"
#include "util/cycle.h"
#include "util/control.h"
#include "util/cache.h"
#include "math/vmath.h"
#include "core/flaggable.h"
#include "core/renderbuffer.h"
#include "core/display.h"
#include "shader.h"
#include "mesh.h"
#include "mesh_shapes.h"
#include "collider.h"
#include "core/entity.h"
#include "object.h"
#include "camera.h"
#include "scene.h"
#include "config.h"
#include "engine.h"

#endif
