#include <iostream>
#include <vector>

using namespace std;

/*
    Solution 1:
    Arr1 = { 1 , 3 , 4,  7, 10,  12 }
    Arr2 = {2,  3,  6,  15}

    Merged Arr = {1, 2, 3, 3, 4, 6, 7, 10, 12, 15}
                  0  1  2  3  4  5  6   7   8   9

    Median :
        If n is even  Median = (Arr[n/2]+Arr[n/2-1])/2
        If n is  Odd  Median = (Arr[n/2])/2
*/

// TC --> O(min(m,n)) + O(m-min(m,n)) + O(n-min(m,n))  ~~ 3*O(N)
// SC --> O(m+n) for Storing Merged Array
int MergeSortedArrayAndFindMedian_Sol1(vector<int>& Arr1,vector<int>& Arr2,vector<int> Arr3)
{
    int m = Arr1.size(),n=Arr2.size();
    Arr3.resize(m+n);
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(Arr1[i]<Arr2[j])
        {
            Arr3[k] = Arr1[i];
            k++;
            i++;
        }
        else
        {
            Arr3[k] = Arr2[j];
            k++;
            j++;
        }
    }

    while(i<m)
       Arr3[k++] = Arr1[i++];

    while(j<n)
       Arr3[k++] = Arr2[j++];

    int sz = m+n;
    int mid = sz/2;
    if(sz%2) // Odd
        return Arr3[mid];
    else
        return (Arr3[mid]+Arr3[mid-1])/2;
}

/*
    The Solution 2 is same as Solution Except the fact that we don't have third Array Arr3

    Instead we store the indexs from Hypothetical Arr3 as idx1 and idx2,
    We keep on increasing 'k' and compare if k=idx1 or k=idx2
    This k is an index in Hypothetical Arr3
*/

// TC --> O(min(m,n)) + O(m-min(m,n)) + O(n-min(m,n))  ~~ 3*O(N)
// SC --> O(1)
int MergeSortedArrayAndFindMedian_Sol2(vector<int>& Arr1,vector<int>& Arr2)
{
    int m = Arr1.size(),n=Arr2.size();
    int sz = m+n;
    int i=0,j=0;

    int idx1=-1,idx2=-1;
    int v1=-1,v2=-1;
    int mid = sz/2;
    if(sz%2) // Odd
        idx1 = mid;
    else
    {
        idx1 = mid;
        idx2 = mid-1;
    }

    int k = 0; // This is the count of Hypothetical Merged Array
    while(i<m && j<n)
    {
        if(Arr1[i]<Arr2[j])
        {
            if(k==idx1)
                v1 = Arr1[i];
            if(k==idx2)
                v2 = Arr1[i];
            i++;
            k++;
            //cout << "Increase i =" << i << "  v1=" << v1 << " v2=" << v2 << endl;
        }
        else
        {
            if(k==idx1)
                v1 = Arr2[j];
            if(k==idx2)
                v2 = Arr2[j];
            j++;
            k++;

            //cout << "Increase j =" << j << "  v1=" << v1 << "  v2=" << v2 << endl;
        }
    }

    while(i<m)
    {
        if(k==idx1)
            v1 = Arr1[i];
        if(k==idx2)
            v2 = Arr1[i];
        i++;
        k++;

    }

    while(j<n)
    {
        if(k==idx1)
            v1 = Arr2[j];
        if(k==idx2)
            v2 = Arr2[j];
        j++;
        k++;
    }

    //cout << "v1=" << v1 << endl;
    //cout << "v2=" << v2 << endl;
    if(sz%2) // Odd
        return v1;
    else
    {
        return (v1+v2)/2;
    }
}

void find_Values(int& L1,int& L2,int& R1,int& R2,vector<int>& Arr1,int mid1,vector<int>& Arr2,int mid2)
{
    //Pick mid1 elements from Arr1 and mid2 elements from Array 2
    int n1 = Arr1.size(),n2=Arr2.size();
    if(mid1<n1)
       R1=Arr1[mid1];
    if(mid2<n2)
        R2=Arr2[mid2];

    if(mid1-1>=0)
        L1=Arr1[mid1-1];
    if(mid2-1>=0)
        L2=Arr2[mid2-1];


}
/*
    Here mid means No of Elements picked,
    Hence mid can range from 0 to n/2
    if(L1>R2) This means we selected a value from mid1 which is greater than R2
        Hence anything beyond mid1 will also result as L1>R2
        So we need to reduce L1 range
        Hence we do high = mid-1;

    If(L2>R1) This means we selected a val in mid2 greater than R1
        Hence we need to include value of Arr1 next to mid1
        To include value of Arr1 we make low = mid+1;


    If Neither of above means Array is sorted and we got he correct combination
    Now calculate median.


    For median of Even calculate as (max(L1,L2)+min(R1,R2))/2.0;

    For Median of Odd calculate as max(L1,L2);


*/

// TC --> O(Log(min(m,n))) ~~ O(LogN)
// SC --> O(1)
double MergeSortedArrayAndFindMedian_Sol3(vector<int>& Arr1,vector<int>& Arr2)
{
    int n1 = Arr1.size();
    int n2 = Arr2.size();

    if(n1>n2)
        return MergeSortedArrayAndFindMedian_Sol3(Arr2,Arr1);
    int n = (n1+n2+1)/2;
    int L1 = -1e9,L2 = -1e9,R1 = 1e9,R2=1e9;

    int low=0,high=n;
    while(low<=high)
    {
        int mid1 = (low+high)/2;
        int mid2 = n-mid1;

        find_Values(L1,L2,R1,R2,Arr1,mid1,Arr2,mid2);

        if(L1>R2)
           high = mid1-1;
        else if(L2>R1)
            low = mid1+1;
        else
        {
            cout << "L1=" << L1 << " L2=" << L2 << " R1=" << R1 << " R2=" << R2 << endl;
            double ans = -1.0;
            if((n1+n2)%2==0)
                 ans = (max(L1,L2)+min(R1,R2))/2.0;
            else
                 ans = max(L1,L2);

            cout << "ans=" << ans << endl;
            return ans;
        }
    }

    return -1;

}

int main()
{
    vector<int> Arr1 = {1,3,4,7,10},Arr2 = {2,3,6,15};
    vector<int> Arr3 = {0};
    int median1 = MergeSortedArrayAndFindMedian_Sol1(Arr1,Arr2,Arr3);
    cout << "Using Sol1 Median = " << median1 << endl;

    int median2 = MergeSortedArrayAndFindMedian_Sol2(Arr1,Arr2);
    cout << "Using Sol2 Median = " << median2 << endl;

    double median3 = MergeSortedArrayAndFindMedian_Sol3(Arr1,Arr2);
    cout << "Using Sol3 Median = " << median3 << endl;

    return 0;
}
