#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>

using namespace std;

/*
 * This program allows the user to work with a list of students; the user can add and delete an individual student.
 * Completed by Artur Drobot October 2016.
 */

struct Student{//Datum in studentList
  char *fname;
  char *lname;
  int id;
  float gpa;
  ~Student(){//These were made using the new operator:
    delete[] fname;
    delete[] lname;
  }
};

//Function prototypes
Student* getStudentPointer();
void printStudentList(vector<Student*> studentList);
void deleteStudent(vector<Student*> &studentList);

int main(){
  vector<Student*> studentList;
  char input[25]; //Input of command
  cout << "Enter \"ADD\" to add a new student entry, \"PRINT\" to print out the current list of students, or \"DELETE\" to delete a student entry." << endl;
  cout << "Enter \"q\" at any time to quit the program." << endl;

  while (true){ //Primary loop
    cout << "Type a command: ";
    cin >> input;
    cout << endl;
    //Convert input to lower case
    int i = 0;
    while(input[i]){
      input[i] = tolower(input[i]);
      i++;
    }
    if(strcmp(input, "q") == 0){//quit
      //Wipe everything the contents of the vector point to.
      for(vector<Student*>::iterator it = studentList.begin(); it != studentList.end(); it++){
	delete (*it);
      }
      //The vector itself should be removed automatically.
      return 0;
    }
    else if(strcmp(input, "add") == 0){
      studentList.push_back(getStudentPointer());
    }
    else if(strcmp(input, "print") == 0){
      printStudentList(studentList);
    }
    else if(strcmp(input, "delete") == 0){
      deleteStudent(studentList);
    }
    else{
      cout << "Command not found." << endl;
    }
  }


  //studentList.push_back(ptr);
  //cout << studentList[0]->fname << endl;
}

Student* getStudentPointer(){//Asks user for student info; creates student with that info and returns its pointer.
  Student* student = new Student(); //New student and pointer at once.
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

void printStudentList(vector<Student*> studentList){//Prints out the student list.
  for(vector<Student*>::iterator it = studentList.begin(); it != studentList.end(); it++){
    cout << (*it)->fname << " " << (*it)->lname << ", ID: " << (*it)->id << ", GPA: ";
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << (*it)->gpa << "." << endl;
  }
  cout << endl;
  return;
}

void deleteStudent(vector<Student*> &studentList){//removes student with given ID from the list (prompts user for id).
  int input;
  cout << "Enter ID of student to be removed: ";
  cin >> input;
  cout << endl;
  bool done = false;
  //Search for student with given id:
  for(vector<Student*>::iterator it = studentList.begin(); it != studentList.end() && !done; it++){
    if((*it)->id == input){
      delete (*it);
      studentList.erase(it);
      done = true;
    }
  }
  if(done){
    cout << "Removed student from list successfully." << endl;
  }
  else{
    cout << "No student found with the given ID." << endl;
  }
  cout << endl;
}
