#include <iostream>
#include <ctime>

#include "PriorityQueue.h"

//Constructor
PriorityQueue::PriorityQueue() {
  pq_arr = new int*[10];
  pq_size = 0;
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
        RecMinHeapify(0);
      }
      else if(pq_arr[getChildOf(rootIndex, 3)] != nullptr && pq_arr[getChildOf(rootIndex, 3)] < pq_arr[rootIndex]) {
        int * temp = pq_arr[getChildOf(rootIndex, 3)];
        pq_arr[getChildOf(rootIndex, 3)] = pq_arr[rootIndex];
        pq_arr[rootIndex] = temp;
        RecMinHeapify(0);
      }
      else {
        RecMinHeapify(getChildOf(rootIndex, 1));
        RecMinHeapify(getChildOf(rootIndex, 2));
        RecMinHeapify(getChildOf(rootIndex, 3));
      }
  }
}

void PriorityQueue::RecMaxHeapify(int rootIndex){
  if(pq_arr[rootIndex] != nullptr) {
      if(pq_arr[getChildOf(rootIndex, 1)] != nullptr && pq_arr[getChildOf(rootIndex, 1)] > pq_arr[rootIndex]) {
        int * temp = pq_arr[getChildOf(rootIndex, 1)];
        pq_arr[getChildOf(rootIndex, 1)] = pq_arr[rootIndex];
        pq_arr[rootIndex] = temp;
        RecMaxHeapify(0);
      }
      else if(pq_arr[getChildOf(rootIndex, 2)] != nullptr && pq_arr[getChildOf(rootIndex, 2)] > pq_arr[rootIndex]) {
        int * temp = pq_arr[getChildOf(rootIndex, 2)];
        pq_arr[getChildOf(rootIndex, 2)] = pq_arr[rootIndex];
        pq_arr[rootIndex] = temp;
        RecMaxHeapify(0);
      }
      else if(pq_arr[getChildOf(rootIndex, 3)] != nullptr && pq_arr[getChildOf(rootIndex, 3)] > pq_arr[rootIndex]) {
        int * temp = pq_arr[getChildOf(rootIndex, 3)];
        pq_arr[getChildOf(rootIndex, 3)] = pq_arr[rootIndex];
        pq_arr[rootIndex] = temp;
        RecMaxHeapify(0);
      }
      else {
        RecMaxHeapify(getChildOf(rootIndex, 1));
        RecMaxHeapify(getChildOf(rootIndex, 2));
        RecMaxHeapify(getChildOf(rootIndex, 3));
      }
  }
}

void PriorityQueue::MinHeapify(){
  RecMinHeapify(0);
}

void PriorityQueue::MaxHeapify(){
  RecMaxHeapify(0);
}

void PriorityQueue::RecInsert(int * value, int rootIndex) {
  if(pq_arr[rootIndex] != nullptr) {
      if(pq_arr[getChildOf(rootIndex, 1)] == nullptr) {
        pq_arr[getChildOf(rootIndex, 1)] = value;
      }
      else if(pq_arr[getChildOf(rootIndex, 2)] == nullptr) {
        pq_arr[getChildOf(rootIndex, 2)] = value;
      }
      else if(pq_arr[getChildOf(rootIndex, 3)] == nullptr) {
        pq_arr[getChildOf(rootIndex, 3)] = value;
      }
      else {
        RecInsert(value, getChildOf(rootIndex, 1));
        RecInsert(value, getChildOf(rootIndex, 2));
        RecInsert(value, getChildOf(rootIndex, 3));
      }
  }
}

void PriorityQueue::Insert(int * value) {
  if(pq_arr[0] == nullptr) {
    // std::cout <<"Empty Array, adding first item.\n";
    pq_arr[0] = value;
  }
  else {
    // std::cout <<"First Node: " <<*pq_arr[0] <<std::endl;
    RecInsert(value, 0);
  }
  // IncPQ_Size();
}

bool PriorityQueue::Delete(int value) {
  // DecPQ_Size();
  return true;
}

int PriorityQueue::MaxPQ_Highest() {
  return *pq_arr[0];
}

int PriorityQueue::MaxPQ_Lowest() {
  return 1;
}

int PriorityQueue::MinPQ_Highest() {
  return 1;
}

int PriorityQueue::MinPQ_Lowest() {
  return *pq_arr[0];
}

void PriorityQueue::RecLevelOrder(int rootIndex) {
  if(pq_arr[rootIndex] != nullptr) {
    std::cout <<*pq_arr[rootIndex] <<" ";
  }
  // if(pq_arr[getChildOf(rootIndex, 1)] != nullptr) {
  //   std::cout <<*pq_arr[getChildOf(rootIndex, 1)] <<" ";
  // }
  // if(pq_arr[getChildOf(rootIndex, 2)] != nullptr) {
  //   std::cout <<*pq_arr[getChildOf(rootIndex, 2)] <<" ";
  // }
  // if(pq_arr[getChildOf(rootIndex, 3)] != nullptr) {
  //   std::cout <<*pq_arr[getChildOf(rootIndex, 3)] <<" ";
  // }
    if(pq_arr[rootIndex] != nullptr) {
      RecLevelOrder(getChildOf(rootIndex, 1));
      RecLevelOrder(getChildOf(rootIndex, 2));
      RecLevelOrder(getChildOf(rootIndex, 3));

      std::cout << std::endl;
    }
  }

void PriorityQueue::LevelOrder() {
  std::cout <<"> Output:\n";
  std::cout <<"LevelOrder Traversal \n";

  int pos = 0;
  // std::cout <<"Size: " <<GetPQ_Size() <<std::endl;
  // for(int lcv = 0; lcv < GetPQ_Size(); lcv++) {
  //   std::cout <<*pq_arr[lcv] <<" ";
  // }
  // std::cout << std::endl;

  int level = 0;
  int ind = 1;
  int range = 1;
  std::cout <<*pq_arr[0] <<" \n";

  while(ind < GetPQ_Size()) {
    for(int r = 0; r < level; r++) {
      range = range * 3;
    }
    for(int lcv = 0; lcv < range; lcv++) {
      if(pq_arr[ind] != nullptr) {
        std::cout <<*pq_arr[ind] <<" ";
        ind++;
      }
    }
    level++;
    range = 1;
    std::cout << std::endl;
  }

  // if(pq_arr[0] != nullptr) {
    // std::cout <<*pq_arr[0] <<" \n";
    // RecLevelOrder(0);
  // }
}

double PriorityQueue::Time_MaxLowestPQ() {
  std::clock_t begin = std::clock();
  MaxPQ_Lowest();
  std::clock_t end = std::clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  return elapsed_secs;
}

double PriorityQueue::Time_MinLowestPQ() {
  std::clock_t begin = std::clock();
  MinPQ_Lowest();
  std::clock_t end = std::clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  return elapsed_secs;
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
