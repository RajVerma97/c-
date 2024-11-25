#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <thread>
#include <memory>

#include "project-button.h"
#include "project-path-finder.h"
#include "project-sorting-visualizer.h"

using namespace std;
using namespace sf;



enum class AppMode
{
    MODE_SELECTION,
    PATHFINDING,
    SORTING
};


class Application
{
private:
    RenderWindow window;
    Font font;
    AppMode currentMode;
    PathFinder pathFinder;
    vector<Button> buttons;
    unique_ptr<SortingVisualizer> sortingVisualizer;

public:
    Application() : window(VideoMode(800, 800), "Visualizer App"),
                    pathFinder(window),
                    currentMode(AppMode::MODE_SELECTION)
    {
        if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf"))
        {
            cerr << "Error loading font!" << endl;
        }

        buttons.push_back(Button(Vector2f(200, 50), Vector2f(300, 300), Color(99, 102, 241), Color::White, "Start Pathfinding", font, [this]()
                                 { currentMode = AppMode::PATHFINDING; }));

        buttons.push_back(Button(Vector2f(200, 50), Vector2f(300, 400), Color(99, 102, 241), Color::White, "Sorting Visualizer", font, [this]()
                                 { 
                             currentMode = AppMode::SORTING;
                             sortingVisualizer.reset(new SortingVisualizer()); }));
    }

    void run()
    {
        while (window.isOpen())
        {
            if (currentMode == AppMode::SORTING && sortingVisualizer)
            {
                sortingVisualizer->run();
                if (!sortingVisualizer->getWindow().isOpen())
                {
                    currentMode = AppMode::MODE_SELECTION;
                    sortingVisualizer.reset();
                }
            }
            else
            {
                handleEvents();
                draw();
            }
        }
    }

private:
    void handleEvents()
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                if (currentMode == AppMode::MODE_SELECTION)
                {
                    for (auto &button : buttons)
                    {
                        if (button.isClicked(mousePos))
                            button.onClick();
                    }
                }
                else if (currentMode == AppMode::PATHFINDING)
                {
                    pathFinder.handleClick(mousePos.x, mousePos.y, event.mouseButton.button);
                }
            }

            if (event.type == Event::KeyPressed)
            {
                if (currentMode == AppMode::PATHFINDING &&
                    (event.key.code == Keyboard::Space || event.key.code == Keyboard::Enter))
                {
                    pathFinder.run();
                }
                else if (event.key.code == Keyboard::Escape)
                {
                    currentMode = AppMode::MODE_SELECTION;
                }
            }
        }
    }

    void draw()
    {
        window.clear(Color(0, 0, 0)); 

        if (currentMode == AppMode::MODE_SELECTION)
        {
            for (auto &button : buttons)
                button.draw(window);
        }
        else if (currentMode == AppMode::PATHFINDING)
        {
            pathFinder.draw();
        }

        window.display();
    }
};

int main()
{
    srand(time(nullptr));
    Application app;
    app.run();
    return 0;
}