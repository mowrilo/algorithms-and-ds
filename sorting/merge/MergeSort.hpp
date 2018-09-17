#include <iostream>
#include <vector>

class MergeSort{
    public:
        MergeSort();
        void sort(std::vector<double> &vec, int p1, int p2);
    private:
        void merge(std::vector<double> &vec, int lim1, int lim2, int lim3); // p1, p2 and p3 are the limits of the subarrays to merge
};
