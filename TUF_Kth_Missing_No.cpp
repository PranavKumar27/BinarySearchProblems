#include <iostream>
#include <vector>

using namespace std;

/*
    Finding Kth Missing no is simple if No element are present in Arr or Number in Arr is less than K
    For Number in Arr K increases by 1.
    Number Lesser than K will take place and move k by 1
    suppose we were looking for k=5 5th Missing Number and 2 occurs in Arr
    This means we will be need to look for 6th Number

    Similarly Now we will be looking for k= 6  6th Missing Number and if 3 occurs in Arr
    This means we will be need to look for 7th Number  Formula = k+1 for each Arr[i]>k

*/
int find_Kth_Missing_No_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        if(Arr[i]<k)
            k++;
        else
            break;
    }
    return k;
}

/*
    Formula
    Kth Missing No = Arr[high] + more
                   = Arr[high] + k - total_missing
                   = Arr[high] + k - ( Arr[high] -(high+1) )
                   = k + high + 1

    low = high+1

    or we can say Missing No = low + k
*/
int find_Kth_Missing_No_Sol2(vector<int>& Arr,int k)
{
    int n = Arr.size()-1;
    int low = 0,high = n-1;
    while(low<=high)
    {
        int mid = (high+low)/2;
        int total_missing_No = Arr[mid] - (mid+1);

        if(total_missing_No<k)
            low = mid+1;
        else
            high = mid-1;
    }
    // Ans is in high
    int total_missing = Arr[high]-(high+1);
    int more = k-total_missing;
    //return Arr[high]+more;

    return k+high+1;

}
int main()
{
    vector<int> Arr = {2,3,4,7,11};
    int k = 5;
    int missing_element1 = find_Kth_Missing_No_Sol1(Arr,k);
    cout << "Using Sol 1 missing element1 = " << missing_element1 << endl;

    int missing_element2 = find_Kth_Missing_No_Sol2(Arr,k);
    cout << "Using Sol 2 missing element1 = " << missing_element1 << endl;
    return 0;
}
