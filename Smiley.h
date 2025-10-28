#pragma once
#include "PPP/Graph.h"
using namespace Graph_lib;

class Smiley : public Circle
{
public:
	Smiley(Point p, int r);

	void draw_specifics(Painter& painter) const override;
};
