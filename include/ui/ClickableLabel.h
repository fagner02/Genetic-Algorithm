#pragma once

#include <functional>
#include "DrawObject.h"
#include "Label.h"

class ClickableLabel : public DrawObject {
public:
    Label* label;
    sf::Color hoverColor = sf::Color(150, 150, 150);
    sf::Color pressedColor = sf::Color(200, 200, 200);
    sf::Color defaultColor = sf::Color(100, 100, 100);
    bool pressed = false;

    ClickableLabel(Label* label, std::function<void()> onClick);
    ClickableLabel(createLabelArgs args, std::function<void()> onClick);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2f calculateSize() const override;
    void setPosition(sf::Vector2f position) override;
    void setSize(sf::Vector2f size) override;
    sf::FloatRect getBounds() override;

    void onClick();
    void hover();
    void unhover();
    void press();
    void release();

private:
    std::function<void()> _onClick;
};