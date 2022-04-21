#pragma once
#include "series.h"

series:: series(){
    seriesId = -1;
    type = -1;
    dateAdded = -1;
    releaseYear = -1;
    durationTime = -1;
    similarityRanking = 0;
    durationType = ""; //gives min or seasons
    title = "";
    director = "";
    cast = {};
    countryOfProduction = "";
    rating = "";
    genre = {};
    description = "";
}

series:: series(string id, int type, int _dateAdded, int releaseYr, int durTime, string _title, string dir,
                vector<string> castList, string country, string _rating, vector<string> genres, string _description, string platform){
    seriesId = id;
    type = type;
    dateAdded = _dateAdded;
    releaseYear = releaseYr;
    similarityRanking = 0;
    durationTime = durTime;
    if(type == 0)
        durationType = "seasons";
    else
        durationType = "minutes";
    title = _title;
    director = dir;
    for(string c: castList)
        cast.push_back(c);
    countryOfProduction = country;
    rating = _rating;
    genre = genres;
    description = _description;
    streamingPlatform = platform;
}

string series:: getSeriesId(){
    return seriesId; }
    int series:: getType(){
    return type; }
    int series:: getDateAdded(){
    return dateAdded; }
    int series:: getReleaseYear(){
    return releaseYear; }
    int series:: getSimilarityRanking(){
    return similarityRanking;}
    int series:: getDurationTime(){
    return durationTime; }
    string series:: getDurationType(){
    return durationType; }
    string series:: getTitle(){
    return title; }
    string series:: getDirector(){
    return director; }
    vector<string> series:: getCast(){
    return cast; }
    string series:: getCountryofProduction(){
    return countryOfProduction; }
    string series:: getRating(){
    return rating; }
    vector<string> series:: getGenre(){
    return genre;}
    string series:: getDescription (){
    return description; }
    string series:: getStreamingPlatform(){
        return streamingPlatform;}
    
    bool series:: print(){
        if(title == "" ){
            cout << "Sorry, no title found!" << endl;
            return false;
        }
        else{
            cout << title << " " << rating << endl; 
            cout << "Duration time" << durationTime << " " << durationType << endl;
            cout << "Director: " << director << endl;
            cout << "Cast: " ;
            for(string c: cast)
                cout << c << ", ";
            cout << endl << "Produced in " << countryOfProduction << endl;
            cout << "Genres: " ;
            for(string g: genre)
                cout << g << ", ";
            cout << endl << "Streaming Platform: " << streamingPlatform;
            cout << "Description: " << description;
            return true;
        }
    }

    void series:: setSimilarityRanking(int r){
        similarityRanking = r;
    }