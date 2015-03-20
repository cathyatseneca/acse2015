#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;
int binarySearch(int key,int arr[],int size){
  int rc=-1;
  int low=0;
  int high=size-1;
  int mid;
  while(low<=high && rc==-1){
    mid=(low+high)/2;
    if(key < arr[mid])
      high=mid-1;
    else if(key > arr[mid])
      low = mid+1;
    else
      rc=mid;
  }/*while*/
  return rc;
}


int linearSearch(int key,int arr[],int size){
      int rc=-1;
      for(int i=0;i<size && rc==-1;i++){
            if(arr[i]==key){
                rc=i;
        }
      }
      return rc;
}
int main(int argc, char* argv[]){
  if(argc < 3){
    cout << "usage: a.out <array size> <number of searches>" << endl;
    exit(0);
  }
  int size=atoi(argv[1]);
  int numSearches = atoi(argv[2]);
  int * myarr=new int[size];
  Timer stopwatch;

  for(int i=0;i<size;i++){
    myarr[i]=rand();
  }
  stopwatch.start();
  for(int i=0;i<numSearches;i++){
    int v=rand();
    linearSearch(v,myarr,size);
  }
  stopwatch.stop();
  cout << fixed;
  cout << "amount of time needed to perform "<< numSearches<< endl;
  cout << "linear searches on arrays of size " << size << " is: ";
  cout << stopwatch.currtime() << endl;
  stopwatch.reset();
  cout << "************************************"<<endl << endl;
  stopwatch.start();
  for(int i=0;i<numSearches;i++){
    int v=rand();
    binarySearch(v,myarr,size);
  }
  stopwatch.stop();
  cout << "amount of time needed to perform "<< numSearches<< endl;
  cout << "binary searches on arrays of size " << size << " is: ";
  cout << stopwatch.currtime() << endl;
  
  delete [] myarr;
  return 0;
}

