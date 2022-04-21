//hash table definition

#include <iostream>
#include <vector>
#include "series.h"

using namespace std;

class hashTable{

    float maxLoadFactor;
    int buckets;//table size
    int elements;

    vector<vector<series>> map;//vector of vectors of series objects;

public:
    hashTable();
    float calculateLoadFactor();
    int hashFunction(string title);
    void insert(series s);
    void rehash();//rehash when table is resized
    bool has(string title);
    void remove(string title);
    int getSize();
    void printElements(); //just prints titles, for debugging

    //helper functions for main method
    series findTitle(string title);
    vector<series> findDirector(string director);
    vector<series> findActor(string actor);
    vector<series> findRuntime(int timeMin, int timeMax, int type);
    vector<series> findGenre(string genre);
    vector<series> findReleaseYear(int releaseYr);
    vector<series> findRating(string rating);
};