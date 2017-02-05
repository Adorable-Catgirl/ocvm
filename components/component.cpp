#include "component.h"
#include "log.h"

#include <iostream>
#include <string>

void Component::add(const std::string& methodName, ComponentMethod method)
{
    _methods[methodName] = method;
}

ValuePack Component::invoke(const std::string& methodName, const ValuePack& args)
{
    if (_methods.find(methodName) == _methods.end())
    {
        log << "component does not have any such method: " << methodName << std::endl;
        return ValuePack();
    }

    ComponentMethod pmethod = _methods.at(methodName);
    return ((*this).*pmethod)(args);
}

