#include "ClassFactoryManager.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);
    ClassFactoryManager::register_classes();
    ClassFactoryManager::generate_gdns("bin","gdnative_class_factory"); // you can remove this if you don't want the gdns files to get generated
                                                                        // make sure this function only gets called in editor, as it might produce unwanted 
                                                                        // results in builds
}
