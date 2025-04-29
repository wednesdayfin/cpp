#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    char grade;
    string group = "2025 group";

public:

    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setGrade(char g) {
        grade = g;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    char getGrade() {
        return grade;
    }

    void displayInfo() {
        cout << "Student Info:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Grade: " << getGrade() << endl;
        cout << "Group: " << group << endl;
    }
};

int main() {
    Student student1;

    student1.setName("John Doe");
    student1.setAge(20);
    student1.setGrade('A');

    cout << "Name: " << student1.getName() << endl;
    cout << "Age: " << student1.getAge() << endl;
    cout << "Grade: " << student1.getGrade() << endl;

    student1.displayInfo();

    return 0;
}
