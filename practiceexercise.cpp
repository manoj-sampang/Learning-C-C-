/*
=============================================================================
                    PRACTICE EXERCISES - LESSON 5
=============================================================================

This lesson provides hands-on exercises to practice the concepts learned.
Complete each exercise to reinforce your understanding.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

/*
=============================================================================
EXERCISE 1: CREATE A SIMPLE STUDENT CLASS
=============================================================================

Task: Create a Student class with the following requirements:
1. Private members: name, studentId, grade (A, B, C, D, F)
2. Constructor that takes name and studentId
3. Getter and setter methods for all members
4. A method to display student information
5. A method to check if the student is passing (grade A, B, or C)

Complete the class below:
*/

class Student {
private:
    // TODO: Add private members here
    
public:
    // TODO: Add constructor here
    
    // TODO: Add getter methods here
    
    // TODO: Add setter methods here
    
    // TODO: Add display method here
    
    // TODO: Add isPassing method here
};

/*
=============================================================================
EXERCISE 2: CREATE A CLASSROOM MANAGEMENT SYSTEM
=============================================================================

Task: Create a Classroom class that manages multiple students:
1. Store students in a vector
2. Add method to enroll a new student
3. Add method to find a student by ID
4. Add method to display all students
5. Add method to count passing students
6. Add method to save students to file
7. Add method to load students from file

Complete the class below:
*/

class Classroom {
private:
    vector<Student> students;
    string className;
    
public:
    Classroom(const string& name) : className(name) {}
    
    // TODO: Implement enrollStudent method
    void enrollStudent(const Student& student) {
        // Your code here
    }
    
    // TODO: Implement findStudent method
    Student* findStudent(const string& studentId) {
        // Your code here
        return nullptr;
    }
    
    // TODO: Implement displayAllStudents method
    void displayAllStudents() {
        // Your code here
    }
    
    // TODO: Implement countPassingStudents method
    int countPassingStudents() {
        // Your code here
        return 0;
    }
    
    // TODO: Implement saveToFile method
    void saveToFile(const string& filename) {
        // Your code here
    }
    
    // TODO: Implement loadFromFile method
    void loadFromFile(const string& filename) {
        // Your code here
    }
};

/*
=============================================================================
EXERCISE 3: TEMPLATE PRACTICE
=============================================================================

Task: Create a generic Container template class:
1. Store items of any type in a vector
2. Add method to insert an item
3. Add method to remove an item
4. Add method to find an item
5. Add method to get size
6. Add method to display all items

Complete the template below:
*/

template<typename T>
class Container {
private:
    // TODO: Add private members
    
public:
    // TODO: Implement insert method
    void insert(const T& item) {
        // Your code here
    }
    
    // TODO: Implement remove method
    bool remove(const T& item) {
        // Your code here
        return false;
    }
    
    // TODO: Implement find method
    bool find(const T& item) const {
        // Your code here
        return false;
    }
    
    // TODO: Implement size method
    size_t size() const {
        // Your code here
        return 0;
    }
    
    // TODO: Implement display method
    void display() const {
        // Your code here
    }
};

/*
=============================================================================
EXERCISE 4: INHERITANCE PRACTICE
=============================================================================

Task: Create a hierarchy for library items:
1. Base class: LibraryItem (title, id, isAvailable)
2. Derived class: Book (author, isbn)
3. Derived class: Magazine (issueNumber, month)
4. Each class should have appropriate constructors and methods
5. Use virtual functions for polymorphism

Complete the classes below:
*/

class LibraryItem {
protected:
    // TODO: Add protected members
    
public:
    // TODO: Add constructor
    
    // TODO: Add virtual destructor
    
    // TODO: Add getter methods
    
    // TODO: Add virtual display method
    
    // TODO: Add borrow and return methods
};

class Book : public LibraryItem {
private:
    // TODO: Add private members specific to Book
    
public:
    // TODO: Add constructor
    
    // TODO: Override display method
    
    // TODO: Add Book-specific methods
};

class Magazine : public LibraryItem {
private:
    // TODO: Add private members specific to Magazine
    
public:
    // TODO: Add constructor
    
    // TODO: Override display method
    
    // TODO: Add Magazine-specific methods
};

/*
=============================================================================
EXERCISE 5: FILE HANDLING PRACTICE
=============================================================================

Task: Create a simple inventory system:
1. Create an Item class with name, quantity, and price
2. Create an Inventory class that manages items
3. Implement save/load functionality
4. Add methods to add, remove, and search items

Complete the implementation:
*/

class Item {
private:
    // TODO: Add private members
    
public:
    // TODO: Add constructor
    
    // TODO: Add getter and setter methods
    
    // TODO: Add toString method for file storage
    
    // TODO: Add fromString method for file loading
    
    // TODO: Add display method
};

class Inventory {
private:
    // TODO: Add private members
    
public:
    // TODO: Implement addItem method
    
    // TODO: Implement removeItem method
    
    // TODO: Implement searchItem method
    
    // TODO: Implement displayAll method
    
    // TODO: Implement saveToFile method
    
    // TODO: Implement loadFromFile method
};

/*
=============================================================================
SOLUTIONS AND TESTING
=============================================================================

Below are the solutions to the exercises. Try to complete them yourself first!
*/

// SOLUTION FOR EXERCISE 1
class StudentSolution {
private:
    string name;
    string studentId;
    char grade;
    
public:
    StudentSolution(const string& n, const string& id) 
        : name(n), studentId(id), grade('F') {}
    
    // Getters
    string getName() const { return name; }
    string getStudentId() const { return studentId; }
    char getGrade() const { return grade; }
    
    // Setters
    void setName(const string& n) { name = n; }
    void setStudentId(const string& id) { studentId = id; }
    void setGrade(char g) { 
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D' || g == 'F') {
            grade = g;
        }
    }
    
    void display() const {
        cout << "Name: " << name << ", ID: " << studentId << ", Grade: " << grade << "\n";
    }
    
    bool isPassing() const {
        return grade == 'A' || grade == 'B' || grade == 'C';
    }
};

// Test function for the solutions
void testSolutions() {
    cout << "\n=== TESTING SOLUTIONS ===\n\n";
    
    // Test Student class
    cout << "Testing Student class:\n";
    StudentSolution student("John Doe", "S001");
    student.setGrade('B');
    student.display();
    cout << "Is passing: " << (student.isPassing() ? "Yes" : "No") << "\n\n";
    
    // You can add more tests here for other solutions
}

/*
=============================================================================
CHALLENGE EXERCISES
=============================================================================

For advanced practice, try these challenges:

1. MINI LIBRARY SYSTEM
   Create a complete mini library system with:
   - User authentication
   - Book management
   - Borrowing system
   - File persistence
   - Search functionality

2. GRADE CALCULATOR
   Create a system that:
   - Manages multiple courses
   - Calculates GPA
   - Generates transcripts
   - Saves/loads student data

3. INVENTORY MANAGEMENT
   Create a system for a store that:
   - Manages products
   - Tracks sales
   - Generates reports
   - Handles low stock alerts

4. BANKING SYSTEM
   Create a simple banking system with:
   - Account management
   - Transactions (deposit, withdraw, transfer)
   - Transaction history
   - Interest calculation
*/

int main() {
    cout << "=============================================================================\n";
    cout << "                    PRACTICE EXERCISES\n";
    cout << "=============================================================================\n";
    
    cout << "This file contains exercises for you to practice.\n";
    cout << "Read through each exercise and implement the required functionality.\n";
    cout << "Solutions are provided at the bottom for reference.\n\n";
    
    testSolutions();
    
    cout << "=== END OF EXERCISES ===\n";
    return 0;
}