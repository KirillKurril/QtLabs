#ifndef DSORT_H
#define DSORT_H
#include<utility>
#include <algorithm>

class DSort
{
public:
    DSort();
    static void qsort(int arr[], int low, int high);
    static int partition(int arr[], int low, int high);
    static void aboba(int arr[]);

};

#endif // DSORT_H
