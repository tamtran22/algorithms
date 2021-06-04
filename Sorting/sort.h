#include <vector>
#include <iostream>
#include <functional>
#include <string>

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class AbstractComparableType {
private:
    virtual bool isEqual(AbstractComparableType& a)=0;
    virtual bool isSmaller(AbstractComparableType& a)=0;
public:
    virtual ~AbstractComparableType() {};
    bool operator<(AbstractComparableType& b) {
        return this->isSmaller(b);
    };
    bool operator>(AbstractComparableType& b) {
        return (!this->isSmaller(b)) && (!this->isEqual(b));
    };
    bool operator<=(AbstractComparableType& b) {
        return this->isSmaller(b) || this->isEqual(b);
    };
    bool operator>=(AbstractComparableType& b) {
        return !this->isSmaller(b);
    };
};


// A sample of comparable data type.
class SampleString : public AbstractComparableType {
private:
    bool isEqual(AbstractComparableType& a) override {
        // Important to dynamic cast to subclass
        auto _a = dynamic_cast<SampleString&>(a); 
        return this->value.length() == _a.value.length();
    };
    bool isSmaller(AbstractComparableType& a) override {
        // Important to dynamic cast to subclass
        auto _a = dynamic_cast<SampleString&>(a);
        return this->value.length() < _a.value.length();
    };
public:
    std::string value;
    SampleString() {};
    SampleString(std::string s) {
        this->value = s;
    };
    ~SampleString() {};

};



// Quick Sort
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
template <class T>
void QuickSort(std::vector<T> &vec) {

    std::function<void(std::vector<T>&, int, int)> swap = 
        [](std::vector<T> &vec, int ithPositionIndex, int jthPositionIndex) {
        if ((ithPositionIndex < vec.size()) && (jthPositionIndex < vec.size()) 
            && (ithPositionIndex >= 0) && (jthPositionIndex>= 0)) {
            T tempElement = vec[ithPositionIndex];
            vec[ithPositionIndex] = vec[jthPositionIndex];
            vec[jthPositionIndex] = tempElement;
        }
    };

    std::function<int(std::vector<T>&, int, int)> partition = 
        [swap](std::vector<T> &vec, int leftIndex, int rightIndex) {
        int firstLargerThanPivotIndex = leftIndex, pivotIndex = rightIndex - 1; // Last element as pivot.
        for (int j = leftIndex; j < pivotIndex; j++) {
            if (vec[j] < vec[pivotIndex]) {
                swap(vec, firstLargerThanPivotIndex++, j);
            }
        }
        T tempElement = vec[pivotIndex];
        for (int j = pivotIndex; j > firstLargerThanPivotIndex + 1; j--) {
            vec[j] = vec[j-1];
        }
        vec[firstLargerThanPivotIndex] = tempElement;
        return firstLargerThanPivotIndex;
    };

    std::function<void(std::vector<T>&, int, int)> sort = 
        [partition, &sort](std::vector<T> &vec, int leftIndex, int rightIndex) {
        if (leftIndex < rightIndex) {
            int pivotIndex = partition(vec, leftIndex, rightIndex);
            sort(vec, leftIndex, pivotIndex);
            sort(vec, pivotIndex + 1, rightIndex);
        }
    };
    sort(vec, 0, vec.size());
}



// Merge Sort
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
template <class T>
void MergeSort(std::vector<T> &vec) {

    std::function<void(std::vector<T>&, int, int, int)> merge =
        [](std::vector<T> &vec, int leftIndex, int middleIndex, int rightIndex) {
        int leftIncrementIndex=leftIndex, rightIncrementIndex=middleIndex, currentTempIndex=leftIndex;
        std::vector<T> tempVec(vec.size());
        while (true) {
            if (leftIncrementIndex == middleIndex) {
                for (int j = rightIncrementIndex; j < rightIndex; j++) {
                    tempVec[currentTempIndex++] = vec[j];
                }
                break;
            } else if (rightIncrementIndex == rightIndex) {
                for (int j = leftIncrementIndex; j < middleIndex; j++) {
                    tempVec[currentTempIndex++] = vec[j];
                }
                break;
            } else if (vec[leftIncrementIndex] <= vec[rightIncrementIndex]) {
                tempVec[currentTempIndex++] = vec[leftIncrementIndex];
                leftIncrementIndex++;
            } else {
                tempVec[currentTempIndex++] = vec[rightIncrementIndex];
                rightIncrementIndex++;
            }
        }
        for (int j = leftIndex; j < rightIndex; j++) {
            vec[j] = tempVec[j];
        }
    };

    std::function<void(std::vector<T>&, int, int)> sort =
        [&sort, merge](std::vector<T> &vec, int leftIndex, int rightIndex) {
        if (rightIndex - leftIndex > 1) {
            int middleIndex = (leftIndex + rightIndex) / 2;
            sort(vec, leftIndex, middleIndex);
            sort(vec, middleIndex, rightIndex);
            merge(vec, leftIndex, middleIndex, rightIndex);
        }
    };
    
    sort(vec, 0, vec.size());
}



// Insertion Sort
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
template <class T>
void InsertionSort(std::vector<T> &vec) {
    int forwardIndex, backwardIndex, currentIndex;
    T currentElement;
    for (forwardIndex = 1; forwardIndex < vec.size(); forwardIndex++) {
        currentIndex = forwardIndex;
        currentElement = vec[currentIndex];
        for (backwardIndex = currentIndex - 1; backwardIndex >=0; backwardIndex--) {
            if (vec[backwardIndex] <= currentElement) {
                break;
            } else {
                vec[backwardIndex + 1] = vec[backwardIndex];
            }
        }
        vec[backwardIndex + 1] = currentElement;
    }
}



// Selection Sort
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


