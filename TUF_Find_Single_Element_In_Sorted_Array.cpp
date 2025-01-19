#include <iostream>
#include <vector>

using namespace std;

int single_Element_Sol1(vector<int>& Arr)
{
    int n = Arr.size();

    //if(n==1)
        //return Arr[0];

    for(int i=0;i<n;i++)
    {
        int cur = Arr[i];
        int prev=-1,next=-1;
        if(i>=1)
            prev = Arr[i-1];
        if(i+1<n)
            next = Arr[i+1];

        if(cur!=prev && cur!=next)
        {
            // Element is single
            return cur;
        }
    }
    return -1;
}

/*
    1 1 2 2 4 5 5
    0 1 2 3 4 5 6

    mid = 0 then if( Arr[mid] == Arr[mid+1] ) then Left Part is Existing in Pairs
    mid = 1 then if( Arr[mid] == Arr[mid-1] ) then Left Part is Existing in Pairs

    Hence if mid%2==0 && ( Arr[mid] == Arr[mid+1] )  || mid%2==1 && ( Arr[mid] == Arr[mid-1] )
            then We can eliminate Left and Keep Only Right
            So low = mid+1

    {even,odd} --> Eliminate Left
    {Odd,even} --> Eliminate Left
*/
int single_Element_Sol3(vector<int>& Arr)
{
    int n = Arr.size();

    if(Arr[0]!=Arr[1]) return Arr[0];

    if(Arr[n-1]!=Arr[n-2]) return Arr[n-1];
    int low = 1,high = n-2;

    while(low<=high)
    {
        int mid = low + (high-low)/2;

        int cur = Arr[mid];
        int prev = Arr[mid-1];
        int next = Arr[mid+1];

        if(cur!=prev && cur!=next)
        {
            // Element is single
            return cur;
        }

        if( (mid%2==0 && Arr[mid]==Arr[mid+1]) ||
            (mid%2==1 && Arr[mid]==Arr[mid-1]) )  // Left part is existing as Pairs, Eliminate Left
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> Arr = {1,1,2,2,3};
    int single_ele_1 = single_Element_Sol1(Arr);
    cout << "Using Sol 1 Single Element in Array = " << single_ele_1 << endl;

    int single_ele_3 = single_Element_Sol3(Arr);
    cout << "Using Sol 3 Single Element in Array = " << single_ele_3 << endl;
    return 0;
}
