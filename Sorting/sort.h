#include <vector>
#include <iostream>
#include <functional>
#include <string>

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class AbstractComparableType {
public:
    virtual ~AbstractComparableType() {};
    virtual bool isEqual(AbstractComparableType& a)=0;
    virtual bool isSmaller(AbstractComparableType& a)=0;
};
bool operator<(AbstractComparableType& a, AbstractComparableType& b) {
    return a.isSmaller(b);
};
bool operator>(AbstractComparableType& a, AbstractComparableType& b) {
    return b.isSmaller(a);
};
bool operator<=(AbstractComparableType& a, AbstractComparableType& b) {
    return a.isSmaller(b) || a.isEqual(b);
};
bool operator>=(AbstractComparableType& a, AbstractComparableType& b) {
    return b.isSmaller(a) || a.isEqual(b);
};






class SampleString : public AbstractComparableType {
public:
    std::string value;
    SampleString(std::string s) {
        this->value = s;
    };
    ~SampleString() {};
    bool isEqual(AbstractComparableType& a) override {
        auto _a = dynamic_cast<SampleString&>(a);
        return this->value.length() == _a.value.length();
    };
    bool isSmaller(AbstractComparableType& a) override {
        auto _a = dynamic_cast<SampleString&>(a);
        return this->value.length() < _a.value.length();
    };

};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
template <class T>
void QuickSort(std::vector<T> &vec) {
    std::function<void(std::vector<T>&, int, int)> swap = 
        [](std::vector<T> &vec, int i, int j) {
        if ((i < vec.size()) && (j < vec.size()) && (i >= 0) && ( j>= 0)) {
            T temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        } //else {
        //     std::cout << "Index out of bound." << std::endl;
        // }
    };
    std::function<int(std::vector<T>&, int, int)> partition = 
        [swap](std::vector<T> &vec, int left, int right) {
        int i = left - 1, pivot = right - 1;
        for (int j = left; j < pivot; j++) {
            if (vec[j] < vec[pivot]) {
                i++;
                swap(vec, i, j);
            }
        }
        T temp = vec[pivot];
        for (int j = pivot; j > i + 1; j--) {
            vec[j] = vec[j-1];
        }
        vec[i+1] = temp;
        return i + 1;
    };
    std::function<void(std::vector<T>&, int, int)> sort = 
        [partition, &sort](std::vector<T> &vec, int left, int right) {
        if (left < right) {
            int pivot = partition(vec, left, right);
            sort(vec, left, pivot);
            sort(vec, pivot + 1, right);
        }
    };
    sort(vec, 0, vec.size());
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
template <class T>
void MergeSort(std::vector<T> &vec) {
    std::function<void(std::vector<T>&, int, int, int)> merge =
        [](std::vector<T> &vec, int left, int middle, int right) {
        int left_i=left, right_i=middle, i=left;
        std::vector<T> temp(vec.size());
        while (true) {
            if (left_i == middle) {
                for (int j = right_i; j < right; j++) {
                    temp[i++] = vec[j];
                }
                break;
            } else if (right_i == right) {
                for (int j = left_i; j < middle; j++) {
                    temp[i++] = vec[j];
                }
                break;
            } else if (vec[left_i] <= vec[right_i]) {
                temp[i++] = vec[left_i];
                left_i++;
            } else {
                temp[i++] = vec[right_i];
                right_i++;
            }
        }
        for (int j = left; j < right; j++) {
            vec[j] = temp[j];
        }
    };
    std::function<void(std::vector<T>&, int, int)> sort =
        [&sort, merge](std::vector<T> &vec, int left, int right) {
        if (right - left > 1) {
            int middle = (left + right) / 2;
            // sort(vec, left, middle);
            // sort(vec, middle, right);
            // merge(vec, left, middle, right);
        }
    };
    sort(vec, 0, vec.size());
}