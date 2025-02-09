#include <iostream>
#include <vector>

using namespace std;

// TC --> O(m*n)
int find_Row_Index_Max_1s_Sol1(vector<vector<int>>& Mat)
{
    int r = Mat.size();
    int c = Mat[0].size();

    int max_cnt = -1e9;
    int max_row = -1;
    for(int i=0;i<r;i++)
    {
        int cnt = 0;
        for(int j=0;j<c;j++)
        {
            if(Mat[i][j]==1)
                cnt++;
        }
        if(max_cnt<cnt)
        {
            max_cnt = cnt;
            max_row = i;
        }
    }
    return max_row;
}

int find_1s_in_Arr(vector<int>& Arr)
{
    // Find First Occurence of 1 as first
    // and difference n-first will give count of 1s

    int n = Arr.size();
    int low=0,high=n-1;
    int first = -1;
    while(low<=high)
    {
        int mid = (high+low)/2;

        if(Arr[mid]==1)
        {
            first = mid;
            high=mid-1;
        }
        else
        {
            low = mid+1;
        }
    }

    int diff = 0;
    if(first!=-1)
       diff = n-first;

    return diff;
}

// TC --> O(m)*O(LogN)
int find_Row_Index_Max_1s_Sol2(vector<vector<int>>& Mat)
{
    int r = Mat.size();

    int max_cnt = -1e9;
    int max_row = -1;
    for(int i=0;i<r;i++)
    {
        int cnt = find_1s_in_Arr(Mat[i]);

        if(max_cnt<cnt)
        {
            max_cnt = cnt;
            max_row = i;
        }
    }
    return max_row;
}
int main()
{
    vector<vector<int>> Mat = {
                                {0,0,1,1,1},
                                {0,0,0,0,0},
                                {0,1,1,1,1},
                                {0,0,0,0,0},
                                {0,1,1,1,1}
                            };
    int max_row1=find_Row_Index_Max_1s_Sol1(Mat);
    cout << "Using Sol1 Row_Index with Max 1s = " << max_row1 << endl;

    int max_row2=find_Row_Index_Max_1s_Sol2(Mat);
    cout << "Using Sol2 Row_Index with Max 1s = " << max_row2 << endl;
    return 0;
}
