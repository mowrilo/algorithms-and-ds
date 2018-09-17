#include "MergeSort.hpp"

MergeSort::MergeSort(){}

void MergeSort::sort(std::vector<double> &vec, int p1, int p2){
    if (p1 == p2)   return;

    int middle = p1 +  (p2 - p1)/2;
    sort(vec,p1,middle);
    sort(vec,middle+1,p2);
    merge(vec,p1,middle,p2);
}

void MergeSort::merge(std::vector<double> &vec, int lim1, int lim2, int lim3){
    int i = lim1;
    int j = lim2+1;
    std::vector<double> vec2(lim3-lim1+1);

    int k = 0;
    while(i <= lim2 || j <= lim3){        
        
        if (i > lim2){
            vec2[k] = vec[j];
            j++;
            k++;
        }
        else if (j > lim3){
            vec2[k] = vec[i];
            i++;
            k++;
        }        
        else if (vec[i] <= vec[j]){
            vec2[k] = vec[i];
            i++;
            k++;
        }
        else if (vec[j] <= vec[i]) {
            vec2[k] = vec[j];
            j++;
            k++;
        }
    }

    for (int count=0; count < vec2.size(); count++) vec[lim1+count] = vec2[count];
}
