#include <iostream>
#include <vector>

using namespace std;

int find_Rotated_Arr(vector<int>& Arr)
{
    int n = Arr.size();
    int low = 0,high = n-1;

    int mini = 1e9; // The minimum value index is the point of rotation
    int min_idx = -1; // Minimum value In Arr found at index min_idx
    while(low<=high)
    {
        int mid = (high+low)/2;
        cout << "low= "<< low << " high= " << high <<" mid= " << mid << endl;
        cout << "mini =" << mini << endl;
        if(Arr[low]<=Arr[high])
        {
            cout << "min_idx=" << min_idx << endl;
            if(Arr[low]<mini)
            {
               mini = Arr[low];
               min_idx = low;
            }
            break;
        }
        else if(Arr[low]<=Arr[mid]) // Left Part is sorted
        {
            //mini = min(Arr[low],mini);
            if(Arr[low]<mini)
            {
                mini = Arr[low];
                min_idx = low;
            }
            low = mid+1;
        }
        else // Right Part is sorted
        {
            //mini = min(Arr[mid],mini);
            if(Arr[mid]<mini)
            {
                mini = Arr[mid];
                min_idx = mid;
            }
            high = mid-1;
        }
    }
    cout << "mini =" << mini << endl;
    return min_idx;

}

int main()
{
    vector<int> Arr ={5,6,7,1,2,3,4};
    int ans = find_Rotated_Arr(Arr);
    cout << "Number of times Arr is Rotated --> "<< ans << endl;
    return 0;
}
