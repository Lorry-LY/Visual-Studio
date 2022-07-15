#include "CRectangle.h"

double CRectangle::GetWidth()
{
	return dbWidth;
}

double CRectangle::GetHeight()
{
	return dbHeight;
}

double CRectangle::Area()
{
	return dbHeight * dbWidth;
}