#include <ui/InstructionText.h>

InstructionText::InstructionText(std::wstring text, sf::Font& font) {
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(20);
    this->text.setOrigin(this->text.getLocalBounds().getPosition());
    this->text.setFillColor(sf::Color(0, 0, 0));
    this->text.setOutlineColor(sf::Color(255, 255, 255));
    this->text.setOutlineThickness(3);
}

void InstructionText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (visible) target.draw(text, states);
}

sf::Vector2f InstructionText::calculateSize() const {
    return text.getGlobalBounds().getSize();
}

void InstructionText::setPosition(sf::Vector2f position) {
    text.setPosition(position);
}

void InstructionText::setText(std::wstring text) {
    this->text.setString(text);
    parent->childUpdated = true;
    parent->update();
}