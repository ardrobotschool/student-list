#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Student{
  char *fname;
  char *lname;
  int id;
  float gpa;
};

Student* getStudentPointer();

int main(){
  vector<Student*> studentList;
  char *input = new char;
  cout << "Enter \"ADD\" to add a new student entry, \"PRINT\" to print out the current list of students, or \"DELETE\" to delete a student entry." << endl;
  cout << "Enter \"q\" at any time to quit the program." << endl;

  while (true){ //Primary loop
    cout << "Type a command: ";
    cin >> input;
    cout << endl;
    if(strcmp(input, "q") == 0){
      break;
    }
    else if(strcmp(input, "ADD") == 0){
      studentList.push_back(getStudentPointer());
      cout << studentList[0]->lname << ", " << studentList[0]->gpa << endl;
    }
  }


  //studentList.push_back(ptr);
  //cout << studentList[0]->fname << endl;
}

Student* getStudentPointer(){//Asks user for student info; creates student with that info and returns its pointer.
  Student* student = new Student();
  student->fname = new char[20];
  student->lname = new char[20];
  cout << "Enter student\'s first name: ";
  cin >> student->fname;
  cout << endl;
  cout << "Enter student\'s last name: ";
  cin >> student->lname;
  cout << endl;
  cout << "Enter student\'s ID: ";
  cin >> student->id;
  cout << endl;
  //student.id = stoi(id);
  cout << "Enter student\'s GPA: ";
  cin >> student->gpa;
  cout << endl;
  //student.gpa = stof(gpa);

  return student;
}
