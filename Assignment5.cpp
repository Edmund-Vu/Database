#include "Assignment5.h"

using namespace std;

Data::Data(){
  masterStudent = new BST<Student>();
  masterFaculty = new BST<Faculty>();
  studentStack = new GenStack<BST<Student>>(5);
  facultyStack = new GenStack<BST<Faculty>>(5);
  getFiles();
  studentStack->push(*masterStudent);
  facultyStack->push(*masterFaculty);
}

Data::~Data(){

}

void Data::printStudents(){
  masterStudent->printTree();
}

void Data::printFaculty(){
  masterFaculty->printTree();
}

void Data::findStudent(){
  string input;
  cout << "Enter Student ID: " << endl;
  cin >> input;
  // create a student object with inputted ID
  Student s(stoi(input));
  // check whether the student exists
  if(masterStudent->contains(s)){
    // if student exists, print all information about that student
    cout << masterStudent->search(s) << endl;
  } else{
    cout << "Student not found." << endl;
  }
}

void Data::findFaculty(){
  string input;
  cout << "Enter Faculty ID: " << endl;
  cin >> input;
  // create a faculty object with the inputted ID
  Faculty f(stoi(input));
  // if faculty exists, print all information about that faculty
  if(masterFaculty->contains(f)){
    cout << masterFaculty->search(f) << endl;
  } else{
    cout << "Faculty not found." << endl;
  }
}

void Data::getAdvisor(){
  string input;
  cout << "Enter Student ID: " << endl;
  cin >> input;
  Student s(stoi(input));
  // search for advisor using the student ID
  if(masterStudent->contains(s)){
    cout << masterFaculty->search(s.adv) << endl;
  } else{
    cout << "Student not found." << endl;
  }
}

void Data::getStudents(){
  string input;
  cout << "Enter Faculty ID: " << endl;
  cin >> input;
  // create a faculty object with the inputted id
  Faculty f(stoi(input));
  if(masterFaculty->contains(f)){
    // if the ID matches a faculty in the database, create a faculty object
    // that matches the information in the database
    Faculty t = masterFaculty->search(f);
    for(int i = 0; i < t.adv->size; ++i){
      int x = t.adv->removeBack();
      cout << masterStudent->search(Student(x)) << endl;
      t.adv->insertFront(x);
    }
  } else{
    cout << "Faculty not found." << endl;
  }
}

void Data::addStudent(){
  string name, level, major, adv, gpa;
  cout << "Enter name: " << endl;
  cin >> name;
  cin.clear();
  cout << "Enter level: " << endl;
  cin >> level;
  cin.clear();
  cout << "Enter major: " << endl;
  cin >> major;
  cin.clear();
  cout << "Enter GPA: " << endl;
  cin >> gpa;
  cin.clear();
  cout << "Enter Advisor ID: " << endl;
  cin >> adv;
  cin.clear();
  // if the advisor is already in the database, assign the student to that advisor
  if(masterFaculty->contains(stoi(adv))){
    Student s = Student(name, level, major, stoi(adv), stod(gpa));
    // insert the new student into the BST
    masterStudent->insert(s);
    // add the student to the list of students under their advisor
    masterFaculty->search(stoi(adv)).addAdv(s.id);
    studentStack->push(*masterStudent);
    facultyStack->push(*masterFaculty);
  } else{
    cout << "Advisor not found." << endl;
  }
}

void Data::deleteStudent(){
  string input;
  int adv;
  cout << "Enter Student ID: " << endl;
  cin >> input;
  Student s(stoi(input));
  // check whether the student is in the database
  if(masterStudent->contains(s)){
    adv = masterStudent->search(s).adv;
    // delete the student from the BST
    masterStudent->deleteRec(s);
    // delete the student from their advisor's list of students
    masterFaculty->search(adv).delAdv(stoi(input));
    studentStack->push(*masterStudent);
    facultyStack->push(*masterFaculty);
  } else{
    cout << "Student not found." << endl;
  }
}

void Data::addFaculty(){
  string name, level, dept;
  cout << "Enter name: " << endl;
  cin >> name;
  cout << "Enter level: " << endl;
  cin >> level;
  cout << "Enter department: " << endl;
  cin >> dept;
  // create a faculty object from the inputs
  Faculty f = Faculty(name, level, dept);
  // insert the new faculty into the BST
  masterFaculty->insert(f);
  studentStack->push(*masterStudent);
  facultyStack->push(*masterFaculty);
}

void Data::deleteFaculty(){
  // get the ID's for the faculty to remove and faculty to transfer to
  string input1, input2;
  int adv;
  cout << "Enter Faculty ID: " << endl;
  cin >> input1;
  cout << "Enter Faculty ID to transfer students: " << endl;
  cin >> input2;

  if(input1 != input2){
    Faculty f(stoi(input1));
    Faculty t(stoi(input2));
    // check if both ID's are in the system
    if(masterFaculty->contains(t) && masterFaculty->contains(f)){
      NaiveList<int>* old = masterFaculty->search(f).adv;
      while(old->getSize() != 0){
        int id = old->removeFront();
        Student s = Student(id);
        // change each of the students' advisors to the new advisor
        masterStudent->search(s).setAdv(stoi(input2));
        // add each of the students to their new advisor's list of students
        masterFaculty->search(t).adv->insertFront(id);
      }
      masterFaculty->deleteRec(f);
      studentStack->push(*masterStudent);
      facultyStack->push(*masterFaculty);
    } else{
      cout << "Faculty not found." << endl;
    }
  } else{
    cout << "Please input different IDs" << endl;
  }
}

void Data::changeAdvisor(){
  string id, adv;
  cout << "Enter Student ID: " << endl;
  cin >> id;
  cout << "Enter Advisor ID: " << endl;
  cin >> adv;

  Student s(stoi(id));
  Faculty f(stoi(adv));
  // check whether the IDs exist in their BSTs
  if(masterStudent->contains(s) && masterFaculty->contains(f)){
    // change the student's advisor
    masterStudent->search(s).setAdv(stoi(adv));
    masterFaculty->search(f).addAdv(stoi(id));
    // remove the student from their previous advisor's list of students
    masterFaculty->search(masterStudent->search(s).adv).delAdv(stoi(id));
    studentStack->push(*masterStudent);
    facultyStack->push(*masterFaculty);
  } else{
    cout << "ID does not exist." << endl;
  }
}

void Data::removeAdvisor(){
  string adv, st;
  cout << "Enter Advisor ID: " << endl;
  cin >> adv;
  cout << "Enter Student ID: " << endl;
  cin >> st;

  Student s(stoi(st));
  Faculty f(stoi(adv));
  // check whether the IDs exist in their BSTs
  if(masterStudent->contains(s) && masterFaculty->contains(f)){
    // delete the current advisor
    masterStudent->search(s).setAdv(0);
    masterFaculty->search(masterStudent->search(s).adv).delAdv(stoi(st));
    studentStack->push(*masterStudent);
    facultyStack->push(*masterFaculty);
  }
}

void Data::rollback(){
  string count;
  cout << "How many commands would you like to undo?" << endl;
  cin.clear();
  cin.ignore(10000, '\n');
  getline(cin, count);
  cout << stoi(count) << endl;
  for(int i = 0; i < (stoi(count) + 1); ++i){
    // create copies of the BSTs, except reverting a change
    BST<Faculty> facCopy = facultyStack->pop();
    masterFaculty = &facCopy;
    BST<Student> stCopy = studentStack->pop();
    masterStudent = &stCopy;
  }
}

void Data::run(string s){
  if(s == "1"){
    printStudents();
  } else if(s == "2"){
    printFaculty();
  } else if(s == "3"){
    findStudent();
  } else if(s == "4"){
    findFaculty();
  } else if(s == "5"){
    getAdvisor();
  } else if(s == "6"){
    getStudents();
  } else if(s == "7"){
    addStudent();
  } else if(s == "8"){
    deleteStudent();
  } else if(s == "9"){
    addFaculty();
  } else if(s == "10"){
    deleteFaculty();
  } else if(s == "11"){
    changeAdvisor();
  } else if(s == "12"){
    removeAdvisor();
  } else if(s == "13"){
    rollback();
  } else if(s == "14"){
    return;
  } else{
    cout << "That is an invalid option." << endl;
    cout << endl;
    return;
  }
}

void Data::save(){
  ofstream s, f;
  s.open("studentTable.txt", std::ofstream::out);
  f.open("facultyTable.txt", std::ofstream::out);
  masterStudent->treeToFile(s);
  masterFaculty->treeToFile(f);
}

void Data::getFiles(){
  string line;
  ifstream s, f;
  s.open("studentTable.txt", ifstream::in);
  f.open("facultyTable.txt", ifstream::in);
  if(s){
    // '#' stands for BST null pointers
    while(getline(s, line)){
      int count = 0;
      string id = "";
      string name = "";
      string level = "";
      string major = "";
      string gpa = "";
      string adv = "";
      if(line != "#"){
        // '/' is the delimiter for field values
        for(int i = 0; i  < line.size(); ++i){
          if(line[i] == '/'){
            ++count;
            continue;
          } else if(line[i] != '#' && count == 0){
            name += line[i];
          } else if(line[i] != '#' && count == 1){
            level += line[i];
          } else if(line[i] != '#' && count == 2){
            major += line[i];
          } else if(line[i] != '#' && count == 3){
            adv += line[i];
          } else if(line[i] != '#' && count == 4){
            gpa += line[i];
          } else if(line[i] != '#' && count == 5){
            id += line[i];
          }
        }
        masterStudent->insert(Student(name, level, major, stoi(adv), stod(gpa), stoi(id)));
      }
    }
  }
  if(f){
    while(getline(f, line)){
      int count = 0;
      string id = "";
      string name = "";
      string level = "";
      string dept = "";
      string adv = "";
      if(line != "#"){
        for(int j = 0; j < line.size(); ++j){
          if(line[j] == '/'){
            ++count;
            continue;
          } else if(line[j] == '-'){
            break;
          } else if(line[j] != '#' && count == 0){
            name += line[j];
          } else if(line[j] != '#' && count == 1){
            level += line[j];
          } else if(line[j] != '#' && count == 2){
            dept += line[j];
          } else if(line[j] != '#' && count == 3){
            id += line[j];
          }
        }
        Faculty f = Faculty(name, level, dept, stoi(id));
        for(int k = 0; k < line.size(); ++k){
          if(line[k] == '|'){
            f.addAdv(stoi(adv));
            adv = "";
          } else{
            adv += line[k];
          }
        }
        masterFaculty->insert(f);
      }
    }
  }
}
