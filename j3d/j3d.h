/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /j3d.h
******************************************************************************/
#ifndef J3D_J3D_H_
#define J3D_J3D_H_

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <sstream>
using namespace std;

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

#define SAFE_DELETE( obj ) { if( obj != nullptr ) delete obj; obj = nullptr; }
#define SAFE_DELETE_ARR( obj ) { if( obj != nullptr ) delete [] obj; obj = nullptr; }

#include "debug.h"
#include "util.h"
#include "trigger.h"
#include "stackable.h"
#include "labler.h"
#include "settings.h"
#include "timer.h"
#include "vmath.h"
#include "control.h"
#include "renderbuffer.h"
#include "mesh.h"
#include "mesh_shapes.h"
#include "entity.h"
#include "camera.h"
#include "object.h"
#include "shader.h"
#include "scene.h"
#include "cache.h"
#include "display.h"
#include "engine.h"

#endif
