#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void print_array(float arr[],int n)
{
  for(int i=0;i<n;i++)
  printf("%.2f\n",arr[i]);
  cout <<endl;
}

void insertion_sort(float arr[],int n)
{
  int i;
  float key;
  for(int j=1;j<n;j++)
  {
    key=arr[j];
    i=j-1;
    while(i>=0 && arr[i]>key)
    {
      arr[i+1]=arr[i];
      i=i-1;
    }
    arr[i+1]=key;
  }
  // printf("array after sorting: \n");
  // print_array(arr,n);
}

int main(int argc, char** argv)
{

  int k=atoi(argv[1]);
  float arr[k];
  ifstream inFile;
  float value;

  inFile.open(argv[2]);
  int i=0;
  while (inFile >> value)
  {
      arr[i++]=value;
  }
  inFile.close();

  int n= sizeof(arr)/sizeof(*arr);
  // for(int j=0;j<n;j++)
    // printf("%0.2f\n",arr[j]);

  auto start = high_resolution_clock::now();
  insertion_sort(arr,n);
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<milliseconds>(stop - start);

  cout << duration.count()<<" milliseconds"<<endl;
  //------------------------------------------------------------//

  return 0;
}
