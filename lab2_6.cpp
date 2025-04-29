#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    char name[50];
    int id;
    float grade;
};

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Add a student\n";
        cout << "2. Display all students\n";
        cout << "3. Search student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Student list is full!\n";
                    break;
                }
                Student s;
                cout << "Enter name: ";
                cin.ignore(); // Clear newline from input buffer
                cin.getline(s.name, 50);

                cout << "Enter ID: ";
                cin >> s.id;
                cout << "Enter grade: ";
                cin >> s.grade;

                students[studentCount++] = s;
                cout << "Student added successfully!\n";
                break;
            }
            case 2: {
                if (studentCount == 0) {
                    cout << "No students to display.\n";
                } else {
                    cout << "\n--- Student List ---\n";
                    for (int i = 0; i < studentCount; ++i) {
                        cout << "Name: " << students[i].name
                             << ", ID: " << students[i].id
                             << ", Grade: " << students[i].grade << endl;
                    }
                }
                break;
            }
            case 3: {
                int searchId;
                bool found = false;
                cout << "Enter ID to search: ";
                cin >> searchId;

                for (int i = 0; i < studentCount; ++i) {
                    if (students[i].id == searchId) {
                        cout << "Student found:\n";
                        cout << "Name: " << students[i].name
                             << ", Grade: " << students[i].grade << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student with ID " << searchId << " not found.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
