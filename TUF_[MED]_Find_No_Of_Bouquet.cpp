#include <iostream>
#include <vector>

using namespace std;

/*
Find the Minimum Nth Day when M Bouquet ,
each of size K is possible where All K flowers are adjacent Only

eg : Below is list of day when the Floor Blooms
        Flower Boomed = 1 Not Bloomed = 0
            7  7  7  7  13  11  12  7
On day 1    0  0  0  0   0   0   0  0
On day 2    0  0  0  0   0   0   0  0
On day 3    0  0  0  0   0   0   0  0
........
........
On day 7    1  1  1  1  0   0   0  1  No of Groups of K = 1
........
........
On day 11   1  1  1  1  0   1   0  1  No of Groups of K = 1
On day 12   1  1  1  1  0   1   1  1  No of Groups of K = 2**
On day 13   1  1  1  1  1   1   1  1  No of Groups of K = 2

**Hence Ans can be 12,13 But since we want minimum no of days, Return 12

*/

int find_max(vector<int>& Arr)
{
    int max_val = -1e9;
    for(int i=0;i<Arr.size();i++)
        max_val = max(max_val,Arr[i]);
    return max_val;
}

int find_No_Adjacent_Set(vector<int>& Bloom_Hash,int M,int K)
{
    int n = Bloom_Hash.size();
    int total = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(cnt == K)
        {
            total = total+1;
            cnt = 0;
        }
        if(Bloom_Hash[i]==1)
            cnt++;
        else if(Bloom_Hash[i]==0)
        {
            cnt = 0;
        }
    }
    if(cnt==K)
        total = total+1;
    return total;
}

int find_bouquet(vector<int>& Arr,int day,int M,int K)
{
    int n = Arr.size();
    vector<int> Bloom_Hash(n,0);

    for(int i=0;i<n;i++)
    {
        if(Arr[i]<=day)
            Bloom_Hash[i]=1;
    }

    int no_of_bouquet = find_No_Adjacent_Set(Bloom_Hash,M,K);
    return no_of_bouquet;
}

int find_day_Sol1(vector<int>& Arr,int M,int K)
{
    int n = Arr.size();
    int no_of_flowers = M*K;
    if(n<no_of_flowers)
        return -1;

    int max_day_to_Bloom = find_max(Arr);
    for(int day=1;day<=max_day_to_Bloom;day++)
    {
        int No_of_bouquet_Possible = find_bouquet(Arr,day,M,K);
        //cout << "ON Day=" << day << " No_of_bouquet_Possible=" << No_of_bouquet_Possible << endl;
        if(No_of_bouquet_Possible == M)
        {
            return day;
        }

    }
}

int find_day_Sol2(vector<int>& Arr,int M,int K)
{
    int low = 0,high = find_max(Arr);

    while(low<=high)
    {
        int mid = low+(mid-low)/2;

        int no_of_Bouquet = find_bouquet(Arr,mid,M,K);

        if(no_of_Bouquet >= M)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    vector<int> Arr = {7,7,7,7,13,11,12,7};
    int M=2,K=3; // M is No of Bouquet and K is the No Of Flowers in Bouquet

    int ans1= find_day_Sol1(Arr,M,K);
    cout << "Using Sol1 Min Days to Make Bouquet = " << ans1 << endl;

    int ans2= find_day_Sol2(Arr,M,K);
    cout << "Using Sol2 Min Days to Make Bouquet = " << ans2 << endl;
    return 0;
}
