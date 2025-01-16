#include <iostream>
#include <vector>

using namespace std;

pair<int,int> First_And_Last_Occurence_Sol1(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int first = -1,last=-1;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]==target)
        {
            if(first==-1)
                first = i;
            last=i;
        }
    }

    return {first,last};
}

int find_lb(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low=0,high=n-1;
    int ans = n;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(Arr[mid]>=target)
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int find_ub(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low=0,high=n-1;
    int ans = n;

    while(low<=high)
    {
        int mid = low+(high-low)/2;

        if(Arr[mid]>target)
        {
            ans = mid;
            high = mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}


pair<int,int> First_And_Last_Occurence_Sol2(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int lb = find_lb(Arr,target);
    int ub = find_ub(Arr,target);

    cout << " lb=" << lb << "  ub=" << ub  << endl;

    int first = -1,last=-1;
    if(lb==n && ub-1==n)
    {

    }
    else if(lb!=n && ub-1==n && Arr[lb-1]==target)
    {
        first = lb;
        last = lb;
    }
    else if(lb==n && ub-1!=n && Arr[ub-1]==target)
    {
        first = ub;
        last = ub-1;
    }
    else if(lb!=n && ub-1!=n && Arr[ub-1]==target && Arr[lb]==target)
    {
        first = lb;
        last = ub-1;
    }

    return {first,last};

}


/*
    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13         first = 3 , move to left to find first occurence
    l              m                    h

    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13         first = 3 , 4<8 move right l = m+1
    l    m    h


    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13          first = 2 , 8==8 move left h = mid-1
             l,h
              m

    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13           while(l<=h) --> Fail
         h    l

    Hence First occurrence Index = 2


    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13         last = 3 , move to right to find last occurence
    l              m                    h

    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13         last = 5 , move to right to find last occurence
                       l    m           h

    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13         last = 5 , 11>8 move to the left h = m-1
                                l,m      h


    0    1    2    3   4    5    6     7
    2,   4,   8,   8,  8,   8,   11,   13         last = 5 , while(l<=h) --> Fail
                            h    l

    Hence Last Occurence Index = 5

    Ans is {first,last} or {2,5}

*/

pair<int,int> First_And_Last_Occurence_Sol3(vector<int>& Arr,int target)
{
    int n = Arr.size();
    int low = 0,high = n-1;
    int first=-1,last=-1;

    // Finding First Occurence, First Occurence can be on left side of the node where found or the node itself
    // So if arr[mid] matches target always move left
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(Arr[mid]==target)
        {
            first = mid;
            high = mid-1;
        }
        else if(Arr[mid]<target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    if(first==-1) // If first itself is not found, we can't find last also
    return {first,last};

    // Finding Last Occurence, Last Occurence can be on right side of the node where found or the node itself
    // So if arr[mid] matches target always move right

    low = 0,high = n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;

        if(Arr[mid]==target)
        {
            last = mid;
            low = mid+1;
        }
        else if(Arr[mid]<target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return {first,last};

}


int main()
{
    vector<int> Arr = {2,4,8,8,8,8,11,13};
    int target = 8;
    pair<int,int> Ans1 = First_And_Last_Occurence_Sol1(Arr,target);
    cout << "Using Sol 1 first occurence =" << Ans1.first << " last occurence =" << Ans1.second << endl;

    pair<int,int> Ans2 = First_And_Last_Occurence_Sol2(Arr,target);
    cout << "Using Sol 2 first occurence =" << Ans2.first << " last occurence =" << Ans2.second << endl;

    pair<int,int> Ans3 = First_And_Last_Occurence_Sol3(Arr,target);
    cout << "Using Sol 3 first occurence =" << Ans3.first << " last occurence =" << Ans3.second << endl;
    return 0;
}
