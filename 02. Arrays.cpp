#include <bits/stdc++.h> 
using namespace std;

//ARRAYS

//MAXIMUM SUBARRAY SUM 
//BRUTE FORCE                                                                {T.C = O(N^2), S.C = O(1)}
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum = sum + arr[j];
            if(sum < 0){
                sum = 0;
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
//(KADANE'S ALGO)                                                            {T.C = O(N), S.C = O(1)}
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long maxi = 0;
    for(int i = 0 ; i < n ; i++){
        sum = sum + arr[i];
        maxi = max(maxi, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}
/*
Sample Input 1 :
9
1 2 7 -4 3 2 -10 9 1
Sample Output 1 :
11
*/


//FLIP BITS                                                                   {T.C = O(N), S.C = O(1)}
#include <bits/stdc++.h> 
int flipBits(int* arr, int n) {
    int oneCount = 0;
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        //before flipping count
        if (arr[i] == 1) {
            oneCount++;
        } 
        //after flipping
        int val = (arr[i] == 0) ? 1 : -1;
        sum = sum + val;
        maxi = max(maxi, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return oneCount + maxi;
}
/*
Sample Input 1 :
3
5
1 0 0 1 0
4
1 1 1 0
5
0 0 1 0 0
Sample Output 1 :
4
4
4
*/


//MAXIMUM SUBARRAY SUM AFTER K CONCATENATION                                          {T.C = O(N*K), S.C = O(1)}
#include <bits/stdc++.h> 
//1 test case failed
long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
	//using kadane's algo
	long long sum = 0; 
	long long maxi = INT_MIN;
	
	for(int i = -1 ; i < n*k-1 ; i++){
		if(sum < 0){
			sum = 0;
		}
		sum += arr[(i+1)%n];
		maxi = max(maxi , sum);
	}
	return maxi;
}
//copied
long long kadane(vector<int> &arr, int n, int k)
{
  long long maxSum = -1e15;
  long long curSum = 0; 
  for (int i = 0; i < n * k; i++){ 
    curSum += arr[i % n];   
    maxSum = max(maxSum, curSum);  
    if (curSum < 0){
      curSum = 0;
    } 
  } 
  return maxSum;
}

long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{   
  long long maxSubSum;
  if (k == 1){
    maxSubSum = kadane(arr, n, k);
    return maxSubSum;
  }
  int arrSum = 0;
  for (int i = 0; i < n; i++){
    arrSum += arr[i];
  }
  if (arrSum <= 0){   
    // Finding the maximum subarray sum for k = 2.
    maxSubSum = kadane(arr, n, 2);   
  }
  else{
    // Finding the maximum subarray sum for k = 2.
    maxSubSum = kadane(arr, n, 2);
    maxSubSum += (long long)(k - 2) * (long long)arrSum;
  } 
  return maxSubSum;
}
/*
Sample Input 1 :
2
2 3
1 3
3 2
1 -2 1
Sample Output 1 :
12
2
*/


//MAXIMUM SUM RECTANGLE                                                  {T.C = O(N*M^2), S.C = O(N)}
int kadane(vector<int>& arr, int n) {
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
        maxi = max(maxi, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m) {
    vector<int> sum(n, 0);
    int maxSum = INT_MIN;
    for (int cStart = 0; cStart < m; cStart++) {
        for (int cEnd = cStart; cEnd < m; cEnd++) {
            for (int row = 0; row < n; row++) {
                sum[row] += arr[row][cEnd];
            }
            int currSum = kadane(sum, n);
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
        for (int row = 0; row < n; row++) {
            sum[row] = 0; // reset the sum array for the next column range
        }
    }
    return maxSum;
}
/*

Sample Input 2
1
4 5
1 2 -1 -4 -20
-8 -3  4 2 1
3  8 10 1 3
-4 -1 1 7 -6
Sample Output 2
29
*/


//SORT 0's 1's and 2's                                                     {T.C = O(N), S.C = O(1)}
void sort012(int *arr, int n)
{  
   int low =0;
   int mid = 0;
   int high = n-1;
   // while(mid <= high){
   for(int i = 0 ; i < n ; i++){
      if(arr[mid] == 0){
         swap(arr[mid], arr[low]);
         low++;
         mid++;
      }
      else if(arr[mid] == 1){
         mid++;
      }
      else{   //mid == 2
         swap(arr[mid], arr[high]);
         high--;
      }
   }
}
/*
Sample Input 1 :
2
6
0 1 2 2 1 0
7
0 1 2 1 2 1 2
Sample Output 1 :
0 0 1 1 2 2
0 1 1 1 2 2 2
*/


//QUICKSORT USING THE DUTCH NATIONAL FLAG ALGORITHM                                                  {T.C = O(N*LOGN), S.C = O(LOGN)}
void dutchNationalFlag(vector<int>&arr, int s, int &midLeft, int &midRight, int e){
    int pivot = arr[s];
    int mid = s;
    while( mid <= midRight){
        if(arr[mid] < pivot){
            swap(arr[mid], arr[midLeft]);
            mid++;
            midLeft++;
        }
        else if(arr[mid] == pivot){
            mid++;
        }
        else{
            swap(arr[mid], arr[midRight]);
            midRight--;
        }
    }
}
void quickSort(vector<int>&arr, int s, int e){
    if(s >= e){
        return;
    }
    int midLeft = s;
    int midRight = e;

    dutchNationalFlag(arr, s , midLeft, midRight, e);

    quickSort(arr, s , midLeft-1);
    quickSort(arr, midRight+1, e);
}
vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr)
{
    int s = 0;
    int e = arr.size()-1;
    quickSort(arr, s, e);
    return arr;
}
/*
Sample Input 1 :
2
5
4 2 1 4 2
5
5 2 7 3 5
Sample Output 1:
1 2 2 4 4
2 3 5 5 7
*/


//SEARCH IN ROTATED SORTED ARRAY
//BRUTE FORCE (LINEAR SEARCH)                                                                {T.C = O(N), S.C = O(1)}
int search(int* arr, int n, int key) {
   for(int i = 0 ; i < n ; i++){
      if(arr[i] == key){
         return i;
      }
   }
   return -1;
}

//BINARY SEARCH                                                                              {T.C = O(LOGN), S.C = O(1)}
int search(int* arr, int n, int key) {
   int lo = 0;
   int hi = n-1;
   while(lo <= hi){
      int mid = lo + (hi - lo)/2;
      if(arr[mid] == key){
         return mid;
      }
      //left part sorted
      if(arr[lo] <= arr[mid]){
         if(arr[lo] <= key && key <= arr[mid]){
            hi = mid-1;
         }
         else{
            lo = mid+1;
         }
      }
      //right part sorted
      else{   
         if(arr[mid] <= key && key <= arr[hi]){
            lo = mid+1;
         }
         else{
            hi = mid-1;
         }
      }
   }
   return -1;
}
/*
Sample Input 1:
4
2 5 -3 0
2
5
1
Sample Output 1:
1
-1
*/


//FORM A TRIANGLE
//BRUTE  FORCE                                                                               {T.C = O(N^3) , S.C = O(1)}
bool check(int a, int b, int c){
    if((a+b > c) && (b+c > a) && (a+c > b)){
        return true;
    }
    return false;
}
bool possibleToMakeTriangle(vector<int> &arr)
{   
    int n = arr.size();
    bool ans = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            for(int k = j+1; k < n ; k++){
                if(arr[i] > 0 && arr[j] > 0 && arr[k] > 0){
                    ans = check(arr[i], arr[j], arr[k]);
                }
                if(ans == true){
                    return true;
                }
            }
        }
    }
    return false;
}  
//using triangle property in single loop                                                {T.C = O(N*LOGN), S.C = O(1)}
bool possibleToMakeTriangle(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i = 0 ; i <= n-3 ; i++){
        if((arr[i]+arr[i+1] > arr[i+2]) && (arr[i]+arr[i+2] > arr[i]) && (arr[i+1]+arr[i+2] > arr[i])){
            return true;
        }
    }
    return false;
}
/*
Sample Input 2:
2
5
12 3 7 4 28
4
7 12 9 20
Sample Output 2:
NO
YES
*/


//FIND FIRST AND LAST INDEX OF ELEMENT IN A SORTED ARRAY                            {T.C = O(N), S.C = O(1)}
vector<int> searchRange(vector<int> &arr, int x)
{
	int n = arr.size();
	int start = -1;
	int end = -1;
	for(int i = 0 ; i < n ; i++){
		if(arr[i] == x){
			start = i;
			break;
		}
	}
	for(int j = n-1 ; j >= 0 ; j-- ){
		if(arr[j] == x){
			end = j;
			break;
		}
	}

	return {start,end};                            //way to return direct vector
}
/*
Sample Input 1:
5
-10 -5 -5 -5 2
-5
Sample Output 1:
1 3
*/


//COUNT SMALLER OR EQUAL ELEMENTS IN ARRAY
//BRUTE FORCE                                                                            {T.C = O(N*M), S.C = O(1)}
vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {
    
    vector<int> count(n, 0);
    for(int i = 0  ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i] >= b[j]){
                count[i]++;
            }
        }
    }
    return count;
}
//OPTIMIZED APPROACH (BINARY SEARCH)                                                     {T.C = O(N*LOGM), S.C = O(N)}
int search(int key , int arr[], int m){
    int lo = 0; 
    int hi = m-1;
    int count = 0;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid] <= key ){
            count += (mid-lo+1);                    //gives length
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return count;
}
vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {
    // sort(b.begin(), b.end());                  //for vector
    sort(b, b+m);                                 //for array
    vector<int>ans;
    for(int i = 0  ; i < n ; i++){
        int key = a[i];
        int count = search(key,b,m );
        ans.push_back(count);
    }
    return ans;
}
/*
Sample Input 1:
1
5
5 4 3 2 1
2
3 4
Sample Output 1:
2 2 1 0 0
*/

 
//SEARCH INSERT POSITION                                                                        {T.C = O(LOGN), S.C = O(1)}
int searchInsert(vector<int>& arr, int m)
{	
	int n = arr.size();
	if(n == 0){
		return 0;                                //empty array after insert element index == 0 also
	}

	int lo = 0;
	int hi = n-1;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(arr[mid] == m){
			return mid;                         //return index
		}
		else if(arr[mid] < m){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}

	//lo == 0 reperesent correct position if empty
	return lo;
}
/*
Sample Input 1:
4 9
1 2 4 7
Sample Output 1:
4
Explanation Of Input 1:
The given array 'arr' is: [1, 2, 4, 7] and m = 9. We insert m = 9 in the array and get 'arr' as: [1, 2, 4, 7, 9].
The position of 9 is 4 (according to 0-based indexing)
*/


//SUM OF INFINITE ARRAY
int mod=1e9+7;

// function for finding sum from 1 to i'th term 
long long sum_upto_i(vector<long long> &prefix, long long i, long long n){
    
    // how much time this whole array are repeat we store here  
    long long repeat = (i/n)%mod;
    // and find the prefix sum of repeat time and store in sum 
    long long sum = (repeat*prefix[n]) % mod;

    // some last remining array element's sum we add here 
    sum = (sum + (prefix[(i%n)])) % mod;

    // after finding sum return it 
    return sum;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // create a vector for prefix sum of the array
    vector<long long> prefix_sum(n+1, 0);
    vector<int> result;

    //find prefix sum and store it 
    for(int i=1; i<=n; i++){
        // prefix sum start from i=1 t0 i=n beacuse base case is 1. 
        prefix_sum[i] =((arr[i-1] + prefix_sum[i-1])%mod);
    }

    // here we store the values of l and r from queries and find prefix sum
    for(int j=0; j<q; j++){
        long long l=queries[j][0];
        long long r=queries[j][1];

        // find and store prefix sum for i=l
        long long left_sum = sum_upto_i(prefix_sum, l-1, n);
        // find and store prefix sum for i=r
        long long right_sum = sum_upto_i(prefix_sum, r, n);

        // required prefix sum is right_sum - left_sum
        // ans here we add mod beacuse if left_sum > right_sum then we get 
        // nagetive value so for that case we add mod 
        result.push_back((right_sum-left_sum+mod)%mod);

    }
    //return result here
    return result;
}
/*
Sample Input 1 :
1
3
1 2 3
2
1 3
1 5
Sample Output 1 :
6 9
Explanation To Sample Input 1 :
For the first test case, the given array A is [1,2,3] therefore the infinite array “B” will be 
[1,2,3,1,2,3,1,2,3,.......]. So the answer for the given first query is 6 because the sum of the subarray from 
index 1 to 3 of infinite array “B” i.e. (B[1]+B[2]+B[3]) is 6.

For the given second query is 9 because the sum of the subarray from index 1 to 5 of array “B” .ie 
(B[1]+B[2]+B[3]+B[4]+B[5]) is 9.
*/