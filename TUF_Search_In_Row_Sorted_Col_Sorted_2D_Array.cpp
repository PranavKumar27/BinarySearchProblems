#include <iostream>
#include <vector>

using namespace std;

// TC --> O(N)*O(M)

pair<int,int> findElement_Sol1(vector<vector<int>>& Mat,int K)
{
    int m = Mat.size();
    int n = Mat[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Mat[i][j]==K)
                return {i,j};
        }
    }
    return {-1,-1};
}

int BinarySearch(vector<int>& Arr,int val)
{
    int n = Arr.size(),low = 0,high=n-1;

    while(low<=high)
    {
        int mid = (high+low)/2;

        if(Arr[mid]==val)
            return mid;
        else if(Arr[mid]>val)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

// TC --> O(N)*O(LogM)

pair<int,int> findElement_Sol2(vector<vector<int>>& Mat,int K)
{
    int m = Mat.size();
    int n = Mat[0].size();

    for(int i=0;i<m;i++)
    {
        int col = BinarySearch(Mat[i],K);
        if(col!=-1)
            return {i,col};
    }
    return {-1,-1};
}


/*
    {1,  4,  7,  11,  15}
    {2,  5,  8,  12,  19}
    {3,  6,  9,  16,  22}
    {10, 13, 14, 17,  24}
    {18, 21, 23, 26,  30}

    Val = 15  Now we check 15<14 then go to prev col

    {1,  4,  7,  11}
    {2,  5,  8,  12}
    {3,  6,  9,  16}
    {10, 13, 14, 17}
    {18, 21, 23, 26}

    Val = 11  Now we check 11<14 then go to next row

    {2,  5,  8,  12}
    {3,  6,  9,  16}
    {10, 13, 14, 17}
    {18, 21, 23, 26}

    Val = 12  Now we check 12<14 then go to next row

    {3,  6,  9,  16}
    {10, 13, 14, 17}
    {18, 21, 23, 26}


    Val = 16  Now we check 12<14 then go to prev col


    {3,  6,  9 }
    {10, 13, 14}
    {18, 21, 23}

    Val = 9  Now we check 9<14 then go to new row

    {10, 13, 14}
    {18, 21, 23}

    Val = 14  Now we check 14==14 then Return {row,col}


*/
// TC ---> O(m+n) at max we need to move from 0,n-1 to m,0  which will take m+n at max if movement is left and down

pair<int,int> findElement_Sol3(vector<vector<int>>& Mat,int K)
{
    int m = Mat.size();
    int n = Mat[0].size();

    int row = 0,col = n-1;

    while(row<m && col>=0)
    {
        if(Mat[row][col]==K)
            return {row,col};
        else if(Mat[row][col]<K)
            row++;
        else
            col--;
    }

    return {-1,-1};
}



int main()
{
    vector<vector<int>> Mat = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
    int K = 14;

    pair<int,int> res1 = findElement_Sol1(Mat,K);
    cout << "Using Sol1 Found K =" << K << " at row=" << res1.first << " at col=" << res1.second << endl;

    pair<int,int> res2 = findElement_Sol2(Mat,K);
    cout << "Using Sol2 Found K =" << K << " at row=" << res2.first << " at col=" << res2.second << endl;

    pair<int,int> res3 = findElement_Sol3(Mat,K);
    cout << "Using Sol3 Found K =" << K << " at row=" << res3.first << " at col=" << res3.second << endl;

    return 0;
}
