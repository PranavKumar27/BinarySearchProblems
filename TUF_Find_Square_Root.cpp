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

int main()
{
    int N = 38;
    vector<int> Arr(N/2);
    for(int i=0;i<N/2;i++)
    {
        Arr[i]=i+1;
    }
    int res = SquareRoot_Sol1(Arr,N);
    cout << "SquareRoot_Sol1 = " << res << endl;
    return 0;
}
