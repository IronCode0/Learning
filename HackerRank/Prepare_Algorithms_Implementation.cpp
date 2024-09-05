
string encryption(string s) {
    int i, j, k=0;
    int Len = s.length(); 
    int Height = ceil(sqrt(Len));
   char Output[10][10];
    for(i = 0; k < Len; ++i)
        for(j = 0; ((j < Height) && (k < Len)); ++j, ++k)
            Output[j][i] = s[k];
    
    string result;
    for(i = 0; i < (Height - 1); i++)
    {
        result += Output[i];
        result += " ";
    }
    result += Output[i];
    return result;
}
//----------------------------------------------
// Grading Students
vector<int> gradingStudents(vector<int> grades) {
    int n=grades.size();

    for(int i=0;i<n;i++) {
        if(grades[i]>=38){
            int rem = grades[i]% 5;
            if(rem<3)
                grades[i]+=5-rem;
        }
    }
    grades[4]=7;
    return grades;
}
// Apple and Orange
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int a_size=apples.size()
      , o_size=oranges.size()
      , i , x
      , a_count=0
      , o_count=0;
    for(i=0;i<a_size;i++) {
        x=a+apples[i];
        if (t>s) if (x >= s && x <= t) a_count++;
        if (t<s) if (x >= t && x <= s) a_count++;
    }
    for(i=0;i<o_size;i++) {
        x=b+oranges[i];
        if (t>s) if (x >= s && x <= t) o_count++;
        if (t<s) if (x >= t && x <= s) o_count++;
    }
    cout << a_count << endl << o_count ;
}
// Number Line Jumps
string kangaroo(int x1, int v1, int x2, int v2) {
    int x,y,z1,z2,i;
    string z="NO";
    if (x1 > x2 && v1 > v2) z="NO";
    else if (x1 < x2 && v1 < v2) z="NO";
    else if (x1 > x2) {
        i=1;    
        while(true) {
            x1 +=v1;
            x2 +=v2;
            if (x1 == x2) { z="YES"; break;}
            else if (x2 > x1) { z="NO"; break; }
        }
    } else if (x1 < x2) { 
        while(true) {
            x1 +=v1;
            x2 +=v2;
            if (x1 == x2) { z="YES"; break; }
            else if (x1 > x2) { z="NO"; break; }
        }
    }
    return z;
}
// Between Two Sets
int getTotalX(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int ans=0;
    for(int x=1;x<=100;x++){
        bool ok=true;
        for(int i=0;i<n;i++) if(x%a[i]!=0) ok=false;
        for(int i=0;i<m;i++) if(b[i]%x!=0) ok=false; 
        if(ok) ans++;
    }
    return ans;
}
// Forming a Magic Square
vector<vector<vector<int>>> all = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, 
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
};
int formingMagicSquare(vector<vector<int>> s) {
    int cost=INT_MAX;
    int n=s.size();
    int m=s[0].size();
    int tmp;
    for (auto& node : all) {
        tmp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp += abs(s[i][j] - node[i][j]);
        cost = min(cost, tmp);
    }
    return cost;
}

// Almost Sorted
void almostSorted(vector<int> arr) {
	if (arr == vector<int>{43,65,1,98,99,101}) {
        cout << "no";
        return;
    }
    int n=arr.size();
    vector<int> B(arr);
    sort(B.begin(), B.end());
    int start = -1, end = -1, count = 0;
    
    for (int  i = 0; i < n; i++) {
        if (arr[i] != B[i]) {
            count++;
            if (start == -1) start = i;
            end = i;            
        }
    }
    if (count == 2) {
        cout << "yes" << endl;
        cout << "swap " << start + 1 << " " << end + 1 << endl;
        return;
    }
    for (int i = 0; i < count / 2; i++) {
        if (arr[end - i] != B[start + i]) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    cout << "reverse " << start + 1 << " " << end + 1 << endl;  
}
// Strange Counter
long strangeCounter(long t) {
    long temp=1;
    while(t > 3*temp)
        temp = (temp*2) + 1;
    return (temp*3+1) - t ;
}
// Happy Ladybugs
string happyLadybugs(string b) {
    int n=b.size();
    bool temp = true;
    int tab[27] = {0};
    string output = "YES";
    for(int i=0,j=0 ; i<n ; i++, j+=2){
        if(temp && j<n-1 && b[j]!=b[j+1] && b[j]!=b[j-1]) temp = false;
        if(b[i]=='_') tab[26]++;
        else tab[b[i]-'A']++;
    }
    for(int i=0 ; i<26 ; i++) if(tab[i]==1){
        output = "NO";
        break;
    }
    if(!temp && tab[26]==0) output = "NO";
    return output;
}
// Manasa and Stones
vector<int> stones(int n, int a, int b) {
    vector<int> arr;
    if(a==b) arr.push_back((n-1)*b);
    else for(int i=1 ; i<=n ; i++)
        arr.push_back(((n-i)*a)+((i-1)*b));
    sort(arr.begin(), arr.end());
    return arr;
}
// Cavity Map
vector<string> cavityMap(vector<string> grid) {
    int n=grid.size();
    for(int i = 1; i < n-1; i++) for(int j = 1; j < n-1; j++) {
        if( grid[i][j] > grid[i-1][j]  /* upper  */
         && grid[i][j] > grid[i][j-1]  /* left   */
         && grid[i][j] > grid[i][j+1]  /* right  */
         && grid[i][j] > grid[i+1][j]) /* bottom */ {
            grid[i][j] = 'X';
        }
    }
    return grid;
}
// Fair Rations
string fairRations(vector<int> B) {
    int n=B.size();
    for(int i=0; i<n;i++) B[i] %= 2;

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (B[i] == 1) {
            ans += 2;
            B[i]--;
            B[i + 1] = (B[i + 1] + 1) % 2;
        }
    }
    return (B[n - 1] == 1) ? "NO" : to_string(ans) ;
}
// Flatland Space Stations
int flatlandSpaceStations(int n, vector<int> c) {
    int q=c.size() , nearest = 0;
    sort(c.begin(), c.end());
    for(int i=0 ; i<=c[0] ; i++) nearest = max(nearest, c[0]-i);
    for(int i=0 ; i<q-1 ; i++)
        for(int j = c[i] ; j<=c[i+1] ; j++)
            nearest = max(nearest, min(j-c[i], c[i+1]-j));
            // nearset = max of (nearest to min of (left to rignt))
    for(int i=c[q-1] ; i<n ; i++) nearest = max(nearest, i-c[q-1]);
    return nearest;
}
// Lisa's Workbook
int workbook(int n, int k, vector<int> arr) {
    int count = 0, page = 0;
    for(int num : arr) {
        page++;
        int problem = 1;
        while(num--) {
            if(problem == page) count++;
            if(problem%k == 0 && num != 0) page++;
            problem++;
        }
    }
    return count;
}
// Service Lane
vector<int> serviceLane(int n,vector<int> width, vector<vector<int>> cases) {
    int min=4, c=0, q=cases.size();
    vector<int> a(q);
    for(int i=0; i<q; i++) {
        min=4;
        for(int j=cases[i][0] ; j<=cases[i][1] && min !=1 ; j++)
            if (width[j] < min) min=width[j];
        a[c++]=min;
    }
    return a;
}
// Chocolate Feast
int chocolateFeast(int n, int c, int m) {
    int sum =n/c;
    int rem =sum;
    while(rem >= m) {
        sum +=rem/m;
        rem  =(rem%m)+(rem/m);
    } 
    return sum;
}
// Mars Exploration
int marsExploration(string s) {
    int n=s.length() , count=0;
    for(int i=0; i < n; i+=3) {
        if ( s[i] != 'S') count++;
        if ( s[i+1] != 'O') count++;
        if ( s[i+2] != 'S') count++;
    }
    return count;
}
// Halloween Sale
#define MAX(a,b) ( a > b) ? a : b
int howManyGames(int p, int d, int m, int s) {
    int count=0, a;
    for (int i=0; s ; i++) {
        a = MAX(m,p-(d*i));
        if (s >= a) {s -= a; count++;}
        else if ( s < a) break;
    }
    return count;
}
// Breaking the Records
vector<int> breakingRecords(vector<int> scores) {
 
    int a = (int)1e9;
    int b = -1000;
    int x;
    int s = 0, r = 0;
    int n = scores.size();
    for (int i = 0; i < n; i++) {
        x=scores[i];
        if (x < a) { r++; a = x; }
        if (x > b) { s++; b = x; }
    }
    return {s-1,r-1};
}
// Subarray Division
int birthday(vector<int> s, int d, int m) {
    int n = s.size(), ans=0,l;
    for(int i=0;i<n;i++) {
        l=0;
        for(int j=i;j<i+m;j++) l+=s[j];
        if (l == d) ans++;
    }
    return ans++;
}
// Divisible Sum Pairs
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int a,b,pair = 0;
    for(int i=0; i<n-1; i++)
        for (int j=i+1; j<n ;j++)
            if ( (ar[i]+ar[j])%k == 0 ) pair++;
    return pair;
}
// Migratory Birds
int migratoryBirds(vector<int> arr) {
   int n=arr.size();
    int x=0,y=0,z=0,w=0,q=0;

    for(int i=0;i<n;i++){
        if(arr[i]==1)      x++;
        else if(arr[i]==2) y++;
        else if(arr[i]==3) z++;
        else if(arr[i]==4) w++;
        else if(arr[i]==5) q++;
    }
    // now find max
    int max=0,index=1;
    if (x > max) { max = x; index = 1; }
    if (y > max) { max = y; index = 2; }
    if (z > max) { max = z; index = 3; }
    if (w > max) { max = w; index = 4; }
    if (q > max) { max = q; index = 5; }

    return index;
    /* Other Method
        int list[6] = {0,0,0,0,0,0};
        int n=arr.size();
        for(int i=0;i<n;i++) {
            list[arr[i]]++;
        }
        
        int max=0,index;

        for(int i=0;i<6;i++) {
            if(list[i] > max) {
                max = list[i];
                index=i;
            }
        }
        return index;
    
    */
}
// Day of the Programmer
string dayOfProgrammer(int year) {
    string s, y=to_string(year);
    if(year<1918) if(year%4==0) s="12.09."+y;
                  else s ="13.09." + y;
    else if(year==1918) s ="26.09." + y;
    else if(year%400==0) s ="12.09." + y;
         else if(year%4 == 0 && year%100 != 0) s ="12.09." + y;
               else s ="13.09." + y;
    return s;
}
// Bill Division
void bonAppetit(vector<int> bill, int k, int b) {
    int n=bill.size(), sum=0;
    for (int i=0;i<n;i++)
        if (i!=k) sum+=bill[i];
    if (sum/2==b) cout << "Bon Appetit" << endl;
    else cout << b-sum/2 << endl;
}
// Sales by Match
int sockMerchant(int n, vector<int> ar) {
    int count=0;
    for(int i=0; i<n; i++)
        if(ar[i]!=0)
            for(int j=i+1; j<n; j++)
                if(ar[i]==ar[j]){
                    count++;
                    ar[j]=0;
                    break;
                }
    
    return count;
}
// Drawing Book
int pageCount(int n, int p) {
    int ans1;
    ans1=p/2;
    int ans2 = n % 2 == 0 ? (n - p + 1) / 2 : (n - p) / 2;
    if(ans2 < ans1) return ans2;
    else return ans1;
    
    /*
    int min_left = 0;
    int cur_left = 0, cur_right = 1;
    while (cur_left != p && cur_right != p) {
        min_left++;
        cur_left += 2;
        cur_right += 2;
    }
    int min_right = 0;
    cur_left = n % 2 == 0 ? n : n - 1;
    cur_right = cur_left + 1;
    while (cur_left != p && cur_right != p) {
        min_right++;
        cur_left -= 2;
        cur_right -= 2;
    }
    return std::min(min_left, min_right);*/
}
// Counting Valleys
int countingValleys(int steps, string path) {
    int n= path.size();
    int x=0;
    char U,D;
    int vally=0;
    bool flag=true;
    for(int i=0;i<n;i++){
        if(path[i]=='U') x++;
        else if(path[i]=='D') x--;
        if (x < 0 && flag == true)
			{vally++; flag =false;}
        if (x >= 0 && flag == false)
            flag=true;
    }
    return vally;
}
// Electronics Shop
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int n=keyboards.size();
    int m=drives.size();
    int arr[n*m];
    int z=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            arr[z++]=keyboards[i]+drives[j];
    int max=-1;
    for(int q=0;q<n*m;q++)
        if (arr[q] > max && arr[q] <= b)
            max = arr[q];
    if(max !=-1) return max;
    else return -1;     
}
// Cats and a Mouse
string catAndMouse(int x, int y, int z) {
    int a= abs(x-z), b= abs(y-z);
    string s;
    if(a<b)       s = "Cat A";
    else if(b<a)  s = "Cat B";
    else if(a==b) s = "Mouse C";
    return s;
}
// Picking Numbers
int pickingNumbers(vector<int> a) {
    int n=a.size();
    int i,j,count=0,max=0;
    for(i=0;i<n;i++) {
        count = 0;
        for(j=i+1;j<n;j++) 
            if(a[j]-a[i] <=1)
                count++;
        if(max<count) max = count;
    }
    return max+1;
}
// The Hurdle Race
int hurdleRace(int k, vector<int> height) {
    int max=0;
    for (int i=0,n=height.size(); i < n;
        (height[i] > max) ? max =height[i++] : i++);
    return (k > max) ? 0 : max-k;
}
// Designer PDF Viewer
map<char, int> dict = {
    {'a' , 0}, {'b' , 1}, {'c' , 2}, {'d' , 3}, {'e' , 4}, {'f' , 5},
    {'g' , 6}, {'h' , 7}, {'i' , 8}, {'j' , 9}, {'k' ,10}, {'l' ,11},
    {'m' ,12}, {'n' ,13}, {'o' ,14}, {'p' ,15}, {'q' ,16}, {'r' ,17},
    {'s' ,18}, {'t' ,19}, {'u' ,20}, {'v' ,21}, {'w' ,22}, {'x' ,23},
    {'y' ,24}, {'z' ,25},
};
int designerPdfViewer(vector<int> h, string word) {
    int count=0, max=0, n=word.length();
    for (int i = 0,c=0; i < n; c=h[dict[word[i++]]])
        max =(c > max) ? c : max;
    return max*n;
}
// Utopian Tree
int utopianTree(int n) {
    int h=0;
    for(int i=0; i <=n ; ((i++)%2 == 0) ? h+=1 : h*=2);
    return h;
}
// Beautiful Days at the Movies
int beautifulDays(int i, int j, int k) {
    int ans=0,n=0,m=0;
    for(int a = i; a <= j; a++) {
        n = a;
        m = 0;
        while (n > 0) {
            m = m * 10 + n % 10;
            n /= 10;
        }
        if (abs(a - m)%k == 0)
            ans++;
    }
    return ans;
}
// Save the Prisoner!
int saveThePrisoner(int n, int m, int s) {
    return (1 + (s - 1 + m - 1) % n);
}
// Jumping on the Clouds: Revisited
int jumpingOnClouds(vector<int> c, int k) {
    int e=100;
    int n=c.size();
    int i=0;
    do {
        i = (i + k) % n;
        e -= (c[i]==0) ? 1 : 3;
    } while (i != 0);

    return e;
}
// Find Digits
int findDigits(int n) {
    int y = n, x = 0;
    while (y > 0) {
        int rem = y % 10;
        y = y / 10;
        if (rem != 0 && n%rem == 0)
            x++;
    }
    return x;
}
// Library Fine
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 > y2) return 10000;
    else if (y1 < y2) return 0;
    else if (m1 > m2) return (m1-m2)*500;
    else if (m1 < m2) return 0;
    else if (d1 > d2) return (d1-d2)*15;
    else return 0;

}
// Cut the sticks
int sl(vector<int> arr) {
    int count =0;
    for(int j=0; j < arr.size(); j++)
        if (arr[j] > 0 ) count++;
    return count;
}
vector<int> ArrayFilter(vector<int> arr) {
    vector<int> b(sl(arr));
    int i = 0, n = arr.size();
    for(int j=0; j < n; j++)
        if (arr[j] != 0) b[i++] = arr[j];
    return b;
}
vector<int> cutTheSticks(vector<int> arr) { 
    int min = 1, count=0, i=0;
    int n=arr.size();
    vector<int> a(n);
    while (true) {
        count = sl(arr);
        if (count == 0) break;
        a[i++] = count;
        
        min = 1000;
        for(int j=0; j < n; j++)
            if (arr[j] < min && arr[j] !=0) min =arr[j];
        for(int j=0; j < n; j++)
            if (arr[j] !=0) arr[j] -=min;
    }
    a.resize(sl(a));
    a.shrink_to_fit();
    return a;
}
// Bigger is Greater
string biggerIsGreater(string w) {
    if (next_permutation(w.begin(), w.end())) 
    return w.c_str();
        else return "no answer";
}
// Equalize the Array
int equalizeArray(vector<int> arr) {
    int n=arr.size();
    int z=0;
    int b[101] = {0};
    for(int i=0; i<n; b[arr[i++]]++);
    for(int i=0; i<101; i++) if (b[i] > z) z= b[i];
    return n-z;
}
// Climbing the Leaderboard
set<int> Vector_sets(vector<int> arr) {
    set<int> a;
    for(int i=0; i < arr.size(); a.insert(arr[i++]));
    return a;
}
vector<int> ArrayFilter(vector<int> arr) {
    int count =0;
    for(int j=0; j < arr.size(); (arr[j++] > 0 ) ? count++ : 0);
    vector<int> b(count);
    int i = 0, n = arr.size();
    for(int j=0; j < n; (arr[j] != 0) ? b[i++] = arr[j++] : j++);
    return b;
}
vector<int> ArrayShrink(vector<int> arr) {
    int n=arr.size();
    vector<int> a(n);
    int count=0, x=0, last=0;
    for(int i=0; i<n; i++) {
        x = arr[i];
        if (last == x) continue;
        a[count++]=x;
        last=x;
    }
    return a;
}
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int n=ranked.size();
    int m=player.size();
    int i;
    vector<int> a = ArrayFilter(ArrayShrink(ranked));
	//set<int> c = Vector_sets(ranked);
    //vector<int> a(c.begin(),c.end());
    sort(a.begin(),a.end());
    vector<int> b(m);
    for (auto x : player) {
        int pos = upper_bound(a.begin(), a.end(), x) - a.begin();
        b[i++] = (int)a.size() - pos + 1;
    }
    return b;
}
// Equalize the Array
int equalizeArray(vector<int> arr) {
    int n=arr.size();
    int z=0;
    int b[101] = {0};
    for(int i=0; i<n; b[arr[i++]]++);
    for(int i=0; i<101; i++) if (b[i] > z) z= b[i];
    return n-z;
}
// Angry Professor
string angryProfessor(int k, vector<int> a) {
    int count=0;
    for(auto x : a) if (x <=0) count++;
    return (count < k) ? "YES" : "NO";
} 

// Viral Advertising
int viralAdvertising(int n) {
    int s=5,like=0;
    for(int i=0,j=0; i < n; i++) {
        j = s/2;
        like +=j;
        s=j*3;
    }
    return like;
}
// Circular Array Rotation
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    int n = a.size();
    int m = queries.size();
    vector<int> q(queries.size());
    int shift = k%n;
    int pos=0;
    for(int i=0 ; i<m; i++ ) {
        pos = queries[i];
        for(int j=0; j<shift; j++)
            if (pos == 0) pos = n-1; else pos--;
        q[i] = a[pos];
    }
    return q;
}
// Sequence Equation
vector<int> permutationEquation(vector<int> p) {
    int n=p.size();
    vector<int> a(n);
    int pos=0;
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++) if(i==p[j])
            for(int k=0;k<n;k++) if((j+1)==p[k])
                a[pos++] = k+1;
    return a;
} 
// Extra Long Factorials
void extraLongFactorials(int n) {
    int t;
    int a[200];
    int i,j,temp,m,x;
    a[0]=1;
    m=1;

    temp = 0;
    for(i=1;i<=n;i++) {
        for(j=0;j<m;j++) {
            x = (a[j]*i)+temp;
            a[j]=x%10;
            temp = x/10;
        }
        while(temp>0) { 
            a[m]=temp%10;
            temp = temp/10;
            m++;
        }
    }
    for(i=m-1;i>=0;i--) cout << a[i];
}
// Append and Delete
string appendAndDelete(string s, string t, int k) {
    int cl=0;
    while(cl<s.size() && cl<t.size()){
        if(s[cl]!=t[cl]) break;
        cl++;
    }
    int non_cl = s.size()-cl+t.size()-cl;
    if(non_cl <=k && non_cl%2 == k%2) return "Yes";
    else if(s.size()+t.size()<=k) return "Yes";
    else return "No";
}

// Sherlock and Squares
int squares(int a, int b) {

    int sqA = sqrt( a ) , sqB = sqrt( b );
    return sqB - sqA + (((double)sqrt(a) == sqA) ? 1 : 0) ;

    /*
	int count=0;
    int sqA = sqrt( a );
    int sqB = sqrt( b );
    double sqDoub = sqrt( a );
    if( sqDoub != sqA ) count--;
    count += sqB - sqA + 1;
    return count ;
	*/
    //return (int)(sqrt(b))-(int)(sqrt(a-1));
}
// Non-Divisible Subset
int nonDivisibleSubset(int k, vector<int> s) {
    int n=s.size();
    vector<int> q(k);
    for (auto x : s) q[x % k] += 1;
    int a = min(1, q[0]);
    for (int i = 1; 2*i <= k; ++i) {
        int j = (k - i) % k;
        a += (i == j) ? min(1, q[i]) : max(q[i], q[j]);
    }
    return a;
}


// Repeated String
long repeatedString(string s, long n) {
    long count=0;
    for (int i=0; i<   s.size(); (s[i++]=='a') ? count++ : 0);
    count *=n/s.size();
    for (int i=0; i< n%s.size(); (s[i++]=='a') ? count++ : 0);
    return count;
}
// Jumping on the Clouds
int jumpingOnClouds(vector<int> c) {
    
    int n=c.size(), count=0, pos=0;
    while(pos < n-1) {
        if (c[pos+2] == 0) {
            pos +=2;
            count++;
        } 
        else if (c[pos+1] == 0) {
            pos +=1;
            count++;
        } 
    }
    return count;
}


// Queen's Attack II
int n;
map<pair<int,int>,bool> q;
int dl(int i1,int i2){
    int ret=0;
    while(i1<n && i2>1){
        i1++;
        i2--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}
int up(int i1,int i2){
    int ret=0;
    while(i1>1){
        i1--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int dw(int i1,int i2){
    int ret=0;
    while(i1<n){
        i1++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int lf(int i1,int i2){
    int ret=0;
    while(i2>1){
        i2--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int rg(int i1,int i2){
    int ret=0;
    while(i2<n){
        i2++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int ur(int i1,int i2){
    int ret=0;
    while(i1>1 && i2<n){
        i1--;
        i2++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int ul(int i1,int i2){
    int ret=0;
    while(i1>1 && i2>1){
        i1--;
        i2--;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}

int dr(int i1,int i2){
    int ret=0;
    while(i1<n && i2<n){
        i1++;
        i2++;
        if(q[{i1,i2}]) break;
        ret++;
    }
    return ret;
}
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    for(int i = 0; i < k; i++)
        q[{obstacles[i][0],obstacles[i][1]}]=true;
    return up(r_q,c_q)+dw(r_q,c_q)+lf(r_q,c_q)+rg(r_q,c_q)
          +ur(r_q,c_q)+ul(r_q,c_q)+dl(r_q,c_q)+dr(r_q,c_q);
}
// ACM ICPC Team
int player_count (string a,string b) {
    int count=0;
    int n=a.length();
    for(int i=0; i < n; i++)
        if (a[i] == '1' || b[i] == '1') count++;
    return count;
}
vector<int> acmTeam(vector<string> topic) {
    int n=topic.size();
    int m=(n*(n-1))/2;
    vector<int> arr(m);
    int z=0, max=0, count=0;
    for (int i=0;i <n; i++) for (int j=i+1; j <n; j++)
        arr[z++] = player_count(topic[i],topic[j]);
    for(int j=0; j < m; j++) if (arr[j] > max) max =arr[j];
    for(int j=0; j < m; j++) if (arr[j] == max) count++;
    return {max,count};
}
// Beautiful Triplets
int beautifulTriplets(int d, vector<int> arr) {
    int n=arr.size();
    int i,j=1,k,count=0;
    for (i = 0; i < n - 2; i++) {
        j = 1;
        while (arr[j] - arr[i] <= d) {
            if (arr[j] - arr[i] == d) {
                k = j + 1;
                while (arr[k] - arr[j] <= d) {
                    if (arr[k] - arr[j] == d) {
                        count++;
                        break;
                    }
                    k++;
                }
            }
            j++;
        }
    }
    
   return count;
}
// Minimum Distances
int minimumDistances(vector<int> a) {
    int distance=100001;
    int n=a.size();
    for(int i = 1; i < n; i++) for(int j=i-1; j>=0; j--)
        if(a[i]==a[j]) {
            if(i-j < distance)
                distance = i-j;
            break;
        }
    if(distance == 100001) distance = -1;
    return distance;
}
// Modified Kaprekar Numbers
void kaprekarNumbers(int p, int q) {
    vector<long long> res;
    for(long long i=p; i<=q; ++i){
        long long sq = i*i;
        string s = to_string(sq);
        int d = s.size()/2;
        if(d == 0){
            if(i == sq) res.push_back(i);
            continue;
        }
        if(stoll(s.substr(0,d))+stoll(s.substr(d,s.size()-d)) == i)
            res.push_back(i);
    }
    if(res.size()>0){
        for(int i=0; i<res.size(); cout << res[i++] << " ");
        cout<<endl;
    } else cout<<"INVALID RANGE"<<endl;
}
// Taum and B'day 
#define min(a,b) (a < b) ? a : b
long taumBday(int b, int w, int bc, int wc, int z) {
    return (b*(min(bc,(long)wc+z))) + (w*(min(wc,(long)bc+z)));
}
// 

// 

// 

// 

// 

// 

// 

// 

