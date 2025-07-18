/*
=============================================================================
                    FILE HANDLING - LESSON 2
=============================================================================

This lesson covers file input/output operations used in the Library Management System.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Student {
private:
    string name;
    int age;
    string course;
    
public:
    Student() : name(""), age(0), course("") {}
    
    Student(const string& n, int a, const string& c) 
        : name(n), age(a), course(c) {}
    
    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }
    
    // Convert object to string for file storage
    string toString() const {
        return name + "," + std::to_string(age) + "," + course;
    }
    
    // Create object from string (read from file)
    void fromString(const string& data) {
        stringstream ss(data);
        string item;
        
        getline(ss, name, ',');
        getline(ss, item, ',');
        age = std::stoi(item);
        getline(ss, course, ',');
    }
    
    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Course: " << course << "\n";
    }
};

// 1. WRITING TO FILES
void demonstrateFileWriting() {
    cout << "\n=== FILE WRITING DEMONSTRATION ===\n\n";
    
    // Create some student objects
    vector<Student> students;
    students.push_back(Student("Alice Johnson", 20, "Computer Science"));
    students.push_back(Student("Bob Smith", 22, "Mathematics"));
    students.push_back(Student("Carol Davis", 19, "Physics"));
    
    // Writing to file
    ofstream outFile("students.txt");
    
    if (outFile.is_open()) {
        cout << "Writing students to file...\n";
        
        for (const auto& student : students) {
            outFile << student.toString() << "\n";
            cout << "Wrote: " << student.toString() << "\n";
        }
        
        outFile.close();
        cout << "File writing completed successfully!\n";
    } else {
        cout << "Error: Could not open file for writing!\n";
    }
}

// 2. READING FROM FILES
void demonstrateFileReading() {
    cout << "\n=== FILE READING DEMONSTRATION ===\n\n";
    
    vector<Student> loadedStudents;
    ifstream inFile("students.txt");
    
    if (inFile.is_open()) {
        cout << "Reading students from file...\n";
        string line;
        
        while (getline(inFile, line)) {
            if (!line.empty()) {
                Student student;
                student.fromString(line);
                loadedStudents.push_back(student);
                cout << "Read: " << line << "\n";
            }
        }
        
        inFile.close();
        cout << "File reading completed successfully!\n";
        
        cout << "\nLoaded students:\n";
        for (const auto& student : loadedStudents) {
            student.display();
        }
    } else {
        cout << "Error: Could not open file for reading!\n";
    }
}

// 3. APPENDING TO FILES
void demonstrateFileAppending() {
    cout << "\n=== FILE APPENDING DEMONSTRATION ===\n\n";
    
    // Create a new student
    Student newStudent("David Wilson", 21, "Engineering");
    
    // Append to existing file
    ofstream appendFile("students.txt", ios::app);
    
    if (appendFile.is_open()) {
        cout << "Appending new student to file...\n";
        appendFile << newStudent.toString() << "\n";
        appendFile.close();
        cout << "Appended: " << newStudent.toString() << "\n";
    } else {
        cout << "Error: Could not open file for appending!\n";
    }
}

// 4. STRING STREAM PROCESSING
void demonstrateStringStream() {
    cout << "\n=== STRING STREAM DEMONSTRATION ===\n\n";
    
    string data = "John,25,Biology,3.8,Active";
    cout << "Original string: " << data << "\n";
    
    // Parse using stringstream
    stringstream ss(data);
    string name, course, status;
    int age;
    double gpa;
    
    getline(ss, name, ',');
    ss >> age; ss.ignore(); // ignore the comma
    getline(ss, course, ',');
    ss >> gpa; ss.ignore();
    getline(ss, status, ',');
    
    cout << "Parsed data:\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Course: " << course << "\n";
    cout << "GPA: " << gpa << "\n";
    cout << "Status: " << status << "\n";
}

// 5. ERROR HANDLING
void demonstrateErrorHandling() {
    cout << "\n=== ERROR HANDLING DEMONSTRATION ===\n\n";
    
    // Try to read from non-existent file
    ifstream testFile("nonexistent.txt");
    
    if (!testFile.is_open()) {
        cout << "File does not exist - this is expected!\n";
    }
    
    // Try to write to protected location (might fail)
    ofstream protectedFile("/root/test.txt");
    
    if (!protectedFile.is_open()) {
        cout << "Cannot write to protected location - this is expected!\n";
    }
    
    // Demonstrate file state checking
    ifstream dataFile("students.txt");
    if (dataFile.is_open()) {
        cout << "File opened successfully!\n";
        
        string line;
        while (getline(dataFile, line)) {
            if (dataFile.fail()) {
                cout << "Error reading file!\n";
                break;
            }
            cout << "Read line: " << line << "\n";
        }
        
        if (dataFile.eof()) {
            cout << "Reached end of file successfully!\n";
        }
        
        dataFile.close();
    }
}

int main() {
    cout << "=============================================================================\n";
    cout << "                    FILE HANDLING TUTORIAL\n";
    cout << "=============================================================================\n";
    
    demonstrateFileWriting();
    demonstrateFileReading();
    demonstrateFileAppending();
    demonstrateStringStream();
    demonstrateErrorHandling();
    
    cout << "\n=== END OF LESSON 2 ===\n";
    return 0;
}