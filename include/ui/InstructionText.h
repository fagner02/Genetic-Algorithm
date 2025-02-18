#include <SFML/Graphics.hpp>
#include <ui/DrawObject.h>

#pragma once

class InstructionText : public DrawObject {
public:
    sf::Text text;

    InstructionText(std::wstring text, sf::Font& font);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f calculateSize() const override;

    void setPosition(sf::Vector2f position) override;

    void setText(std::wstring text);
};