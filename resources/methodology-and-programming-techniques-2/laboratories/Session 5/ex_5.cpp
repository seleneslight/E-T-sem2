#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int global_counter = 0;
mutex counter_mutex;

void increase_counter(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lock(counter_mutex);
        global_counter++;
    }
}

int main() {
    int increments[3] = {1000, 2000, 3000}; 

    thread t1(increase_counter, increments[0]);
    thread t2(increase_counter, increments[1]);
    thread t3(increase_counter, increments[2]);

    t1.join();
    t2.join();
    t3.join();

    cout << "Final counter value: " << global_counter << endl;

    return 0;
}