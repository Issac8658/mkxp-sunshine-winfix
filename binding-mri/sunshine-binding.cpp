#include <ruby.h>
#include <SDL3/SDL_version.h>

static VALUE string_clone(VALUE self){
    if (!RB_TYPE_P(self, T_STRING)) {
        rb_raise(rb_eTypeError, "wrong argument type (expected String)");
    }
    return rb_obj_clone(self);
}

static VALUE ruby_eval(VALUE self, VALUE code){
    if (!RB_TYPE_P(code, T_STRING)) {
        rb_raise(rb_eTypeError, "wrong argument type (expected String)");
    }
    
    #ifdef HAVE_RB_EVAL_STRING_PROTECT
        int error = 0;
        VALUE result = rb_eval_string_protect(RSTRING_PTR(code), &error);
        
        if (error) {
            rb_clear_exception();
            return Qnil;
        }
        return result;
    #else
        // Fallback
        return rb_eval_string(RSTRING_PTR(code));
    #endif
}

void SunshineBindingInit(){
    printf("[SunshineBindingInit] Initializing Sunshine binding\n");
    VALUE module = rb_define_module("Sunshine");
    rb_const_set(module, rb_intern("SDLVersion_major"), INT2NUM(SDL_MAJOR_VERSION));
    rb_const_set(module, rb_intern("SDLVersion_minor"), INT2NUM(SDL_MINOR_VERSION));
    rb_const_set(module, rb_intern("SDLVersion_micro"), INT2NUM(SDL_MICRO_VERSION));
    printf("[SunshineBindingInit] SDL version: %i.%i.%i\n", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_MICRO_VERSION);

	printf("[SunshineBindingInit] Initializing helpers\n");
	rb_define_method(rb_cObject, "class", rb_obj_class, 0);
	rb_define_method(rb_cString, "clone", RUBY_METHOD_FUNC(string_clone), 0);
	
	if (!rb_respond_to(rb_mKernel, rb_intern("eval"))) {
		printf("[SunshineBindingInit] Well, the standard eval is not available, let's try a custom one...\n");
		rb_define_method(rb_mKernel, "eval", RUBY_METHOD_FUNC(ruby_eval), 1);
	}
    
    printf("[SunshineBindingInit] Done\n");
}
