#include "sort.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <typename T>
void print(std::vector<T> vec) {
    for (int i  = 0; i < vec.size(); i++) {
        cout<< vec[i].value << " ";
    }
    cout<<endl;
}
int main() {
    std::vector<SampleString> a;
    a.push_back(SampleString("lsfjslkdf"));
    a.push_back(SampleString("133"));
    a.push_back(SampleString("23233"));
    a.push_back(SampleString("lsfjlkdf"));
    a.push_back(SampleString("13"));
    a.push_back(SampleString("23fffffff233"));
    // std::vector<double> a{1,3,54,6.6,4,3,1,-3,44.3};
    cout<<a.size()<<endl;
    QuickSort<SampleString>(a);
    print(a);
    return 0;
}