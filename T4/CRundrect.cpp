#include "CRundrect.h"

double CRundrect::Area()
{
	
	return CRectangle::Area() - CCircle::Area();
}