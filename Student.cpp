/*
Student.cpp
Author:  Brian Weber
Submission  Date: 1/25/17
Purpose:  Student class to test ADT UnsortedList
Statement  of Academic  Honesty:
The  following  code  represents  my  own  work.  I  have  neitherreceived  nor  given  inappropriate assistance. I have not copiedor  modified code from any source other than the course webpageor the course textbook. I recognize that any unauthorizedassistance or plagiarism will be handled in accordance  withthe  University  of  Georgia's  Academic  Honesty  Policy  and  thepolicies  of  this course.  I  recognize  that  my  work  is  basedon  an  assignment  created  by  the  Department  of ComputerScience at the University of Georgia. Any publishingor posting of source code for this project  is strictlyprohibited  unless  you  have written consent  from  the  Departmentof Computer Science  at the  University  of  Georgia.
*/

#include <string>
#include<cstdlib>
#include <iostream>

using namespace std;

class Student{
public:
  Student(int i, string n, string m);
  Student();
  const int getId();
  const string getName();
  const string getMajor();
  void setId(int i);
  void setName(string n);
  void setMajor(string m);
  bool operator==(const Student& s);
private:
  int Id;
  string Name;
  string Major;
}; // Student class

Student::Student() {
  Id = 0000;
  Name = "";
  Major = "";
} // Student

Student::Student(int i, string n, string m) {
  Id = i;
  Name = n;
  Major = m;
} // Student()

bool Student::operator==(const Student& s) {
  if (Id == s.Id) {
    return true;
  }
  else 
    return false;
} // ==

int const Student::getId() {
  return Id;
} // getId

const string Student::getName() {
  return Name;
} // getName

const string Student::getMajor() {
  return Major;
} // getMajor

void Student::setId(int i) {
  Id = i;
} // setId

void Student::setName(string n) {
  Name = n;
} // setName 

void Student::setMajor(string m) {
  Major = m;
} // setMajor
