#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "TennisWinners.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"

using namespace std;

int main() {
    // Project 3 Main.cpp file
    // file output object
    ofstream myFile;

    // All the binary search tree stuff
    BinarySearchTree<int> orderedInts;
    BinarySearchTree<int> randomInts;
    BinarySearchTree<TennisWinners> tWinnersBST;

    // ordered binary search tree of ints
    for(int i = 1; i <= 100; i++){
        orderedInts.add(i);
    }

    // creat the file for ordered BST depth recording
    myFile.open("../BSTOrderedInts.csv");
    myFile << "i, depth\n";
    // recording depth of these values for ordered
    int depth;
    cout << "Beginning of the ordered BST list" << endl;
    for(int i = 1; i < 100; i++){
        depth = 0;
        // TODO: record depths to file (BSTOrderedInts.csv)
        orderedInts.find(i, &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of the ordered BST list" << endl;
    // closing the file
    myFile.close();

    // TODO: answer question about these 3 in the report
    // search for 0, 101, and 102
    depth = 0;
    // search for 0
    cout << "Is 0 in the tree: " << orderedInts.find(0, &depth) << endl;
    cout << "The depth reached was: " << depth << endl;

    depth = 0;
    // searching for 101
    cout << "Is 101 in the tree: " << orderedInts.find(101, &depth) << endl;
    cout << "The depth reached was: " << depth << endl;

    depth = 0;
    // searching for 102
    cout << "Is 102 in the tree: " << orderedInts.find(102, &depth) << endl;
    cout << "The depth reached was: " << depth << endl;

    // unsorted list creation
    vector<int> randInt;
    for(int i = 1; i <= 100; i++){
        randInt.push_back(i);
    }
    /*
    Original Line was random_shuffle(tWinners.begin(), tWinners.end()); however random_shuffle has since not only been depricated but altogether removed in c++17
    link to solution https://stackoverflow.com/questions/45013977/random-shuffle-is-not-a-member-of-std-error
    */

    random_device rd;
    mt19937 g(rd());
    shuffle(randInt.begin(), randInt.end(), g);
    for(int i = 0; i < 100; i++){
        randomInts.add(randInt[i]);
    }

    // unordered list depth loop
    // creating file for unordered bst list
    myFile.open("../BSTRandomOrder.csv");
    myFile << "i, depth\n";

    cout << "Beginning of the unordered BST list" << endl;
    for(int i = 1; i <= 100; i++){
        depth = 0;
        // TODO: record depths to file here (BSTRandomOrder.csv)
        orderedInts.find(randInt[i], &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of the unordered BST list" << endl;
    // close file
    myFile.close();

    // BST of tennis winners
    vector<TennisWinners> tWinners;
    getTennisWinnersFromFile("TennisWins2000.csv", tWinners);
    for(int i = 0; i < tWinners.size(); i++){
        tWinnersBST.add(tWinners[i]);
    }

    // creat depth of tennis winners file
    myFile.open("../BSTTennisWinners.csv");
    myFile << "i, depth\n";

    // depth of tenis winners
    cout << "Beginning of the tWinners BST tree" << endl;
    for(int i = 0; i < tWinners.size(); i++){
        depth = 0;
        // TODO: record depth to file here last of the BST file outputs (BSTTennisWinners.csv)
        // TODO: Graph the depths of this one in excell
        tWinnersBST.find(tWinners[i], &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of tWinners BST tree" << endl;
    // closing my file
    myFile.close();
    // end of BST stuff


    // Beginning of AVL tree stuff
    AVLTree<int> orderedAVL;
    AVLTree<int> unorderedAVL;
    AVLTree<TennisWinners> tWinnersAVL;

    // filling ordered int avl tree
    for(int i = 1; i <= 100; i++){
        orderedAVL.add(i);
    }
    // filling unorderedd int avl tree
    vector<int> unorderedAVLvec;
    for(int i = 1; i <= 100; i++){
        unorderedAVLvec.push_back(i);
    }

    /*
    Original Line was random_shuffle(unorderedAVLvec.begin(), unorderedAVLvec.end()); however random_shuffle has since not only been depricated but altogether removed in c++17
    link to solution https://stackoverflow.com/questions/45013977/random-shuffle-is-not-a-member-of-std-error
    */

    mt19937 h(rd()); // mt19937 is the type of random sorter i am using for these randoms
    shuffle(unorderedAVLvec.begin(), unorderedAVLvec.end(), h);


    // open file for avl ordered int
    myFile.open("../AVLOrderedInts.csv");
    myFile << "i, depth\n";
    // getting depth of all values in ordered avl int tree
    cout << "Beginning of ordered AVL tree" << endl;
    for(int i = 1; i <= 100; i++){
        depth = 0;
        // TODO: record these depths to a file (AVLOrderedInts.csv)
        orderedAVL.find(i, &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of ordered AVL tree" << endl;
    // close file
    myFile.close();


    // open file for unordered avl int tree
    myFile.open("../AVLUnorderedInts.csv");
    myFile << "i, depth\n";

    // getting the depth of all values in the unordered avl int tree
    cout << "Beginning of unordered AVL tree" << endl;
    for(int i = 0; i < 100; i++){
        depth = 0;
        // TODO: record these depths to a file (AVLUnorderedInts.csv)
        unorderedAVL.find(unorderedAVLvec[i], &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of unordered AVL Tree" << endl;
    // close file
    myFile.close();

    // AVL tree for tennis winners
    for(int i = 0; i < tWinners.size(); i++){
        tWinnersAVL.add(tWinners[i]);
    }
    // open file for tennis winner avl
    myFile.open("../AVLTennisWinners.csv");
    myFile << "i, depth\n";

    // depth of tenis winners AVL
    cout << "Beginning of the tWinners AVL tree" << endl;
    for(int i = 0; i < tWinners.size(); i++){
        depth = 0;
        // TODO: record these depths to a file (AVLTennisWinners.csv)
        // TODO: graph this one to compare with BST and SPLAY
        tWinnersAVL.find(tWinners[i], &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of tWinners AVL tree" << endl;
    // close file
    myFile.close();
    // end of AVL stuff


    // Beginning of Splay trees
    SplayTree<int> orderedSplay(false);
    SplayTree<int> orderedSplay2(false);
    SplayTree<TennisWinners> tWinnersSplay1(true);
    SplayTree<TennisWinners> tWinnersSplay2(true);
    SplayTree<TennisWinners> tWinnersSplay3(false);
    SplayTree<TennisWinners> tWinnersSplay4(false);

    // adding the valuse into the int splay trees
    for(int i = 1; i <= 100; i++){
        orderedSplay.add(i);
        orderedSplay2.add(i);
    }

    // open file for splay int tree 1
    myFile.open("../SplayOrderedInts.csv");
    myFile << "i, depth\n";

    // searching the integers in order on the first tree
    cout << "Beginning of the ordered search of the int spaly tree" << endl;
    for(int i = 1; i <= 100; i++){
        depth = 0;
        // TODO: record depth to a file (SplayOrderedInts.csv)
        orderedSplay.find(i, &depth);
        myFile << i << ", " << depth << "\n";
    };
    cout << "End of the ordered search of the int spaly tree" << endl;
    // close file
    myFile.close();

    // open file for splay random order
    myFile.open("../SplayUnorderedInts.csv");
    myFile << "i, depth\n";

    // searching the intergers in a random order in the second tree
    cout << "Beginning of the unordered search of the splay tree int" << endl;
    for(int i = 0; i < 100; i++){
        depth = 0;
        // using one of my previouse random ordered int vecotrs for simplicity
        // TODO: record depth to a file (SplayUnorderedInts.csv)
        orderedSplay2.find(unorderedAVLvec[i], &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of the unordered search of the splay tree int" << endl;
    // close file
    myFile.close();

    // Splay trees for Tennis winners
    // adding the values into all the trees
    for(int i = 0; i < tWinners.size(); i++){
        tWinnersSplay1.add(tWinners[i]);
        tWinnersSplay2.add(tWinners[i]);
        tWinnersSplay3.add(tWinners[i]);
        tWinnersSplay4.add(tWinners[i]);
    }

    // open file for splay twinners 1
    myFile.open("../SplaytWinnersOrderedTrue.csv");
    myFile << "i, depth\n";

    // searching tWinnersSplay1 which is set to true for splay on add
    cout << "Beginning of the first ordered tWinnersSplay" << endl;
    for(int i = 0; i < tWinners.size(); i++){
        depth = 0;
        // TODO: record these depths to a file (SplaytWinnersOrderedTrue.csv)
        tWinnersSplay1.find(tWinners[i], &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of the first ordered tWinnersSplay" << endl;
    // close file
    myFile.close();

    // open file for splay tWinners 3
    myFile.open("../SplaytWinnersOrderedFalse.csv");
    myFile << "i, depth\n";

    // searching tWinnersSplay3 which is set to false for splay on add
    cout << "Beginning of the second ordered tWinners Splay" << endl;
    for(int i = 0; i < tWinners.size(); i++){
        depth = 0;
        // TODO: record these depths to a file (SplaytWinnersOrderedFalse.csv)
        tWinnersSplay3.find(tWinners[i], &depth);
        myFile << i << ", " << depth << "\n";
    }
    cout << "End of the second ordered tWinners Splay tree" << endl;
    // close file
    myFile.close();

    // searching the other trees in a random order
    // creat a copy of the tWinners vec and make it a random order to do this
    vector<TennisWinners> tWinRandOrder;
    tWinRandOrder = tWinners;
    
    /*
    Original Line was random_shuffle(ttWinRandOrder.begin(), tWinRandOrder.end()); however random_shuffle has since not only been depricated but altogether removed in c++17
    link to solution https://stackoverflow.com/questions/45013977/random-shuffle-is-not-a-member-of-std-error
    */

    mt19937 l(rd()); // mt19937 (mersenne twister engine) is the type of random sorter i am using for these randoms
    shuffle(tWinRandOrder.begin(), tWinRandOrder.end(), l);

    // open file for twinners splay 2
    myFile.open("../SplaytWinnersUnorderedTrue.csv");
    myFile << "i, depth\n";


    // searching tWinnersSplay2 which is set to true for splay on add
    // using the random ordered tWinners vector copy
    cout << "Beginning of the first random order search of tWinners splay" << endl;
    for(int i = 0; i < tWinRandOrder.size(); i++){
        for(int j = 0; j < 5; j++) {
            depth = 0;
            // TODO: record depths to file (SplaytWinnersUnorderedTrue.csv)
            // TODO: Graph these to compare to other trees
            tWinnersSplay2.find(tWinRandOrder[i], &depth);
            myFile << i << ", " << depth << "\n";
        }
    }
    cout << "End of the first random order search of twinners splay" << endl;
    // close file
    myFile.close();

    // open file for twinners splay 4
    myFile.open("../SplaytWinnersUnorderedFalse.csv");
    myFile << "i, depth\n";

    // second search of tWinnersSplay4 which is set to false for splay on add
    cout << "Beginning of the second random order search of tWinsplay" << endl;
    for(int i = 0; i < tWinRandOrder.size(); i++) {
        for (int j = 0; j < 5; j++) {
            depth = 0;
            // TODO: record depth to file (SplaytWinnersUnorderedFalse.csv)
            // TODO: graph these to compare to other trees
            tWinnersSplay4.find(tWinRandOrder[i], &depth);
            myFile << i << ", " << depth << "\n";
        }
    }
    cout << "End of the second random order search of tWinsSplay" << endl;
    // close file
    myFile.close();

    // returning 0 means there were no errors in the run any other number means error
    return 0;
}
