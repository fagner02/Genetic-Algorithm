#include <ui/Stack.h>
#include <iostream>

Stack::Stack(std::vector<DrawObject*> children) {
    this->children = children;
    for (auto& child : children) {
        child->parent = this;
    }
}

void Stack::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto child : children) {
        if (child->visible) {
            target.draw(*child, states);
        }
    }
}

sf::Vector2f Stack::calculateSize() const {
    return parent == nullptr ? sf::Vector2f(0, 0) : parent->size;
}

void Stack::setSize(sf::Vector2f size) {
    this->size = size;
}

void Stack::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Stack::update() {
    if (parent != nullptr)
        size = parent->size;
    for (auto child : children) {
        child->update();
    }
}