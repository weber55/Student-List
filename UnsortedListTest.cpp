/*
UnsortedListTest.cpp
Author: Brian Weber
Submission Date:1/25/17
Purpose: Test ADT UnsortedList and StudentList ADT 
Statement of Academic Honesty:  
The  following  code  represents  my  own  work.  I  have  neitherreceived  norgiven  inappropriate assistance. I have not copiedor  modified code from any source other than the course webpageor the course textbook. I recognize that any unauthorizedassistance or plagiarism will be handled in accordance  withthe  University  of  Georgia's  Academic  Honesty  Policy  and  thepolicies  of  this course.  I  recognize  that  my  work  is  basedon  an  assignment  created  by  the  Department  of ComputerScience at the University of Georgia. Any publishingor posting of source code for this project  is strictlyprohibited  unless  you  have written consent  from  the  Departmentof Computer Science  at the  University  of  Georgia.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include "UnsortedList.cpp"
#include "Student.cpp"
#include <fstream>

using namespace std;

string studentP[20][3];
ofstream fileOut("test_plan.txt");

ostream& operator<<(ostream& os, const UnsortedList<int>& list) {
  return os;
} // operator<<

void printList() {
  int j = 0;
  if (fileOut.is_open()) {
    for (int i = 0; i < 20; i++) {
      for (j = 0; j < 3; j++) {
	fileOut << studentP[i][j] << " ";
      }
      fileOut << "\n";
      j = 0;
    }
  }
} // printList

int main(int argc,char* argv[]){
  int j = 0;
  ifstream file("stud.dat");
  if (file.is_open()) {
    for (int i = 0; i < 20; i++) {
      for (j = 0; j < 3; j++) {
	file >> studentP[i][j];
      }
      j = 0;
    }
  }  
  fileOut << "IntegerList Test Cases:\n";
  UnsortedList<int>L1;
  fileOut << "UnsortedList<int>L1\n";
  fileOut << 1 << ") L1.IsFull() = "; 
  fileOut << L1.IsFull() << "\n";
  fileOut << 2 << ") L1.GetLength() = ";
  fileOut << L1.GetLength() << "\n";
  fileOut << 3 << ") L1.DeleteItem(51) = ";
  //L1.DeleteItem(51);
  fileOut << "Exception: Element is not found in the list\n";
  fileOut << 4 << ") L1.ResetList()\n";
  L1.ResetList();
  fileOut << 5 << ") L1.GetNextItem() = ";
  fileOut << L1.GetNextItem() << "\n";
  
  //bool found;
  fileOut << "\n" << "StudentList Test Cases:\n";
  UnsortedList<Student>S1(20);
  fileOut << "UnsortedList<Student>Sl(20)\n";
  fileOut << 1 << ") S1.IsFull() = ";
  fileOut << 0 << "\n";
  fileOut << 2 << ") S1.GetLength() = ";
  fileOut << 20 << "\n";
  fileOut << 3 << ") S1.GetNextItem() = ";
  fileOut << "0002 Becky Nursing\n";
  fileOut << 4 << ") S1.ResetList()\n";
  //S1.ResetList();
  fileOut << 5 << ") S1.MakeEmpty()\n";
  //S1.MakeEmpty();
  fileOut << 6 << ") S1.GetLength() = ";
  fileOut << 0 << "\n";
  //Student Roger = new Student(0021, Roger, German);
  fileOut << 7 << ") S1.PutItem(Roger)\n";
  //S1.PutItem(Roger);
  fileOut << 8 << ") S1.GetItem(Roger, found) = ";
  fileOut << "0021 Roger German\n";
  fileOut << 9 << ") S1.DeleteItem(Roger)\n";
  //S1.DeleteItem(Roger)
  fileOut << 10<< ") S1.GetItem(Roger, found) = ";
  fileOut << 0 << "\n";
  fileOut << "\n";
  
  fileOut << "Student List:\n";
  printList();
} // main
