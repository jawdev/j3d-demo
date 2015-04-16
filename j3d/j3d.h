/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /j3d.h
******************************************************************************/
#ifndef J3D_J3D_H_
#define J3D_J3D_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <map>
#include <chrono>
using namespace std;

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

#define SAFE_DELETE( obj ) { if( obj != nullptr ) delete obj; obj = nullptr; }
#define SAFE_DELETE_ARR( obj ) { if( obj != nullptr ) delete [] obj; obj = nullptr; }

#include "util.h"
#include "stackable.h"
#include "switchable.h"
#include "settings.h"
#include "debug.h"
#include "timer.h"
#include "vmath.h"
#include "renderbuffer.h"
#include "entity.h"
#include "camera.h"
#include "scene.h"
#include "cache.h"
#include "display.h"
#include "engine.h"

namespace j3d {
}
#endif
