#include <ruby.h>
#include <SDL3/SDL_version.h>

void SunshineBindingInit(){
    printf("[SunshineBindingInit] Initializing Sunshine binding\n");
    VALUE module = rb_define_module("Sunshine");
    rb_define_const(module, "SDLVersion_major", INT2NUM(SDL_MAJOR_VERSION));
    rb_define_const(module, "SDLVersion_minor", INT2NUM(SDL_MINOR_VERSION));
    rb_define_const(module, "SDLVersion_micro", INT2NUM(SDL_MICRO_VERSION));
    //SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_MICRO_VERSION
    printf("[SunshineBindingInit] SDL version: %i.%i.%i\n", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_MICRO_VERSION);
    printf("[SunshineBindingInit] Done\n");
}
