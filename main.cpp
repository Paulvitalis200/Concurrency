#include <iostream>
#include <thread>
#include <vector>

void hello() {
    std::cout << "Hello Paul" << std::endl;
}

int main() {
    std::thread t(hello);
    t.join();

    std::vector<std::jthread> myThreads;

    auto lambda = [](int x) {
        std::cout << "Hello from thread: " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };

    for (int i = 0; i < 10; i++) {
        myThreads.push_back(std::jthread(lambda, i));
    }

    // for (int i = 0; i < 10; i++) {
    //     myThreads[i].join();
    // }



    std::cout << "This is the main thread" << std::endl;
    return 0;
}

// To run with jthreads, use C++ version 20. 
// Use command g++-16 -std=c++20 -o main main.cpp
