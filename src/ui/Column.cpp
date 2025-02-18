#include <ui/Column.h>

Column::Column(std::vector<DrawObject*> children, float gap) : gap(gap) {
    childrenContainer = children;
    for (auto& child : children) {
        child->parent = this;
    }
    updateLayout();
}

void Column::updateLayout() {
    float y = 0;
    sf::Vector2f pos(position);
    pos.y += margin;
    pos.x += margin;
    for (auto& child : childrenContainer) {
        child->parentUpdated = true;
        child->setPosition(sf::Vector2f(pos.x, pos.y + y));
        y += child->calculateSize().y + gap;
    }
    size = calculateSize();
}

void Column::update() {
    if (childUpdated) {
        childUpdated = false;
        updateLayout();
    }
}

void Column::addChild(DrawObject* child) {
    childrenContainer.push_back(child);
    updateLayout();
}

void Column::addChildren(std::vector<DrawObject*> children) {
    for (auto& child : children) {
        childrenContainer.push_back(child);
    }
    updateLayout();
}

void Column::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) return;
    for (auto& child : childrenContainer) {
        child->draw(target, states);
    }
}

sf::Vector2f Column::calculateSize() const {
    float width = 0;
    float height = 0;
    for (auto& child : childrenContainer) {
        auto size = child->calculateSize();
        if (size.x > width) {
            width = size.x;
        }
        height += size.y + gap;
    }
    return sf::Vector2f(width, height);
}

void Column::setPosition(sf::Vector2f position) {
    this->position = position;
    updateLayout();
}