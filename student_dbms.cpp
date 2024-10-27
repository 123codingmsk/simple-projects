#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    string course;

public:
    Student(int id, string name, int age, string course) 
        : id(id), name(name), age(age), course(course) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }

    void display() const {
        cout << "ID: " << id << "\nName: " << name << "\nAge: " << age 
             << "\nCourse: " << course << "\n" << endl;
    }

    // Save student data to file
    void saveToFile(ofstream& file) const {
        file << id << "\n" << name << "\n" << age << "\n" << course << "\n";
    }

    // Load student data from file
    static Student loadFromFile(ifstream& file) {
        int id, age;
        string name, course;
        file >> id;
        file.ignore();
        getline(file, name);
        file >> age;
        file.ignore();
        getline(file, course);
        return Student(id, name, age, course);
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;
    string filename = "students.txt";

public:
    void addStudent() {
        int id, age;
        string name, course;

        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Student Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Student Course: ";
        getline(cin, course);

        Student student(id, name, age, course);
        students.push_back(student);
        saveToFile();

        cout << "Student added successfully.\n" << endl;
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students to display.\n";
            return;
        }

        for (const Student& student : students) {
            student.display();
        }
    }

    void searchStudentById(int id) const {
        for (const Student& student : students) {
            if (student.getId() == id) {
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    void saveToFile() const {
        ofstream file(filename);
        for (const Student& student : students) {
            student.saveToFile(file);
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file(filename);
        while (file) {
            if (file.peek() == EOF) break;
            students.push_back(Student::loadFromFile(file));
        }
        file.close();
    }
};

int main() {
    StudentManagementSystem sms;
    sms.loadFromFile();

    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayAllStudents();
                break;
            case 3: {
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                sms.searchStudentById(id);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
