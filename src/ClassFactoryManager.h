#ifndef REGISTERCLASSMETHODFACTORY_H
#define REGISTERCLASSMETHODFACTORY_H
#include "ClassFactory.h"
#include <string>
#include <map>
#include <functional>

class ClassFactoryManager
{
public:
    ClassFactoryManager() = delete;

    static bool add_class_registrator(const std::string &name, std::function<void()> func);

    static void register_classes();

    static void generate_gdns(const std::string &output_path,const std::string &lib_name);

private:
    static std::map<std::string,std::function<void()>> s_methods;
};

#endif