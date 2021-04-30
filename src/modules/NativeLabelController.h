#ifndef NATIVE_LABEL_CONTROLLER_H
#define NATIVE_LABEL_CONTROLLER_H
#include <Godot.hpp>
#include <Label.hpp>
#include <ClassFactory.h>

class NativeLabelController : public godot::Label, public ClassFactory<NativeLabelController> 
// You need to inherit from ClassFactory in order for the class to be counted in the factory
{
    GODOT_CLASS(NativeLabelController,godot::Label);
    public:
        static void _register_methods();
        NativeLabelController() = default;
        ~NativeLabelController() = default;
        void _init(); 
};
#endif