#include <iostream>
#include <vector>

using namespace std;

int ceil(int n1,int n2)
{
    if(n1%n2==0)
        return n1/n2;
    else
        return (n1/n2)+1;
}

int time_taken(vector<int>& Arr,int rate)
{
    int total_time = 0;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        total_time+=ceil(Arr[i],rate);
    }
    cout << "total_time=" << total_time << endl;
    return total_time;
}

// TC --> O(n)*O(M) where M is max Range
int find_K(vector<int>& Arr,int hours)
{
    int n = Arr.size();
    int max_K = Arr[n-1];
    int ans = Arr[n-1];
    for(int i=1;i<=max_K;i++)
    {
        int res = time_taken(Arr,i);
        if(res<=hours)
            return i;
    }
    return ans;
}

/*
low is at a place which was not possible and high is at the place which is possible
High ends at a place which is not possible and low ends up at a place which is possible
Opposite polarity Hence ans will be low
*/

// TC --> O(n)*O(LogM where M is max Range)
int find_K_Sol2(vector<int>& Arr,int hours)
{
    int n = Arr.size();
    int low = 1,high = Arr[n-1];
    int ans = Arr[n-1]; // Max element is always possible ans
    while(low<=high)
    {
        int mid = low + (high-low)/2;

        int time = time_taken(Arr,mid);

        if(time<=hours)
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;

    }
    return ans;
}

int main()
{
    vector<int> Arr = {3,6,7,11};
    int hours = 8;
    int ans1 = find_K(Arr,hours);
    cout << "Rate at which KOKO should Eat Bananas --> " << ans1 << endl;


    int ans2 = find_K_Sol2(Arr,hours);
    cout << "Using Sol 2 Rate at which KOKO should Eat Bananas --> " << ans2 << endl;
    return 0;
}
