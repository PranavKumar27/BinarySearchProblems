#include <iostream>

using namespace std;

int NthRoot_Sol1(int N,int x)
{
    int ans = -1;
    for(int i=1;i<=N;i++)
    {
        int val = 1;
        for(int j=1;j<=x;j++)
        {
            val=val*i;
        }
        if(val==N)
            return i;
        if(val>N)
            break;
    }
    return ans;
}

// if ans==m return 1;
// if ans>m return 2;
// if ans<m return 0;
int find_Pow_value(int value,int x,int m)
{
    int ans = 1;
    for(int j=1;j<=x;j++)
    {
        ans=ans*value;
        if(ans==m)
            return 1;
        else if(ans>m)
            return 2;

    }
    if(ans==m)
        return 1;
    //else
        return 0;
}
int NthRoot_Sol2(int N,int x)
{
    int ans = -1;
    int low = 1, high = N;

    while(low<=high)
    {
        int mid = low+(high-low)/2;
        int IsPossible = find_Pow_value(mid,x,N); // mid^x
        cout << "IsPossible =" << IsPossible << endl;

        if(IsPossible == 1)
        {
            ans = mid;
            break;
        }
        else if(IsPossible == 0)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}
int main()
{
    int N = 343,x=3;
    int ans1 = NthRoot_Sol1(N,x);
    cout << "Using Sol1 NthRoot ->" << ans1 << endl;

    int ans2 = NthRoot_Sol2(N,x);
    cout << "Using Sol2 NthRoot ->" << ans2 << endl;
    return 0;
}
