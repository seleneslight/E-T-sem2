#include <iostream>
#include <thread>
#include <string>

using namespace std;

void msg(const string &str)  {
    cout << "Message: " << str << endl;
}

int main(){
  // notice how the parameters of the function msg are passed
  // during the initialization of the thread
  thread my_runner1(msg, "hi!");
  thread my_runner2(msg, "bye!");

  my_runner1.join();
  my_runner2.join();
}