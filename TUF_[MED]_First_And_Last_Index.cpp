#include <iostream>
#include <vector>

using namespace std;

pair<int,int> First_And_Last_Occurence_Sol1(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int first = -1,last=-1;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]==target)
        {
            if(first==-1)
                first = i;
            last=i;
        }
    }

    return {first,last};
}

int find_lb(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low=0,high=n-1;
    int ans = n;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(Arr[mid]>=target)
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int find_ub(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low=0,high=n-1;
    int ans = n;

    while(low<=high)
    {
        int mid = low+(high-low)/2;

        if(Arr[mid]>target)
        {
            ans = mid;
            high = mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

pair<int,int> First_And_Last_Occurence_Sol2(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int lb = find_lb(Arr,target);
    int ub = find_ub(Arr,target);

    cout << "ub=" << ub << " lb=" << lb << endl;

    int first = -1,last=-1;
    if(lb==n && ub-1==n)
    {

    }
    else if(lb!=n && ub-1==n && Arr[lb-1]==target)
    {
        first = lb;
        last = lb;
    }
    else if(lb==n && ub-1!=n && Arr[ub-1]==target)
    {
        first = ub;
        last = ub-1;
    }
    else if(lb!=n && ub-1!=n && Arr[ub-1]==target && Arr[lb]==target)
    {
        first = lb;
        last = ub-1;
    }

    return {first,last};

}
int main()
{
    vector<int> Arr = {2,4,6,8,8,8,11,13};
    int target = 11;
    pair<int,int> Ans = First_And_Last_Occurence_Sol2(Arr,target);
    cout << "first occurence =" << Ans.first << " last occurence =" << Ans.second << endl;
    return 0;
}
