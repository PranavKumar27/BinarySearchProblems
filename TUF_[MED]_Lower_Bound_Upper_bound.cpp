#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Lower bound : Consider an array as {1,2,3,4,5,6,7,8,9}
For x = 7, find lower bound
A lower bound is the smallest value greater than or equal to the node
such that arr[index] >= x
Find what is the index ??

This can be done using Binary
low = 0, high = 8, mid = 4

Is arr[4] >= 7 => 5 >= 7 --> False

So value x will be possibly on the right
low = mid+1, high = 8
low = 5, high = 8 , mid = 6

Is arr[6] >= 7  -> 7 >= 7 --> True

Hence lower bound index for x=7 is 6
Ans = 6

Consider An array as 7,10,11,13,20
Apply binary Search and find lower bound of 19

low= 0; high = 4, mid = 2
arr[2]>=19 --> 11>=19 --> False
Move to right
low = mid+1 high = 4
low = 3, high =4 , mid = 3
arr[3]<=19 --> 13>=19 False
Move right

low = mid+1, high = 4
low = 4, high =4 , mid = 4

arr[4]>=19 --> 20>=19 --> True
Hence lower bound index for x =19 is index = 4

UPPER BOUND: An Upper bound is the smallest value greater than the node
such that arr[index] > x . Not equal

For finding upper bound the only change to be done
is in the condition arr[index] < x
*/
// TC --> O(NLogN) Same as for Binary Search

int find_lower_bound(vector<int> Arr,int target)
{
    int n = Arr.size();
    int low = 0;
    int high = n-1;
    int low_bound=n;

    while(low<=high)
    {
        int mid = low+((high-low)/2);
        cout << "mid=" << mid << endl;
        //if(Arr[mid]==target)
        //    low_bound = mid;
        if(Arr[mid]>=target)
        {
            low_bound = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return low_bound;
}


int find_Upper_bound(vector<int> Arr,int target)
{
    int n = Arr.size();
    int low = 0;
    int high = n-1;
    int up_bound=n;

    while(low<=high)
    {
        int mid = low+((high-low)/2);
        cout << "mid=" << mid << endl;
        //if(Arr[mid]==target)
        //    up_bound = mid;
        if(Arr[mid]>target)
        {
            up_bound = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return up_bound;
}


int main()
{
    vector<int> Arr ={3,4,5,6,9};
    int target = 6;
    int n = Arr.size();
    int low_bound = find_lower_bound(Arr,target);
    int val = -1e9;
    if(low_bound!=n)
        val = Arr[low_bound];
    cout << "Lower_bound of " << target << "  equals index = " << low_bound << " value = " << val  << endl;

    int Up_bound = find_Upper_bound(Arr,target);
    val = -1e9;
    if(Up_bound!=n)
        val = Arr[Up_bound];
    cout << "Upper_bound of " << target << "  equals index = " << Up_bound << " value = " << val  << endl;


    auto itr = lower_bound(Arr.begin(),Arr.end(),target);
    cout << "lower bound val of " << target << " Using STL =" << *itr << endl;


    itr = upper_bound(Arr.begin(),Arr.end(),target);
    cout << "upper bound val of " << target << " Using STL =" << *itr << endl;
    return 0;
}
