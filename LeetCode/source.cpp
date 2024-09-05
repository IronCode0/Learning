class Solution { /*  345. Reverse Vowels of a String				*/
    bool isVowel(char x){
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x== 'u' 
                || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x== 'U')?true:false;
    }
public:
    string reverseVowels(string s) {
		int l = 0, r = s.size()-1;
		while(l < r){
			while(l < s.size() && !isVowel(s[l]))  l++;
			while(r >= 0 && !isVowel(s[r])) r--;
			if(l < r) swap(s[l],s[r]);
			l++; r--;
		}
		return s;
    }
};
class Solution { /*  350. Intersection of Two Arrays II					*/
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        int ptr1 = 0, ptr2 = 0;
        int n = nums1.size(), m = nums2.size();
        
        while(ptr1 < n && ptr2 < m){
            if(nums1[ptr1] == nums2[ptr2]){
                ans.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            } else if(nums1[ptr1] < nums2[ptr2])
                ptr1++;
            else ptr2++;
        }
        
        return ans;
    }
};
class Solution { /*  371. Sum of Two Integers							*/
public:
    int getSum(int a, int b) {
        int carry=0;
         while(b!=0){
             carry = a&b;
             a = a^b;
             if (carry < 0) b=(abs(carry)<<1)*(-1);
             else b=carry<<1;
         }
     return a;
        
    }
};
class Solution { /*  387. First Unique Character in a String			*/
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> arr(26);
        for(char c : s) arr[c-'a']++;
        for(int i = 0; i < n; i++)
            if(arr[s[i]-'a'] == 1) return i;
        return -1;
    }
};
class Solution { /*  392. Is Subsequence								*/
public:
    bool isSubsequence(string s, string t) {
        int x=0,m=s.length(),n=t.length();
        for(int i=0; i<n && x<m; i++)
            if(t[i]==s[x]) x++;
        if(x!=s.length()) return false;
        else return true;
    }
};
class Solution { /*  412. Fizz Buzz										*/
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i=1; i<=n; i++) {
            if(i%15==0) ans[i-1] = "FizzBuzz";
            else if(i%3==0) ans[i-1] = "Fizz";
            else if(i%5==0) ans[i-1] = "Buzz";
            else ans[i-1] = to_string(i);
        }
        return ans;
    }
};
class Solution { /*  434. Number of Segments in a String				*/
public:
    int countSegments(string s) {
        int segment = 0;
        for(int i=0, n=s.size(); i<n; i++) if(s[i] != ' ') {
            while(s[i] != ' ' && i < n) i++;
            segment++;
        }
        return segment; 
    }
};
class Solution { /*  442. Find All Duplicates in an Array (Method 1)	*/
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n-1;i++) {
            if(nums[i]==nums[i+1])
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
class Solution { /*  442. Find All Duplicates in an Array (Method 2)	*/
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> count;
        vector<int> ans;
        for(int a : nums) {
            if (count.find(a) == count.end()) {
                count[a] = 1;
            } else {
                count[a]++;
                ans.push_back(a);
            }
        }
        return ans;
    }
};
class Solution { /*  448. Find All Numbers Disappeared in an Array		*/
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {   
        if(nums.size()==0) return vector<int>();
        int n=nums.size();
        vector<bool> exist(nums.size(), false);
        for(int a : nums) exist[a-1] = true;
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(!exist[i]) ans.push_back(i+1);
        return ans;
    }
};
class Solution { /*  506. Relative Ranks								*/
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> temp;
        int n = score.size();
        for(int i=0;i<n;i++)
            temp.push_back(make_pair(score[i], i));
        sort(temp.rbegin(), temp.rend());
        vector<string> res(n);
        res[temp[0].second] = "Gold Medal";
        if(n>=2) res[temp[1].second] = "Silver Medal";
        if(n>=3) res[temp[2].second] = "Bronze Medal";
        for(int i=3;i<n;i++) res[temp[i].second] = to_string(i+1);
        return res;
    }
};
class Solution { /*  520. Detect Capital								*/
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        if (isupper(word[0])) {
            if (n<2) return true;
            if (isupper(word[1])) {
                for (int i = 1; i < n; i++)
                    if (islower(word[i])) return false;
            } else {
                for (int i = 1; i < n; i++)
                    if (isupper(word[i])) return false;
            }
        } else {
            for (int i = 1; i < n; i++)
                if (isupper(word[i])) return false;
        }
        return true;
    }
};
class Solution { /*  530. Minimum Absolute Difference in BST			*/
    vector<int> nums;
    void inorder(TreeNode* node ) {
        if (node == NULL) return;
        inorder(node->left);
        nums.push_back(node->val);
        inorder(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int ans = INT_MAX;
        for(int i=0; i<nums.size()-1; i++)
            ans = min(ans, nums[i+1]-nums[i]);
        return ans;
    }
};
class Solution { /*  551. Student Attendance Record I					*/
public:
    bool checkRecord(string s) {
        return count(s.begin(), s.end(), 'A') <= 1
            && s.find("LLL") == string::npos;
    }
};
class Solution { /*  671. Second Minimum Node In a Binary Tree			*/
    set<int> nums;
    void inorder(TreeNode* node){
		if(node==NULL) return;
		findSecondMinimumValue(node->left);
        nums.insert(node->val);
        findSecondMinimumValue(node->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        if (nums.size() == 1) return -1;
        int min1=INT_MAX,min2=INT_MAX;
        for(int a : nums) {
            if (a < min1) {
                min2 = min1;
                min1 = a;
            } else if(a > min1 && a < min2){
                min2 = a;
            } else if (a == min1) min2=a;
        }
        return (min1 == min2) ? -1 : min2;
    }
};
class Solution { /*  668. Kth Smallest Number in Multiplication Table	*/
    int BS(int m, int n, int x){
        int count = 0;
        for(int i = 1; i <= n; i++) count += min(x / i, m);
        return count;
   }
public:
    int findKthNumber(int m, int n, int k) {
        int output = -1;
        int left = 1;
        int right = m * n ;
        while(left <= right) {
            int mid = left + (right - left)/ 2;
            int _get = BS(m, n, mid);
            if (_get >= k) {
                right = mid - 1;
                output = mid;
            } else left = mid + 1;
        }
        return output;
    }
};
class Solution { /*  728. Self Dividing Numbers							*/
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++){
			int val=i;
			while(val>0){
				int digit=val%10;
				if(digit==0 || i%digit!=0) break;
				val=val/10;
			}
			if(val==0) ans.push_back(i);
        }
        return ans;
    }
};
class Solution { /*  735. Asteroid Collision							*/
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int a : asteroids) {
            bool exploded = false;
            while (!stk.empty() && stk.top() > 0 && a < 0){
                int prev = stk.top();
                if (abs(prev) > abs(a)) {
                    exploded = true;
                    break;
                } else if(abs(prev) == abs(a)) {
                    stk.pop();
                    exploded = true;
                    break;
                } else stk.pop();
            }
            if (!exploded) stk.push(a);
        }
        asteroids.clear();
        while(!stk.empty()){
            asteroids.insert(asteroids.begin(), stk.top());
            stk.pop();
        }
        
        return asteroids;
    }
};
class Solution { /*  744. Find Smallest Letter Greater Than Target		*/
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c : letters) if ( c > target) return c;
        return letters[0];
    }
	/*
	char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int i=0;
        for(int i=0;i<n;i++){
            if(letters[i]>target){
                return letters[i];
            }
        }
        return letters[0];
    } 
	*/
};
class Solution { /*  747. Largest Number At Least Twice of Others		*/
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int max = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] > nums[max])
                max = i;

        for (int i = 0; i < n; i++)
            if (max != i && nums[max] < 2 * nums[i])
                return -1;
          return max;
    }
};
class Solution { /*  796. Rotate String									*/
public:
    bool rotateString(string s, string goal) {
        return (s.size() == goal.size())
			&& (s+s).find(goal)!=string::npos;
    }
};
class Solution { /*  852. Peak Index in a Mountain Array				*/
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i+1]) i++;
        return i;
    }
};
class Solution { /*  896. Monotonic Array								*/
public:
    bool isMonotonic(vector<int>& nums) {
        bool Inc = true, Dec = true;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i+1] < nums[i] ) Inc = false;
            if(nums[i+1] > nums[i] ) Dec = false;
            if(!Inc && !Dec) return false;
        }
        return Inc || Dec;
    }
};
class Solution { /*  938. Range Sum of BST								*/
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return (root==NULL) ? 0 : ((low <= root->val && root->val <=high) ? root->val : 0)
                + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};
class Solution { /*  961. N-Repeated Element in Size 2N Array			*/
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(int i : nums)
            if(s.find(i)==s.end()) s.insert(i);
            else return i;
        return 0;
    }
};
class Solution { /* 1103. Distribute Candies to People					*/
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int curr=0;
        while(candies>0) for(int i=0; i<num_people; i++) {
            curr++;
            if(candies>=curr) {
                ans[i]+=curr;
                candies-=curr;
            } else {
                ans[i]+=candies;
                candies=0;
            }
        }
        return ans;
    }
};
class Solution { /* 1207. Unique Number of Occurrences					*/
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n= arr.size();
        map<int, int> all_list;
        for(int a : arr){
            if(all_list.find(a) == all_list.end())
				all_list[a] = 1;
            else all_list[a]++; 
        }
        set<int> uni_list;
        for(auto it : all_list){
            if(uni_list.find(it.second) == uni_list.end())
                uni_list.insert(it.second); 
            else return false; 
        }
        return true;
    }
};
class Solution { /* 1493. Longest Subarray of 1's After Deleting One... */
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int L,R,k = 1;
        for(L = 0, R = 0; R < n ; R++){
            if(nums[R] == 0) k--;
            if(k < 0 && nums[L++] == 0) k++;
        }

        return R-L-1;
    }
};
class Solution { /* 1985. Find the Kth Largest Integer in the Array		*/
public:
    string kthLargestNumber(vector<string>& nums, int k) {
		sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
            if (a.size() != b.size())
				return a.size() < b.size();
			int n = a.size();
			for (int i = 0; i < n; ++i) {
				if (a[i] == b[i]) continue;
				return a[i] < b[i];
			}
			return false;
		});
        return nums[nums.size() - k];
    }
};
class Solution { /* 2109. Adding Spaces to a String						*/
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int m = spaces.size();
        string ans;
        for (int i = 0, j = 0; i < s.length(); ++i) {
              if (j < m && i == spaces[j]) {
                ans += " ";
                ++j;
              }
              ans += s[i];      
        }
        return ans;
    }
};
class Solution { /* 2351. First Letter to Appear Twice					*/
public:
    char repeatedCharacter(string s) {
        vector<bool> arr(26);
        for (char c : s)
            if (arr[c-'a']) return c;
            else arr[c-'a']=true;
        return 'a';       
    }
};




