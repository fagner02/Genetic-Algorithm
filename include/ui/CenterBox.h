#include <ui/DrawObject.h>
#include <SFML/Graphics.hpp>

#pragma once

class CenterBox : public DrawObject {
public:
    DrawObject* child;

    CenterBox(DrawObject* child);

    CenterBox();

    void updateLayout();

    void update() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setSize(sf::Vector2f size);

    sf::Vector2f calculateSize() const override;

    void setPosition(sf::Vector2f position) override;
};