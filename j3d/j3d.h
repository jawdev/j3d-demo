/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/j3d.h
*******************************************************************************/
#ifndef __J3D_J3D_H__
#define __J3D_J3D_H__

#define _USE_MATH_DEFINES

////////////////////////////////////////
// STANDARD LIB

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
#include <functional>
using namespace std;

////////////////////////////////////////
// OPENGL GLUT

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

////////////////////////////////////////
// BASE MACROS

#define J3D_SAFE_DELETE(obj) do {\
	if (obj != nullptr)\
		delete obj;\
	obj = nullptr;\
} while (0)

#define J3D_SAFE_DELETE_ARR(obj) do {\
	if (obj != nullptr)\
		delete [] obj;\
	obj = nullptr;\
} while (0)

#define J3D_LITERAL(val) #val

////////////////////////////////////////
// PREDECLARATIONS

namespace j3d {
	class engine;
	namespace util {
		class control;
	}
	namespace core {
		class Cacheable;
		class Batch;
	}
}

////////////////////////////////////////
// J3D LIB

#include "util/debug.h"
#include "util/util.h"
#include "util/cycle.h"
#include "util/control.h"
#include "util/cache.h"
#include "util/batches.h"

#include "math/vmath.h"

#include "core/flaggable.h"
#include "core/cacheable.h"
#include "core/batch.h"
#include "core/reshapeable.h"
#include "core/renderbuffer.h"
#include "core/display.h"
#include "core/entity_base.h"
#include "core/entity.h"

#include "shader.h"
#include "mesh.h"
#include "mesh_shapes.h"
#include "collider.h"
#include "object.h"
#include "camera.h"
#include "scene.h"
#include "config.h"
#include "engine.h"

#endif
