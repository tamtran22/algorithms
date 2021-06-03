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
    // std::vector<SampleString> a;
    // a.push_back(SampleString("lsfjslkdf"));
    // a.push_back(SampleString("133"));
    // a.push_back(SampleString("23233"));
    // a.push_back(SampleString("lsfjlkdf"));
    // a.push_back(SampleString("13"));
    // a.push_back(SampleString("23fffffff233"));
    // MergeSort<SampleString>(a);
    // print(a);
    SampleString a("aaaaaa");
    SampleString b("kkkkk");
    if (a < b) {
        std::cout<<"a nho hon b";
    } else {
        std::cout<<"a ko nho hon b";
    }
    return 0;
}