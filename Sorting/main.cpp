#include "sort.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <typename T>
void print(std::vector<T> vec) {
    for (int i  = 0; i < vec.size(); i++) {
        cout<< vec[i] << " ";
    }
    cout<<endl;
}
int main() {
    // MergeSort<int> ms;
    QuickSort<int> qs;
    std::vector<int> a{2,1,7,34,46,22222,1,-3,5,3,4,1};
    qs.sort(a);
    print<int>(a);
    return 0;
}