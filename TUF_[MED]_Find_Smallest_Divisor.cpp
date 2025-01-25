#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int find_max(vector<int>& Arr)
{
    int max_val = -1e9;
    int min_val = 1e9;
    for(int i=0;i<Arr.size();i++)
    {
        max_val = max(max_val,Arr[i]);
    }

    return max_val;
}

int find_Ans_After_Division(vector<int>& Arr,int divisor)
{
    int n = Arr.size();
    int res = 0;
    for(int i=0;i<n;i++)
    {
        res+=ceil((double)Arr[i]/divisor);
    }
    return res;
}

// TC --> O(M)*O(N) Were M is the Max value in Arr
int find_Smallest_Divisor_Sol1(vector<int>& Arr, int threshold)
{
    int low = 1,high = find_max(Arr);
    int n = Arr.size();
    if(n>threshold) // If Arr is divided by the Max Element we can have sum as n
        return -1;
    for(int divisor=low;divisor<=high;divisor++)
    {
        int Possible_val = find_Ans_After_Division(Arr,divisor);
        if(Possible_val<=threshold)
            return divisor;
    }
    return -1;
}

// TC --> O(LogM)*O(N) Were M is the Max value in Arr
int find_Smallest_Divisor_Sol2(vector<int>& Arr, int threshold)
{
    int low = 1,high = find_max(Arr);

    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int Possible_val =find_Ans_After_Division(Arr,mid);

        if(Possible_val<=threshold)
        {
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    vector<int> Arr = {1,2,5,9};
    int threshold = 6;

    //cout << "ceil(1/2) =" << ceil((double)1/2) << endl;

    int ans1 = find_Smallest_Divisor_Sol1(Arr,threshold);
    cout << "Using Sol1 Smallest Divisor = " <<  ans1 << endl;

    int ans2 = find_Smallest_Divisor_Sol2(Arr,threshold);
    cout << "Using Sol2 Smallest Divisor = " <<  ans2 << endl;

    return 0;
}
