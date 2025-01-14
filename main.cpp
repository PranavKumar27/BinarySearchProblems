#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
