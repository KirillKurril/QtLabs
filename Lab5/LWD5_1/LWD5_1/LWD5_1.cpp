#include "queue.h"
#include <iostream>
#include <random>

int random_number() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 99);
    return dist(mt);
}

int main() {
    queue ueue;
    for (int i = 0; i < 10; i++) {
        ueue.push(random_number());
        std::cout << ueue[i] << " ";
    }
    ueue.cycle();
    return 0;
}
