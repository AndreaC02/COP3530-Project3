//movie attributes
#include <iostream>
#include <vector>
using namespace std;

class Series{
    int seriesId;
    int type; //0 for tv show, 1 for movie
    int dateAdded; //MMDDYYYY for simplest formating
    int releaseYear; //YYYY
    int durationTime; //min or seasons
    string durationType; //gives min or seasons
    string title; 
    string director;
    vector<string> cast;
    string countryOfProduction;
    string rating;

    public: 
    Series(int id, int type, int dateAdded, int releaseYr, int durTime, string title, string dir, 
        vector<string> cast, string country, string rating);
    int getSeriesId();
    int getType();
    int getDateAdded();
    int getReleaseYear();
    int getDurationTime();
    string getDurationType();
    string getTitle();
    string getDirector();
    vector<string> getCast();
    string getCountryofProduction();
    string getRating();
};