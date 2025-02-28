#include <ui/Row.h>

Row::Row(std::vector<DrawObject*> children) {
    this->children = children;
    for (auto& child : children) {
        child->parent = this;
    }
    updateLayout();
}

void Row::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) return;
    for (auto& child : children) {
        child->draw(target, states);
    }
}

sf::Vector2f Row::calculateSize() const {
    float width = 0;
    float height = 0;
    for (auto& child : children) {
        auto size = child->calculateSize();
        width += size.x;
        if (size.y > height) {
            height = size.y;
        }
    }
    width += gap * (children.size() - 1);
    return sf::Vector2f(width, height);
}

void Row::setPosition(sf::Vector2f position) {
    this->position = position;
    updateLayout();
}

void Row::updateLayout() {
    float height = 0;
    float x = 0;
    for (auto& child : children) {
        child->setPosition(sf::Vector2f(position.x + x, position.y));
        auto childSize = child->calculateSize();
        x += childSize.x + gap;
        if (childSize.y > height) {
            height = childSize.y;
        }
    }
    for (auto& child : children) {
        auto childSize = child->calculateSize();
        child->setSize(sf::Vector2f(childSize.x, height));
    }
    size = calculateSize();
}

void Row::addChild(DrawObject* child) {
    children.push_back(child);
    child->parent = this;
    updateLayout();
}
