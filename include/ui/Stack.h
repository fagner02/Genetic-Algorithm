#include <ui/DrawObject.h>

class Stack : public DrawObject {
    std::vector<DrawObject*> children;
public:
    Stack(std::vector<DrawObject*> children);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f calculateSize() const override;

    void setSize(sf::Vector2f size) override;

    void setPosition(sf::Vector2f position) override;

    void update() override;
};