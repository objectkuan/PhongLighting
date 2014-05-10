#include "stdafx.h"
#include "Elements.h"

shape::shape()
{
	faces = NULL;
	points = NULL;
	pointAmount = 0;
	faceAmount = 0;
}

point::point()
{
	faceAmount = 0;
}

face::face()
{
}
