#include<iostream>
using namespace std;

int main(){
    
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
            {
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