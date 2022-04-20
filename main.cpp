#include<iostream>
using namespace std;

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
    */
    
    int selection;
    bool keep;
    cout << "\nWelcome to Media Mogul! The algorithm tool that based on your inputs of your all-time favorite Netflix or Hulu movies, directors, or cast members, outputs suggested movies just for you! \nPlease input below whether you would like to search by movie, director name, movie length, or cast member.";
    
    while(keep == true){
    
        cout << "Select:\n1.  Movie Title\n2.  Director Name\n3.   Movie Length\n4.    Cast Member" << endl;
        cin >> selection;

        switch(selection){

            case 1:
            {

                cout << "Please input your favorite movie title:" << endl;
                string title;
                cin >> title;

                break;
            }
            case 2:
            {
                cout << "Please input the name of your favorite director:" << endl;
                string director;
                cin >> director;
                break;
            }
            case 3:
            {//can be minutes or seasons and then input the type into function (0 for seasons, 1 for minutes)
                cout << "Please input a maximum runtime in minutes:" << endl;
                int maximum;
                cin >> maximum;
                cout << "\nPlease input a minimum runtime in minutes:" << endl;
                int minimum;
                cin >> minimum;
                break;
            }
            case 4:
            {
                cout << "Please input the name of your favorite actor:" << endl; 
                break;
            }
            default:
            {
                cout << "\nInvalid selection! Please try again:" << endl;           
            }

        }

    }

}