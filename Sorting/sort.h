#include <vector>
#include <iostream>


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
template <typename T>
class MergeSort {
private:
    std::vector<T> temp;
    void merge(std::vector<T> &vec, int left, int middle, int right) {
        int left_i = left, right_i = middle, i = left;
        while (true) {
            if (left_i == middle) {
                for(int k = right_i; k < right; k++) {
                    this->temp[i++] = vec[k];
                }
                break;
            } else if (right_i == right) {
                for(int k = left_i; k < middle; k++) {
                    this->temp[i++] = vec[k];
                }
                break;
            } else if (vec[left_i] <= vec[right_i]) {
                this->temp[i] = vec[left_i];
                i++;
                left_i++;
            } else {
                this->temp[i] = vec[right_i];
                i++;
                right_i++;
            }
        }
        for (int k = left; k < right; k++) {
            vec[k] = this->temp[k]; 
        }
        
    }
    void sort(std::vector<T> &vec, int left, int right) {
        if (right - left > 1) {
            int middle = (left + right) / 2;
            this->sort(vec, left, middle);
            this->sort(vec, middle, right);
            this->merge(vec, left, middle, right);
        }
    }
public:
    MergeSort() {
        std::cout<< "Initilizing MergeSort..." << std::endl;
    }
    void sort(std::vector<T> &vec) {
        this->temp.resize(vec.size());
        std::cout<< "Start sorting..." << std::endl;
        this->sort(vec, 0, vec.size());
    }
};



/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
template <typename T>
class QuickSort {
private:
    void swap(std::vector<T> &vec, int pos1, int pos2) {
        T temp;
        temp = vec[pos1];
        vec[pos1] = vec[pos2];
        vec[pos2] = temp;
    }
    int partition(std::vector<T> &vec, int left, int right) {
        int i = left - 1, pivot = right - 1;
        for (int j = left; j < pivot; j++) {
            if (vec[j] < vec[pivot]) {
                i++;
                this->swap(vec, i, j);
            }
        }
        T temp = vec[pivot];
        for (int k = pivot; k > i+1; k--) {
            vec[k] = vec[k-1];
        }
        vec[i+1] = temp;
        return i+1;
    }
    void sort(std::vector<T> &vec, int left, int right) {
        if (left < right) {
            int pivot = this->partition(vec, left, right);
            sort(vec, left, pivot);
            sort(vec, pivot + 1, right);
        }
    }
public:
    QuickSort() {
        std::cout<< "Initilizing QuickSort..." << std::endl;
    }
    void sort(std::vector<T> &vec) {
        std::cout<< "Start sorting..." << std::endl;
        this->sort(vec, 0, vec.size());
    }
};

