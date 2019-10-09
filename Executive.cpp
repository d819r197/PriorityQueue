#include <iostream>
#include <string>
#include <fstream>

#include "PriorityQueue.h"
#include "Executive.h"

Executive::Executive(std::string path) {
  filePath = path;
  pq = new PriorityQueue;
}

int Executive::menuInput() {
  int choice;

  std::cout << "Please choose one of the following commands: \n";
  std::cout << "1. Insert \n";
  std::cout << "2. Delete \n";
  std::cout << "3. Leaf \n";
  std::cout << "4. PrintLeaf \n";
  std::cout << "5. PrintTreeHeight \n";
  std::cout << "6. Preorder \n";
  std::cout << "7. Postorder \n";
  std::cout << "8. Inorder \n";
  std::cout << "9. Levelorder \n";
  std::cout << "10. SearchItem \n";
  std::cout << "11. Exit \n";

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
          //pq->Insert(input);
          break;
      }
      //Delete
      case 2: {
        int input;
        std::cout << "Enter the value to be deleted: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "Output: ";
        // if(pq->Delete(input)) {
        //   std::cout << "Deletion was successful.\n";
        // }
        // else {
        //   std::cout << "Deletion failed. The value: " <<input <<" is not present in the tree.\n";
        // }
        break;
      }
      //PQ_Highest
      case 3: {
        // std::cout << "Output: The element with the highest priority is: " << pq->PQ_Highest() <<".\n";
        break;
      }
      //PQ_Lowest
      case 4: {
        // std::cout << "Output: The element with the lowest priority is: " << pq->PQ_Lowest() <<".\n";
        break;
      }
      //LevelOrder
      case 5: {
          std::cout << "Output: \nLevelOrder Traversal \n";
          pq->LevelOrder();
          break;
      }
      //Time_LowestPQ
      case 6: {
          // std::cout << "Output: " <<pq->Time_LowestPQ() <<"s.\n";
          break;
      }
      //Exit
      case 7: {
        delete pq;
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and 11.\n\n";
          break;
      }
    }
  }
}

bool Executive::parseInputFile() {
  std::ifstream inputFile(filePath);
  std::string input;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        input += c;
      }
      else {
        int strInt = std::stoi(input);
        pq->Insert(strInt);
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
