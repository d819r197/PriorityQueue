#include <iostream>

#include "Executive.h"

int main(int argc, char* argv[]) {
  //./DoubleLinkedList filePath
  if(argc == 2) {
    Executive exec(argv[1]);
    if(exec.parseInputFile(exec.getMin3Heap())) {
      // if(exec.parseInputFile(exec.getMax3Heap())) {
        // std::cout <<"Import completed!\n";
        exec.run();
      // }
      // else {
        // std::cout <<"Parse failed to complete on Max3Heap. Please try again.\n";
      // }
    }
    else {
      std::cout <<"Parse failed to complete on Min3Heap. Please try again.\n";
      return 0;
    }
  }
  //Bad Input
  else {
    std::cout<<"Invalid input. Try again.\n";
  }

  return 0;
}
