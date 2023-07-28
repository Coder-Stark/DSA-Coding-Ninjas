//STRINGS

#include<bits/stdc++.h>
using namespace std;

/*
//number to char
str s = tostring(num);

//string to number
int x = 0;
for (int i = 0; i < str.size(); i++) {
    x = x * 10 + (str[i] - '0');
}
*/

//26. CONVERT TO STRING                                                    {T.C = O(N), S.C = O(1)}
string convertString(string str) 
{
	str[0] = toupper(str[0]);

	for(int i = 1 ; i < str.length() ; i++){
		
		if(str[i] == ' '){
			str[i+1] = toupper(str[i+1]);
		}
	}
	return str;
}
/*
Sample Input 1 :
3
I love programming
they are playing cricket
good to see you
Sample Output 1 :
I Love Programming
They Are Playing Cricket
Good To See You
*/


//27.  ENCODE THE MESSAGE                                                     {T.C = O(N), S.C = O(N)}
string encode(string &msg)
{
    string ans = "";
    int k = 1;
    for(int i = 0 ; i < msg.length(); i++){
        if(msg[i] == msg[i+1]){
            k++;
        }
        else{
            ans += msg[i];
            ans += to_string(k);
            k = 1;
        }
    }
    return ans;
}
/*
Sample Input 1 :
3
aabbc
abcd
abbdcaas
Sample Output 1 :
a2b2c1
a1b1c1d1
a1b2d1c1a2s1
*/

 
//28. REMOVE VOWELS                                                           {T.C = O(N) , S.C = O(N)}
string removeVowels(string inputString) {
    int n = inputString.size();
    string ans = "";
    for(int i = 0 ; i < n ; i++){
        if(inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u' || 
        inputString[i] == 'A' || inputString[i] == 'E' || inputString[i] == 'I' || inputString[i] == 'O' || inputString[i] == 'U'){
            continue;
        }
        else{
            ans += inputString[i];
        }
    }
    return ans;
}
/*
Sample Input 1:
2
Mobile
CodingNinjas
Sample Output 1:
Mbl
CdngNnjs
*/


//29. MINIMUM PARENTHISIS                                                                {T.C = O(N), S.C = O(N)}
int minimumParentheses(string pattern) {
    stack<char>s;
    
    for(int i = 0 ; i < pattern.size() ; i++){
        if(s.empty()){
            s.push(pattern[i]);
        }
        else if(s.top() == '(' && pattern[i] == ')'){
            s.pop();
        } 
        else { // pattern[i] == '('
          s.push(pattern[i]);
        }
    }
    return s.size();
}
/*
Sample Input 1:
2
)((()
((
Sample Output 1:
3
2
*/


//30. LEFT AND RIGHT ROTATION OF A STRING
//MY APPROACH                                                                  {T.C = O(N), S.C = O(1)}
string leftRotate(string str, int d) {
    //rotation value d is greater than or equal to the length of the string n
    d %= str.length();
    //revere 0->d characters
    reverse(str.begin(), str.begin()+d);
    //reverse d -> end
    reverse(str.begin()+d , str.end());
    //reverse o->end
    reverse(str.begin(), str.end());

    return str;
}

string rightRotate(string str, int d) {
    //rotation value d is greater than or equal to the length of the string n
    d %= str.length();
    //reverse 0->end
    reverse(str.begin() , str.end());
    //reverse 0->d
    reverse(str.begin(), str.begin()+d);
    //reverse d->end
    reverse(str.begin()+d, str.end());

    return str;
}
//ANOTHER APPORACH                                                                                 {T.C = O(N), S.C = O(N)}
string leftRotate(string str, int d) {
    // Write your code here.    
    string s="",st="";  
    int n=str.length(); 
    int m=d%n;  
    if(n==d)    return str; 
    for(int i=0;i<m;i++){   
        s+=str[i];  
    }   
    for(int i=m;i<n;i++){   
        st+=str[i]; 
    }   
    return st+s;

}

string rightRotate(string str, int d) {
    // Write your code here.    
    int n=str.size();   
    int m=d%n;  
    string s="",st="";  
    if(n==d)    return str; 
    for(int i=n-m;i<n;i++){ 
        s+=str[i];  
    }   
    for(int j=0;j<n-m;j++){ 
        st+=str[j]; 
    }   
    return s+st;

}
/*
Sample Input 1 :
1
codingninjas
3
Sample Output 1 :
ingninjascod 
jascodingnin
*/


//31. LONGEST SUBSTRING WITH K DISTINCT CHARACTERS                                                         {T.C = O(N), S.C = O(N)}
int getLengthofLongestSubstring(string s, int k) {
    int n = s.length();

    unordered_map<char, int> mp;
    int maxCount = 0;
    int i = 0, j = 0; 

    while (j < n) {
        mp[s[j]]++; // Expand the window by adding the current character.

        if (mp.size() <= k) {
            int windowSize = j - i + 1;
            maxCount = max(maxCount, windowSize); // Update maxCount with the current window size.
        }
        else {
            while (mp.size() > k) {
                mp[s[i]]--; // Contract the window by removing the leftmost character.
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }

    return maxCount;
}
/*
Sample Input 1:
2
2
abcbc
1
abccc
Sample Output 1:
4
3
*/


//32. ANAGRAM DIFFERENCE                                                                          {T.C = O(N), S.C = O(N)}
int getMinimumAnagramDifference(string &str1, string &str2) {
    int n = str1.length();
    int count = 0;
    unordered_map<char, int>mp;
    for(int i = 0 ; i < n ; i++){
        mp[str1[i]]++;
    }

    for(int j = 0 ; j < n ; j++){
        //checks str2 characters present in mp of str1
        if(mp[str2[j]] != 0){
            mp[str2[j]]--;
        }else{
            count++;
        }
    }
    return count;
}
/*
Sample Input 1:
2
except
accept
buy
bye
Sample Output 1 :
2
1
*/


//33. MINIMUM OPERATIONS TO MAKE STRINGS EQUAL                                                                {T.C = O(N), S.C = O(N)}
//copied
#include<bits/stdc++.h>
int minimumOperations(string &a, string &b)
{
    if (a.size() != b.size())
        return -1;
    int ans=0;
    int n=a.length();
    for(int i=0;i<n/2;i++)
    {
        unordered_map<char,int>mp;
        mp[a[i]]++;
        mp[b[i]]++;
        mp[a[n-1-i]]++;
        mp[b[n-1-i]]++;
        int sz=mp.size();
        if(sz==4)
            ans+=2;
        else if(sz==3)
            ans+=1+(a[i]==a[n-1-i]);
        else if(sz==2)
            ans+=mp[a[i]]!=2;
    }
    if(n%2==1 && a[n/2]!=b[n/2])
        ans++;
    return ans;
}
/*
Sample Input 1:
2
abacaba
bacabaa
zcabd
dbacz
Sample Output 1:
4
0
*/


//34. MATCH SPECIFIC PATTERN                                                            {T.C = O(N*max(l, m)), s.c = O(K)}
vector<string> matchSpecificPattern(vector<string> words, int n, string pattern) {
    vector<string> v; // Initialize an empty vector to store the words that match the given pattern

    int l = pattern.length(); // Get the length of the pattern string

    // Iterate through each word in the words vector
    for (int i = 0; i < n; i++) {
        string str = words[i]; // Get the current word from the words vector
        int x = 1, y = 1; // Initialize variables x and y for traversing str and pattern, respectively
        bool flag = true; // Initialize a flag to indicate if the current word matches the pattern
        int m = str.size(); // Get the length of the current word

        // If the length of the current word is not equal to the length of the pattern, skip to the next word
        if (m != l) {
            continue;
        } else {
            // While x and y are less than the length of the pattern, check the mapping conditions
            while (x < l && y < l) {
                // Check if adjacent characters in the current word have different mappings in the pattern
                if ((str[x] == str[x - 1] && pattern[y] != pattern[y - 1]) ||
                    (str[x] != str[x - 1] && pattern[y] == pattern[y - 1])) {
                    flag = false; // If the condition is met, set the flag to false
                    break; // Exit the loop as the current word doesn't match the pattern
                } else if ((str[x - 1] == str[x + 1] && pattern[x - 1] != pattern[x + 1]) ||
                           (str[x - 1] != str[x + 1] && pattern[x - 1] == pattern[x + 1])) {
                    flag = false; // If the condition is met, set the flag to false
                    break; // Exit the loop as the current word doesn't match the pattern
                } else {
                    x++; // Move to the next character in the current word
                    y++; // Move to the next character in the pattern
                }
            }
        }

        // If the flag is true, it means the current word matches the pattern
        if (flag == true) {
            v.push_back(str); // Add the current word to the vector of matching words
        }
    }

    return v; // Return the vector containing the words that match the given pattern
}
/*
Sample Input 1:
2
2
cdd pcm
foo
3
abcd km qst
pqr
Sample Output 1:
cdd 
qst 
*/


//35. GIVEN A STRING FIND THE NEXT SMALLEST PALINDROME


//36. FIND UNIQUE CHARACTER IN A STRING                                              {T.C = O(N), S.C = O(N)}
char findNonRepeating(string str) {
    
    int n = str.length();
    unordered_map<char, int>mp;
    for(int i = 0 ; i < n ;i++){
        mp[str[i]]++;
    }

    char ch = '\0';
    for(int i = 0 ; i < n ;i++){
        if(mp[str[i]] == 1){
            ch = str[i];
            break;
        }
    }
    return ch ? ch :'#';       //if not unique then print '#'
}
/*
Sample Input 2:
3
cbbd
bebeeed
abcd
Sample Output 2:
c
d
a
*/


//COMPARE VERSION NUMBERS                                                                       {T.C = O(N+M) , S.C = O(1)}
int compareVersions(string a, string b) 
{
    int i = 0; // Index for string 'a'
    int j = 0; // Index for string 'b'

    while (i < a.size() || j < b.size()) {
        long x = 0; // Temporary variable to store the numeric value of segments in string 'a'
        long y = 0; // Temporary variable to store the numeric value of segments in string 'b'

        // Converting characters to numbers until a '.' or end of string 'a' is encountered
        while (i < a.size() && a[i] != '.') {
            x = x * 10 + (a[i] - '0');
            i++;
        }

        // Converting characters to numbers until a '.' or end of string 'b' is encountered
        while (j < b.size() && b[j] != '.') {
            y = y * 10 + (b[j] - '0');
            j++;
        }

        if (x > y) {
            return 1; // Version 'a' is greater than version 'b'
        } else if (x < y) {
            return -1; // Version 'b' is greater than version 'a'
        }

        // Skip the '.' character and move to the next segment
        i++;
        j++;
    }

    return 0; // Both versions are equal
}
/*
Sample Input 1:
2
1.2.4
1.2.3
10.2.2
10.2.2
Sample Output 1:
1
0
*/


//FIND KTH CHARACTER OF DECRYPTED STRING                                                                  {T.C = O(N), S.C = O(1)}
char kThCharaterOfDecryptedString(string s, long long k)
{
    string curr; // Stores the current character being processed (substring).
    long long cnt = 0; // Stores the count of character repetitions for the current character.
    int i = 0; // Iterator to traverse the input string 's'.

    // Iterate through each character 's[i]' of the string 's'.
    while (s[i]) {
        // Extract non-digit characters ('curr') until a digit is encountered.
        while (s[i] && !isdigit(s[i])) {
            curr.push_back(s[i]);
            i++;
        }

        // Extract subsequent digits ('cnt') until a non-digit character is encountered.
        while (s[i] && isdigit(s[i])) {
            cnt = cnt * 10 + (s[i] - '0');
            i++;
        }

        // Calculate the length of the current character repetition sequence ('len').
        long long len = curr.size();

        // Check if 'k' is greater than the length of the current character repetition sequence ('len*cnt').
        // If so, update 'k' to represent the position in the next sequence.
        if (k > len * cnt)
            k -= len * cnt;
        else
            // If 'k' is within the current sequence, calculate the position of the 'k'-th character
            // within 'curr' using modulo operation ('(k-1) % len') and return the character at that position.
            return curr[(k - 1) % len];

        // Clear 'curr' and reset 'cnt' to process the next character sequence.
        curr.clear();
        cnt = 0;
    }

    // If the 'k'-th character is beyond the length of the decrypted string, return '#'.
    return '#';
}
/*
Sample Input 2 :
ab12c3
20
Sample Output 2 :
b
 Explanation to Sample Input 2 :
S = "ab12c3"
Decrypted String of S = "ababababababababababababccc"
So 20th character is 'b'.
*/


//MULTIPLY STRING
//ONLY FOR SMALL INTEGER VALUES                                                                          {T.C = O(N*M), S.C = O(N)}
string multiplyStrings(string a , string b ){

    int i = 0;
    int j = 0;

    int count1 = 0;
    int count2 = 0;
    while(i < a.length()){
        count1 = count1 * 10 + (a[i]-'0');
        i++;
    }

    while(j < b.length()){
        count2 = count2 * 10 + (b[j]-'0');
        j++;
    }

    int ans = count1*count2;

    string s = "";
    s = to_string(ans);

    return s;
}

//OPTIMIZED APPROACH                                                                                  {T.C = O(N*M), S.C = O(N+M)}
#include<vector>
string multiplyStrings(string a , string b ){
    if(a == "0" || b == "0"){
        return "0";
    }
    
    //a.size() + b.size() = max(ans.size)
    vector<int>ans(a.size()+b.size());
    
    for(int i = a.size()-1  ; i >= 0 ;i--){
        for(int j = b.size()-1 ; j >= 0 ; j--){
            int product = (a[i]-'0')*(b[j]-'0');
            ans[i+j+1] += product;                          //product place to rightmost
            //handle carray
            ans[i+j] += ans[i+j+1] / 10;
            ans[i+j+1] %= 10;
        }
    }

    //skip leading 0
    int i = 0;
    while(i < ans.size() && ans[i] ==  0){
        i++;
    }
    
    //vector to string
    string res = "";
    while(i < ans.size()){
        res.push_back(ans[i++]+ '0');
    }
    
    return res;
}
/*
Sample Input 1:
2
17281 
91276
123
456
Sample Output 1:
1577340556
56088    
*/


//PROGRAM TO VALIDATE IP ADDRESS                                                                         {T.C = O(N), S.C = O(1)}
bool isValidIPv4(string ipAddress) {
    int x = 0;
    int dotCount = 0;
    for(int i = 0 ; i < ipAddress.size() ; i++){
        if(ipAddress[i] != '.' && isdigit(ipAddress[i])){
            x = x*10 + (ipAddress[i] - '0');
        }
        else if(ipAddress[i] == '.'){
            if(x > 255){
                return false;
            }
            dotCount++;
            x = 0;
        } 
        else{
            return false;
        }
    }
    if(dotCount < 3 || dotCount > 3){
        return false;
    }
    return true;
}
/*
Sample Input 1:
4
123.111.12.k
122.0.330.0
1.1.1.250
1.0.0.0.1
Sample Output 1:
False
False
True
False
*/


/*------------------------------------------------       THE END              --------------------------------------------------------------*/