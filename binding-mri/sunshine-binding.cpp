#include <ruby.h>
#include <SDL3/SDL_version.h>

void SunshineBindingInit(){
    printf("[SunshineBindingInit] Initializing Sunshine binding\n");
    VALUE module = rb_define_module("Sunshine");
    
    rb_define_const(module, "SDLVersion", INT2NUM(SDL_VERSION));
    
    printf("[SunshineBindingInit] SDL version: %u\n", SDL_VERSION);
    printf("[SunshineBindingInit] Done\n");
}
