#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Person {
public:
    string name;
    string decision;

    Person(const string& name, const string& decision) : name(name), decision(decision) {}
};

string findMajorityDecision(const vector<Person>& people) {
    int guiltyCount = 0;
    int notGuiltyCount = 0;

    for (const auto& person : people) {
        if (person.decision == "Guilty") {
            guiltyCount++;
        } else if (person.decision == "NotGuilty") {
            notGuiltyCount++;
        }
    }

    if (guiltyCount >= notGuiltyCount) {
        return "Guilty";
    } else if (notGuiltyCount > guiltyCount) {
        return "NotGuilty";
    }
}

int main() {
    vector<Person> people = {
        Person("Judge", "Guilty")
        Person("Alice", "Guilty"),
        Person("Bob", "NotGuilty"),
        Person("Charlie", "Guilty"),
        Person("David", "NotGuilty"),
        Person("Eve", "Guilty")
    };

    string majorityDecision = findMajorityDecision(people);

    cout << "The majority decision is: " << majorityDecision << endl;

    return 0;
}
