#include "oneshot.h"
#include "etc.h"
#include "sharedstate.h"
#include "binding-util.h"
#include "binding-types.h"
#include "eventthread.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_version.h>
//for future use

void SunshineBindingInit(){
	VALUE module = rb_define_module("Sunshine");
	rb_const_set(module, rb_intern("SDLVersion"), static_cast<char>(SDL_VERSION));
}
