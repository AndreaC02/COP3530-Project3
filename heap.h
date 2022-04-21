#include "series.h"
#include <vector>
using namespace std;
class Heap 
{

    vector<series> maxHeap;
    series comparison;

public:
    Heap();
    void push(series obj);
    void pop();
    series top();
    void heapSort(int i);
    void printSimilarities();
    void setSimilarityRanking(series curr); 
    void setAllSimilarities(vector<series> vect);
    void buildHeap();
    void heapify(int index);
    void setComparison(series _comparison);
    void setMaxHeap(vector<series> _maxHeap);

};