/*Define a base class File with a constructor and destructor that print messages,
and a derived class TextFile with its own constructor and destructor that also
print messages. In main(), create a File* pointer and assign it to a dynamically
allocated TextFile object. First, implement the program without making the base
class destructor virtual and observe the output when the object is deleted through
the base class pointer. Then, modify the program to make the destructor in the
File class virtual and compare the results. Explain why using a virtual destructor
is necessary when deleting derived class objects through base class pointers.*/

#include<iostream>
using namespace std;

class File {
    public:
        File() {
            cout << "File Created" << endl;
        }
        ~File() {
            cout << "File Destryoed" << endl;
        }
};

class TextFile : public File {
    public:
        TextFile() {
            cout << "Text File Created" << endl;
        }

        ~TextFile() {
            cout << "Text File Destroyed" << endl;
        }
};

int main() {
    File *F = new TextFile;
    delete F;
    return 0;
}
