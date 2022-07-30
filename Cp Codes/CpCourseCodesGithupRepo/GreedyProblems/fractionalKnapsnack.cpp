#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool compare(struct Item a, struct Item b){
    double value1 = (double)(a.value)/(a.weight);
    double value2 = (double)(b.value)/(b.weight);
    return value1 > value2;
}

double fKnapsnack(struct Item arr[], int w, int n){
    sort(arr, arr + n, compare);
    int currw = 0;
    double fValue = 0;
    for(int i = 0;i < n;i++){
        if(currw + arr[i].weight <= w){
            currw += arr[i].weight;
            fValue += arr[i].value;
        }
        else{
            int rWeight = w - currw;
            fValue += (double)(rWeight)/(arr[i].weight) * arr[i].value;
            break;
        }
    }
    return fValue;
}

int main(){
    int w = 70;
    Item arr[] = {{60, 20}, {70, 15}, {80, 40}};
    cout << "Maximum Value : " << fKnapsnack(arr, w, 3) << endl; 
    return 0;
}