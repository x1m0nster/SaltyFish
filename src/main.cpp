#include "component.h"
int main() {
    auto main_page = std::make_unique<TestPage>();
    main_page->print();
    return 0;
}
