#include <ui/CenterBox.h>
#include <iostream>
CenterBox::CenterBox(DrawObject* child) : child(child) {
    updateLayout();
}

CenterBox::CenterBox() {
    child = nullptr;
}

void CenterBox::updateLayout() {
    if (parent != nullptr) {
        size = parent->size;
    }
    if (child) {
        auto childSize = child->calculateSize();
        auto childPos = sf::Vector2f(
            position.x + (size.x - childSize.x) / 2.0f,
            position.y + (size.y - childSize.y) / 2.0f
        );
        child->setPosition(childPos);
    }
}

void CenterBox::update() {
    updateLayout();
}

void CenterBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (visible && child) {
        child->draw(target, states);
    }
}

void CenterBox::setSize(sf::Vector2f size) {
    this->size = size;
    updateLayout();
}

sf::Vector2f CenterBox::calculateSize() const {
    if (child) {
        return child->calculateSize();
    }
    return size;
}

void CenterBox::setPosition(sf::Vector2f position) {
    this->position = position;
    updateLayout();
}