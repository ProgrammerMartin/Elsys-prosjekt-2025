#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/subprojects/animationwindow/include/internal/windows_main_fix.h"
#pragma once

// SDL needs a main function with "proper" arguments on Windows because it tries to define its own main function
// This is bad practice, but we want you to be able to use both main variants (e.g. with and without arguments)
// at will to avoid some confusion, and therefore need to work around the problem :)
// We therefore define a macro that replaces anything that looks like a main() function as the SDL_main function, with the proper arguments.

#ifdef _WIN32
#include <SDL.h>
#ifdef main
#undef main
#endif
#define main(...) SDL_main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
#endif