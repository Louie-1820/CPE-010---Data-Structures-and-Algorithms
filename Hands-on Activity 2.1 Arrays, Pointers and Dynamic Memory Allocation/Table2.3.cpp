#include <iostream>
#include <string.h>

class Student {
    private: 
        std::string studentName;
        int studentAge;
        int *data;
        size_t size;

    public:
        //Constructor 
        Student (std::string newName = "John Doe", int newAge = 18) {
            studentName = std::move (newName);
            studentAge = newAge;
            std::cout << "Constructor Successfully Called." << std::endl;
            
        };

        //Deconstructor
        ~Student () {
            std::cout << "Destructor Successfully Called." << std::endl;
        }

        //Copy Constructor 
        Student (const Student &copyStudent) {
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
            std::cout << "Copy Constructor Successfully Called." << std::endl;
        }

        //Copy Assignment Operator
        Student& operator = (const Student &copyStudent) {
            if (this != &copyStudent) {
                studentName = copyStudent.studentName;
                studentAge = copyStudent.studentAge;
                std::cout << "Copy Assignment Operator Successfully Called." << std::endl;
            }
            return *this; 
        }

        //Display Attributes 
        void printDetails () {
            std::cout << this->studentName << " " << this->studentAge << std::endl;
        }

};

int main() {
    const size_t j = 5;

    Student studentList[j] = {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    for(int i = 0; i < j; i++){ //loop A
        Student *ptr = new Student(namesList[i], ageList[i]);
        studentList[i] = *ptr;

        delete ptr;
        ptr = nullptr;
}

     for(int i = 0; i < j; i++){ //loop B
        studentList[i].printDetails();
}

    return 0;
}