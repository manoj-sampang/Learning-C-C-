/*
=============================================================================
                    ADVANCED CONCEPTS - LESSON 3
=============================================================================

This lesson covers advanced C++ concepts used in the Library Management System.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>

using namespace std;

// 1. INHERITANCE
class Person {
protected:  // Protected members can be accessed by derived classes
    string name;
    int age;
    
public:
    Person(const string& n, int a) : name(n), age(a) {
        cout << "Person constructor called for: " << name << "\n";
    }
    
    virtual ~Person() {  // Virtual destructor for proper cleanup
        cout << "Person destructor called for: " << name << "\n";
    }
    
    // Virtual function - can be overridden by derived classes
    virtual void introduce() const {
        cout << "Hi, I'm " << name << ", age " << age << "\n";
    }
    
    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
};

class Student : public Person {  // Student inherits from Person
private:
    string studentId;
    string course;
    
public:
    Student(const string& n, int a, const string& id, const string& c)
        : Person(n, a), studentId(id), course(c) {
        cout << "Student constructor called for: " << name << "\n";
    }
    
    ~Student() {
        cout << "Student destructor called for: " << name << "\n";
    }
    
    // Override the virtual function
    void introduce() const override {
        cout << "Hi, I'm " << name << ", a " << age << "-year-old student.\n";
        cout << "Student ID: " << studentId << ", Course: " << course << "\n";
    }
    
    string getStudentId() const { return studentId; }
    string getCourse() const { return course; }
};

class Teacher : public Person {
private:
    string subject;
    int experience;
    
public:
    Teacher(const string& n, int a, const string& s, int exp)
        : Person(n, a), subject(s), experience(exp) {
        cout << "Teacher constructor called for: " << name << "\n";
    }
    
    ~Teacher() {
        cout << "Teacher destructor called for: " << name << "\n";
    }
    
    void introduce() const override {
        cout << "Hi, I'm " << name << ", a " << subject << " teacher.\n";
        cout << "Age: " << age << ", Experience: " << experience << " years\n";
    }
    
    string getSubject() const { return subject; }
    int getExperience() const { return experience; }
};

// 2. POLYMORPHISM
void demonstratePolymorphism() {
    cout << "\n=== POLYMORPHISM DEMONSTRATION ===\n\n";
    
    // Create objects
    vector<unique_ptr<Person>> people;
    people.push_back(make_unique<Student>("Alice", 20, "S001", "Computer Science"));
    people.push_back(make_unique<Teacher>("Dr. Smith", 45, "Mathematics", 15));
    people.push_back(make_unique<Student>("Bob", 22, "S002", "Physics"));
    
    cout << "Introducing everyone:\n";
    for (const auto& person : people) {
        person->introduce();  // Calls appropriate version based on actual object type
        cout << "------------------------\n";
    }
}

// 3. TEMPLATES
template<typename T>
class Container {
private:
    vector<T> items;
    
public:
    void add(const T& item) {
        items.push_back(item);
        cout << "Added item to container\n";
    }
    
    void remove(const T& item) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
            cout << "Removed item from container\n";
        } else {
            cout << "Item not found in container\n";
        }
    }
    
    void display() const {
        cout << "Container contents:\n";
        for (const auto& item : items) {
            cout << "- " << item << "\n";
        }
    }
    
    size_t size() const { return items.size(); }
    bool empty() const { return items.empty(); }
};

// Template function
template<typename T>
T findMax(const vector<T>& vec) {
    if (vec.empty()) {
        throw runtime_error("Cannot find max of empty vector");
    }
    
    T maxVal = vec[0];
    for (const auto& item : vec) {
        if (item > maxVal) {
            maxVal = item;
        }
    }
    return maxVal;
}

void demonstrateTemplates() {
    cout << "\n=== TEMPLATES DEMONSTRATION ===\n\n";
    
    // Template class with different types
    Container<string> stringContainer;
    stringContainer.add("Hello");
    stringContainer.add("World");
    stringContainer.add("C++");
    stringContainer.display();
    
    Container<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);
    intContainer.display();
    
    // Template function
    vector<int> numbers = {5, 2, 8, 1, 9, 3};
    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << "\nMax number: " << findMax(numbers) << "\n";
    
    vector<string> words = {"apple", "zebra", "banana", "orange"};
    cout << "Words: ";
    for (const string& w : words) cout << w << " ";
    cout << "\nMax word: " << findMax(words) << "\n";
}

// 4. LAMBDA FUNCTIONS AND STL ALGORITHMS
void demonstrateLambdasAndSTL() {
    cout << "\n=== LAMBDAS AND STL ALGORITHMS ===\n\n";
    
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Original numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << "\n";
    
    // Lambda function to check if number is even
    auto isEven = [](int n) { return n % 2 == 0; };
    
    // Count even numbers
    int evenCount = count_if(numbers.begin(), numbers.end(), isEven);
    cout << "Even numbers count: " << evenCount << "\n";
    
    // Find first number greater than 5
    auto it = find_if(numbers.begin(), numbers.end(), [](int n) { return n > 5; });
    if (it != numbers.end()) {
        cout << "First number > 5: " << *it << "\n";
    }
    
    // Transform all numbers (multiply by 2)
    vector<int> doubled;
    transform(numbers.begin(), numbers.end(), back_inserter(doubled), 
              [](int n) { return n * 2; });
    
    cout << "Doubled numbers: ";
    for (int n : doubled) cout << n << " ";
    cout << "\n";
    
    // Sort in descending order
    sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
    cout << "Sorted descending: ";
    for (int n : numbers) cout << n << " ";
    cout << "\n";
}

// 5. SMART POINTERS
void demonstrateSmartPointers() {
    cout << "\n=== SMART POINTERS DEMONSTRATION ===\n\n";
    
    // unique_ptr - exclusive ownership
    {
        cout << "Creating unique_ptr:\n";
        unique_ptr<Student> student = make_unique<Student>("Charlie", 19, "S003", "Biology");
        student->introduce();
        
        // Transfer ownership
        unique_ptr<Student> anotherPtr = move(student);
        cout << "Ownership transferred\n";
        
        if (!student) {
            cout << "Original pointer is now null\n";
        }
        
        anotherPtr->introduce();
    } // unique_ptr automatically deletes the object here
    
    // shared_ptr - shared ownership
    {
        cout << "\nCreating shared_ptr:\n";
        shared_ptr<Teacher> teacher = make_shared<Teacher>("Prof. Johnson", 50, "Chemistry", 20);
        cout << "Reference count: " << teacher.use_count() << "\n";
        
        {
            shared_ptr<Teacher> anotherRef = teacher;
            cout << "Reference count after copy: " << teacher.use_count() << "\n";
            anotherRef->introduce();
        } // anotherRef goes out of scope here
        
        cout << "Reference count after scope: " << teacher.use_count() << "\n";
    } // teacher is deleted when last shared_ptr is destroyed
}

int main() {
    cout << "=============================================================================\n";
    cout << "                    ADVANCED C++ CONCEPTS TUTORIAL\n";
    cout << "=============================================================================\n";
    
    demonstratePolymorphism();
    demonstrateTemplates();
    demonstrateLambdasAndSTL();
    demonstrateSmartPointers();
    
    cout << "\n=== END OF LESSON 3 ===\n";
    return 0;
}