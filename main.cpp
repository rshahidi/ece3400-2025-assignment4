#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "Clock.h"

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;
    Window w(140, 240, "Traffic light");

    Rectangle r({ 10, 10 }, 120, 220);
    r.set_fill_color(Color::black);

    const int second = 1000;
    const int amber_delay_seconds = 1;
    const int red_green_delay_seconds = 12;
    const int amber_delay = amber_delay_seconds * second;
    const int red_green_delay = red_green_delay_seconds * second;

    Clock red({ 70,50 }, 30);
    Clock amber({ 70, 120 }, 30);
    Clock green({ 70, 190 }, 30);

    w.attach(r);
    w.attach(red);
    w.attach(amber);
    w.attach(green);

    while (true)
    {
        for (int i = 0; i < 3; i++) // Cycle through lights 3 times
        {
            for (int j = 0; j < red_green_delay_seconds; j++)
            {
                amber.set_fill_color(Color::black);
                green.set_fill_color(Color::black);
                red.set_fill_color(Color::red);
                w.timer_wait(second); // wait a second before redrawing
            }
            for (int j = 0; j < amber_delay_seconds; j++)
            {
                amber.set_fill_color(Color::yellow);
                red.set_fill_color(Color::black);
                green.set_fill_color(Color::black);
                w.timer_wait(second); // wait a second before redrawing
            }
            for (int j = 0; j < red_green_delay_seconds; j++)
            {
                amber.set_fill_color(Color::black);
                red.set_fill_color(Color::black);
                green.set_fill_color(Color::green);
                w.timer_wait(second); // wait a second before redrawing
            }
        }
    }
    app.gui_main();
}
