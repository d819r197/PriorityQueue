#include <iostream>
#include <string>
#include <fstream>

#include "PriorityQueue.h"
#include "Executive.h"

Executive::Executive(std::string path) {
  filePath = path;
  min3_heap = new PriorityQueue;
  max3_heap = new PriorityQueue;
}

int Executive::menuInput() {
  int choice;

  std::cout << "Please choose one of the following commands: \n";
  std::cout << "1. Insert \n";
  std::cout << "2. Delete \n";
  std::cout << "3. PQ_Lowest \n";
  std::cout << "4. PQ_Highest \n";
  std::cout << "5. LevelOrder \n";
  std::cout << "6. Time_LowestPQ \n";
  std::cout << "7. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //Insert
      case 1: {
          int input;
          std::cout << "Please enter the value which you want to enter into the PriorityQueue: ";
          std::cin >> input;
          int * value = new int(input);
          min3_heap->Insert(value);
          // max3_heap->Insert(value);
          break;
      }
      //Delete
      case 2: {
        int input;
        std::cout << "Enter the value to be deleted: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "Output: ";
        // if(min3_heap->Delete(input)) {
        //   std::cout << "Deletion was successful.\n";
        // }
        // else {
        //   std::cout << "Deletion failed. The value: " <<input <<" is not present in the tree.\n";
        // }
        break;
      }
      //min3_heap_Highest
      case 3: {
        std::cout << "Output: The element with the highest priority is: " << min3_heap->MinPQ_Highest() <<".\n";
        // std::cout << "Output: The element with the highest priority is: " << max3_heap->MaxPQ_Highest() <<".\n";
        break;
      }
      //min3_heap_Lowest
      case 4: {
        std::cout << "Output: The element with the lowest priority is: " << min3_heap->MinPQ_Lowest() <<".\n";
        // std::cout << "Output: The element with the lowest priority is: " << max3_heap->MaxPQ_Lowest() <<".\n";
        break;
      }
      //LevelOrder
      case 5: {
          min3_heap->LevelOrder();
          // max3_heap->LevelOrder();
          break;
      }
      //Time_LowestPQ
      case 6: {
          std::cout << "Output: " <<min3_heap->Time_MinLowestPQ() <<"s.\n";
          // std::cout << "Output: " <<max3_heap->Time_MaxLowestPQ() <<"s.\n";
          break;
      }
      //Exit
      case 7: {
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and 7.\n\n";
          break;
      }
    }
  }
}

bool Executive::parseInputFile(PriorityQueue pq) {
  // pq = *min3_heap;
  std::ifstream inputFile(filePath);
  std::string input;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        input += c;
        // std::cout <<"current input: " <<input <<std::endl;
      }
      else {
        // std::cout << "In loop, inserting: " <<input <<" into pq of size: " <<min3_heap->GetPQ_Size() <<std::endl;
        int strInt = std::stoi(input);
        int * value = new int(strInt);
        min3_heap->Insert(value);
        min3_heap->IncPQ_Size();
        input = "";
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
