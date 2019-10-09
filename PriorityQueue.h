#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

class PriorityQueue {
  public:
    //Constructor
    PriorityQueue();

    //Class Functions
    bool Insert(int value);
    bool Delete(int value);
    int PQ_Highest();
    int PQ_Lowest();
    void LevelOrder();
    double Time_LowestPQ();

  private:

};

#endif
