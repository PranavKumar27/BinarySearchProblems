#include <iostream>
#include <vector>

using namespace std;

int SquareRoot_Sol1(vector<int>& Arr,int N)
{
    int n = Arr.size();
    int ans = 1;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]*Arr[i]<=N)
        {
            ans = Arr[i];
        }
        else
            break;
    }
    return ans;
}

int SquareRoot_Sol2(vector<int>& Arr,int N)
{
    int n = Arr.size();
    int low = 0,high = n-1;
    int ans = 1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        cout << "low=" << low << " high=" << high << " mid=" << mid << endl;
        int sq = Arr[mid]*Arr[mid];

        if(sq==N)
        {
           ans = mid;
           break;
        }
        else if(sq<N)
        {
            ans = mid;
            low = mid+1;
        }

        else
        {
            ans = mid;
            high = mid-1;
        }

    }
    return ans;
}

int SquareRoot_Sol3(int N)
{
    int low = 1,high = N;
    int ans = 1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        cout << "low=" << low << " high=" << high << " mid=" << mid << endl;
        int sq = mid*mid;

        if(sq==N)
        {
           ans = mid;
           break;
        }
        else if(sq<N)
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            ans = mid;
            high = mid-1;
        }

    }
    return ans;
}

int main()
{
    int N = 17;
    vector<int> Arr(N/2);
    for(int i=0;i<N/2;i++)
    {
        Arr[i]=i+1;
    }
    int res1 = SquareRoot_Sol1(Arr,N);
    cout << "SquareRoot_Sol1 = " << res1 << endl;

    int res2 = SquareRoot_Sol3(N);
    cout << "SquareRoot_Sol2 = " << res2 << endl;
    return 0;
}
