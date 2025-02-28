#include <ui/DrawObject.h>

class Row : public DrawObject {
public:
    std::vector<DrawObject*> children;
    float gap = 5;

    Row(std::vector<DrawObject*> children);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f calculateSize() const override;

    void setPosition(sf::Vector2f position) override;

    void updateLayout();

    void addChild(DrawObject* child);
};