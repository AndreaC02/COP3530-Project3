#pragma once
#include <math.h>
#include "hashTable.h"
#include <vector>
#include "series.h"

using namespace std;

hashTable:: hashTable(){
    maxLoadFactor = .7;
    buckets = 16,000;
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
        i--;
    }

    //reduce
    index %= buckets;
    return index;
}

void hashTable:: insert(series s){
    int index = hashFunction(s.getTitle());
    map.at(index).push_back(s);
    elements++;
    if(calculateLoadFactor() > maxLoadFactor)
        rehash();

}

void hashTable:: rehash(){
    buckets *= 2;
    vector<vector<series>> resizedMap;
    resizedMap.resize(buckets);
    for(int i = 0; i < buckets / 2; i++){
        for(int j = 0; j < map.at(i).size(); j++){
            resizedMap.at(i).push_back(map.at(i).at(j));
        }
    }
    map = resizedMap;
}

bool hashTable:: has(string title){
    vector<series> temp = map.at(hashFunction(title));
    for(series s: temp){
        if(s.getTitle() == title)
            return true;
    }
    return false;
}

void hashTable:: remove(string title){
    int index = hashFunction(title);
    if(has(title)){
        int i = 0;
        for(series s: map[index]){
            if(s.getTitle() == title){
                map.at(index).erase(map.at(index).begin() + i);
                elements--;
            }
            i++;
        }
    }
}

int hashTable::getSize() {
    return buckets;
}

void hashTable::printElements() {
    for (int i = 0; i < map.size(); ++i) {
        for (series j: map.at(i)) {
            cout << j.getTitle() << endl;
        }
    }
}

series hashTable:: findTitle(string title){
    for(series s: map.at(hashFunction(title)))
        if(s.getTitle() == title)
            return s;
}

vector<series> hashTable:: findDirector(string director){
    vector<series> series;
    for(int i = 0; i < buckets; i++)
        for(series s: map.at(i))
            if(s.getDirector() == director)
                series.push_back(s);
    return series;
}

vector<series> hashTable:: findActor(string actor){
    vector<series> series;
    for(int i = 0; i < buckets; i++)
        for(series s: map.at(i))
            for(string a: s.getCast()){
                if(a == actor){
                    series.push_back(s);
                    break;
                }
            }
    return series;
}

vector<series> hashTable:: findRuntime(int timeMin, int timeMax, int type){
    vector<series> series;
    for(int i = 0; i < buckets; i++)
        for(series s: map[i])
            if(s.getType() == type)
                if(s.getDurationTime() >= timeMin  && s.getDurationTime() <= timeMax)
                    series.push_back(s);
    return series;
}

vector<series> hashTable:: findGenre(string genre){
   vector<series> series;
    for(int i = 0; i < buckets; i++)
        for(series s: map[i])
            for(string g: s.getGenre())
                if(g == genre)
                    series.push_back(s);
    return series; 
}

vector<series> hashTable:: findReleaseYear(int year){
   vector<series> series;
    for(int i = 0; i < buckets; i++)
        for(series s: map[i])
            if(s.getReleaseYear() == year)
                series.push_back(s);
    return series; 
}

vector<series> hashTable:: findRating(string rating){
   vector<series> series;
    for(int i = 0; i < buckets; i++)
        for(series s: map[i])
            if(s.getRating() == rating)
                series.push_back(s);
    return series; 
}
