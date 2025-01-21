#include <iostream>
#include <vector>

using namespace std;


// TC --> O(N)
// SC --> O(1)
int find_Peak_Element_Sol1(vector<int>& Arr)
{
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        if( (i==0 || Arr[i]>Arr[i-1]) &&
           (i==n-1 || Arr[i]>Arr[i+1]) )
        {
            return i;
        }
    }
    return -1;
}

/*
 Here mid can either found on
 1.)greater than mid-1 and greater mid+1   arr[mid-1] < arr[mid]  > arr[mid+1]
 2.) increasing part
          .
         .
        .mid                arr[mid]>arr[mid-1]
      . mid-1
    .
   . low


 3.) decreasing part

    .
     .
      . mid
       . mid+1     arr[mid]>arr[mid+1]
        .
         .
          .high


 4.) Neither inc nor decr

    .        .
     .      .                 arr[mid]<arr[mid+1]
      .    .
       .  .mid+1
        .mid
*/

// TC --> O(LogN)
// SC --> O(1)
int find_Peak_Element_Sol2(vector<int>& Arr)
{
    int n = Arr.size();

    if(n==1)
        return 0;
    if(Arr[0]>Arr[1]) return 0;
    if(Arr[n-1]>Arr[n-2]) return n-1;

    int low = 1,high=n-2;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(Arr[mid]>Arr[mid-1] && Arr[mid]>Arr[mid+1])
            return mid;
        else if(Arr[mid]>Arr[mid-1]) // mid is on increasing path
            low = mid+1;
        else if(Arr[mid]>Arr[mid+1]) // mid is on decreasing path
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}
int main()
{
    // vector<int> Arr1 = {1,2,1,5,6,8,5,4,9,3}; // Multiple Peaks
    vector<int> Arr1 = {1,2,3,4,5,6,7,8,5,2}; // Single Peak

    int idx1 = find_Peak_Element_Sol1(Arr1);

    cout << " Sol1 _Peak_Element index = " << idx1 << endl;
    if(idx1!=-1)
       cout << " Sol1 _Peak_Element Value = " << Arr1[idx1] << endl;


    vector<int> Arr2 = {1,2,1,5,6,8,5,4,9,3}; // Multiple Peaks
    int idx2 = find_Peak_Element_Sol2(Arr2);

    cout << "Sol 2 _Peak_Element index = " << idx2 << endl;
    if(idx2!=-1)
       cout << "Sol 2 _Peak_Element Value = " << Arr2[idx2] << endl;


    return 0;
}
