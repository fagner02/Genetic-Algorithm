#include <ui/ClickableLabel.h>

ClickableLabel::ClickableLabel(Label* label, std::function<void()> onClick) : label(label), _onClick(onClick) {}

ClickableLabel::ClickableLabel(createLabelArgs args, std::function<void()> onClick) : _onClick(onClick) {
    this->label = new Label(args);
}

void ClickableLabel::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) return;
    label->draw(target, states);
}

sf::Vector2f ClickableLabel::calculateSize() const {
    return label->calculateSize();
}

void ClickableLabel::setPosition(sf::Vector2f position) {
    label->setPosition(position);
}

void ClickableLabel::setSize(sf::Vector2f size) {
    label->setSize(size);
}

sf::FloatRect ClickableLabel::getBounds() {
    return label->getBounds();
}

void ClickableLabel::onClick() {
    label->box.setFillColor(defaultColor);
    pressed = false;
    _onClick();
}

void ClickableLabel::hover() {
    label->box.setFillColor(hoverColor);
}

void ClickableLabel::unhover() {
    label->box.setFillColor(defaultColor);
}

void ClickableLabel::press() {
    pressed = true;
    label->box.setFillColor(pressedColor);
}

void ClickableLabel::release() {
    pressed = false;
    label->box.setFillColor(defaultColor);
}