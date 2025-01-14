#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low = 0;
    int high = n-1;


    while(low<=high)
    {
        //int mid = (low+high)/2; // --> Existing Approach
        // For overflow Case if high or low is INT_MAX
        // then mid = (INT_MAX+INT_MAX)/2 , This will case
        // mid to overflow INT range. To avoid this fix is below
        int mid = low + (high-low)/2; // --> Sol-1

        // Other Sol is store as
        //long long mid = (low+high)/2; // --> Sol-2

        if(Arr[mid]==target)
            return mid;
        else if(Arr[mid]<target)
        {
            // Search space is left
            low = mid+1;

        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int BinarySearch(vector<int>& Arr,int low,int high,int target)
{
    if(low>high)
        return -1;

    int mid = (low+high)/2;
    if(Arr[mid]==target)
        return mid;
    else if(Arr[mid]<target)
        return BinarySearch(Arr,mid+1,high,target);
    else
        return BinarySearch(Arr,low,mid-1,target);

}
int main()
{
    vector<int> Arr = {1,2,3,5,7,8,12,16,19};
    int target = 16;
    int ans = BinarySearch(Arr,target);
    cout << "Using Iterative Index of val= "<< target << " equals --> " << ans << endl;

    int n = Arr.size();
    ans = BinarySearch(Arr,0,n-1,target);
    cout << "Using Recursion Index of val= "<< target << " equals --> " << ans << endl;

    return 0;
}
