#include <iostream>
#include <vector>

using namespace std;

int search_In_Rotated_Arr_Q2(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low = 0,high = n-1;

    while(low<=high)
    {
        int mid = low+(high-low)/2;

        if(Arr[mid]==target)
            return mid;
        else if(Arr[mid]==Arr[low] && Arr[mid]==Arr[high])
        {
            low++;
            high--;
        }
        else if(Arr[low]<=Arr[mid]) // Left part is sorted
        {
            if(Arr[low]<=target && target<=Arr[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else  // Right part is sorted
        {
            if(Arr[mid]<=target && target<=Arr[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> Arr = {3,3,1,2,3,3,3,3};
    int target = 1;
    int ans = search_In_Rotated_Arr_Q2(Arr,target);
    cout << "search_In_Rotated_Arr_Q2 = " << ans << endl;
    return 0;
}
