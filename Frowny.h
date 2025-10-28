#pragma once
#include "PPP/Graph.h"
using namespace Graph_lib;

class Frowny : public Circle
{
public:
	Frowny(Point p, int r);

	void draw_specifics(Painter& painter) const override;
};
