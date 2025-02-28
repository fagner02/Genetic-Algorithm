#include <ui/Root.h>
#include <iostream>

Root::Root(std::vector<DrawObject*> children) {
    this->children = children;
    for (auto& child : children) {
        child->parent = this;
    }
}

void Root::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto child : children) {
        if (child->visible) {
            target.draw(*child, states);
        }
    }
}

void Root::add(DrawObject* child) {
    children.push_back(child);
}

sf::Vector2f Root::calculateSize() const {
    return size;
}

void Root::setSize(sf::Vector2f size) {
    this->size = size;
    update();
}

void Root::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Root::update() {
    for (auto child : children) {
        child->update();
    }
}
