#include "NativeLabelController.h"

REGISTER_CLASS(NativeLabelController); // This is required for the class to be registered

void NativeLabelController::_register_methods()
{
    godot::register_method("_init",&NativeLabelController::_init);
}

void NativeLabelController::_init()
{
    set_text("Hello from the gdnative class factory !"); 
}