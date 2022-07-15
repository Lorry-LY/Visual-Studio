#pragma once
#include "CShape.h"
class CRectangle :
    public CShape
{
public:
    double dbWidth;
    double dbHeight;
public:
    CRectangle(double width, double height, double x, double y) :dbWidth(width), dbHeight(height), CShape(x, y) { };
    double GetWidth();
    double GetHeight();
    double Area();
};

