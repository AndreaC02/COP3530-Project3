#include "series.h"
#include <vector>
using namespace std;
class Heap 
{

    vector<Series> maxHeap;
    Series comparison;

public:
    Heap();
    void push(Series obj);
    void pop();
    Series top();
    void heapSort();
    void printSimilarities();
    void setSimilarityRanking(Series curr); 
    void setAllSimilarities(vector<Series> vect);
    void buildHeap();
    void heapify(int index);
    void setComparison(Series _comparison);
    void setMaxHeap(vector<Series> _maxHeap);

};