#include "Dummy.h"

REGISTER_CLASS(Dummy);

void Dummy::_register_methods()
{
    register_method("_init",&Dummy::_init);
}

void Dummy::_init()
{
    Godot::print("Dummy gdns loaded");
}