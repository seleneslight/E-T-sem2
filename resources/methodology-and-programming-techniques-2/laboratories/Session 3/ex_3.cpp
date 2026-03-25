#include <iostream>
#include <queue>

using namespace std;

class Applicant {
public:
    int applicant_num;
    int time;
};

class QueueManager {
private:
    queue<Applicant> eit;
    int next_id = 1;
    const int MAX_CAPACITY = 5; 

public:
    void addApplicant() {
        if (eit.size() >= MAX_CAPACITY) {
            cout << "Service Suspended: Queue has exceeded capacity." << endl;
            return;
        }

        Applicant p;
        p.applicant_num = next_id++;
        p.time = 0; 
        eit.push(p);

        cout << "Added applicant #" << p.applicant_num << ". Total in queue: " << eit.size() << endl;
    }

    void removeApplicant() {
        if (!eit.empty()) {
            cout << "Serving applicant #" << eit.front().applicant_num << endl;
            eit.pop();
            
            int waiting = (eit.size() > 0) ? (eit.size() - 1) : 0;
            cout << "Applicants currently waiting for service: " << waiting << endl;
        } else {
            cout << "Queue is empty." << endl;
        }
    }

    bool isLimitExceeded() {
        if (eit.size() >= MAX_CAPACITY) {
            cout << "[ALERT] Queue limit reached! Further additions suspended." << endl;
            return true;
        }
        return false;
    }
};

int main() {
    QueueManager manager;

    manager.addApplicant(); // ID 1
    manager.addApplicant(); // ID 2
    manager.addApplicant(); // ID 3
    manager.addApplicant(); // ID 4
    manager.addApplicant(); // ID 5
    
    manager.isLimitExceeded();
    manager.addApplicant(); 

    cout << "--- Removing an applicant ---" << endl;
    manager.removeApplicant();

    return 0;
}