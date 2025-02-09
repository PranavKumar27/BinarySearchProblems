#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// BRUUUUTEEEE APPPROAACH
// TC --> O(min(n1,n2)) + O(n1-min(n1,n2)) + O(n2-min(n1,n2)) ~~ 3*O(N)
// SC --> O(N) for Storing Merged Arr
int findKth_Element_Sol1(vector<int>& Arr1,vector<int>& Arr2,
                         int K)
{
    if(K==0)
        return -1;
    K = K-1; // Since Zero Based Indexing
    int n1=Arr1.size(),n2=Arr2.size();
    int i=0,j=0;
    int n = n1+n2;
    vector<int> Arr3;
    while(i<n1 && j< n2)
    {
        if(Arr1[i]<Arr2[j])
        {
            Arr3.push_back(Arr1[i]);
            i++;
        }
        else
        {
            Arr3.push_back(Arr2[j]);
            j++;
        }
    }

    while(i<n1)
    {
        Arr3.push_back(Arr1[i]);
        i++;
    }

    while(j<n2)
    {
        Arr3.push_back(Arr2[j]);
        j++;
    }
    int sz = Arr3.size();
    if(K<sz)
        return Arr3[K];
    else
        return -1;
}

// BETTTTTTER APPPROAACH
// TC --> O(min(n1,n2)) + O(n1-min(n1,n2)) + O(n2-min(n1,n2)) ~~ 3*O(N)
// SC --> O(1)
int findKth_Element_Sol2(vector<int>& Arr1,vector<int>& Arr2,
                         int K)
{
    if(K==0)
        return -1;
   K = K-1; // Since Zero Based Indexing
   int n1 = Arr1.size(),n2=Arr2.size();
   int i=0,j=0,k=0;
   int element_K=-1;
   while(i<n1 && j<n2)
   {
       if(Arr1[i]<Arr2[j])
       {
           if(k==K)
           {
               element_K = Arr1[i];
           }
           i++;
           k++;
       }
       else
       {
           if(k==K)
           {
               element_K = Arr2[j];
           }
           j++;
           k++;
       }
   }

   while(i<n1)
   {
        if(k==K)
        {
            element_K = Arr1[i];
        }
        i++;
        k++;
   }

   while(j<n2)
   {
        if(k==K)
        {
            element_K = Arr2[j];
        }
        j++;
        k++;
   }

   return element_K;
}

// OPTIIIIMAAALLL APPPROAACH
int findKth_Element_Sol3(vector<int>& Arr1,vector<int>& Arr2,
                         int K)
{
    if(K==0)
        return -1;
    int n1=Arr1.size(),n2=Arr2.size();
    if(n1>n2)
        return findKth_Element_Sol3(Arr2,Arr1,K);

    int low = max(0,K-n2); // At least we need K elements from Arr1 if K>n2
                            // eg: If we need K=7 elements and N2 has only 5 elements
                            // we will need to keep low as 2 instead of 0,
                            // low = 0 means pick Zero elements from Arr1
                            // So low = 2 now means we will have to pick atleast 2 elements
                            // from Arr1
    int high = min(n1,K); // At max We can pick only min of n1,
                            //K elements since we need only K elements
    int n = n1+n2;
    while(low<=high)
    {
       int L1=INT_MIN,L2=INT_MIN;
       int R1=INT_MAX,R2=INT_MAX;
       int mid1 = (low+high)/2;
       cout << "mid1=" << mid1 << endl;
       int mid2 = K-mid1;
       cout << "mid2=" << mid2 << endl;

       if(mid1-1>=0)
        L1 = Arr1[mid1-1];
       if(mid2-1>=0)
        L2 = Arr2[mid2-1];
       if(mid1>=0 && mid1<n1)
        R1 = Arr1[mid1];
       if(mid2>=0 && mid2<n2)
        R2 = Arr2[mid2];

        cout << "L1=" << L1  << " R1=" << R1 << " L2=" << L2 << " R2=" << R2 << endl;

       if(L1<=R2 && L2<=R1)  // The Array is sorted
       {
           return max(L1,L2);
       }
       if(L1>R2)
        high = mid1-1;
       else if(L2>R1)
        low = mid1+1;
    }
    return -1;
}
int main()
{
    vector<int> Arr1 = {2,3,6,7,9},Arr2 = {1,4,8,10};
    int K = 9;
    int res1 = findKth_Element_Sol1(Arr1,Arr2,K);
    cout << "Using Sol1 Kth Element in the Merged Array = " << res1 << endl;

    int res2 = findKth_Element_Sol2(Arr1,Arr2,K);
    cout << "Using Sol2 Kth Element in the Merged Array = " << res2 << endl;

    int res3 = findKth_Element_Sol3(Arr1,Arr2,K);
    cout << "Using Sol3 Kth Element in the Merged Array = " << res3 << endl;

    return 0;
}
