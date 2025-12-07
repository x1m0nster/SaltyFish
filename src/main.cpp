#include "component.h"
#include <chrono>
#include <thread>

int main() {

    auto page = std::make_unique<Component::TestPage>();
    while (true) {
        page->print();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}
