#include <iostream>
#include <vector>

using namespace std;

/*
floor : Largest Value lesser than target
        lesser than target --> (Arr[i]<target)
                                then store ans_idx = i,eliminate Left Search
        floor Value is not same as Upper bound
        Upper bound Condition is Arr[i]>target --> greater than target
        whereas floor is Smaller than target
*/
int floor(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low = 0,high = n-1;
    int ans_index=-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(Arr[mid]<target)
        {
            ans_index = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }

    if(ans_index!=-1)
        return Arr[ans_index];
    else
        return -1;
}

/*
Ceil --> Smallest Value greater than the target
        greater than the target --> (Arr[i]>=target)
                                then store ans_idx = i, eliminate right Search

        Ceil Value is same as lower bound
*/

int ceil(vector<int>& Arr,int target)
{
    int ans_index = -1;
    int n = Arr.size();
    int low = 0,high = n-1;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(Arr[mid]>=target)
        {
            ans_index = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    if(ans_index!=-1)
        return Arr[ans_index];
    else
        return -1;
}

int main()
{
    vector<int> Arr = {3,4,5,6,9};
    int target = 7;
    int fl = floor(Arr,target);
    int cl = ceil(Arr,target);
    cout << "floor of target:" << target << " floor equals --> " << fl << " ceil equals --> " << cl << endl;
    return 0;
}
