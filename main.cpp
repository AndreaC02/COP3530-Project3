#include<iostream>
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


    if (fileStream.is_open()) {
        while (getline(fileStream, line)) {

            istringstream stringStream(line);
            string temp;

            getline(stringStream, id, ',');
            getline(stringStream, temp, ',');
            if(temp == "Movie"){
                type = 1;
                }else{
                type = 0;
                }
            getline(stringStream, title, ',');
            getline(stringStream, dir, ',');
            getline(stringStream, temp, ','); // cast
            stringstream s_stream(temp);
            while(s_stream.good()){
                string substr;
                getline(s_stream, substr, ',');
                if(substr.at(0) == ' '){
                    substr = substr.substr(1,(substr.length()-1));
                }
                cast.push_back(substr);
            }
            getline(stringStream, country, ',');
            getline(stringStream, temp, ',');
            dateAdded = stoi(temp);
            getline(stringStream, temp, ',');
            releaseYr = stoi(temp);
            getline(stringStream, rating, ',');
            getline(stringStream, temp, ','); 
            durTime = stoi(temp);           
            getline(stringStream, temp, ',');  // genre
            stringstream s_stream(temp);
            while(s_stream.good()){
                string substr;
                getline(s_stream, substr, ',');
                if(substr.at(0) == ' '){
                    substr = substr.substr(1,(substr.length()-1));
                }
                genres.push_back(substr);
            }
            getline(stringStream, description, ',');

            Series s = Series(id, type, dateAdded, releaseYr, durTime, title, dir, cast, country, rating, genres, description, plat );
            TABLE.insert(s);
            ALL.insert(s);

            if(type == 0){

                TV.insert(s);
                ALLTV.insert(s);

            }else if(type == 1){

                MOVIE.insert(s);
                ALLMOVIE.insert(s);

            }

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
    string platform;
    string plat;
    string genreChose;
    const char *possGenres[30] = {"Action", "Adventure", "Animation", "Black Stories", "Classics", "Comedy", "Crime", "Documentary", "Drama", "Family", "Health","History", "Horror", "International", "Kids", "LGBTQ+ Stories", "Music", "Musicals", "Mystery", "News", "Reality", "Romance", "Science-Fiction", "Sports", "Stand-Up", "Suspense", "Teen", "Thriller", "War", "Western" };
    const char *tvRatings[11] = {"TV-G", "TV-Y", "TV-PG", "TV-Y7", "13+", "TV-14", "16+", "18+","TV-MA", "TV-NR", "ALL"};
    const char *movieRatings[16] = {"G","PG","PG-13","R","NR","TV-G", "TV-Y", "TV-PG", "TV-Y7", "13+", "TV-14", "16+", "18+","TV-MA", "TV-NR", "ALL"};
    int year;
    string ratingChose;
    int i;
    unsigned int input;
    vector<Series> series;

    
    loadFromFile("netflix_titles.csv", Netflix, "Netflix", ALL, NetflixTV, NetflixMovie, ALLTV, ALLMovie);
    loadFromFile("hulu_titles.csv", Hulu, "Hulu", ALL, HuluTV, HuluMovie, ALLTV, ALLMovie);
    loadFromFile("amazon_prime_titles.csv", Amazon, "Amazon", ALL, AmazonTV, AmazonMovie, ALLTV, ALLMovie);
    loadFromFile("disney_plus_titles.csv", Disney, "Disney", ALL, DisneyTV, DisneyMovie, ALLTV, ALLMovie);

    cout << "\nWelcome to Media Mogul! The algorithm tool that based on your inputs of your all-time favorite movies, tv-shows, directors, cast members, and other prefrences such as genre, length, release year, and rating, outputs suggested movies/tv shows just for you!" << endl;;
    
    while(keep == true){
        
        cout << "\nPlease input below whether you would like to \n1. Receive suggestions based on your favorite series\n2. Receieve movie/show suggestions based on input\n 3. Quit" << endl;
        cin >> input;
        if(input == 3){

            cout << "Are you sure you would like to quit Media Mogul? Enter 1 if Yes, you would like to quit, enter any other digit if you want to stay." << endl;
                    cin >> var;
                    if(var == 1){

                        cout << "Thank you for using Media Mogul! Goodbye!" << endl;;
                        keep == false;

                    }else{

                        cout << "We are glad you stayed." << endl;;

                    }

        }else if(input == 2){
    
            cout << "\nPlease input below whether you are searching for a \n1.  TV show \n2.    Movie" << endl;
            cin >> dataType;
            if(dataType != 1 && dataType != 2){

                cout << "Invalid Selection! Please try again!" << endl;

            }else{

                cout << "\nSelect if you want to search by a specific platform.\n1.    Netflix\n2.    Hulu\n3.    Amazon Prime\n4.    Disney+\n5.    ALL" << endl;
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
                    cin >> selection;

                    switch(selection){

                        case 1:
                        {
                            cout << "Please input the name of your desired director:" << endl;
                            cin >> director;

                            series = platformSelect(platform, dataType-1).findDirector(director);
                            printMethod(series);

                            break;
                        }
                        case 2:
                        {//can be minutes or seasons and then input the type into function (0 for seasons, 1 for minutes)

                            if(dataType == 2){

                                cout << "Please input a maximum runtime in minutes:" << endl;
                                cin >> maxMin;
                                cout << "\nPlease input a minimum runtime in minutes:" << endl;
                                cin >> minMin;

                                series = platformSelect(platform, 1).findRuntime(minMin, maxMin, 1);
                                printMethod(series);

                            }else if(dataType == 1){

                                cout << "Please enter a maximum number of seasons:" << endl;
                                cin >> maxSeason;
                                cout << "\nPlease enter a minimum number of season:" << endl;
                                cin >> minSeason;

                                series = platformSelect(platform, 0).findRuntime(minSeason, maxSeason, 0);
                                printMethod(series);
                            
                            }
                            break;

                        }
                        case 3:
                        {
                            cout << "Please input the name of your desired actor:" << endl;
                            cin  >> actor;

                            series = platformSelect(platform, dataType-1).findActor(actor);
                            printMethod(series); 

                            break;
                        }
                        case 4:
                        {
                            cout << "Please input the genre you would like to see:" << endl;
                            for(i=0; i <= 30; i++){
                                cout << (i+1) << ".    " << possGenres[i] << endl;
                            }
                            cin  >> var;
                            genreChose = possGenres[var-1];
                          
                            series = platformSelect(platform, dataType-1).findGenre(genreChose);
                            printMethod(series); 

                            break;
                        }
                        case 5:
                        {
                            cout << "Please input the release year you are looking for:" << endl;
                            cin  >> year;

                            series = platformSelect(platform, dataType-1).findReleaseYear(year);
                            printMethod(series); 


                            break;
                        }
                        case 6:
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

                                ratingChose = tvRatings[var-1];  
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
            cin >> title;
            Series s;
            s = ALL.findTitle(title);

            bool validTitle = s.print();

            if(validTitle){
                cout << "\nWould you like suggestions based off this title?\n1.    Yes\n2.    No" << endl;
                cin >> var;
            }

            else{
                while(!validTitle){
                    cout << "\nPlease input name of media you are searching for:" << endl;
                    cin >> title;
                    bool validTitle = s.print();
                }
                
            }

            
            if(var == 1){

                cout << "\nGreat! Here are suggested movies and TV shows based off of this title:" << endl;
                Heap myHeap;
                vector<Series> reducedSimilar = ALL.findGenre(s.getGenre()[0]);
                myHeap.setComparison(s);
                myHeap.setMaxHeap(reducedSimilar);
                myHeap.setAllSimilarities(reducedSimilar);
                for(Series x: reducedSimilar)
                    myHeap.push(x);
                //figure out building heap here

                cout << "Here are the top 5 suggestions: ";
                bool more;
                do{
                   for(int i = 0; i < 5; i++){
                       myHeap.top().print();
                       myHeap.pop();
                   } 

                   cout << "Would you like to see the next 5 suggestions?\nEnter 0 for no and 1 for yes!" << endl;
                   string moreSugg;
                   cin >> moreSugg;
                   if(moreSugg == "0")
                        more = false;
                    else if(moreSugg == "1")
                        more = true;
                    else{
                        cout << "Invalid selection!\nPrinting the next 5 suggestions!" << endl;
                    }

                }while(more == true);


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