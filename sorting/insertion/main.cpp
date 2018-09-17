#include <cstdlib>
#include <iostream>
#include <vector>

#include "InsertionSort.hpp"

int main(){
    std::vector<double> vec = {2,5,4,1,3,6,7,8,1,23,54,1,8,90};
    std::cout << "Original vector:\n\t";
    for (std::vector<double>::iterator it=vec.begin(); it!=vec.end(); it++){
        std::cout << *it << " ";
    }
    InsertionSort sorter;
    vec = sorter.sort(vec);
    std::cout << "Sorted vector:\n\t";
    for (std::vector<double>::iterator it=vec.begin(); it!=vec.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}
