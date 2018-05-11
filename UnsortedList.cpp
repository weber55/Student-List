/*
UnsortedList.cpp
Author: Brian Weber
Submission Date: 1/25/2017
Purpose: Define ADT UnsortedList mothods 
Statement of Academic Honesty:
The  following  code  represents  my  own  work.  I  have  neitherreceived  nor given  inappropriate assistance. I have not copiedor  modified code from any source other than the course webpageor the course textbook. I recognize that any unauthorizedassistance or plagiarism will be handled in accordance  withthe  University  of  Georgia's  Academic  Honesty  Policy  and  thepolicies  of  this course.  I  recognize  that  my  work  is  basedon  an  assignment  created  by the  Department  of ComputerScience at the University of Georgia. Any publishing or posting of source code for this project  is strictlyprohibited  unless  you  have written consent  from  the  Departmentof Computer Science  at the  University  of  Georgia.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

const int MAX_ITEMS = 50;
enum RelationType {LESS, EQUAL, GREATER};

template<class ItemType>
class UnsortedList {
private:
  int id = 0;
  int length;
  int currentPos = 0;
  ItemType info[MAX_ITEMS];
  int FindItem(ItemType item);
public:
  UnsortedList();
  UnsortedList(int n);
  ~UnsortedList();
  RelationType ComparedTo(ItemType) const;
  void MakeEmpty();
  bool IsFull();
  int GetLength();
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  ItemType GetNextItem();
  void SplitLists(ItemType item, UnsortedList& list1, UnsortedList& list2);
};
  
template<class ItemType>
UnsortedList<ItemType>::UnsortedList(){
  length = 50;
}

template<class ItemType>
UnsortedList<ItemType>::~UnsortedList(){
  length = 0;
  id = 0;
  currentPos = 0;
}


template<class ItemType>
UnsortedList<ItemType>::UnsortedList(int n){
  length = n;
}

template<class ItemType>
RelationType UnsortedList<ItemType>::ComparedTo(ItemType item) const {
  if (id < item.id) {
    return LESS;
  }
  else if (id > item.id) {
    return GREATER;
  }
  else {
    return EQUAL;
  }
}

template<class ItemType>
void UnsortedList<ItemType>::MakeEmpty(){
  //pre: none
  //post: list is empty
  length = 0;
}

template<class ItemType>
bool UnsortedList<ItemType>::IsFull(){
  //pre: list is initialized
  //post: return true if list is full  
  bool full = false;
  if (length == 50) {
    full = true;
  }
  return (full);
}

template<class ItemType>
int UnsortedList<ItemType>::GetLength(){
  //pre: list is initialized
  //post: returns number of elements in list
  return length;
}

template<class ItemType>
ItemType UnsortedList<ItemType>::GetItem(ItemType item, bool& found){
  //pre: list is initialized, key member of item is initialized
  //post: if there is an element someItemwhose key matches item’s key, then found = true and copy of someItemis returned; otherwise found = false and item is returned.List is unchanged
  int loc = 0;
  found = false;
  bool search = (loc < length);
  while (search && !found) {
    switch (item.ComparedTo(info[loc])) {
    case LESS :
    case GREATER :
      loc++;
      search = (loc < length);
      break;
    case EQUAL :
      found = true;
      item = info[loc];
      break;
    }
  }
}

template<class ItemType>
void UnsortedList<ItemType>::PutItem(ItemType item){
  //pre: list is initialized and not full
  //post: item is in the list
  bool repeat = false;
  for (int loc = 0; loc < length; loc++) {
    if (item.ComparedTo(info[loc]) == EQUAL) {
      cout << "Exception: Item already in list";
      repeat = true;
    }
  }
  if (repeat == false) {
    info[length] = item;
    length++;
  }
}

template<class ItemType>
void UnsortedList<ItemType>::DeleteItem(ItemType item){
  //pre: list is initialized and key member is initialized
  //post: no element in list has a key matching item's key
  bool match = false;
  for (int loc = 0; loc < length; loc++) {
    if (item.comparedTo(info[loc]) == EQUAL) {
	info[loc] = info[length - 1];
	length--;
	match = true;
    }
  }
  if (match == false) {
    cout << "Exception: Element is not found in the list";
  }
}

template<class ItemType>
void UnsortedList<ItemType>::ResetList(){
  //pre: list is initialized
  //post: current position is prior to list
  currentPos = -1;
}

template<class ItemType>
ItemType UnsortedList<ItemType>::GetNextItem(){
  //pre: list is initialized, current position defined, and element at current position is not last in list
  //post: current position is updated to next position and a copy of element at current position is returned.
  currentPos++;
  ItemType item = info[currentPos];
  return item;
}

template<class ItemType>
void UnsortedList<ItemType>::SplitLists(ItemType item, UnsortedList& list1, UnsortedList& list2) {
  //pre: list is initialized
  //post: If  list  is  not empty: list1 contains all the  items of  list  whose keys are  less than or equal  to  item’s  key; list2 contains all the items of list whose keys are greater than item’s key.If  list  was empty  an exception  is thrown  displaying  appropriate  message  to the user.
  if (length == 0) {
    cout << "Exception: List is Empty";
  }
  else {
    //
  }
}

template<class ItemType>
int UnsortedList<ItemType>::FindItem(ItemType item) {
  //pre: list is initialized and key member of item is initialized
  //post: list is unchanged if element whose key matches item's key then index is returned otherwise -1 is returned.
  return -1;
}
