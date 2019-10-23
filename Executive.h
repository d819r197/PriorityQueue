#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>

#include "PriorityQueue.h"

class Executive {
  public:
    //Constructor
    Executive(std::string path);

    //Class Methods
    int menuInput();
    void run();
    bool parseInputFile(PriorityQueue pq);

    //Helper Functions
    PriorityQueue getMin3Heap() { return *min3_heap; }
    PriorityQueue getMax3Heap() { return *max3_heap; }


  private:
    std::string filePath;
    PriorityQueue * min3_heap;
    PriorityQueue * max3_heap;
};

#endif
