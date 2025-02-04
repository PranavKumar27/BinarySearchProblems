#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
    Pages in Books [ 25    46     28      49       24]
    Students = 4

    Divide Books in such a way that all Students have atleast 1 book
    Books are distributed in consecutive given order as in Arr
    Minimum Pages are with a student to read

    All Possible
Type1:    25,46 |  28  | 49  |  24   Max = 71

Type1:    25 |  46,28  | 49  |  24   Max = 74

Type1:    25 |  46  | 28,49  |  24   Max = 77

Type1:    25 |  46  | 28  |  49,24   Max = 73

Hence Ans is 71

If we choose min as 49 which is max pages in a book

At max there can be only 1 student which will read all book so Sum(Arr) for all Pages


With 49 Pages as max, Find No of Students
    s1 = 25          Possible < 49
    s1 = 25 + 46 --> No Possible  < 49

    s2 =  46           Possible < 49
    s2 =  46 + 28 --> No Possible  < 49

    s3=  28            Possible < 49
    s3 =  28 + 49 --> No Possible  < 49

    s4 =  49            Possible < 49
    s4 =  49 + 24 --> No Possible  < 49

    s5 =  24 , Possible < 49

    Hence No of Students Needed = 5
....


....
With 71 Pages as max, Find No of Students
    s1 = 25             Possible < 71
    s1 = 25 + 46 -->    Possible < 71
    s1 = 25 + 46 + 28   Not Possible < 71

    s2 =  28           Possible < 71
    s2 =  28 + 49 --> No Possible  < 71

    s3=  49            Possible < 71
    s3 =  49 + 24 --> No Possible  < 71

    s4 =  24            Possible < 71

   Hence No of Students Needed = 4


*/

int findNoOfSudentsPossible(vector<int>& Arr,int Max_pages)
{
    int n = Arr.size();
    int cnt = 1;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]+sum<=Max_pages)
        {
            sum = sum + Arr[i];
        }
        else
        {
            sum = 0;
            cnt++;
            i--;
            /*
            if(Arr[i]+sum<=Max_pages)
            {
                sum = sum + Arr[i];
            }*/
        }
    }
    return cnt;
}

// TC O(max-min+1)*O(N)
int findMin_Allocate_Book_Pages_Sol1(vector<int>& Arr,int Students)
{
    int max_pages = *max_element(Arr.begin(),Arr.end());
    int sum = accumulate(Arr.begin(),Arr.end(),0);

    for(int pages=max_pages;pages<=sum;pages++)
    {
        cout << "pages = "<< pages << endl;
        int stud = findNoOfSudentsPossible(Arr,pages);
        cout << "students = "<< stud << endl;
        if(stud==Students)
            return pages;
    }
    return -1;
}


// TC O(Log(max-min+1))*O(N)
int findMin_Allocate_Book_Pages_Sol2(vector<int>& Arr,int Students)
{
    int max_pages = *max_element(Arr.begin(),Arr.end());
    int sum = accumulate(Arr.begin(),Arr.end(),0);

    int low = max_pages,high = sum;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        cout << "mid / pages = "<< mid << endl;
        int stud = findNoOfSudentsPossible(Arr,mid);
        cout << "students = "<< stud << endl;

        if(stud>Students)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}

int main()
{
    vector<int> Arr = {25,46,28,49,24};
    int Students = 4;
    int res1 = findMin_Allocate_Book_Pages_Sol1(Arr,Students);
    cout << "Using Sol1 findMin_Allocate_Book_Pages = " << res1 << endl;


    int res2 = findMin_Allocate_Book_Pages_Sol2(Arr,Students);
    cout << "Using Sol2 findMin_Allocate_Book_Pages = " << res2 << endl;
    return 0;
}
