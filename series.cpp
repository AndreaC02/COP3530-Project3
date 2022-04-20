//
// Created by Andrea Chacon on 4/20/22.
//
#pragma once
#include "series.h"

Series:: Series(){
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

Series:: Series(int id, int type, int _dateAdded, int releaseYr, int durTime, string _title, string dir,
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

int Series:: getSeriesId(){
    return seriesId; }
    int Series:: getType(){
    return type; }
    int Series:: getDateAdded(){
    return dateAdded; }
    int Series:: getReleaseYear(){
    return releaseYear; }
    int Series:: getSimilarityRanking(){
    return similarityRanking;}
    int Series:: getDurationTime(){
    return durationTime; }
    string Series:: getDurationType(){
    return durationType; }
    string Series:: getTitle(){
    return title; }
    string Series:: getDirector(){
    return director; }
    vector<string> Series:: getCast(){
    return cast; }
    string Series:: getCountryofProduction(){
    return countryOfProduction; }
    string Series:: getRating(){
    return rating; }
    vector<string> Series:: getGenre(){
    return genre;}
    string Series:: getDescription (){
    return description; }
    string Series:: getStreamingPlatform(){
        return streamingPlatform;}