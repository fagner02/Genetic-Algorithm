#include <ui/Column.h>

Column::Column(std::vector<DrawObject*> children, float gap) : gap(gap) {
    this->children = children;

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
    for (auto& child : children) {
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
    children.push_back(child);
    child->parent = this;
    updateLayout();
}

void Column::addChildren(std::vector<DrawObject*> children) {
    for (auto& child : children) {
        children.push_back(child);
    }
    updateLayout();
}

void Column::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) return;
    for (auto& child : children) {
        child->draw(target, states);
    }
}

sf::Vector2f Column::calculateSize() const {
    float width = 0;
    float height = 0;
    for (auto& child : children) {
        auto _size = child->calculateSize();
        if (_size.x > width) {
            width = _size.x;
        }
        height += _size.y + gap;
    }
    return sf::Vector2f(width, height);
}

void Column::setPosition(sf::Vector2f position) {
    this->position = position;
    updateLayout();
}