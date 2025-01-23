#include <iostream>
#include <vector>

using namespace std;

// Brute Force TC -> O(N)
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
// Using Array
int SquareRoot_Sol2(vector<int>& Arr,int N)
{
    int n = Arr.size();
    int low = 0,high = n-1;
    int ans = 1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int sq = Arr[mid]*Arr[mid];

        if(sq==N)
        {
           ans = Arr[mid];
           break;
        }
        else if(sq<N)
        {
            ans = Arr[mid];
            low = mid+1;
        }

        else
        {
            high = mid-1;
        }
    }
    return ans;
}

/*
    Explanation find Sqrt of 11
    Find floor of Sqrt(11)
    Possible Value is 1,2,3
    Max Floor of Sqrt(11) --> Ans = 3, Sq(3) = 9
    sq(3) < 11 < sq(4)

    1  2  3  4  5  6  7  8  9  10  11
    ^                               ^
   low                             high

    1  2  3  4  5  6  7  8  9  10  11            sq(6) <= 11 Eliminate Right
    ^              ^                ^              36 <= 11
   low            mid               high            high = mid-1 , high = 5

                                                mid = 3
    1  2  3  4  5  6  7  8  9  10  11            sq(3) <= 11 Eliminate left
    ^     ^     ^                                    9 <= 11 , ans = 9
   low   mid    high                               low = mid+1 , low = 4

                                                       mid = 9/2 ==> mid = 4
    1  2  3     4       5  6  7  8  9  10  11            sq(4) <= 11 Eliminate Right
                ^       ^                                    16 <= 11 , ans = 9
             low,mid    high                               high = mid-1 , high = 3



    1  2  3       4   5  6  7  8  9  10  11            Invalid Condition  low<=high
          ^       ^                                    Note : high is pointing to Ans
          high   low                                    We can also return high


*/
// Return Ans
int SquareRoot_Sol3(int N)
{
    int low = 1,high = N;
    int ans = 1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int sq = mid*mid;

        if(sq<=N)
        {
           ans = mid;
           low = mid+1;
        }
        else
        {
            high = mid-1;
        }

    }
    return ans;
}

// Return high as Ans
int SquareRoot_Sol4(int N)
{
    int low = 1,high = N;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int sq = mid*mid;

        if(sq<=N)
        {
           low = mid+1;
        }
        else
        {
            high = mid-1;
        }

    }
    return high;
}

int main()
{
    int N = 17;
    vector<int> Arr(N);
    for(int i=0;i<N;i++)
    {
        Arr[i]=i+1;
    }
    int res1 = SquareRoot_Sol1(Arr,N);
    cout << "SquareRoot_Sol1 = " << res1 << endl;

    int res2 = SquareRoot_Sol2(Arr,N);
    cout << "SquareRoot_Sol2 = " << res2 << endl;

    int res3 = SquareRoot_Sol3(N);
    cout << "SquareRoot_Sol3 = " << res3 << endl;

    int res4 = SquareRoot_Sol4(N);
    cout << "SquareRoot_Sol4 = " << res4 << endl;
    return 0;
}
