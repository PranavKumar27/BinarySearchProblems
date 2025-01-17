#include <iostream>
#include <vector>

using namespace std;

int findMinInSortedRotatedArray(vector<int>& Arr)
{
    int mini = 1e9;
    int n = Arr.size();
    int low = 0,high = n-1;

    while(low<=high)
    {
        int mid = low + (high-low)/2;

        // If the Search Space is already Sorted we can find min at low and break
        if(Arr[low]<=Arr[high]) // This Happens when we cross pivot either on left or right
        {
            mini = min(Arr[low],mini);
            break;
        }

        mini = min(Arr[mid],mini); // May not be needed Here

        if(Arr[low]<=Arr[mid]) // Left is Sorted and min is at low
        {
            mini = min(Arr[low],mini);
            // Now move to the right
            low = mid+1;
        }
        else // Right is Sorted
        {
            mini = min(Arr[mid],mini);
            high = mid-1;
        }
    }
    return mini;
}

int main()
{
    vector<int> Arr = {7,8,1,2,3,4,5,6};
    int ans = findMinInSortedRotatedArray(Arr);
    cout << "findMinInSortedRotatedArray : " << ans << endl;
    return 0;
}
