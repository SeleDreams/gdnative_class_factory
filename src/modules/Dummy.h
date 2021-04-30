#ifndef DUMMY_H
#define DUMMY_H
#include <Godot.hpp>
#include <Node.hpp>
#include <ClassFactory.h>

class Dummy : public godot::Node, public ClassFactory<Dummy> 
// You need to inherit from ClassFactory in order for the class to be counted in the factory
{
    GODOT_CLASS(Dummy,godot::Node);
    public:
        static void _register_methods();
        Dummy() = default;
        ~Dummy() = default;
        void _init(); 
};
#endif