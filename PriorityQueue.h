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
    void Insert(int * value);

    bool Delete(int value);

    int MaxPQ_Highest();
    int MaxPQ_Lowest();
    int MinPQ_Highest();
    int MinPQ_Lowest();

    void RecLevelOrder(int rootIndex);
    void LevelOrder();

    double Time_MaxLowestPQ();
    double Time_MinLowestPQ();

    //Helper Functions
    int getChildOf(int parentNum, int childNum);
    int getParentOf(int childNum);

    void IncPQ_Size() { pq_size++; }
    void DecPQ_Size() { pq_size--; }
    int GetPQ_Size() { return pq_size; }

  private:
    int ** pq_arr;
    int pq_size;
};

#endif
