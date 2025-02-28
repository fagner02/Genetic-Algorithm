#include <ui/DrawObject.h>

class Root : public DrawObject {
    std::vector<DrawObject*> children;
public:
    Root(std::vector<DrawObject*> children);

    void add(DrawObject* child);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f calculateSize() const override;

    void setSize(sf::Vector2f size) override;

    void setPosition(sf::Vector2f position) override;

    void update() override;
};