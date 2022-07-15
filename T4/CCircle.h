#pragma once
#include "CShape.h"

class CCircle :
    public CShape
{
public:
    double dbRadius;
public:
    CCircle(double radius, double x, double y) :dbRadius(radius), CShape(x, y) {};
    double GetRadius();
    double Area();
};

