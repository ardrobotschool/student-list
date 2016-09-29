#include <iostream>

using namespace std;

struct student{
  char *fname;
  char *lname;
  int id;
  float gpa;
};

int main(){
  student bob;
  bob.fname = new char;
  cin >> bob.fname;
  cout << bob.fname << endl;
}
