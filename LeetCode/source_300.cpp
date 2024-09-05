class Solution { /*  104. Maximum Depth of Binary Tree	*/
public:
	 int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	 }
};
class Solution { /*  120. Triangle	*/
public:
	 int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int> arr(n,0);
		int pre=0, temp=0;
		
		for(int i = 0; i < n; i++) {
			pre = INT_MAX;
			for(int j = 0; j <= i; j++){
				temp = arr[j];
				if(i == 0) arr[j] = triangle[i][j];
				else arr[j] = min(j > 0 ? pre : INT_MAX
						  , j < i ? arr[j] : INT_MAX)
						  + triangle[i][j];
				pre = temp;
			}
		}
		return *min_element(arr.begin(), arr.end());
		}
};
class Solution { /*  121. Best Time to Buy and Sell Stock	*/
public:
	 int maxProfit(vector<int>& prices) {
		int gap = INT_MAX;
		int n =prices.size();
		int ans = 0;
		for(int curr : prices){
			if (curr < gap) gap = curr;
			else if (curr - gap > ans) ans = curr - gap;
		}
		return ans;
	 }
};
class Solution { /*  125. Valid Palindrome					*/
	 string clean(string& s){
		int n=s.size();
		string d;
		for(int i=0; i<n; i++)
			if(isalpha(s[i]) || isdigit(s[i]))
				d.push_back(tolower(s[i]));
		return d;
	 }
public:
	 bool isPalindrome(string s) {
		s = clean(s);
		int n=s.size();
		for(int i=0; i<n/2; i++)
			if ( s[i] != s[n-i-1] ) return false;
		return true;
	 }
	 
};
class Solution { /*  136. Single Number						*/
public:
	 int singleNumber(vector<int>& nums) {
		int n=nums.size();
		int res=nums[0];
		for(int i=1;i<n;i++) {
			res=res^nums[i];
		}
		return res;
	 }
};
class Solution { /*  148. Sort List							*/
public:
	 ListNode* merge(ListNode* a, ListNode* b){
		ListNode *newHead = new ListNode(0);
		ListNode *ptr = newHead;
		
		while(a && b){
			if (a->val <= b->val){
			 ptr->next = a;
			 a = a->next;
			} else {
			 ptr->next = b;
			 b = b->next;
			}
			ptr = ptr->next;
		}
	 
		if (a) ptr->next = a;
		else if (b) ptr->next = b;

		return newHead->next;
	 };
	 
	 ListNode* sortList(ListNode* head) {
		if(!head || !head->next) return head;
		
		ListNode *slow = head, *fast = head, *Prev;
		
		while(fast && fast->next) {
			Prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
  
		Prev->next = nullptr;
		
		head = sortList(head);
		slow = sortList(slow);
		
		return merge(head, slow);
	 }
/*  method 2
	ListNode* sortList(ListNode* head) {
		if(!head) return head;
		vector<int> arr;
		ListNode* ptr = head;
		
		while(ptr){
		  arr.push_back(ptr->val);
		  ptr = ptr->next;
		}
		
		sort(arr.begin(), arr.end());
		
		ptr = head;
		int i = 0;
		while(ptr){
		  ptr->val = arr[i++];
		  ptr = ptr->next;
		}
		
		return head;
	 }
*/
};
class Solution { /*  169. Majority Element					*/
public:
	 int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size()/2];
	 }
};
class Solution { /*  190. Reverse Bits						*/
public:
	 uint32_t reverseBits(uint32_t n) {
		uint32_t x = 0;
		int d = 0;
		while(n > 0){
			x += (n%2) << (31 - d);
			n >>= 1;
			d++;
		}
		return x;
	 }
};
class Solution { /*  202. Happy Number						*/
public:
    bool isHappy(int n) {
        set<int> s;
        while(s.count(n)==0) {
            if(n==1) return true;
            s.insert(n);
            int temp=0;
            while(n) {
                temp+= (n%10)*(n%10);
                n/=10;
            }
            n=temp;
        }
        return false;
    }
};
class Solution { /*  203. Remove Linked List Elements		*/
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev, *cur;
        
        while(head != NULL && head->val == val) head = head->next;
        
        cur = head;
        while(cur != NULL){
            if(cur->val == val)
                prev->next = cur->next;
            else
                prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
class Solution { /*  215. Kth Largest Element in an Array	*/
public:
	 int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());
		return nums[nums.size()-k];
	 }
};
class Solution { /*  219. Contains Duplicate II				*/
public:
	 bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n=nums.size();
		for(int i = 0; i< n-1; i++) {
			int target = min(n, i+k+1);
			if (find(nums.begin()+i+1, nums.begin()+target, nums[i])
				 != nums.begin()+target) return true;
		}
		return false;
	 }
};
class Solution { /*  222. Count Complete Tree Nodes			*/
public:
	 int countNodes(TreeNode* root) {
		if(root == nullptr) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	 }
};
class Solution { /*  230. Kth Smallest Element in a BST		*/
public:
	 int k;
	 
	 int inOrder(TreeNode* node){
		if (!node) return -1;
		int Left = inOrder(node->left);
		if (Left != -1) return Left;
		if ( --k ==  0) return node->val;
		int Right = inOrder(node->right);
		if (Right != -1) return Right;
		return -1;
	 };
	 
	 int kthSmallest(TreeNode* root, int k) {
		this->k = k;
		return inOrder(root);
	 }
};
class Solution { /*  237. Delete Node in a Linked List		*/
public:
	 void deleteNode(ListNode* node) {
		if (node->next == NULL) return
		node->val = node->next->val;
		node->next = node->next->next;
	 }
};
class Solution { /*  238. Product of Array Except Self		*/
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int r = 1;
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] * nums[i-1];
        for(int i = n-2; i >= 0; i--) {
            r *= nums[i+1];
            ans[i] *= r;
        }
        return ans;
    }
};
class Solution { /*  240. Search a 2D Matrix II				*/
public:
	 bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if(m == 0) return false;
		int n = matrix[0].size();
		if(n == 0) return false;
		int row = 0, col = n-1;
		while(col >= 0 && row < m){
			if(matrix[row][col] == target) return true;
			else if(target < matrix[row][col]) col--;
			else row++;
		}
		return false;
	 }
};
class Solution { /*  258. Add Digits						*/
public:
	 int addDigits(int num) {
		if (num == 0) return 0;
		if (num % 9 == 0) return 9;
		return num % 9;
	 }
/*
	int addDigits(int num) {
	int sum=0;
	int rem;
	if(num>=10){
		int a=num;
		while(a>0){
				rem=a%10;
				sum=sum+rem;
				a=a/10;  
			 
		  }
		}
		if(num>=10) return addDigits(sum);
		else return num;
	 }
*/
};
class Solution { /*  260. Single Number III					*/
public:
	 vector<int> singleNumber(vector<int>& nums) {
		set<int> unique, dump;
		for(int num : nums){
			if(unique.find(num)==unique.end())
				unique.insert(num);
			else dump.insert(num);
		}
		vector<int> ans(unique.size());
		auto diff = set_difference(unique.begin(), unique.end()
							 ,dump.begin(), dump.end()
							 ,ans.begin());
		ans.resize(diff-ans.begin());
		return ans;
	 }
};
class Solution { /*  263. Ugly Number						*/
public:
	 bool isUgly(int n) {
		if(n == 0) return false;
		while(n % 2 == 0) n /= 2;
		while(n % 3 == 0) n /= 3;
		while(n % 5 == 0) n /= 5;
		return (n == 1);
	 }
};
class Solution { /*  264. Ugly Number II					*/
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        vector<int> list(n);
        int p2 = 0, p3 = 0, p5 = 0, _min = -1;
        list[0] = 1;
        for(int i = 1; i < n; ++i){
			_min = min({list[p2]*2, list[p3]*3, list[p5]*5});
			if (_min == list[p2]*2) list[i] = list[p2++]*2;
			if (_min == list[p3]*3) list[i] = list[p3++]*3;
			if (_min == list[p5]*5) list[i] = list[p5++]*5;
        }
        return list[n-1];
    }
};
class Solution { /*  279. Perfect Squares					*/
public:
    int numSquares(int n) {
        vector<int> dp = {0};
        while(dp.size() <= n) {
            int i = dp.size();
            int count = INT_MAX;
            for(int j = 1; j*j <= i; j++)
                count = min(count, dp[i-j*j]+1);
            dp.push_back(count);
        }
        return dp[n];
    }
};
class Solution { /*  287. Find the Duplicate Number			*/
public:
	 int findDuplicate(vector<int>& nums) {
		int n[100001]={0};
		for(int a : nums) if (++n[a] == 2) return a;
		return 0;
	 }
};



