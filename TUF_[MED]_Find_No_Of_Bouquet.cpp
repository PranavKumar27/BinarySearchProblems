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

pair<int,int> find_max_min(vector<int>& Arr)
{
    int max_val = -1e9;
    int min_val = 1e9;
    for(int i=0;i<Arr.size();i++)
    {
        max_val = max(max_val,Arr[i]);
        min_val = min(min_val,Arr[i]);
    }

    return {max_val,min_val};
}


int find_bouquet(vector<int>& Arr,int day,int M,int K)
{
    int n = Arr.size();
    int no_of_bouquet = 0,cnt = 0;

    for(int i=0;i<n;i++)
    {
        if(Arr[i]<=day)
            cnt++;
        else
        {
            no_of_bouquet+=cnt/K;
            cnt = 0;
        }
    }
    if(cnt>=K)
        no_of_bouquet+=cnt/K;

    return no_of_bouquet;
}
// TC --> O(N) * O(X) (where X is the diff of max - min in Arr)
int find_day_Sol1(vector<int>& Arr,int M,int K)
{
    int n = Arr.size();
    int no_of_flowers = M*K;
    if(n<no_of_flowers)
        return -1;

    pair<int,int> pair_max_min = find_max_min(Arr);
    int max_day_to_Bloom = pair_max_min.first;
    int min_day_to_Bloom = pair_max_min.second;
    for(int day=min_day_to_Bloom;day<=max_day_to_Bloom;day++)
    {
        int No_of_bouquet_Possible = find_bouquet(Arr,day,M,K);
        //cout << "ON Day=" << day << " No_of_bouquet_Possible=" << No_of_bouquet_Possible << endl;
        if(No_of_bouquet_Possible == M)
        {
            return day;
        }

    }
}

// TC --> O(N) * O(Log X) (where X is the diff of max - min in Arr)
int find_day_Sol2(vector<int>& Arr,int M,int K)
{
    int n = Arr.size();
    long long int no_of_flowers = m*1LL * k*1LL; // Convert to Long Long to avoid INT overflow
    if(no_of_flowers>n)
        return -1;

    pair<int,int> pair_max_min = find_max_min(Arr);
    int max_day_to_Bloom = pair_max_min.first;
    int min_day_to_Bloom = pair_max_min.second;

    int low = min_day_to_Bloom,high = max_day_to_Bloom;


    while(low<=high)
    {
        int mid = low+(high-low)/2;

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
