#include <iostream>
#include <vector>

using namespace std;


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

    pair<int,int> Ans = First_And_Last_Occurence_Sol3(Arr,target);
    cout << "Using Sol 3 first occurence =" << Ans.first << " last occurence =" << Ans.second << endl;

    int count = Ans.second-Ans.first+1;
    cout << "Freq of data =" << target << " in the Array is = " << count << endl;
    return 0;
}
