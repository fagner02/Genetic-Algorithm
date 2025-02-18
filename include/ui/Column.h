#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <ui/DrawObject.h>

class Column : public DrawObject {
public:
    float gap;
    std::vector<DrawObject*> childrenContainer;

    Column(std::vector<DrawObject*> children, float gap);
    void updateLayout();
    void update() override;
    void addChild(DrawObject* child);
    void addChildren(std::vector<DrawObject*> children);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2f calculateSize() const override;
    void setPosition(sf::Vector2f position) override;
};