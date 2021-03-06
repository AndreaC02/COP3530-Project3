#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "math.h"
#include <iomanip>
#include <fstream>
#include "series.h"
#include "hashTable.h"
#include "heap.h"

using namespace std;

hashTable TABLE;

hashTable Netflix;
hashTable NetflixTV;
hashTable NetflixMovie;
hashTable Hulu;
hashTable HuluTV;
hashTable HuluMovie;
hashTable Amazon;
hashTable AmazonTV;
hashTable AmazonMovie;
hashTable Disney;
hashTable DisneyTV;
hashTable DisneyMovie;
hashTable ALL;
hashTable ALLTV;
hashTable ALLMovie;

void loadFromFile(string filename, hashTable& TABLE, string platform, hashTable& ALL, hashTable& TV, hashTable& MOVIE, hashTable& ALLTV, hashTable& ALLMOVIE) {
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

    int index = 0;

    if (fileStream.is_open()) {
        getline(fileStream, line);
        while (getline(fileStream, line) && index<500) {

            try {
                istringstream stringStream(line);
                string temp;

                getline(stringStream, id, ',');
                getline(stringStream, temp, ',');
                if (temp == "Movie") {
                    type = 1;
                } else {
                    type = 0;
                }
                getline(stringStream, title, ',');
                getline(stringStream, dir, ',');
                getline(stringStream, temp, ','); // first cast member
                if(!temp.empty()){
                    if(temp.find('"')!=string::npos){
                        if (temp.at(0) == '"') {
                            temp = temp.substr(1, (temp.length() - 1));
                        }
                        cast.push_back(temp);
                    }
                    getline(stringStream, temp, '"'); // cast
                    stringstream s_stream(temp);
                    while (s_stream.good()) {
                        string substr;
                        getline(s_stream, substr, ',');
                        if(!substr.empty()){
                            if (substr.at(0) == ' ') {
                                substr = substr.substr(1, (substr.length() - 1));
                            }
                            cast.push_back(substr);}
                    }
                    getline(stringStream, temp, ','); // clear empty
                }

                getline(stringStream, country, ',');
                getline(stringStream, temp, ',');
                dateAdded=0;
                getline(stringStream, temp, ',');
                try{
                    releaseYr = stoi(temp);
                }catch (exception){
                    releaseYr=0;
                }
                getline(stringStream, temp, ',');//throwaway
                getline(stringStream, rating, ',');
                getline(stringStream, temp, ',');
                try{
                    durTime = stoi(temp);
                }catch (exception){
                    durTime=3;
                }
                getline(stringStream, temp, ',');  // first genre
                if(!temp.empty()){
                    if(temp.find('"')!=string::npos){
                        if (temp.at(0) == '"') {
                            temp = temp.substr(1, (temp.length() - 1));
                        }
                        genres.push_back(temp);
                    }
                    getline(stringStream, temp, '"'); // cast
                    stringstream s_stream(temp);
                    while (s_stream.good()) {
                        string substr;
                        getline(s_stream, substr, ',');
                        if(!substr.empty()){
                            if (substr.at(0) == ' ') {
                                substr = substr.substr(1, (substr.length() - 1));
                            }
                            genres.push_back(substr);}
                    }
                    getline(stringStream, temp, ','); // clear empty
                }
                getline(stringStream, description, ',');

                Series s = Series(id, type, dateAdded, releaseYr, durTime, title, dir, cast, country, rating, genres,
                                  description, plat);
                TABLE.insert(s);
                ALL.insert(s);

                //cout<<"inserted: "<<s.getTitle();

                if (type == 0) {

                    TV.insert(s);
                    ALLTV.insert(s);

                } else if (type == 1) {

                    MOVIE.insert(s);
                    ALLMOVIE.insert(s);

                }
                index++;

            }catch(exception){}
        }
        cout << "File Input from " << filename << " successful." << endl;
    }
}

hashTable platformSelect(string platform, int type){

    if(platform == "Netflix"){

        if(type == 1){

            return NetflixMovie;

        }else if(type == 0){

            return NetflixTV;

        }
    
    }else if(platform == "Hulu"){

        if(type == 1){

            return HuluMovie;

        }else if(type == 0){

            return HuluTV;

        }

    }else if(platform == "Amazon"){

        if(type == 1){

            return AmazonMovie;

        }else if(type == 0){

            return AmazonTV;

        }

    }else if(platform == "Disney"){

        if(type == 1){

            return DisneyMovie;

        }else if(type == 0){

            return DisneyTV;

        }

    }else if(platform == "ALL"){

        if(type == 1){

            return ALLMovie;

        }else if(type == 0){

            return ALLTV;

        }
            
    }

}

void printMethod(vector<Series> series){

    bool cont = true;
    while(cont == true){

        int var;
        int index = 0;
        for(int l = 0; l <= 9; l++){

            if(index < series.size()){

                series.at(l).print();

            }
            if(index == series.size()){
                
                cout << "End of list." << endl;
                break;

            }

            index++;

        }
        
        if(index < series.size()){

            cout << "Would you like to see more options? \n1.    Yes\n2.    No" << endl;
            cin >> var;
            if(var == 1){
                cont = true;
            }else if(var == 0){
                cont = false;
            }else{
                cout << "Invalid selection! Please try again." << endl;
                cont = true;
            }

        }

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


    bool keep = true;
    const char *possGenres[30] = {"Action", "Adventure", "Animation", "Black Stories", "Classics", "Comedy", "Crime", "Documentary", "Drama", "Family", "Health","History", "Horror", "International", "Kids", "LGBTQ+ Stories", "Music", "Musicals", "Mystery", "News", "Reality", "Romance", "Science-Fiction", "Sports", "Stand-Up", "Suspense", "Teen", "Thriller", "War", "Western" };
    const char *tvRatings[11] = {"TV-G", "TV-Y", "TV-PG", "TV-Y7", "13+", "TV-14", "16+", "18+","TV-MA", "TV-NR", "ALL"};
    const char *movieRatings[16] = {"G","PG","PG-13","R","NR","TV-G", "TV-Y", "TV-PG", "TV-Y7", "13+", "TV-14", "16+", "18+","TV-MA", "TV-NR", "ALL"};
    
    vector<Series> series;

    
    loadFromFile("netflix_titles.csv", Netflix, "Netflix", ALL, NetflixTV, NetflixMovie, ALLTV, ALLMovie);
    loadFromFile("hulu_titles.csv", Hulu, "Hulu", ALL, HuluTV, HuluMovie, ALLTV, ALLMovie);
    loadFromFile("amazon_prime_titles.csv", Amazon, "Amazon", ALL, AmazonTV, AmazonMovie, ALLTV, ALLMovie);
    loadFromFile("disney_plus_titles.csv", Disney, "Disney", ALL, DisneyTV, DisneyMovie, ALLTV, ALLMovie);

    cout << "\nWelcome to Media Mogul! The algorithm tool that based on your inputs of your all-time favorite movies, tv-shows, directors, cast members, and other prefrences such as genre, length, release year, and rating, outputs suggested movies/tv shows just for you!" << endl;;
    
    while(keep == true){
        
        cout << "\nPlease input below whether you would like to \n1. Look up a movie\n2. Receieve movie/show suggestions based on input\n 3. Quit" << endl;
        int input;
        cin >> input;
        if(input == 3){

            cout << "Are you sure you would like to quit Media Mogul? Enter 1 if Yes, you would like to quit, enter any other digit if you want to stay." << endl;
                    int var;
                    cin >> var;
                    if(var == 1){

                        cout << "Thank you for using Media Mogul! Goodbye!" << endl;;
                        keep == false;

                    }else{

                        cout << "We are glad you stayed." << endl;;

                    }

        }else if(input == 2){
    
            cout << "\nPlease input below whether you are searching for a \n1.  TV show \n2.    Movie" << endl;
            int dataType;
            cin >> dataType;
            if(dataType != 1 && dataType != 2){

                cout << "Invalid Selection! Please try again!" << endl;

            }else{

                string platform;
                cout << "\nSelect if you want to search by a specific platform.\n1.    Netflix\n2.    Hulu\n3.    Amazon Prime\n4.    Disney+\n5.    ALL" << endl;
                int var;
                cin >> var;
                if(var == 1){

                    platform = "Netflix";

                }else if(var == 2){

                    platform = "Hulu";

                }else if(var == 3){

                    platform = "Amazon";

                }else if(var == 4){

                    platform = "Disney";

                }else if(var == 5){

                    platform = "ALL";

                }else{

                    cout << "Invalid Selection!" << endl;

                }
                
                cout << "\nGreat choice. Now it's time to enter a filter. Please input a filters to recieve best suggestions. Select whether you would like to filter by  director name, cast member name, genre, release year, length, and rating." << endl;
                
                    cout << "1.    Director Name \n2.    Length \n3.    Actor Name \n4.    Genre \n5.    Release Year \n6.    Rating" << endl;
                    int selection;
                    cin >> selection;

                    switch(selection){

                        case 1:
                        {
                            cout << "Please input the name of your desired director:" << endl;
                            string director;
                            getline(cin, director);
                            getline(cin, director);

                            series = platformSelect(platform, dataType-1).findDirector(director);
                            printMethod(series);

                            break;
                        }
                        case 2:
                        {//can be minutes or seasons and then input the type into function (0 for seasons, 1 for minutes)

                            if(dataType == 2){

                                cout << "Please input a maximum runtime in minutes:" << endl;
                                int maxMin;
                                cin >> maxMin;
                                cout << "\nPlease input a minimum runtime in minutes:" << endl;
                                int minMin;
                                cin >> minMin;

                                series = platformSelect(platform, 1).findRuntime(minMin, maxMin, 1);
                                printMethod(series);

                            }else if(dataType == 1){

                                cout << "Please enter a maximum number of seasons:" << endl;
                                int maxSeason;
                                cin >> maxSeason;
                                cout << "\nPlease enter a minimum number of season:" << endl;
                                int minSeason;
                                cin >> minSeason;

                                series = platformSelect(platform, 0).findRuntime(minSeason, maxSeason, 0);
                                printMethod(series);
                            
                            }
                            break;

                        }
                        case 3:
                        {
                            cout << "Please input the name of your desired actor:" << endl;
                            string actor;
                            getline(cin, actor);
                            getline(cin, actor);

                            series = platformSelect(platform, dataType-1).findActor(actor);
                            printMethod(series); 

                            break;
                        }
                        case 4:
                        {
                            cout << "Please input the genre you would like to see:" << endl;
                            for(int i=0; i <= 30; i++){
                                cout << (i+1) << ".    " << possGenres[i] << endl;
                            }
                            cin  >> var;
                            string genreChose;
                            genreChose = possGenres[var-1];
                          
                            series = platformSelect(platform, dataType-1).findGenre(genreChose);
                            printMethod(series); 

                            break;
                        }
                        case 5:
                        {
                            cout << "Please input the release year you are looking for:" << endl;
                            int year;
                            cin  >> year;

                            series = platformSelect(platform, dataType-1).findReleaseYear(year);
                            printMethod(series); 


                            break;
                        }
                        case 6:
                        {
                            cout << "Please input the rating you are interested in:" << endl;
                            if(dataType == 2){

                                for(int i=0; i <= 16; i++){
                                    cout << (i+1) << ".    " << movieRatings[i] << endl;
                                } 

                            }else if(dataType == 1){

                                for(int i=0; i <= 11; i++){
                                    cout << (i+1) << ".    " << tvRatings[i] << endl;
                                }

                            }

                            cin  >> var;

                                string ratingChose = tvRatings[var-1];  
                                series = platformSelect(platform, dataType-1).findRating(ratingChose);
                                printMethod(series);

                            break;
                        }

                        default:
                        {
                            cout << "\nInvalid selection! Please try again:" << endl;           
                        }

                    }

            }

        }else if(input == 1){

            cout << "\nPlease input name of media you are searching for:" << endl;
            string title;
            getline(cin, title);
            getline(cin, title);
            Series s;
            s = ALL.findTitle(title);

            s.print();

            cout << "\nWould you like suggestions based off this title?\n1.    Yes\n2.    No" << endl;
            int var;
            cin >> var;
            if(var == 1){

                cout << "\nGreat! Here are suggested movies and TV shows based off of this title:" << endl;


            }else if(var == 0){

                cout << "\nAlright, let's take you back." << endl;

            }else{

                cout << "Invalid selection!" << endl;

            }
            
        }else{

            cout << "Invalid input. Please try again!" << endl;

        }

    } 

}
