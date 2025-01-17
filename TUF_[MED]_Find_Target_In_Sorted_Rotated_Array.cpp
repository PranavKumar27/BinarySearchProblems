#include <iostream>
#include <vector>

using namespace std;

int Search_In_Rotated_Array(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low = 0, high = n-1;

    while(low<=high)
    {
        int mid = (high+low)/2;

        if(Arr[mid]==target)
            return mid;
        // Identify the Sorted Part
        else if(Arr[low]<=Arr[mid]) // Left Part is Sorted
        {
            // Target is in the left
            if(Arr[low]<=target && target<=Arr[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else if(Arr[mid]<=Arr[high]) // Right Half is sorted
        {
            // Target is on the right Half
            if(Arr[mid]<=target && target<=Arr[high])
                low = mid+1;
            else
                high = mid-1;


        }
    }
}

int main()
{
    vector<int> Arr = {7,8,9,1,2,3,4,5,6};
    int target = 1;
    int ans = Search_In_Rotated_Array(Arr,target);
    cout << "Search_In_Rotated_Array = " << ans << endl;
    return 0;
}
