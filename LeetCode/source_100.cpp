// 2. Add Two Numbers
class Solution { 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *new_node = new ListNode();
        ListNode *head = new_node;
        ListNode *new_l1 = l1, *new_l2 = l2;
        int digit = 0;
        
        while(new_l1 || new_l2 || digit > 0){
            if(new_l1) {
                digit += new_l1->val;
                new_l1 = new_l1->next;
            }
            if(new_l2) {
                digit += new_l2->val;
                new_l2 = new_l2->next;
            }
            ListNode *tmp = new ListNode(digit%10);
            head->next = tmp;
            head = head->next;
            digit/=10;
        }
        return new_node->next;
    }
};

// 3. Longest Substring Without Repeating Characters
#define max(a,b) (a > b) ? a : b
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        int n=s.length();
        set<char>uni_char;
        for(int i=0,j=0; i<n && j<n; ) {
            if (uni_char.count(s[j])) {
                uni_char.erase(s[i]);
                i++;
            } else {
                uni_char.insert(s[j]);
                j++;
                max=max(j-i,max);   
            }
        }
        return max;
    }
};
// 7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long sum=0;
        if(x<0){
            int b=x;
            while(b<0) {
                sum=sum*10+b%10;
                b=b/10; 
            }
        } else if(x>0) {
            int a=x;
            while(a>0){
                sum=sum*10+a%10;
                a=a/10;
            }
        }
        if (x<0) {
            if (sum < -2147483648) return 0;
            else return ((int)sum-1)+1;
        } else if (x>0) {
            if (sum >  2147483647) return 0;
            else return (int)sum;
        }
        return 0;
    }
};
// 10. Regular Expression Matching
class Solution {
public:
    bool isMatch(string s, string p) {
    
        if (p =="") return (s == "");
        bool first_match = ((s != "") &&
                     (p[0] == s[0] || p[0] == '.'));

        if (p.length() >= 2 && p[1] == '*'){
            return (isMatch(s, p.substr(2,p.length())) ||
                    (first_match && isMatch(s.substr(1,s.length()), p)));
        } else {
            return first_match && isMatch(s.substr(1,s.length()), p.substr(1,p.length()));
        }
    
    }
};
// 11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0,L=0,R=height.size()-1;
        while(L<R) {
            int lower=height[height[L]<height[R] ? L++ : R--];
            res=max(res,(R-L+1)*lower);
        }
        return res;
    }
};
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int n=height.size();
        bool flag=true;
        int k=0;
        int l;
        for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++){
            l=min(height[i],height[j]);   
            k=l*(j-i);
            if(k>max){
                max=k;
            }            
        }
        return max;
    }
};
*/
// 12. Integer to Roman
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> arr({ {"I",1} , {"IV",4} , {"V",5}
            ,{"IX",9}, {"X",10}, {"XL",40} , {"L",50} , {"XC",90}
            ,{"C",100}, {"CD",400}, {"D",500}, {"CM",900}, {"M",1000}});
    int n = arr.size();
    int i = n - 1;
    string ans = "";
    while(num>0){
        while(arr[i].second<=num){
            ans += arr[i].first;
            num -= arr[i].second;
        }
        i--;
    }
    return ans;
    }
}; 
// 13. Roman to Integer
class Solution {
    int getInteger(char c) {
        switch(c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return -1;
        }
    }
public:
    int romanToInt(string s) {
        int n = s.size() , result = 0 , current , next , i = 0;
        while(i < n) {
            if(i == n - 1) {
                result += getInteger(s[i]);
                return result;
            }
            current = getInteger(s[i]) , next = getInteger(s[i + 1]);
            if(current >= next)
                result += current , i++;
            else
                result += next - current , i += 2;
        }
        return result;
    }
};
// 15. 3Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> out;
        
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int L = i+1, R = n-1, sum=0;
            
            while(L < R) {
                sum = nums[i] + nums[L] + nums[R];             
                if (sum > 0) {
                    R--;
                } else if (sum < 0) {
                    L++;
                } else {
                    out.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    do {L++;} while(nums[L] == nums[L - 1] && L < R);
                }
            }
        }
        return out;
    }
};
// 17. Letter Combinations of a Phone Number
map<char, string> db({{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});
class Solution {
    void node(int pos, int &len, string str, vector<string> &ans, string &digits) {
        if (pos == len) ans.push_back(str);
        else {
            string letters = db[digits[pos]];
            for (int i = 0; i < letters.size(); i++)
                node(pos+1, len, str+letters[i], ans, digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> ans;
        if (!len) return ans;
        node(0, len, "", ans, digits);
        return ans;
    }
};
// 19. Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = head;
        ListNode* b = head;
        while(n--) a = a->next;
        if (a == NULL) return head->next;
        while(a->next) {
            b = b->next;
            a = a->next;
        }
        if (b->next && b->next->next)
             b->next = b->next->next;
        else b->next = NULL;
        return head;
    }
};
// 21. Merge Two Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode;
        ListNode *temp = head;
        
        while(list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        if(list1 != nullptr) temp->next = list1;
        else if(list2 != nullptr) temp->next = list2;
        
        return head->next;
    }
};
// 28. Implement strStr()
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == "" || needle == "") return 0;
        int n=haystack.size();
        int m=needle.size();
        for(int i=0; i<=n-m; i++) {
            if (haystack[i] == needle[0]) {
                int count=0;
                for(int j=0; j<m; j++)
                    if(needle[j]==haystack[i+j]) {
                        count++; if (count == m) return i;}
                if (count == m) return i;
            }     
        }
        return -1;
    }
};
// 29. Divide Two Integers
class Solution {
public:
    int divide(int dividend, int divisor) {
        int value = 0;
        bool sign = (dividend > 0 == divisor > 0);
        if (divisor == -2147483648) return (dividend == divisor);
        if (dividend == -2147483648) {
            if (divisor == 1)
                return -2147483648;
            else if (divisor == -1)
                return 2147483647;
            else dividend += abs(divisor); value++;
        }
        dividend = abs(dividend), divisor = abs(divisor);
        for (int i = 0; dividend >= divisor; i = 0) {
            while (dividend >> i >= divisor) i++;
            dividend -= divisor << i - 1;
            value += 1 << i - 1;
        }
        return sign ? value : -value;
        
    }
};
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = (dividend > 0) ^ (divisor > 0);
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor; 
        int value = sub_divide(dividend, divisor);
        return negative ? value : -value;
    }
    
private:
    int sub_divide(int dividend, int divisor) {
        if(dividend > divisor) return 0;
        int value = -1;
        int sum = divisor;
        while(sum >= dividend - sum) {
            value += value;
            sum += sum;
            if(sum > 0) break;
        }
        return value + sub_divide(dividend-sum, divisor);
    }   
};
*/
// 33. Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            if (nums[i] == target) return i;
        return -1;
    }
};
// 34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int L = -1, R = -1;
        for (int i = 0; i < n; i++) {
            if (target != nums[i]) continue;
            if (L == -1) L = i;
            R = i;
        }
        return {L,R};
    }
};
// 45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0, jump = 0;
        
        while(end < n-1) {
            int n_end = end;
            int j_limit = min(end, n-1);
            for(int i = start; i <= j_limit; i++)
                n_end = max(n_end, i + nums[i]);
            
            start = end+1;
            end = n_end;
            jump++;
        }
        
        return jump;
    }
};
// 48. Rotate Image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++) for(int j=0; j<i; j++)
            swap(matrix[i][j], matrix[j][i]);
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
// 50. Pow(x, n)
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
       
        if(n == INT_MIN){
            n++;
            n *= -1;
            x = 1/x;
            return myPow(x*x, n/2);
        }
        
        if(n < 0){
            if(n == INT_MIN) n++;
            n *= -1;
            x = 1/x;
        }
        
        return myPow(x*x, n/2) * (n%2 ? x : 1);
        
    }
};
// 53. Maximum Subarray
class Solution {
    int Negative(vector<int>& nums) {
        int Negative = nums[0];
        for(int n : nums){
            if(n >= 0) return 0;
            Negative = max(Negative, n);
        }
        return Negative;
    }
public:
    int maxSubArray(vector<int>& nums) {
        int negative = Negative(nums);
        if(negative < 0) return negative;
        
        int sum = 0, largest = nums[0];
        for(int n : nums){
            sum += n;
            sum = max(sum, 0);
            largest = max(largest, sum);
        }
        
        return largest;
    }
};
// 58. Length of Last Word
class Solution {
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

public:
    int lengthOfLastWord(string s) {
        vector<string> arr = split(rtrim(s));
        return arr[arr.size()-1].size();
    }
};
// 62. Unique Paths
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m+1, vector(n+1, 0));
        arr[1][1] = 1;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 && j == 1) continue;
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        return arr[m][n];
    }
};
// 66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else digits[i]=0;
        }
        vector<int>newnumber(n+1,0);
        newnumber[0]=1;
        return newnumber;
    }
};
// 79. Word Search
class Solution {
    int r,c;
    bool check_next(int i, int j, vector<vector<char>>& board, string word, unsigned int w_loc) {
        if (w_loc >= word.size()) return true;
        if (i<0 || i>=r || j<0 || j>=c || board[i][j] != word[w_loc]) return false;
        char t=board[i][j];
        board[i][j]= '#';
        if (check_next(i  , j+1, board, word, w_loc+1)) return true;
        if (check_next(i+1, j  , board, word, w_loc+1)) return true;
        if (check_next(i  , j-1, board, word, w_loc+1)) return true;
        if (check_next(i-1, j  , board, word, w_loc+1)) return true;
        board[i][j] = t;
    return false;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        r= board.size();
        c= board[0].size();
        for(int i=0; i<r; i++) for(int j=0; j<c; j++)
            if(check_next(i,j,board,word,0)) return true;
        return false;
    }
        
};
// 88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        for(int i=0; i<n; i++)
            nums1[i+m]=nums2[i];
        sort(nums1.begin(),nums1.end());
        return;
    }
};





