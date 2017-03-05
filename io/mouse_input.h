#pragma once

#include <string>
using std::string;

#include "input.h"

class MouseDriver : public InputDriver
{
};

enum class EPressType
{
    Press,
    Release,
    Drag,
    Drop
};

struct MouseEvent : public InputEvent
{
    EPressType press;
    int x;
    int y;
    int btn;
};

class MouseInput : protected InputSource
{
public:
    bool open(unique_ptr<MouseDriver> driver);
    using InputSource::close;

    unique_ptr<MouseEvent> pop();
private:
};

namespace Factory
{
    unique_ptr<MouseDriver> create_mouse(const string& mouseTypeName);
};