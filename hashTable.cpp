#pragma once
#include <math.h>
#include "hashTable.h"

using namespace std;

hashTable:: HashTable(int b){
    maxLoadFactor = .7;
    buckets = b;
    elements = 0;
    map = vector<Series> [buckets];
}

float hashTable:: calculateLoadFactor(){
    return (float)elements/ buckets;

}

int hashTable:: hashFunction(string title){
    //hash function
    int index = 0;
    int i = 0;
    for(char c: title){
        index = int(c) * math.Pow(7, i);
        t++;
    }

    //reduce
    index %= buckets;
    return buckets;
}

void hashTable:: insert(Series s){
    int index = hashFunction(s.getTitle());
    map[index].push_back(s);
    elements++;
    if(calculateLoadFactor() > maxLoadFactor)
        rehash();
    
}

void hashTable:: rehash(){
    buckets *= 2;
    vector<Series> [buckets] resizedMap;
    for(int i = 0; i < buckets / 2; i++){
        for(int j = 0; j < map[i].size(); j++){
            resizedMap.insert(map[i].at(j));
        }
    }
    map = resizedMap;
}

bool hashTable:: has(string title){
    vector<Series> temp = map[hashFunction(title)];
    for(Series s: temp){
        if(s.getTitle() == title)
            return true;
    }
    return false;
}

void hashTable:: remove(string title){
    int index = hashFunction(title);
    if(has(title)){
        int i = 0;
        for(Series s: map[index]){
            if(s.getTitle == title)
                map[index].erase(map[index].begin() + i);
            i++;
        }
            
    }

}
