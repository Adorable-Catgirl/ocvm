#include "frame.h"
#include "log.h"
#include "apis/unicode.h"
#include "color/color_map.h"
#include <iostream>

Framer::Framer()
{
    _initial_depth = EDepthType::_8;
}

Framer::~Framer()
{
}

bool Framer::add(Frame* pframe, size_t index)
{
    for (auto pf : _frames)
    {
        if (pf == pframe)
        {
            lout << "attempt to add the same frame twice\n";
            return false;
        }
    }

    if (index < _frames.size()) // reorder
    {
        _frames.insert(_frames.begin() + index, pframe);
    }
    else
    {
        _frames.push_back(pframe);
    }

    pframe->framer(this);

    return onAdd(pframe);
}

Frame::Frame() :
    _framer(nullptr),
    _gpu(nullptr),
    _scrolling(false)
{
}

Frame::~Frame(){}

bool Framer::open()
{
    return onOpen();
}

void Framer::close()
{
    onClose();
    _frames.clear();
}

void Framer::setInitialDepth(EDepthType depth)
{
    _initial_depth = depth;
}

EDepthType Framer::getInitialDepth() const
{
    return _initial_depth;
}

void Frame::framer(Framer* pfr)
{
    _framer = pfr;
}

Framer* Frame::framer() const
{
    return _framer;
}

void Frame::scrolling(bool enable)
{
    _scrolling = enable;
}

bool Frame::scrolling() const
{
    return _scrolling;
}

void Frame::winched(int width, int height)
{
    if (_gpu)
        _gpu->winched(width, height);
}

EDepthType Frame::getDepth() const
{
    if (!_gpu)
        return EDepthType::_1;
    return _gpu->getDepth();
}

bool Frame::write(int x, int y, const Cell& cell)
{
    if (!_framer)
        return false;
    
    _framer->write(this, x, y, cell);
    return true;
}

void Frame::set_gpu(FrameGpu* gpu)
{
    _gpu = gpu;
}
