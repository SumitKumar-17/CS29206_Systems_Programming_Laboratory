#include <bits/stdc++.h>
using namespace std;

int main()
{   
    cout<<sizeof(int*)<<endl;
    int **p = (int **)malloc(4 * sizeof(int *));   //32
    p[0] = (int *)malloc(9 * sizeof(int));      //36
    p[1] = (int *)malloc(8 * sizeof(int));    //64
    p[2] = (int *)malloc(7 * sizeof(int));   //56
    p[3] = (int *)malloc(5 * sizeof(int));   //40
    // p[3] = (int *)malloc(6 * sizeof(int));    //48
    p = (int **)malloc(2 * sizeof(int *));  //16
    // p[0] = p[1] = (int *)malloc(10 * sizeof(int));   //80
    free(*p);
}