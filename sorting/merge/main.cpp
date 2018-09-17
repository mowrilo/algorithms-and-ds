#include <cstdlib>
#include <iostream>
#include <vector>

#include "MergeSort.hpp"

int main(){
    std::vector<double> vec = {5,2,4,1,3,6,7,8,1,23,54,1,8,90};
    std::cout << "Original vector:\n\t";
    for (std::vector<double>::iterator it=vec.begin(); it!=vec.end(); it++){
        std::cout << *it << " ";
    }
    MergeSort sorter;
    sorter.sort(vec,0,vec.size()-1);
    std::cout << "Sorted vector:\n\t";
    for (std::vector<double>::iterator it=vec.begin(); it!=vec.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}
