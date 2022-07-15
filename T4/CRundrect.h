#pragma once
#include "CCircle.h"
#include"CRectangle.h"
class CRundrect :
    public CCircle ,CRectangle
{
    CRundrect(double width, double height, double radius, double x, double y)
    {
        CShape shape(x, y);
        CCircle cir(radius, x, y);
        CRectangle(width, height, x, y);
    };
    double Area();
};

