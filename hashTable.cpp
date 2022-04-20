#pragma once
#include <math.h>
#include "hashTable.h"
#include <vector>
#include "series.h"

using namespace std;

hashTable:: hashTable(int b){
    maxLoadFactor = .7;
    buckets = b;
    elements = 0;
    map.resize(buckets);
}

float hashTable:: calculateLoadFactor(){
    return (float)elements/ buckets;

}

int hashTable:: hashFunction(string title){
    //hash function
    int index = 0;
    int i = title.length() - 1;
    for(char c: title){
        index = int(c) * pow(7, i);
        i++;
    }

    //reduce
    index %= buckets;
    return index;
}

void hashTable:: insert(Series s){
    int index = hashFunction(s.getTitle());
    map.at(index).push_back(s);
    elements++;
    if(calculateLoadFactor() > maxLoadFactor)
        rehash();

}

void hashTable:: rehash(){
    buckets *= 2;
    vector<vector<Series>> resizedMap;
    resizedMap.resize(buckets);
    for(int i = 0; i < buckets / 2; i++){
        for(int j = 0; j < map.at(i).size(); j++){
            resizedMap.at(i).push_back(map.at(i).at(j));
        }
    }
    map = resizedMap;
}

bool hashTable:: has(string title){
    vector<Series> temp = map.at(hashFunction(title));
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
            if(s.getTitle() == title)
                map.at(index).erase(map.at(index).begin() + i);
            i++;
        }
    }
}

vector<Series> hashTable:: findMovieTitle(string title){
    return map.at(hashFunction(title));
}

vector<Series> hashTable:: findDirector(string director){
    vector<Series> series;
    for(int i = 0; i < buckets; i++)
        for(Series s: map.at(i))
            if(s.getDirector() == director)
                series.push_back(s);
            return series;
}

vector<Series> hashTable:: findActor(string actor){
    vector<Series> series;
    for(int i = 0; i < buckets; i++)
        for(Series s: map.at(i))
            for(string a: s.getCast()){
                if(a == actor){
                    series.push_back(s);
                    break;
                }
            }
    return series;
}


vector<Series> hashTable:: findRuntime(int timeMin, int timeMax, int type){
    vector<Series> series;
    for(int i = 0; i < buckets; i++)
        for(Series s: map[i])
            if(s.getType() == type)
                if(s.getDurationTime() >= timeMin  && s.getDurationTime() <= timeMax)
                    series.push_back(s);
                return series;
}

int hashTable::getSize() {
    return buckets;
}

void hashTable::printElements() {
    for (int i = 0; i < map.size(); ++i) {
        for (Series j: map.at(i)) {
            cout << j.getTitle() << endl;
        }
    }
}

