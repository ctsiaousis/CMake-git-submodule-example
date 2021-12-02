#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#ifndef ITM_FILE_PATH
#error "ITEM DATA FILE MISSING! Make sure you run CMake properly"
#endif
#ifndef USR_FILE_PATH
#error "USR DATA FILE MISSING! Make sure you run CMake properly"
#endif

#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <random>

#include "Utils/LinearAlgebra.h"
#include "Utils/LinearAlgebra.h"


// #define NDEBUG // uncomment to disable assert()
#include <cassert>

// Use (void) to silent unused warnings.
#ifndef assertm
#define assertm(exp, msg) assert(((void)msg, exp))
#endif


#ifndef MAX_FEATURES
#define MAX_FEATURES 8
#endif


#ifndef NORM_DIST_START
#define NORM_DIST_START -8
#endif
#ifndef NORM_DIST_END
#define NORM_DIST_END 18
#endif
#ifndef NORM_DIST_STEP
#define NORM_DIST_STEP 0.1f
#endif


#endif // DEFINITIONS_H
