#ifndef PROJECT_BUTTON_H
#define PROJECT_BUTTON_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button
{
public:
    RectangleShape shape;
    Text text;
    function<void()> onClick;

    Button(const Vector2f &size, const Vector2f &position, Color fillColor, Color textColor, const string &label, Font &font, function<void()> onClickCallback)
    {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(fillColor);

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(24);
        text.setFillColor(textColor);
        text.setPosition(position.x + 10, position.y + 10);

        onClick = onClickCallback;
    }

    void draw(RenderWindow &window)
    {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(const Vector2i &mousePos)
    {
        if (shape.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
        {
            shape.setFillColor(Color(100, 100, 255));

            return true;
        }

        return false;
    }

    bool isHovered(const Vector2i &mousePos) const
    {
        return shape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

    void setDefaultFillColor()
    {
        shape.setFillColor(Color(255, 255, 255));
    }

    void setClickedFillColor()
    {
        shape.setFillColor(Color(0, 210, 255));
    }

    void setClickedTextColor()
    {
        text.setFillColor(Color::White);
    }

    void setDefaultTextColor()
    {
        text.setFillColor(Color(0, 0, 0));
    }
};

#endif
