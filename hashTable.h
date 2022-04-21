//hash table definition

#include <iostream>
#include <vector>
#include "series.h"

using namespace std;

class hashTable{

    float maxLoadFactor;
    int buckets;//table size
    int elements;

    vector<vector<Series>> map;//vector of vectors of Series objects;

public:
    hashTable(int b);
    float calculateLoadFactor();
    int hashFunction(string title);
    void insert(Series s);
    void rehash();//rehash when table is resized
    bool has(string title);
    void remove(string title);
    int getSize();
    void printElements(); //just prints titles, for debugging

    //helper functions for main method
    vector<Series> findMovieTitle(string title);
    vector<Series> findDirector(string director);
    vector<Series> findActor(string actor);
    vector<Series> findRuntime(int timeMin, int timeMax, int type);
};