#include <iostream>
#include <thread>
#include <string>
#include <vector>

using namespace std;

void msg(const string &str) {
    cout << "Message: " << str << endl;
}

int main() {
    vector<string> messages = {
        "Thread 1 says hello!",
        "Thread 2 checking in.",
        "Thread 3 is running.",
        "Thread 4 almost done.",
        "Thread 5 says goodbye!"
    };

    vector<thread> my_threads;

    for (const string& message : messages) {
        my_threads.push_back(thread(msg, message));
    }

    for (thread& t : my_threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}