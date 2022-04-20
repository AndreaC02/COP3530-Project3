//movie or tv show attributes
#include <iostream>
#include <vector>
using namespace std;

class Series{
    int seriesId;
    int type; //0 for tv show, 1 for movie
    int dateAdded; //MMDDYYYY for simplest formating
    int releaseYear; //YYYY
    int durationTime; //min or seasons
    int similarityRanking;
    string durationType; //gives min or seasons
    string title;
    string director;
    vector<string> cast;
    string countryOfProduction;
    string rating;
    vector<string> genre;
    string description;

public:
    Series();
    Series(int id, int type, int dateAdded, int releaseYr, int durTime, string title, string dir,
           vector<string> cast, string country, string rating, vector<string> genres, string description);
    int getSeriesId();
    int getType();
    int getDateAdded();
    int getReleaseYear();
    int getSimilarityRanking();
    int getDurationTime();
    string getDurationType();
    string getTitle();
    string getDirector();
    vector<string> getCast();
    string getCountryofProduction();
    string getRating();
    vector<string> getGenre();
    string getDescription();
};