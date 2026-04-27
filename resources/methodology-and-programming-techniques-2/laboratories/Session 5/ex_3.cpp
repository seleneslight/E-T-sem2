#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void print_numbers() {
    for (int i = 1; i <= 5; ++i) {
        cout << "Detached thread: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main() {
    thread my_detached_thread(print_numbers);

    my_detached_thread.detach();

    cout << "Main thread is free to do other things!" << endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Main thread exiting." << endl;

    return 0;
}
