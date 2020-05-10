#include <iostream>

using namespace std;

class Student{
  public:
    string name;
    string level;
    string major;
    int id;
    int adv;
    double gpa;

    Student();
    Student(string name, string level, string major, int adv, double gpa);
    Student(string name, string level, string major, int adv, int id, double gpa);
    Student(int id);
    ~Student();
    void setAdv(int i);

    friend ostream& operator<<(ostream& os, const Student& s);
    friend bool operator> (const Student &s1, const Student &s2);
    friend bool operator< (const Student &s1, const Student &s2);
    friend bool operator== (const Student &s1, const Student &s2);
    friend bool operator!= (const Student &s1, const Student &s2);
};
