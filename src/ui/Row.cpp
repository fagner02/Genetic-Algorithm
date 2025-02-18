#include <ui/Row.h>

Row::Row(std::vector<DrawObject*> children) {
    childrenContainer = children;
    updateLayout();
}

void Row::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) return;
    for (auto& child : childrenContainer) {
        child->draw(target, states);
    }
}

sf::Vector2f Row::calculateSize() const {
    float width = 0;
    float height = 0;
    for (auto& child : childrenContainer) {
        auto size = child->calculateSize();
        width += size.x;
        if (size.y > height) {
            height = size.y;
        }
    }
    width += gap * (childrenContainer.size() - 1);
    return sf::Vector2f(width, height);
}

void Row::setPosition(sf::Vector2f position) {
    this->position = position;
    updateLayout();
}

void Row::updateLayout() {
    float height = 0;
    float x = 0;
    for (auto& child : childrenContainer) {
        child->setPosition(sf::Vector2f(position.x + x, position.y));
        auto childSize = child->calculateSize();
        x += childSize.x + gap;
        if (childSize.y > height) {
            height = childSize.y;
        }
    }
    for (auto& child : childrenContainer) {
        auto childSize = child->calculateSize();
        child->setSize(sf::Vector2f(childSize.x, height));
    }
    size = calculateSize();
}

void Row::addChild(DrawObject* child) {
    childrenContainer.push_back(child);
    updateLayout();
}
