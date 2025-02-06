#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

using namespace std;

void print_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

void print_PQ(priority_queue<pair<int,int>> pq)
{
    priority_queue<pair<int,int>> temp = pq;
    while(temp.size()>0)
    {
        cout << temp.top().first << " ," << temp.top().second << endl;
        temp.pop();
    }
    cout << endl;
}

int find_Index_Max_Element(vector<int>& Arr)
{
    int ans = -1e9;
    int idx;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        if(Arr[i]>ans)
        {
            ans = Arr[i];
            idx = i;
        }
    }
    return idx;
}
int UpdateDistanceAndSector_Sol1(vector<int>& Arr,vector<int>& All_dist,vector<int>& sector)
{
    int n = Arr.size();
    int index = find_Index_Max_Element(All_dist);

    int val = Arr[index+1]-Arr[index];
    sector[index]+=1;
    int sec = sector[index]+1;
    cout << "index=" << index << " val=" << val << " sec=" << sec << endl;

    All_dist[index] = val/sec;
    cout << "Updated dist=" << All_dist[index] << endl;

    return *max_element(All_dist.begin(),All_dist.end());

}
int UpdateDistanceAndSector_Sol2(vector<int>& Arr,vector<int>& sector,priority_queue<pair<int,int>>& pq)
{
    int n = Arr.size();
    pair<int,int> p = pq.top();
    int index = p.second;

    int val = Arr[index+1]-Arr[index];
    sector[index]+=1;
    int sec = sector[index]+1;
    cout << "index=" << index << " val=" << val << " sec=" << sec << endl;

    int new_val = val/sec;
    pq.pop();
    pq.push({new_val,index});
    cout << "Updated dist=" << new_val << endl;

    return (pq.top()).first;

}

int find_Max_Dist_Sol1(vector<int>& Arr,int K)
{
    int n = Arr.size();
    vector<int> Sec(n-1,0);
    vector<int> All_dist(n-1);
    for(int i=0;i<=n-2;i++)
    {
        All_dist[i] = Arr[i+1]-Arr[i];
    }

    print_v(All_dist);
    print_v(Sec);

    int max_dist = -1;
    for(int i=1;i<=K;i++)
    {
        max_dist = UpdateDistanceAndSector_Sol1(Arr,All_dist,Sec);
        //cout << "distance" << endl;
        print_v(All_dist);
        //cout << "Sector" << endl;
        print_v(Sec);

    }
    return max_dist;
}

int find_Max_Dist_Sol2(vector<int>& Arr,int K)
{
    int n = Arr.size();
    vector<int> Sec(n-1,0);
    vector<int> All_dist(n-1);
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<=n-2;i++)
    {
        int val = Arr[i+1]-Arr[i];
        pq.push({val,i});
    }

    cout << "PQ size =" << pq.size() << endl;
    print_PQ(pq);
    print_v(Sec);

    int max_dist = -1;
    for(int i=1;i<=K;i++)
    {
        max_dist = UpdateDistanceAndSector_Sol2(Arr,Sec,pq);
    }
    return max_dist;
}

int main()
{
    vector<int> Arr ={1,13,17,23};
    int k = 5;
    int res1 = find_Max_Dist_Sol1(Arr,k);
    cout << "Using Sol1 Minimum distance between Fuel Stations =" << res1 << endl;

    int res2 = find_Max_Dist_Sol2(Arr,k);
    cout << "Using Sol2 Minimum distance between Fuel Stations =" << res2 << endl;
    return 0;
}
