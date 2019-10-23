#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

class PriorityQueue {
  public:
    //Constructor
    PriorityQueue();

    //Class Methods
    void RecMinHeapify(int rootIndex);
    void RecMaxHeapify(int rootIndex);
    void MinHeapify();
    void MaxHeapify();

    void RecInsert(int * value, int index);
    void Insert(int value);

    bool Delete(int value);

    int PQ_Highest();
    int PQ_Lowest();

    void RecLevelOrder(int rootIndex);
    void LevelOrder();

    double Time_LowestPQ();

    //Helper Functions
    int getChildOf(int parentNum, int childNum);
    int getParentOf(int childNum);

  private:
    int * pq_arr[10];
};

#endif
