#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"

class Data{
  public:
    BST<Student> *masterStudent;
    BST<Faculty> *masterFaculty;

    GenStack<BST<Student>> *studentStack;
    GenStack<BST<Faculty>> *facultyStack;

    Data();
    ~Data();
    void printStudents();
    void printFaculty();
    void findStudent();
    void findFaculty();
    void getAdvisor();
    void getStudents();
    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeAdvisor();
    void removeAdvisor();
    void rollback();
    void run(string s);
    void save();
    void getFiles();
};
