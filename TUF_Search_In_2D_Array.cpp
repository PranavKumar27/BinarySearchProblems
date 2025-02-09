#include <iostream>
#include <vector>

using namespace std;

// TC --> O(m)*O(n)
bool IsElementPresentinMat_Sol1(vector<vector<int>>& Mat,int val)
{
    int m = Mat.size(),n=Mat[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Mat[i][j]==val)
                return true;
        }
    }
    return false;
}

bool FoundInArr_UsingBinarySearch(vector<int>& Arr,int val)
{
    int n = Arr.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(Arr[mid]==val)
            return true;
        else if(Arr[mid]<val)
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
}

// TC --> O(m)*O(log(n))
bool IsElementPresentinMat_Sol2(vector<vector<int>>& Mat,int val)
{
    int m = Mat.size(),n=Mat[0].size();

    for(int i=0;i<m;i++)
    {
        if(Mat[i][0]<=val && Mat[i][n-1]>=val)
        {
            if(FoundInArr_UsingBinarySearch(Mat[i],val))
                return true;
        }
    }
    return false;
}

// TC --> O(log(m*n))
// Flatten the Array and find
int IsElementPresentinMat_Sol3(vector<vector<int>>& Mat,int val)
{
    int m = Mat.size(),n=Mat[0].size();
    int total = m*n;
    int low=0,high=total-1;

    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int row = mid/m;
        int col = mid%m;
        if(Mat[row][col]==val)
            return true;
        else if(Mat[row][col]>val)
            high = mid-1;
        else
            low = mid+1;
    }
    return false;

}

int main()
{
    vector<vector<int>> Mat = {
                                {3,4,5,6,7},
                                {8,9,10,11,12},
                                {13,14,15,16,17},
                                {18,19,20,21,22},
                                {23,24,25,26,27}
                            };
    int K = 21;

    bool IsFound1=IsElementPresentinMat_Sol1(Mat,K);
    cout << "Using Sol1 IsFound1 = " << IsFound1 << endl;

    bool IsFound2=IsElementPresentinMat_Sol2(Mat,K);
    cout << "Using Sol2 IsFound2 = " << IsFound2 << endl;

    bool IsFound3=IsElementPresentinMat_Sol3(Mat,K);
    cout << "Using Sol3 IsFound3 = " << IsFound3 << endl;

    return 0;
}
