#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include "series.h"
#include "hashTable.h"
#include "heap.h"

using namespace std;

hashTable TABLE;

void loadFromFile(string filename, hashTable& TABLE, string platform) {
    ifstream fileStream(filename);
    string line;
    string to, from;

    string id;
    int type;
    int dateAdded;
    int releaseYr;
    int durTime;
    string title;
    string dir;
    vector<string> cast;
    string country;
    string rating;
    vector<string> genres;
    string description;
    string plat = platform;


    if (fileStream.is_open()) {
        while (getline(fileStream, line)) {

            istringstream stringStream(line);
            string temp;

            getline(stringStream, id, ',');
            getline(stringStream, temp, ',');
            type = stoi(temp);
            getline(stringStream, title, ',');
            getline(stringStream, dir, ',');
            getline(stringStream, temp, ','); // cast?
            stringstream s_stream(temp);
            while(s_stream.good()){
                string substr;
                getline(s_stream, substr, ',');
                cast.push_back(substr)
            }
            getline(stringStream, country, ',');
            getline(stringStream, temp, ',');
            dateAdded = stoi(temp);
            getline(stringStream, temp, ',');
            releaseYr = stoi(temp);
            getline(stringStream, rating, ',');
            getline(stringStream, temp, ','); 
            durTime = stoi(temp);           
            getline(stringStream, temp, ','); //?
            stringstream s_stream(temp);
            while(s_stream.good()){
                string substr;
                getline(s_stream, substr, ',');
                genres.push_back(substr)
            }
            getline(stringStream, description, ',');

            Series s = new Series(id, type, dateAdded, releaseYr, durTime, title, dir, cast, country, rating, genres, description, plat )
            TABLE.insert(s);

        }
        cout << "File Input from " << filename << " successful." << endl;
    }
}

int main(){
    /*
    //THIS IS WHAT I USED TO TEST THE HASHTABLE, I'm leaving it in case you need examples to test with
    hashTable myMap = hashTable(2);
    Series series1 = Series(0, 0, 01012000, 2000, 90, "series1", "director1",
    {"castMember1", "castMember2", "castMember3" }, "France", "MA", {"horror", "true crime"}, "description 1");
    Series series2 = Series(0, 0, 01012000, 2000, 90, "series2", "director1",
            {"castMember1", "castMember2"}, "France", "MA", {"horror", "true crime"}, "description ");
    Series series3 = Series(0, 0, 01012000, 2000, 90, "series3", "director2",
                            {"castMember1", "castMember2"}, "America", "MA", {"horror", "true crime"}, "description 3");
    myMap.insert(series1);
    myMap.insert(series2);
    myMap.insert(series3);
    myMap.printElements();
    vector<Series> sameDir = myMap.findDirector("director1");
    for(Series s: sameDir)
        cout << s.getTitle() << endl;

        testing
    */

    /* testing heap
    Heap myHeap;
    Series series1 = Series(0, 0, 01012000, 2000, 90, "series1", "director1",
    {"castMember1", "castMember2", "castMember3" }, "France", "MA", {"horror", "true crime"}, "description 1");
    Series series2 = Series(0, 0, 01012000, 2000, 90, "series2", "director1",
            {"castMember1", "castMember2"}, "France", "MA", {"horror", "true crime"}, "description ");
    Series series3 = Series(0, 0, 01012000, 2000, 90, "series3", "director2",
                            {"castMember1", "castMember2"}, "America", "MA", {"horror", "true crime"}, "description 3");
    Series series4 = Series(0, 0, 01012000, 2000, 90, "series1", "director1",
    {"castMember1", "castMember2", "castMember3" }, "France", "MA", {"horror", "true crime"}, "description 1");
    Series series5 = Series(0, 0, 01012000, 2000, 90, "series2", "director1",
            {"castMember1", "castMember2"}, "France", "MA", {"horror", "true crime"}, "description ");
    Series series6 = Series(0, 0, 01012000, 2000, 90, "series3", "director2",
                            {"castMember1", "castMember2"}, "America", "MA", {"horror", "true crime"}, "description 3");    
    series1.getSimilarityRanking = 9;
    series2.getSimilarityRanking = 10;    
    series3.getSimilarityRanking = 20;
    series4.getSimilarityRanking = 7;  
    series3.getSimilarityRanking = 15;
    series4.getSimilarityRanking = 11;                                             
                            
    myHeap.push(series1);
    myHeap.push(series2);
    myHeap.push(series3);
    myHeap.push(series4);
    myHeap.push(series5);
    myHeap.push(series6);

    myHeap.printSimilarities();

    */ 


    unsigned int selection;
    bool keep;
    unsigned int dataType;   
    string title;
    string director;
    string actor;
    unsigned int maxMin;
    unsigned int minMin;
    unsigned int maxSeason;
    unsigned int minSeason;
    unsigned int var;
    string genreChose;
    const char *possGenres[30] = {"Action", "Adventure", "Animation", "Black Stories", "Classics", "Comedy", "Crime", "Documentary", "Drama", "Family", "Health","History", "Horror", "International", "Kids", "LGBTQ+ Stories", "Music", "Musicals", "Mystery", "News", "Reality", "Romance", "Science-Fiction", "Sports", "Stand-Up", "Suspense", "Teen", "Thriller", "War", "Western" };
    const char *tvRatings[11] = {"TV-G", "TV-Y", "TV-PG", "TV-Y7", "13+", "TV-14", "16+", "18+","TV-MA", "TV-NR", "ALL"};
    const char *movieRatings[16] = {,"G","PG","PG-13","R","NR","TV-G", "TV-Y", "TV-PG", "TV-Y7", "13+", "TV-14", "16+", "18+","TV-MA", "TV-NR", "ALL"};
    int year;
    string ratingChose;
    int i;

    hashTable Netflix;
    hashTable Hulu;
    hashTable Amazon;
    hashTable Disney;
    loadFromFile("netflix_titles.csv", Netflix, "Netflix");
    loadFromFile("hulu_titles.csv", Hulu, "Hulu");
    loadFromFile("amazon_prime_titles.csv", Amazon, "Amazon");
    loadFromFile("disney_plus_titles.csv", Disney, "Disney");

    cout << "\nWelcome to Media Mogul! The algorithm tool that based on your inputs of your all-time favorite movies, tv-shows, directors, cast members, and other prefrences such as genre, length, release year, and rating, outputs suggested movies/tv shows just for you!";
    
    while(keep == true){
    
        cout << "\nPlease input below whether you are searching for a \n1.  TV show \n2.    Movie" << endl;
        cin >> dataType;
        if(dataType != 1 && dataType != 2){
 //test

            cout << "Invalid Selection! Please try again!" << endl;

        }else{

            cout << "\nNow it's time to enter a filter. Please input whether you would like to filter by media title, director name, cast member name, genre, release year, length, and rating." << endl;
            cout << "1.    Media Title \n2.    Director Name \n3.    Length \n4.    Actor Name \n5.    Genre \n6.    Release Year \n7.    Rating \n8.    Quit Media Mogul" << endl;
            cin >> selection;

            switch(selection){

                case 1:
                {

                    cout << "Please input your favorite movie title:" << endl;
                    cin >> title;
                    break;
                }
                case 2:
                {
                    cout << "Please input the name of your favorite director:" << endl;
                    cin >> director;
                    break;
                }
                case 3:
                {//can be minutes or seasons and then input the type into function (0 for seasons, 1 for minutes)

                    if(dataType == 2){

                        cout << "Please input a maximum runtime in minutes:" << endl;
                        cin >> maxMin;
                        cout << "\nPlease input a minimum runtime in minutes:" << endl;
                        cin >> minMin;

                    }else if(dataType == 1){

                        cout << "Please enter a maximum number of seasons:" << endl;
                        cin >> maxSeason;
                        cout << "\nPlease enter a minimum number of season:" << endl;
                        cin >> minSeason;

                    }else{

                        cout << "Invalid selection. Please try again!";

                    }

                    break;

                }
                case 4:
                {
                    cout << "Please input the name of your favorite actor:" << endl;
                    cin  >> actor;
                    break;
                }
                case 5:
                {
                    cout << "Please input the genre you would like to see:" << endl;
                    for(i=0; i <= 30; i++){
                        cout << (i+1) << ".    " << genres[i] << endl;
                    }
                    cin  >> var;
                    genreChose = possGenres[var-1];
                    break;
                }
                case 6:
                {
                    cout << "Please input the release year you are looking for:" << endl;
                    cin  >> year;
                    break;
                }
                case 7:
                {
                    cout << "Please input the rating you are interested in:" << endl;
                    if(dataType == 2){

                        for(i=0; i <= 16; i++){
                            cout << (i+1) << ".    " << movieRatings[i] << endl;
                        } 

                    }else if(dataType == 1){

                        for(i=0; i <= 11; i++){
                            cout << (i+1) << ".    " << tvRatings[i] << endl;
                        }

                    }

                    cin  >> var;

                    if(dataType == 2){

                        ratingChose = movieRatings[var-1]; 

                    }else if(dataType == 1){

                        ratingChose = tvRatings[var-1];  

                    }

                    break;
                }
                case 8:
                {

                    cout << "Are you sure you would like to quit Media Mogul? Enter 1 if Yes, you would like to quit, enter any other digit if you want to stay." << endl;
                    cin >> var;
                    if(var == 1){

                        cout << "Thank you for using Media Mogul! Goodbye!";
                        keep == false;

                    }else{

                        cout << "We are glad you stayed.";

                    }

                    break;

                }
                default:
                {
                    cout << "\nInvalid selection! Please try again:" << endl;           
                }

            }

        }

    }

}