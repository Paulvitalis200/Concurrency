#include <iostream>
#include <thread>
#include <vector>

void hello() {
    std::cout << "Hello Paul" << std::endl;
}

int main() {
    std::thread t(hello);
    t.join();
    std::cout << "Biri Marung" << std::endl;

    auto myLambda = [](int x) {
        std::cout << "Hello from thread: " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };

    std::vector<std::thread> myThreads;

    for (int i=0; i < 10; i++) {
        myThreads.push_back(std::thread(myLambda, i));
    }

    for (int i = 0; i < 10; i++) {
        myThreads[i].join();
    }
    
    return 0;
}