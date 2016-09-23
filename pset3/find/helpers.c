/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool bSearch(int value,int values[],int lo,int hi);
bool search(int value, int values[], int n)
{
 sort(values, n);
return bSearch(value,values, 0, n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
  int swapCount,temp;
    do{
        swapCount=0;
        for(int i=0;i<n;i++){
            if(values[i]>values[i+1]){
                temp=values[i];
                values[i]=values[i+1];
                values[i+1]=temp;
                swapCount++;
            }
        }
    }
    while(swapCount!=0);

    return;
}

bool bSearch(int value, int values[],int lo,int hi){
    int center = (lo+hi)/2;
    if(lo>hi){
        return false;
    }
    
    if(values[center]>value){
   return  bSearch(value, values,lo,center-1);
    }
    else if(values[center]<value){
     return bSearch(value,values,center+1,hi);
    }
    else {
        return true;
    }
    
}