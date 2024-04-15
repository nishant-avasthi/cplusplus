#include<bits/stdc++.h>
using namespace std;

class Assignment {
private:
    string variableName;
    int value;

public:
    Assignment(string name, int val) : variableName(name), value(val) {}

    string toString() const {
        stringstream ss;
        ss << variableName << " = " << value;
        return ss.str();
    }

    int getValue() const {
        return value;
    }
};

void addAssignment(vector<Assignment*>& assignments) {
    string name;
    int value;
    cout << "Enter variable name: ";
    cin >> name;
    cout << "Enter value: ";
    cin >> value;
    assignments.push_back(new Assignment(name, value));
}

void listAssignments(const vector<Assignment*>& assignments) {
    if (assignments.empty()) {
        cout << "There is no assignment." << endl;
    } else {
        for (const auto& assignment : assignments) {
            cout << assignment->toString() << endl;
        }
    }
}

void statsAssignments(const vector<Assignment*>& assignments) {
    if (assignments.empty()) {
        cout << "There is no assignment." << endl;
    } else {
        int numAssignments = assignments.size();
        auto minMax = minmax_element(assignments.begin(), assignments.end(),
                                     [](Assignment* a, Assignment* b) {
                                         return a->getValue() < b->getValue();
                                     });
        int smallest = (*minMax.first)->getValue();
        int largest = (*minMax.second)->getValue();
        int positiveCount = count_if(assignments.begin(), assignments.end(),
                                     [](Assignment* a) { return a->getValue() > 0; });
        int negativeCount = numAssignments - positiveCount;

        cout << "Number of assignments: " << numAssignments << endl;
        cout << "Smallest assignment: " << smallest << endl;
        cout << "Largest assignment: " << largest << endl;
        cout << "Positive assignments: " << positiveCount << endl;
        cout << "Negative assignments: " << negativeCount << endl;
    }
}

void deleteAssignments(vector<Assignment*>& assignments) {
    for (auto& assignment : assignments) {
        delete assignment;
    }
    assignments.clear();
}

int main() {
    vector<Assignment*> assignments;
    string command;int c=0;

    while (true) {
        cout << "Enter command (add, list, stats, exit): ";
        cin >> command;
        

        if (command == "add") {
            addAssignment(assignments);
        } else if (command == "list") {
            listAssignments(assignments);
        } else if (command == "stats") {
            statsAssignments(assignments);
        } else if (command == "exit") {
            deleteAssignments(assignments);
            break;
        } else {
            c++;
            if(c==5){
                
            cout<<"Attempt exceeded";
            return {};


            }
                
            cout << "Unsupported command. Please try again." << endl;
        }
    }

    return 0;
}