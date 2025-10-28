#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "Smiley.h"
#include "Frowny.h"

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;
    Window w(140, 240, "Traffic light");

    Rectangle r({ 10, 10 }, 120, 220);
    r.set_fill_color(Color::black);

    Frowny red({ 70,50 }, 30);
    Frowny amber({ 70, 120 }, 30);
    Smiley green({ 70, 190 }, 30);

    w.attach(r);
    w.attach(red);
    w.attach(amber);
    w.attach(green);
    const int second = 1000;
    const int yellow_delay = 1 * second;
    const int red_green_delay = 12 * second;
   
    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            red.set_fill_color(Color::red); 
            w.timer_wait(red_green_delay);
            amber.set_fill_color(Color::yellow);
            w.timer_wait(yellow_delay);

            red.set_fill_color(Color::black);
            amber.set_fill_color(Color::black);
            green.set_fill_color(Color::green);
            w.timer_wait(red_green_delay);
            amber.set_fill_color(Color::yellow);
            green.set_fill_color(Color::black);
            w.timer_wait(yellow_delay);

            amber.set_fill_color(Color::black);
        }
    }
    app.gui_main();
}
