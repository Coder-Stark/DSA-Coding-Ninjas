#include <bits/stdc++.h> 
using namespace std;

//ARRAYS

//01. MAXIMUM SUBARRAY SUM 
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


//02. FLIP BITS                                                                   {T.C = O(N), S.C = O(1)}
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


//03. MAXIMUM SUBARRAY SUM AFTER K CONCATENATION                                          {T.C = O(N*K), S.C = O(1)}
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


//04. MAXIMUM SUM RECTANGLE                                                  {T.C = O(N*M^2), S.C = O(N)}
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


//05. SORT 0's 1's and 2's                                                     {T.C = O(N), S.C = O(1)}
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


//06. QUICKSORT USING THE DUTCH NATIONAL FLAG ALGORITHM                                                  {T.C = O(N*LOGN), S.C = O(LOGN)}
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


//07. SEARCH IN ROTATED SORTED ARRAY
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


//08. FORM A TRIANGLE
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


//09. FIND FIRST AND LAST INDEX OF ELEMENT IN A SORTED ARRAY                            {T.C = O(N), S.C = O(1)}
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


//10. COUNT SMALLER OR EQUAL ELEMENTS IN ARRAY
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

 
//11. SEARCH INSERT POSITION                                                                        {T.C = O(LOGN), S.C = O(1)}
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


//12. SUM OF INFINITE ARRAY
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


//13. XOR QUERY
//BRUTE FORCE                                                                     {T.C = O(N^2), S.C = O(N)}
vector<int> xorQuery(vector<vector<int>> &queries)
{
	vector<int>ans;
	for(int i = 0 ; i < queries.size(); i++){
		if(queries[i][0] == 1){                    //push element in array
			ans.push_back(queries[i][1]);
		}
		else{      //queries[i][0] == 2            //xor of each elements of array
			for(int j = 0 ; j < ans.size(); j++){
				ans[j] = ans[j]^queries[i][1];
			}
		}
	}
	return ans;
}

//OPTIMIZED APPROACH                                                              {T.C = O(N), S.C = O(N)}
vector<int> xorQuery(vector<vector<int>> &queries)
{
	vector<int>ans;
	int Xor = 0;
	for(int i = 0 ; i < queries.size(); i++){
		if(queries[i][0] == 1){                    //push element in array
			ans.push_back(queries[i][1]^Xor);
		}
		else{  
			Xor = Xor^queries[i][1];    //queries[i][0] == 2            //xor of each elements of array
		}

	}
	for(int j = 0 ; j < ans.size(); j++){
		ans[j] = ans[j]^Xor;
	}
	return ans;
}
/*
Sample Input 1:
2
2
1 3
2 2
3
1 2
2 3
2 1
Sample Output 1:
1
0
*/


//14. PRODUCT OF ARRAY EXCEPT ITSELF
//BRUTE FORCE                                                                       {T.C = O(N^2) , S.C = O(N)}
int *getProductArrayExceptSelf(int *arr, int n)
{
    int *result = (int *)malloc(n *sizeof(int));
    for(int i = 0 ; i < n ; i++){
        int product = 1;
        for(int j = 0 ; j < n ; j++){
            if(i != j){
                product *= arr[j];
            }
        }
        result[i] = product;
    }
    return result;
}

//OPTIMIZED APPROACH                                                            {T.C = O(N) , S.C = O(1)}
int mod=1000000007;

int* getProductArrayExceptSelf(int* arr, int n) {
    int* res=new int[n];
    if (n==0){
      return res;  
    } 
    res[0]=1;
    //find prefixProductFromStart
    for (int i=1;i<n;i++){
        res[i]=(((long long)res[i-1]*arr[i-1])%mod);
    }
    long long right=1;
    for (int i=n-1;i>=0;i--){
        res[i]=(res[i]*right)%mod;
        right=(right*arr[i])%mod;
    }
    return res;    
}

//5/6 test cases passes                                                         {T.C = O(N) , S.C = O(1)}
int mod = 1000000007; // Modulo value

int* getProductArrayExceptSelf(int* arr, int n) {
    int* res = new int[n];

    int prodBeforeCurrent = 1;
    int prodAfterCurrent = 1;


    for (int i = 0; i < n; i++) {
        res[i] = prodBeforeCurrent;
        prodBeforeCurrent = (prodBeforeCurrent * arr[i]) % mod;
    }

    for (int i = n - 1; i >= 0; i--) {
        res[i] = (res[i] * prodAfterCurrent) % mod;
        prodAfterCurrent = (prodAfterCurrent * arr[i]) % mod;
    }

    return res;
}
/*
Sample Input 1 :
2
3
1 2 3
3
5 2 2
Sample Output 1 :
6 3 2
4 10 10
*/


//15. COUNT ALL SUB-ARRAYS HAVING SUM DIVISIBLE BY K
//BRUTE FORCE                                                                                   {T.C = O(N^2), S.C = O(1)}
int subArrayCount(vector<int> &arr, int k) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum = sum + arr[j];
            
            // Check if sum is a multiple of k
            if (sum % k == 0) { 
                count++;
            }
        }
    }
    return count;
}

//OPTIMIZED APPROACH                                                           {T.C = O(N), S.C = O(N+K)}
int subArrayCount(vector<int> &arr, int k) {
    int ans = 0;

    // Create a frequency map for remainders when dividing the sum by k.
    vector<int> r_map(k, 0);

    // Initialize the sum to 0.
    long long int sum = 0;

    // Set the remainder 0 to 1, as an empty subarray with sum 0 is valid.
    r_map[0]++;

    // Loop through the array elements.
    for (int i = 0; i < arr.size(); i++) {
        // Add the current element to the running sum.
        sum += arr[i];

        // Calculate the remainder when dividing the current sum by k.
        int rem = sum % k;

        // If the remainder is negative, adjust it to a positive value.
        if (sum % k < 0) {
            rem += k;
        }

        /* If we have seen a subarray with the same remainder before, it means the subarray between those two points 
        has a sum that is divisible by k, so we increment the answer by the number of times we have seen this remainder 
        before.*/
        if (r_map[rem]) {
            ans += r_map[rem];
        }

        // Increment the frequency of the current remainder in the map.
        r_map[rem]++;
    }

    return ans;
}
/*
Sample Input 1:
2
3 2
2 3 1
4 1
1 2 3 4
Sample Output 1:
3
10
*/


//16. PAIR SUM                                                                {T.C = O(N^2), S.C = O(N)}
vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(arr.begin(), arr.end());
   vector<vector<int>>ans;
   for(int i = 0 ; i < arr.size(); i++){
      for(int j = i+1 ; j < arr.size(); j++){
         if(arr[i]+arr[j] == s){
            vector<int>temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            ans.push_back(temp);
         }
      }
   }
   return ans;
}
/*
Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
      2 + 3 = 5
Hence the output will be, (1,4) , (2,3).
*/


//17. VALID PAIRS
//BRUTE FORCE                                                                  {T.C = O(N^2), S.C = O(1)}
bool isValidPair(vector<int> &arr, int n, int k, int m)
{
    //odd no. of elements in arr (no pair of last element)
    if(n % 2 == 1){
        return false;
    }
    //(a+b)%k == m
    for(int i = 0 ; i < n ; i++){            //arr[i]=a
        if(arr[i] == -1){                    //-1 number is paired already
            continue;
        }
        for(int j = i+1 ; j < n ;j++){
            if(arr[j] == -1){
                continue;
            }
            if((arr[i]+arr[j]) % k == m){    //arr[j]=b
                arr[i] = -1;
                arr[j] = -1;
                break;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(arr[i] != -1){
            return false;
        }
    }
    return true;
}

//OPTIMIZED APPROACH (unordered map / hashing)                                    {T.C = O(N), S.C = O(N)}
bool isValidPair(vector<int> &arr, int n, int k, int m)
{
    // Check if the size of the array is odd, which makes it impossible to form a pair
    if (n % 2 == 1) {
        return false;
    }
    // Create an unordered map to store the frequency of elements modulo 'k'
    unordered_map<int, int> freq;
    
    // Count the frequency of elements modulo 'k' and store in 'freq'
    for (int i = 0; i < n; i++) {
        freq[arr[i] % k]++;
    }
    for (auto it : freq) {
        int a = it.first;                      //first->element, second->freq        // The current element from the frequency map
        int x = (m - a + k) % k;               //+k -> to make +ve (m-a)             // Calculate the counterpart 'x' for 'a' // b = m-a

        // If the frequency of 'x' is not equal to the frequency of 'a', a valid pair does not exist
        if (freq[x] != freq[a]) {
            return false;
        }
    }
    return true;
}

/*
Sample Input 1:
1
4
2 1 5 7
9 3
Sample Output 1:
True
*/


//18. MAX PRODUCT COUNT                                                        {T.C = O(N^2) , S.C = O(N)}
//COPIED
#include <bits/stdc++.h>                                                         
// Function to find the maximum product count of two distinct elements in the input array
// and return the minimum value among those maximum product counts and a calculated value.
vector<long long> maxProductCount(vector<int> &arr, int n) {

    // If the array size is less than 4, return 0 (as there won't be enough elements to find products).
    if(n < 4) {
        return {0};
    }

    // Create an unordered map to store the product of all possible pairs of elements in the array
    // along with their count.
    unordered_map<long long, long long> mpp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue; // Skip when both indices are the same (to avoid using the same element twice).
            }
            mpp[(long long)arr[i] * arr[j]]++; // Store the product of the pair and increase its count.
        }
    }

    // Find the maximum product count among all pairs.
    long long max_count = 0;
    for(auto it : mpp) {
        max_count = max(max_count, it.second);
    }

    // If the maximum product count is 2 (i.e., there are only two pairs with the same product),
    // return 0, as there won't be enough distinct products to calculate.
    if(max_count == 2) {
        return {0};
    }

    // Find all the products that have the maximum count.
    vector<long long> nums;
    for(auto it : mpp) {
        if(it.second == max_count) {
            nums.push_back(it.first);
        }
    }

    // Find the minimum value among the products with the maximum count.
    long long mini = *min_element(nums.begin(), nums.end());

    // Calculate and return the minimum value and the total number of pairs with the maximum count.
    return {mini, max_count * (max_count / 2 - 1) / 4};
}


//19. BEST TIME TO BUY AND SELL STOCK II                                                                  {T.C = O(N), S.C = O(1)}
long getMaximumProfit(long *values, int n)   //values == prices
{
    long buyDay = 0;
    long sellDay = 0;
    long profit = 0;

    for(int i = 1 ; i < n ; i++){
        if(values[i] > values[i-1]){
            sellDay++;
        }
        else{
            profit += values[sellDay]-values[buyDay];
            buyDay = sellDay = i;
        }
    }
    profit += values[sellDay]-values[buyDay];
    return profit;
}
/*
Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
Explanation :
We can make the maximum profit by buying the stock on the first day and selling it on the last day.
*/


//20. NON DECREASING ARRAY                                                          {T.C = O(N), S.C = O(1)}
bool isPossible(int *arr, int n)
{
    int modification = 0;

    for(int i = 1 ; i < n ;i++){
        if(arr[i] < arr[i-1]){
            if(modification == 1){
                return false;
            }
            //if atleast 2 element less then curr then match previous one not enough
            if(i >= 2 && arr[i] < arr[i-2]){
                //to maintain increasing order
                arr[i] = arr[i-1];
            }
            else{//modify previous element suffient to match curr one
                arr[i-1] = arr[i];
            }
            modification++;
        }
    }
    return true;
}
/*
Sample Input 1 :
2
3
8 4 6
3
8 4 2
Sample Output 1 :
true
false
*/


//21. LONGEST CONSECUTIVE SEQUENCE
//BRUTE FORCE (LENEAR SEARCH ON EACH ELEMENT )                                             {T.C = O(N^2), S.C = O(1)}
//BETTER APPROACH (SORT FIRST THEN SEARCH)                                                 {T.C = O(N*LOGN) , S.C = O(1)}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    int longest = 1;
    int count = 0;
    int lastSmaller = INT_MIN;
    
    for(int i = 0 ; i < n ;i++){
        if(arr[i]-1 == lastSmaller){
            count++;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller){
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, count);
    }    
    return longest;
}
//OPTIMISED APPROACH (UNORDERED SET)                                                         {T.C = O(N), S.C = O(N)}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(n == 0){
        return 0;
    }
    int longest = 1;
    
    unordered_set<int>st;

    //put element on set
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    for (auto it : st) {
        if(st.find(it-1) == st.end()){                //IF NOT FOUND
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {       //FOUND
                x = x + 1;
                count = count + 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}
/*
Sample Input 1 :
1 
5
33 20 34 30 35
Sample Output 1 :
3
*/


//22. SECOND LARGEST ELEMENT IN THE ARRAY
//find largest
/*
int Largest(int n, vector<int> &arr)
{   
    int largest = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}
*/
//OPTIMIZED APPROACH                                                                    {T.C = O(N), S.C = O(1)}
int findSecondLargest(int n, vector<int> &arr)
{   
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }

    if(secondLargest == INT_MIN){
        return -1;
    }
    return secondLargest;
    //or
    // return ((secondLargest != INT_MIN) ? secondLargest : -1);
}
/*
Sample Input 1:
2
6
12 1 35 10 34 1
5
10 10 10 10 10
Sample Output 1:
34
-1
*/
//FINDING 3RD LARGEST ELEMENT                                                                  {T.C = O(N), S.C = O(1)}
int findThirdLargest(int n, vector<int> &arr)
{
    if (n < 3) {
        return -1; // There should be at least 3 elements in the array to find the third largest.
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int thirdLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        }
        else if (arr[i] > thirdLargest && arr[i] != secondLargest && arr[i] != largest) {
            thirdLargest = arr[i];
        }
    }

    if (thirdLargest == INT_MIN) {
        return -1; // If there is no valid third largest element
    }

    return thirdLargest;
}
//FINDING KTH LARGEST && SMALLEST ELEMENT (FOLLOW UP QUESTION)
int findKthLargest(int arr[], int n, int k) {
    sort(arr, arr + n,greater<int>());
    return arr[k - 1];
}
int findKthSmallest(int arr[], int n, int k) {
    sort(arr, arr + n);
    return arr[k - 1];
}


//23. PRINT THE ARRAY AFTER K OPERATIONS                                                      {T.C = O(N), S.C = O(1)}
vector<int> printArrayAfterKOperations(vector<int> &arr, int n, int k) {
    if(k==0){
        return arr;
    }
    int times = 0;
    
    if(k%2==0){     //k = 2 , 4 , 6 the dry run is same 
        times = 2;
    }else{          //k = 1 , 3 , 5 the dry run is same
        times = 1;
    }
    for(int j=0;j<times;j++){
        int maxi = arr[0];
        //find max
        for(int i=1;i<n;i++){
            if(maxi<arr[i]){
                maxi = arr[i];
            }
        }
        //update array
        for(int i=0;i<n;i++){
           arr[i] = maxi-arr[i];
        }
    }
    return arr;
}
/*
Sample Input 1:
1
4 2
20 15 10 5
Sample Output 1:
15 10 5 0
*/


//24. MINIMUM NUMBER OF PLATFORMS                                                                    {T.C = O(N*LOGN), S.C = O(1)}
int calculateMinPatforms(int at[], int dt[], int n) {
    
    //sort the timing of arrival and departure
    sort(at, at+n);
    sort(dt, dt+n);
    
    int platforms = 1;
    int maxPlatforms = 1;

    int i = 1;                 //arrivalIndex
    int j = 0;                 //departureIndex

    while(i < n && j < n){
        if(at[i] <= dt[j]){
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        }
        else{
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}
/*
Sample Input 1:
2
6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000
4
100 200 300 400
200 300 400 500
Sample Output 1:
3
2
*/


//25. MAJORITY ELEMENT - II                                                        {T.C = O(N) , S.C = O(N)}
vector<int> majorityElementII(vector<int> &arr)
{   
    vector<int>ans;

    int n = arr.size();
    int fl = n/3;

    unordered_map<int, int>mp;
    for(int i = 0 ; i < n ; i++){
        mp[arr[i]]++;
    }

    for(auto it : mp){
        int a = it.first;
        int b = it.second;
        if(b > fl){
            ans.push_back(a);
        }
    }
    return ans;
}
/*
Sample Input 1 :
2
7
3 2 2 1 5 2 3
5
7 4 4 9 7
Sample Output 1:
2
4 7
*/


/*----------------------------------------------     THE END    -------------------------------------------------------*/