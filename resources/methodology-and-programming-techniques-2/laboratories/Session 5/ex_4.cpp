#include <iostream>
#include <thread>

using namespace std;

void print_id() {
    cout << "Child thread ID: " << this_thread::get_id() << endl;
}

int main() {
    cout << "Main thread ID: " << this_thread::get_id() << endl;

    unsigned int n_threads = thread::hardware_concurrency();
    cout << "Hardware concurrency (suggested threads): " << n_threads << endl;

    thread child1(print_id);
    thread child2(print_id);

    child1.join();
    child2.join();

    return 0;
}