#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
    Problem: Given a List of Paintings we have divide among Painters such that
            Each Painter has at-least 1 Set of Paintings
            The time to finish the painting is Minimum
            In order to finish the painting in Minimum Time we need to paint Maximum Painting among K Painters
            
    Painting Set   10   20   30   40
    
    Max Painting = 40
    
    P1 = 10         <= 40   --> Possible
       = 10+20      <= 40   --> Possible
       = 10+20+30   <= 40   --> Not Possible
       
    P2 = 30         <= 40   --> Possible
       = 30 + 40    <= 40   --> Not Possible
       
    P3 = 40         <= 40   --> Possible
    
    Hence 3 Painters are Needed
    
    ...
    ...
    
    Try Max Painting as 50
    
    P1 = 10         <= 50   --> Possible
       = 10+20      <= 50   --> Possible
       = 10+20+30   <= 50   --> Not Possible
       
    P2 = 30         <= 50   --> Possible
       = 30 + 40    <= 50   --> Not Possible
       
    P3 = 40         <= 50   --> Possible
    
    Hence 3 Painters are Needed
    
    
    Try Max Painting as 60
    
    P1 = 10             <= 60   --> Possible
       = 10+20          <= 60   --> Possible
       = 10+20+30       <= 60   --> Possible
       = 10+20+30+40    <= 60   --> Not Possible
       
    P2 = 40         <= 60   --> Possible
    
    Hence 2 Painters are Needed
    
    Hence Min Time Needed is 60 units and Painter1  will paint 10,20,30 and Painter2 will paint 40
    
    
*/
int PossibleMinNoOfPainters(vector<int>& Arr,int max_Paintings,int K) // K is No Of Painters
{
    int n = Arr.size();
    int cnt=1;
    int sum = 0;
    for(int idx = 0;idx<n;idx++)
    {
        if(sum+Arr[idx]<=max_Paintings)
        {
            sum+=Arr[idx];
        }
        else
        {
            sum=0;
            cnt++;
            if(sum+Arr[idx]<=max_Paintings)
                sum+=Arr[idx];
        }
    }
    return cnt;
}

int painterPartition_Sol1(vector<int>& Arr,int K) // K is No Of Painters
{
    int max_Paintings = *max_element(Arr.begin(),Arr.end());
    int total_Paintings = accumulate(Arr.begin(),Arr.end(),0);

    for(int painting = max_Paintings;painting<total_Paintings;painting++)
    {
        int min_Painters_Needed_to_Paint = PossibleMinNoOfPainters(Arr,painting,K); // K is No Of Painters

        if(min_Painters_Needed_to_Paint==K)
            return painting;
    }
    return -1;

}


int painterPartition_Sol2(vector<int>& Arr,int K) // K is No Of Painters
{
    int max_Paintings = *max_element(Arr.begin(),Arr.end());
    int total_Paintings = accumulate(Arr.begin(),Arr.end(),0);

    int low = max_Paintings,high = total_Paintings;

    while(low<=high)
    {
        int mid = low + (high-low)/2;

        int min_Painters_Needed_to_Paint = PossibleMinNoOfPainters(Arr,mid,K); // K is No Of Painters

        if(min_Painters_Needed_to_Paint>K)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}

int main()
{
    vector<int> Paintings = {10,20,30,40};
    int K = 2; // No Of Painters = 2;
    int res1 = painterPartition_Sol1(Paintings,K);
    cout << "Using Sol1 Maximum Paints with Min Time res1 = " << res1 << endl;

    int res2 = painterPartition_Sol2(Paintings,K);
    cout << "Using Sol2 Maximum Paints with Min Time res2 = " << res2 << endl;
    return 0;
}
