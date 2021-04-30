#include "ClassFactoryManager.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>

std::map<std::string, std::function<void()>> ClassFactoryManager::s_methods;

bool ClassFactoryManager::add_class_registrator(const std::string &name, std::function<void()> func)
{
    s_methods[name] = func;
    return true;
}

void ClassFactoryManager::register_classes()
{
    for (auto class_type : s_methods)
    {
        Godot::print((std::string("registering class ") + class_type.first).c_str());
        class_type.second();
    }
}

void ClassFactoryManager::generate_gdns(const std::string &output_path, const std::string &lib_name)
{

    using namespace std;
    fstream gdnlib_file(output_path + "/" + lib_name + ".gdnlib");
    if (gdnlib_file.fail())
    {
        return;
    }
    for (auto class_type : s_methods)
    {
        string class_name = class_type.first;
        fstream gdns(output_path + "/" + class_name + ".gdns");
        if (!gdns.fail())
        {
            Godot::print((std::string("gdns ") + class_type.first + " already exists. skipping...").c_str());
            continue;
        }
        gdns.open(output_path + "/" + class_name + ".gdns", std::ios::out);
        gdns << "[gd_resource type=\"NativeScript\" load_steps=2 format=2]" << endl
             << "[ext_resource path=\"res://" << output_path + "/" + lib_name << ".gdnlib\" type=\"GDNativeLibrary\" id=1]" << endl
             << "[resource]" << endl
             << "resource_name = \"" << class_name << "\"" << endl
             << "class_name = \"" << class_name << "\"" << endl
             << "library = ExtResource( 1 )" << endl;
        Godot::print((std::string("generated gdns ") + class_type.first).c_str());     
    }
}