#include<bits/stdc++.h>
using namespace std;

struct point
{
  long long int x,y;
};
long long int distance(long long int x,long long int y)
{
  long long int d = (x*x)+(y*y);
  return d;
}

void swap(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

long long int partition(long long int arr[], long long int l, long long int r, long long int x)
{
    long long int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (long long int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

long long int findMedian(long long int arr[], long long int n)
{
    sort(arr, arr+n);
    return arr[n/2];
}

long long int kthSmallest(long long int arr[], long long int l, long long int r, long long int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        long long int n = r-l+1;

        long long int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }

        long long int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);

        long long int pos = partition(arr, l, r, medOfMed);

        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);

        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    return INT_MAX;
}

int main()
{
  long long int n,t;
  cin >> t;
  while(t--)
  {
  cin >> n;
  struct point pt[n];
  for(long long int i=0;i<n;i++)
  {
    cin >> pt[i].x;
    cin >> pt[i].y;
  }
  long long int dis[n];
  for(long long int i=0;i<n;i++)
  {
    dis[i] = distance(pt[i].x,pt[i].y);
  }
  if(n%2==0)
  cout << sqrt(kthSmallest(dis,0,n-1,n/2)) << endl;
  if(n%2==1)
  cout << sqrt(kthSmallest(dis,0,n-1,(n+1)/2)) << endl;
  }
}
