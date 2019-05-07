#include <iostream>
#include <fstream>
#include "AVLTree.h"
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){

    int insertNum = 0;
    int deleteNum = 0;
    int retrievalNum = 0;
    int count = 0;

    char status;
    string firstN, lastN, ssn;

    AVLTree tempT;

    clock_t start, end;
    double duration;
    start = clock();

    fstream input(argv[1]);

    while (!input.eof()) {
      input >> status >> ssn >> firstN >> lastN;
      string name = firstN + " " + lastN;
        switch(status) {
          case 'i':
            if(tempT.insert(ssn,name)) {
              insertNum++;
            }
            break;
          case 'd':
            if(tempT.deleteNode(ssn)) {
              deleteNum++;
            }
            break;
          case 'r':
            if(tempT.find(ssn)) {
              retrievalNum++;
            }
            break;
        }

    }
    // implement this missing part
    // make the array size inside the hash table is 10007

    cout << "The Number of Valid Insertion: " << insertNum << endl;
    cout << "The Number of Valid Deletion: " << deleteNum << endl;
    cout << "The Number of Valid Retrieval: " << retrievalNum << endl;
    cout << "The height of the AVL tree : " << tempT.height(tempT.getRoot()) << endl;

    end = clock();
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;

    cout << "Time elapsed: "<< duration <<'\n';

    cout << "tree size ..."<< endl;

}
