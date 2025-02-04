#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Check if Min dist 1 is possible for the cows - Possible
        0     3     4      7     9      10
        c1   c2    c3      c4
        <--3-->|<-1->|<--3-->

    Check if Min dist 2 is possible for the cows - Possible

        0     3     4      7     9      10
        c1   c2            c3    c4
        <--3-->|<---4----->|<--2-->

    Check if Min dist 3 is possible for the cows - Possible

        0     3     4      7     9      10
        c1   c2            c3           c4
        <--3-->|<---4----->|<-----4------>


    Check if Min dist 4 is possible for the cows - Not Possible

        0     3     4      7     9      10
        c1         c2            c3                          c4
        <----4----->|<----5----->|<---1------                Not Possible to place c4

        Hence Ans will be 3 Previous possible Distance

*/

bool IsPossible_No_Of_Cows_Placed(vector<int>& Arr,int total_cows,int min_dist)
{
    int n = Arr.size();
    int cow_cnt = 1;
    int val = Arr[0];
    cout << "val=" << val << endl;
    // Check if min_dist is possible for placement of total_cows
    for(int i=1;i<n;i++)
    {
        int diff = Arr[i]-val;
        if(diff>=min_dist)
        {
            cow_cnt++;
            val = Arr[i];
            cout << "val=" << val << endl;
        }


        if(cow_cnt==total_cows)
        {
            return true;
        }
    }
    return false;
}

// TC --> O(NLogN) + O(M)*O(N) ~~ O(NLogN) + O(N^2)
// O(NLogN) for Sorting
// O(M) where M  = max - Arr[0]
// O(N) for IsPossible_No_Of_Cows_Placed

int findMaxCowsMinDistance_Sol1(vector<int> Arr,int total_cows)
{
    sort(Arr.begin(),Arr.end());

    int n = Arr.size();
    int max_dist = Arr[n-1]-Arr[0];
    int max_min_dist = -1;

    for(int dist=1;dist<max_dist;dist++)
    {
        bool IsPossible = IsPossible_No_Of_Cows_Placed(Arr,total_cows,dist);
        if(IsPossible)
            max_min_dist = dist;
        else
            return max_min_dist;
    }

    return -1;

}

// TC --> O(NLogN) + O(LogM)*O(N)
// O(NLogN) for Sorting
// O(LogM) where M  = max - Arr[0]
// O(N) for IsPossible_No_Of_Cows_Placed

int findMaxCowsMinDistance_Sol2(vector<int> Arr,int total_cows)
{
    int n = Arr.size();
    sort(Arr.begin(),Arr.end());
    int low = 0,high = Arr[n-1]-Arr[0];

    while(low<=high)
    {
        int mid = low + (high-low)/2;
        bool IsPossible = IsPossible_No_Of_Cows_Placed(Arr,total_cows,mid);
        if(IsPossible)
            low = mid+1;
        else
            high = mid-1;
    }
    return high;
}


int main()
{
    vector<int> Arr = {0,3,4,7,10,9}; // Cow Stands
    int total_cows = 4;
    int max_cows1 = findMaxCowsMinDistance_Sol1(Arr,total_cows);
    cout << "findMaxCowsMinDistance_Sol1 = " << max_cows1 << endl;

    int max_cows2 = findMaxCowsMinDistance_Sol2(Arr,total_cows);
    cout << "findMaxCowsMinDistance_Sol2 = " << max_cows2 << endl;
    return 0;
}
