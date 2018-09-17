#include "InsertionSort.hpp"

InsertionSort::InsertionSort(){}

std::vector<double> InsertionSort::sort(std::vector<double> vec){
    std::cout << "\n\nBeginning to sort...";
    int N = vec.size();
    for (int i=1; i<N; i++){
        double val = vec[i];
        int j = i-1;
        while(j>=0 && vec[j] >= val){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = val;
    }
    std::cout << "Done!\n\n";
    return vec;
}
