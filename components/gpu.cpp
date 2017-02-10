#include "gpu.h"
#include "log.h"
#include "frame.h"
#include <iostream>

Gpu::Gpu(const string& type, const Value& init, Host* host) :
    Component(type, init, host)
{
    add("setResolution", &Gpu::setResolution);
    add("bind", &Gpu::bind);
    add("set", &Gpu::set);
    add("maxResolution", &Gpu::maxResolution);
    add("getBackground", &Gpu::getBackground);
    add("setBackground", &Gpu::setBackground);
    add("getForeground", &Gpu::getForeground);
    add("setForeground", &Gpu::setForeground);
    add("fill", &Gpu::fill);
}

ValuePack Gpu::bind(const ValuePack& args)
{
    return ValuePack();
}

ValuePack Gpu::setResolution(const ValuePack& args)
{
    lout << "set resolution: " << args.at(0).serialize() << ", " << args.at(1).serialize() << endl;
    return ValuePack();
}

ValuePack Gpu::set(const ValuePack& args)
{
    int x = args.at(0).toNumber();
    int y = args.at(1).toNumber();
    string text = args.at(2).toString();

    // get the bound ScreenFrame and write to it
    // how??

    return ValuePack();
}

ValuePack Gpu::maxResolution(const ValuePack& args)
{
    lout << "TODO, stub gpu max res, i'll have to use a screen frame to know\n";
    return ValuePack({50, 16});
}

ValuePack Gpu::setBackground(const ValuePack& args)
{
    lout << "TODO, stub gpu method\n";
    return ValuePack({0, false});
}

ValuePack Gpu::getBackground(const ValuePack& args)
{
    lout << "TODO, stub gpu method\n";
    return ValuePack({0, false});
}

ValuePack Gpu::setForeground(const ValuePack& args)
{
    lout << "TODO, stub gpu method\n";
    return ValuePack({0, false});
}

ValuePack Gpu::getForeground(const ValuePack& args)
{
    lout << "TODO, stub gpu method\n";
    return ValuePack({0, false});
}

ValuePack Gpu::fill(const ValuePack& args)
{
    lout << "TODO, stub gpu method\n";
    return ValuePack();
}
