#include <iostream>
#include <string>

using namespace std;

class Cricketer {
private :
    string name;
    int age;
    int matches;
public :
    void setName(string name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setMatches(int matches) {
        this->matches = matches;
    }

    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    int getMatches() {
        return matches;
    }
};

int main() {
    Cricketer P1;
    P1.setName("Mainak Modak");
    P1.setAge(18);
    P1.setMatches(25);

    Cricketer P2;
    P2.setName("Aman Roy");
    P2.setAge(20);
    P2.setMatches(37);

    Cricketer arr[] = {P1, P2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++) {
        cout << "Name : " << arr[i].getName() << endl;
        cout << "Age : " << arr[i].getAge() << endl;
        cout << "Matches : " << arr[i].getMatches() << endl << endl;
    }

    return 0;
}