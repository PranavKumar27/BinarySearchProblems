#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int sum(vector<int>& Arr)
{
    int n = Arr.size();

    int s = (Arr[n-1]*(Arr[n-1]+1))/2;

    return s;
}

int findDaysToTransport(vector<int>& Arr,int capacity)
{
    int n = Arr.size();
    int day = 1;
    int load = 0;

    for(int i=0;i<n;i++)
    {
        if(load + Arr[i]>capacity)
        {
            day++;
            load = Arr[i];
        }
        else
        {
            load = load+Arr[i];
        }
    }
    //cout << "Required day =" << day << endl;
    return day;
}

int findDaysToTransport_2(vector<int>& Arr,int capacity)
{
    int n = Arr.size();
    int current_cap = capacity;
    int day = 1;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]<=current_cap)
        {
            current_cap = current_cap - Arr[i];
        }
        else
        {
            day = day + 1;
            current_cap = capacity;

            if(Arr[i]<current_cap)
            {
                current_cap = current_cap - Arr[i];
            }
        }
    }
    return day;
}

// TC --> O(max-min+1)*O(N)
int find_Least_Capacity_of_Ship_Sol1(vector<int>& Arr,int& max_days)
{
    // Considering Arr is sorted
    int n = Arr.size();
    int Max_capacity = sum(Arr);
    int Min_capacity = Arr[n-1]; // Min cap has to max wt present

    for(int cap = Min_capacity;cap<=Max_capacity;cap++)
    {
        int days = findDaysToTransport(Arr,cap);
        if(days<=max_days)
            return cap;
    }
    return -1;
}

// TC --> O(log(max-min+1))*O(N)
int find_Least_Capacity_of_Ship_Sol2(vector<int>& Arr,int& max_days)
{
    int n = Arr.size();
    // Considering Arr is sorted
    int Max_capacity = accumulate(Arr.begin(),Arr.end(),0); // Sum All Numbers
    int Min_capacity = *max_element(Arr.begin(),Arr.end()); // Min cap has to max wt present

    int low = Min_capacity,high = Max_capacity;

    while(low<=high)
    {
        int mid = low + (high-low)/2;

        int day = findDaysToTransport_2(Arr,mid);
        cout << "mid=" << mid <<"  day =" << day << endl;

        if(day<=max_days)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}
int main()
{
    vector<int> Arr = {1,2,3,4,5,6,7,8,9,10};
    int max_days = 5;
    int least_Capacity1 = find_Least_Capacity_of_Ship_Sol1(Arr,max_days);
    cout << "Using Sol_1 Least Capacity Of Ship =" << least_Capacity1 << endl;

    int least_Capacity2 = find_Least_Capacity_of_Ship_Sol2(Arr,max_days);
    cout << "Using Sol_2 Least Capacity Of Ship =" << least_Capacity2 << endl;

    return 0;
}
