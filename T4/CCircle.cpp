#include "CCircle.h"

double CCircle::GetRadius()
{
	return dbRadius;
}

double CCircle::Area()
{
	return PI * dbRadius * dbRadius;
}