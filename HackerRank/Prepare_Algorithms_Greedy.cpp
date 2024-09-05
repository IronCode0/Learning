
// Beautiful Pairs
int beautifulPairs(vector<int> A, vector<int> B) {
    int n = A.size();
    vector<int> a(1001, 0),b(1001, 0);
    for(int i : A) a[i]++;
    for(int i : B) b[i]++;
    int r = 0;
    for(int i = 0;i <= 1000;i++) {
        r += min(a[i], b[i]);
    }
    return (r==n) ? n-1 : r+1;
}
// Maximum Perimeter Triangle
#define triangle(i,j,k) ((j+k) > i)
vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    int n=sticks.size();
    sort(sticks.begin(),sticks.end());
    for(int i = n-1; i>1; i--)
        if(triangle(sticks[i], sticks[i-1], sticks[i-2]))
            return {sticks[i-2],sticks[i-1],sticks[i]};
    return {-1};
}
/*
	#define loop(v,s,n) for(int v=s; v<n; v++)
	#define triangle(i,j,k) ((i+j) > k)
	vector<int> maximumPerimeterTriangle(vector<int> sticks) {
		int n=sticks.size();
		sort(sticks.begin(),sticks.end());
		vector<int> ans={-1};
		int max=0,temp=0;
		int a,b,c;
		loop(i,0,n-2) loop(j,i+1,n-1) loop(k,j+1,n) {
			a=sticks[i], b=sticks[j], c=sticks[k];
			cout << a << " " << b << " " << c << endl;
			if(triangle(a,b,c)) {
				temp = a+b+c;
				if (temp > max) ans = {a,b,c};
			}
		}
		return ans;
	}
*/
// Luck Balance
int luckBalance(int k, vector<vector<int>> contests) {
    int n=contests.size();
    int luck = 0;
    vector<int> arr;
    
    for(int i = 0; i < n; i++) {
        if(contests[i][1] == 0) {
            luck += contests[i][0];
        } else {
            arr.push_back(contests[i][0]);
        }
    }
    
    sort(arr.rbegin(), arr.rend());
    
    while(k > 0 && arr.size() ) {
        luck += arr[0];
        arr.erase(arr.begin());
        k--;
    }
    int m=arr.size();
    for(int i = 0; i < m; i++) luck -= arr[i];
    return luck;
}
// Grid Challenge
string gridChallenge(vector<string> grid) {
    int n= grid.size();
    int m= grid[0].size();
    for(int i=0; i<n; i++) sort(grid[i].begin(),grid[i].end());
    for(int i=0; i<m; i++) for(int j=0; j<n-1;j++)
        if (grid[j][i] > grid[j+1][i]) return "NO";
    return "YES";
}
// Marc's Cakewalk
long marcsCakewalk(vector<int> calorie) {
    int n=calorie.size();
    sort(calorie.begin(),calorie.end());
    reverse(calorie.begin(),calorie.end());
    long temp=1,ans=0;
    for(int i=0;i<n;i++){
        ans+=(long)calorie[i]*temp;
        temp*=2;
    }
    return ans;
}


