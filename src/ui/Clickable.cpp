#include <ui/Clickable.h>

ClickableLabel* Clickable::add(ClickableLabel* obj) {
    objs.push_back(obj);
    return obj;
}