#ifndef BASEFACTORYCLASS_H
#define BASEFACTORYCLASS_H
#include <Godot.hpp>
#include <string>
#include "ClassFactoryManager.h"
using namespace godot;
template <class T>
class ClassFactory
{
protected:
    static void ___register_class()
    {
        godot::register_class<T>();
        
    }
    static bool ___registered;
    static std::string ___name;
};
#define REGISTER_CLASS(CLASS_NAME) template<> bool ClassFactory<CLASS_NAME>::___registered = ClassFactoryManager::add_class_registrator(#CLASS_NAME,ClassFactory<CLASS_NAME>::___register_class);\
template<> std::string ClassFactory<CLASS_NAME>::___name=#CLASS_NAME
#endif