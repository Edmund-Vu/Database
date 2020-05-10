#include "Assignment5.h"

using namespace std;

int main(int argc, char const *argv[]){
  Data d;
  string input = "";
  while(input != "14"){
    cout << "1. Print all students and their information (sorted by asending ID number)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending ID number)" << endl;
    cout << "3. Find and display student information given the student's ID" << endl;
    cout << "4. Find and display faculty information given the faculty's ID" << endl;
    cout << "5. Given a student's ID, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the ID" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the ID" << endl;
    cout << "11. Change a student's advisor given the student's ID and the new faculty ID" << endl;
    cout << "12. Remove an advisee from a faculty member given the ID" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;;
    cin >> input;
    d.run(input);
  }
  d.save();
  return 0;
}
