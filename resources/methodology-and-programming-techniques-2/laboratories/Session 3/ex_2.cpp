#include <queue>
#include <iostream>
using namespace std;

const unsigned char limit = 6;

template <typename T>
void display_queue(queue<T> q)
{
    cout << "[";
    while (!q.empty())
    {
        cout << q.front() << ", ";
        q.pop();
    }

    cout << "]" << endl;
}

template <typename T>
void enforce_limit(queue<T> &v)
{
    while (v.size() > limit)
    {
        cout << "Warning: Queue is full. Element " << v.front() << " is erased." << endl;

        v.pop();
    }
}
int main()
{
    queue<int> q;
    for (size_t i = 1; i <= 12; i++)
    {
        q.push(i+6);
    }
    display_queue(q);
    cout << "length of q: " << q.size() << endl;
    for (size_t i = 0; i < 5; i++)
    {
        q.pop();
    }

    display_queue(q);
    cout << "length of q: " << q.size() << endl;

    enforce_limit(q);
    display_queue(q);
    return 0;
}
