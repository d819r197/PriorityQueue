#include <iostream>

#include "PriorityQueue.h"

//Constructor
PriorityQueue::PriorityQueue() {
}

//Class Methods
void PriorityQueue::RecMinHeapify(int rootIndex){
  if(pq_arr[rootIndex] != nullptr) {
      if(pq_arr[getChildOf(rootIndex, 1)] != nullptr && pq_arr[getChildOf(rootIndex, 1)] < pq_arr[rootIndex]) {
        int * temp = pq_arr[getChildOf(rootIndex, 1)];
        pq_arr[getChildOf(rootIndex, 1)] = pq_arr[rootIndex];
        pq_arr[rootIndex] = temp;
        RecMinHeapify(0);
      }
      else if(pq_arr[getChildOf(rootIndex, 2)] != nullptr && pq_arr[getChildOf(rootIndex, 2)] < pq_arr[rootIndex]) {
        int * temp = pq_arr[getChildOf(rootIndex, 2)];
        pq_arr[getChildOf(rootIndex, 2)] = pq_arr[rootIndex];
        pq_arr[rootIndex] = temp;
      }
      else if(pq_arr[getChildOf(rootIndex, 3)] != nullptr && pq_arr[getChildOf(rootIndex, 3)] < pq_arr[rootIndex]) {
        int * temp = pq_arr[getChildOf(rootIndex, 3)];
        pq_arr[getChildOf(rootIndex, 3)] = pq_arr[rootIndex];
        pq_arr[rootIndex] = temp;
      }
      else {
        RecMinHeapify(getChildOf(rootIndex, 1));
        RecMinHeapify(getChildOf(rootIndex, 2));
        RecMinHeapify(getChildOf(rootIndex, 3));
      }
  }
}

void PriorityQueue::RecMaxHeapify(int rootIndex){

}

void PriorityQueue::MinHeapify(){

}

void PriorityQueue::MaxHeapify(){

}

void PriorityQueue::RecInsert(int * value, int rootIndex) {
  if(pq_arr[rootIndex] != nullptr) {
      std::cout <<"Looking at val: " <<*value <<std::endl;
      if(pq_arr[getChildOf(rootIndex, 1)] == nullptr) {
        pq_arr[getChildOf(rootIndex, 1)] = value;
      }
      else if(pq_arr[getChildOf(rootIndex, 2)] == nullptr) {
        pq_arr[getChildOf(rootIndex, 1)] = value;
      }
      else if(pq_arr[getChildOf(rootIndex, 3)] == nullptr) {
        pq_arr[getChildOf(rootIndex, 1)] = value;
      }
      else {
        RecInsert(value, getChildOf(rootIndex, 1));
        RecInsert(value, getChildOf(rootIndex, 2));
        RecInsert(value, getChildOf(rootIndex, 3));
      }
  }
}

void PriorityQueue::Insert(int value) {
  if(pq_arr[0] == nullptr) {
    std::cout <<"Empty Array, adding first item.\n";
    pq_arr[0] = &value;
  }
  else {
    std::cout <<"First Node: " <<pq_arr[0] <<std::endl;
    RecInsert(&value, 0);
  }
}

bool PriorityQueue::Delete(int value) {
  return true;
}

int PriorityQueue::PQ_Highest() {
  return 1;
}

int PriorityQueue::PQ_Lowest() {
  return 1;
}

void PriorityQueue::RecLevelOrder(int rootIndex) {
  if(pq_arr[rootIndex] != nullptr) {
    std::cout <<*pq_arr[rootIndex] <<" ";
  }
  std::cout << std::endl;
  RecMinHeapify(getChildOf(rootIndex, 1));
  RecMinHeapify(getChildOf(rootIndex, 2));
  RecMinHeapify(getChildOf(rootIndex, 3));
}

void PriorityQueue::LevelOrder() {
  std::cout <<"> Output:\n";
  std::cout <<"LevelOrder Traversal \n";
  RecLevelOrder(0);
}

double PriorityQueue::Time_LowestPQ() {
  return 0.0;
}

//Helper Functions
int PriorityQueue::getChildOf(int parentNum, int childNum) {
  int index = 3*parentNum+childNum;
  return(index);
}

int PriorityQueue::getParentOf(int childNum) {
  int index = (childNum-1)/3;
  return(index);
}
