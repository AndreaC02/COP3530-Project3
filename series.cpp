#pragma once
#include "series.h"

Series:: Series(int id, int type, int dateAdded, int releaseYr, int durTime, string title, string dir, 
    vector<string> castList, string country, string rating, vector<string> genres, string description){
    seriesId = id;
    type = type;
    dateAdded = dateAdded;
    releaseYear = releaseYr;
    similarityRanking = 0;
    durationTime = durTime;
    if(type == 0)
        durationType = "seasons";
    else
        durationType = "minutes";
    title = title;
    director = dir;
    for(string c: castList)
        cast.push_back(c);
    countryOfProduction = country;
    rating = rating;
    genre = genres;
    description = description;
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