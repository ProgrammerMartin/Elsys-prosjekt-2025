#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/subprojects/animationwindow/include/internal/KeyboardKeyConverter.h"
#pragma once

#include "KeyboardKey.h"
#include "SDL.h"

namespace TDT4102 {
    namespace internal {
        KeyboardKey convertSDLKeyToKeyboardKey(SDL_Keysym key);
    }
}