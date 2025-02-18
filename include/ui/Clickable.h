#include <vector>
#include <ui/ClickableLabel.h>

class Clickable {
public:
    std::vector<ClickableLabel*> objs = {};

    ClickableLabel* add(ClickableLabel* obj);
};