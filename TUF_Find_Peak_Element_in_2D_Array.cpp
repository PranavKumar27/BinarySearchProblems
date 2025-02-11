#include <iostream>
#include <vector>

using namespace std;

// TC --> O(N*M*4)
pair<int,int> findPeak_Element_Sol1(vector<vector<int>>& Mat)
{
    int m = Mat.size();
    int n = Mat[0].size();

    pair<int,int> Ans;
    for(int r=0;r<m;r++)
    {
        for(int c=0;c<n;c++)
        {
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};

            bool IsPeak = false;
            for(int i=0;i<4;i++)
            {
                int nrow = r+delRow[i];
                int ncol = c+delCol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n)
                {
                    if(Mat[nrow][ncol]<Mat[r][c])
                    {
                        IsPeak = true;
                    }
                    else
                        IsPeak = false;
                }
            }
            if(IsPeak)
            {
                cout << "Found a Peak Element as " << Mat[r][c] << endl;
                Ans = {r,c};
            }

        }
    }
    return Ans;
}
int find_max_element(vector<int>& Arr,int& val)
{
    int maxi = -1e9;
    int idx=-1;
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        if(Arr[i]>maxi)
        {
            maxi = Arr[i];
            idx = i;
        }
    }

    val = maxi;
    return idx;
}

// Find the Max Element in the Matrix
// TC --> O(M*N)
pair<int,int> findPeak_Element_Sol2(vector<vector<int>>& Mat)
{
    int m = Mat.size();
    int n = Mat[0].size();

    pair<int,int> Ans;
    int max_r=-1,max_c=-1,max_val=-1e9;
    for(int r=0;r<m;r++)
    {
        int val = -1;
        int c = find_max_element(Mat[r],val);
        cout << "Proabable Peak =" << val << endl;
        if(max_val<val)
        {
            max_val = val;
            max_r = r;
            max_c = c;
        }
    }
    return {max_r,max_c};
}

int find_max_element_In_Col(vector<vector<int>>& Mat,int& col,int& val)
{
    int m = Mat.size();
    int n = Mat[0].size();

    int maxi = -1e9;
    int row = -1;
    for(int r=0;r<m;r++)
    {
        if(Mat[r][col]>maxi)
        {
            maxi = Mat[r][col];
            row = r;
        }
    }
    val = maxi;
    return row;
}

// TC --> O(LogN)*O(M)
pair<int,int> findPeak_Element_Sol3(vector<vector<int>>& Mat)
{
    int m = Mat.size();
    int n = Mat[0].size();

    int low = 0,high = n-1;

    while(low<=high)
    {
        int mid = (low+high)/2;

        int val = -1;
        int r = find_max_element_In_Col(Mat,mid,val);
        int c = mid;

        int prev_val=-1,next_val=-1;

        if(r>=0 && c-1>=0)
         prev_val = Mat[r][c-1];
        if(r>=0 && c<n)
         next_val = Mat[r][c+1];

        if(prev_val<Mat[r][c]&& Mat[r][c]>next_val)
        {
            cout << "Peak Element Found =" << Mat[r][c] << endl;
            return {r,c};
        }
        else if(prev_val>Mat[r][c])
        {
            high = mid-1;
        }
        else
            low = mid+1;

    }
    return{-1,-1};
}

int main()
{
    vector<vector<int>> Mat = { {4,2,5,1,4,5},{2,9,3,2,3,2},{1,7,6,0,1,3},{3,6,2,3,7,2} };
    pair<int,int> res1 = findPeak_Element_Sol1(Mat);
    int r1 = res1.first,c1=res1.second;
    if(r1!=-1 && c1!=-1)
        cout << "Using Sol1 Peak Element =" << Mat[r1][c1] << endl;
    cout << "row=" << r1 << " col=" << c1 << endl;


    pair<int,int> res2 = findPeak_Element_Sol2(Mat);
    int r2 = res2.first,c2=res2.second;
    if(r2!=-1 && c2!=-1)
        cout << "Using Sol2 Peak Element =" << Mat[r2][c2] << endl;
    cout << "row=" << r2 << " col=" << c2 << endl;


    pair<int,int> res3 = findPeak_Element_Sol3(Mat);
    int r3 = res3.first,c3=res3.second;
    if(r3!=-1 && c3!=-1)
        cout << "Using Sol3 Peak Element =" << Mat[r3][c3] << endl;
    cout << "row=" << r3 << " col=" << c3 << endl;

    return 0;
}
