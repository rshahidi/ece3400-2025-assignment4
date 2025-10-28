#include "PPP/Graph.h"
#include "Clock.h"
#include <chrono>
#include <thread>
#include <cmath>
#include <numbers>

using namespace Graph_lib;

Clock::Clock(Point p, int r) :Circle(p, r) {}

void Clock::draw_specifics(Painter& painter) const
{
	Circle c(Point(point(0).x + radius(), point(0).y + radius()), radius());
	c.set_fill_color(((Circle*)this)->fill_color());
	c.draw(painter);

	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	// Convert to local time structure
	std::tm* local_time = std::localtime(&now_c);

	// Extract hour, minute, and second
	int hour = local_time->tm_hour;
	int minute = local_time->tm_min;
	int second = local_time->tm_sec;

	// DRAW HOUR, MINUTE AND SECOND HANDS HERE
}