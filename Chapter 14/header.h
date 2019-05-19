#ifndef LANDTRACT_H
#define LANDTRACT_H

#include "Feet_inch.h"

class Land_tract
{
private:
	Feet_inch width;
	Feet_inch length;
public:
	void SetWidth(int f, int i);
	void SetLength(int f, int i);
	
	int Land_tract::GetAreaFeet() const;
	int Land_tract::GetAreaInch() const;
};

#endif