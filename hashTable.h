
//hash table definition
#include <iostream>
#include <vector>
#include "series.h"
using namespace std;

class hashTable{

    float maxLoadFactor;
    int buckets;//table size
    int elements;

    vector<Series> map[];//array of vectors;

    public:
    HashTable(int b);
    float calculateLoadFactor();
    int hashFunction(string title);
    void insert(Series s);
    void rehash();//rehash when table is resized
    bool has(string title);
    void remove(string title);

};