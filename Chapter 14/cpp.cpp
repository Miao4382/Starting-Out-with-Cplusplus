#include "Roomcarpet.h"

double Roomcarpet::GetCost() const //return the cost for the carpet
{
	return cost_per_inch2 * area;
}

void Roomcarpet::SetWidth(int f, int i)
{
	area.SetWidth(f, i);
}

void Roomcarpet::SetLength(int f, int i)
{
	area.SetLength(f, i);
}