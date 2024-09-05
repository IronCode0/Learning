// Mars Exploration
int marsExploration(string s) {
    int count =0;
    for(int i=0, n=s.size() ; i<n ; i+=3)
        count += (s[i] != 'S') + (s[i+1] != 'O') + (s[i+2] != 'S');
    return count;
}
// Caesar 
string caesarCipher(string s, int k) {
    int n=s.size();
    for (int i =0; i<n;i++) {
        if((s[i]>='a' && s[i]<='z'))
            s[i] = ((s[i]-'a'+k) % ('z'-'a'+1)) + 'a';
        else if ((s[i]>='A' && s[i]<='Z'))
            s[i] = ((s[i]-'A'+k) % ('Z'-'A'+1)) + 'A';                 
    }
    return s;
}
// Game of Thrones - I
string gameOfThrones(string s) {
    int list[26]={0};
    for(char x : s) list[x-'a']++;
    int odd=0;
    for(int x : list) {
        if(x % 2 == 1) odd++;
        if(odd > 1) return "NO";
    }
    return "YES";
}
// Making Anagrams
int makingAnagrams(string s1, string s2) {
    int a[26]={0}, b[26]={0};
    for(char x : s1) if (x>='a' && x<='z') a[x-'a']++;
    for(char x : s2) if (x>='a' && x<='z') b[x-'a']++;
    int s=0;
    for(int i=0;i<26; i++) s+=abs(a[i]-b[i]);
    return s;
}
// Two Strings
string twoStrings(string s1, string s2) {
    map <char,bool> list; 
    int counter=0;
    for (auto x : s1) list[x]=true;
    for (auto x : s2) if (list[x]) {
        counter=true;
        break;
    }
    return (counter) ? "YES" : "NO";  
}
// Anagram
int anagram(string s) {
    int a[26]={0},b[26]={0};
    int n=s.length();
    if (n%2 != 0) return -1;
    string str_a=s.substr(0,n/2)
         , str_b=s.substr(n/2,n-1);
    for(int i=0; i<n/2; i++) {
        a[str_a[i]-'a']++;
        b[str_b[i]-'a']++;
    }
    int c=0;
    for(int i=0; i<26; i++) c+=abs(a[i]-b[i]);
    return c/2;
}
// Palindrome Index
char b[1000005];
int pCheck(string a, int n) {
    for(int i=0; i<n/2; i++) if(a[i] != a[n-1-i]) return i;
    return -1;
}
int palindromeIndex(string s) {
    int l = s.length();
    int x = pCheck(s,l);
    int result =-1;
    if(x==-1) return -1;
    else {
        int j=0;
        for(int i=0; s[i];i++)
            if(i!=x) b[j++] = s[i];
        return (pCheck(b,l-1)==-1) ? x : l-1-x;
    }
}
// The Love-Letter Mystery
int theLoveLetterMystery(string s) {
    int n=s.length();
    int to=n/2;
    int count=0;
    for(int i=0,a,b; i<to; i++) {
        a=s[i];
        b=s[n-i-1];
        while(abs(a-b) != 0) {
            if (a > b)  a--; else b--;
            count++;
        }
    }
    return count;
}
// Beautiful Binary String
int beautifulBinaryString(string b) {
    int n=b.length();
    int count=0;
    for(int i=0; i<n-2; i++) {
        if (b[i] == '0' && b[i+1] == '1' && b[i+2] == '0') {
            try { if (b[i+3] == '1') b[i+2] = '1'; }
            catch (...) { b[i+1] = '0'; }
            count++;
        }
    }
    return count;
}
// Gemstones
bool IS(string s,char a) {
    for(auto x : s) if (x == a) {return 1; break;}
    return 0;
}
int gemstones(vector<string> arr) {
    int n=arr.size();  // a=97, z=122
    int ans=0;
    for(int i=0,c=0; i < 26; i++) {
        c=0;
        for(auto x : arr)c +=IS(x,(char)i+97);
        if (c == n) ans++;
    }
    return ans;
}
// Alternating Characters
int alternatingCharacters(string s) {
    int count=0, j = 1, prev = s[0]; 
    while(s[j]!=0) {
        if(s[j] == prev) count++ ;
        else prev = s[j] ;
        j++ ;
    }
    return count;
}
// Funny String
string funnyString(string s) {
    int n=s.length();
    for(int i=0; i<n-1; i++)
        if (abs(s[i]-s[i+1]) != abs(s[n-i-1]-s[n-i-2]))
            return "Not Funny";
    return "Funny";
}
// Separate the Numbers
void separateNumbers(string s) {
    bool possible=false;
    long long int ans=0;
    if(s[0]=='0'){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<=(s.size()/2);i++){
        ans*=10;
        ans+=(s[i-1]-'0');
        long long int next=ans+1;
        string ns=s.substr(0,i);
        while(ns.size() < s.size()) ns+=to_string(next++);
        if(ns==s){ possible=true; break; }
    }
    if(possible&&s.size()>1) cout<<"YES "<<ans<<endl;
    else cout<<"NO"<<endl;
}
// Weighted Uniform Strings
bool reach[10000010];
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    int n=s.size();
    int m=queries.size();
    int val = 0;
    for (int i=0; i<n; i++) {
        if (i > 0 && s[i] != s[i-1]) val = 0;
        val += (s[i]-'a'+1);
        reach[val] = true;
    }
    vector<string> result(m);
    for(int j=0; j<m; j++)
        result[j] = (reach[queries[j]] ? "Yes" : "No");
    return result; 
}
// Two Characters
bool sCheck(string s) {
    int n =s.size();
    if (n < 2) return false;
    char a = s[0];
    char b = s[1];
    if (a == b) return false;
    for (int i=2; i<n; i++) {
        if (i & 1) {
            /* here '&' means binary ANDconvert i to
            8-bit binary then check if it end with 1 */
            if (s[i] != b) return false;
        } else if (s[i] != a) return false;
    }
    return true;
}
int alternate(string s) {
    int ans = 0;
    int n =s.size();
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            if (a == b) continue;
            string t;
            for (int i=0; i<n; i++) {
                if (s[i] == a || s[i] == b) t += s[i];
            }
            if (sCheck(t)) ans = max(ans, (int) t.size());
        }
    }
    return ans;
}
// Strong Password
int minimumNumber(int n, string password) {
    bool c[4] = {false,false,false,false};
    for(auto x : password) {
        if (x >= '0' && x <= '9') c[0] = true;
        if (x >= 'a' && x <= 'z') c[1] = true;
        if (x >= 'A' && x <= 'Z') c[2] = true;
    }
    string special_characters = "!@#$%^&*()-+";
    for(auto y : special_characters) {
        size_t found = password.find(y);
        if (found != string::npos) {
            c[3]= true; break; }
    }
    int z=4-(c[0]+c[1]+c[2]+c[3]);
    return (n<6 && z <= 6-n) ? 6-n : z;
}
// Super Reduced String
bool twinCheck(string s) {
    int n=s.length();
    for(int i=0; i<n-1; i++)
        if (s[i] == s[i+1]) return true;
    return false;
}
string superReducedString(string s) {
    int n=s.length();
    while(twinCheck(s)) {
        for(int i=0; i<n-1; i++)
            if (s[i] == s[i+1])
                s.erase(s.begin()+i, s.begin()+i+2);
    }
    return (s.length() == 0) ? "Empty String" : s;
}
// CamelCase
int camelcase(string s) {
    int a=1;
    for (auto x : s) if ( x >= 'A' && x <='Z') a++;
    return a;
}
// Pangrams
string pangrams(string s) {
    set<char> list;
    for(auto x : s) if (x != ' ') list.insert(tolower(x));
    return (list.size() == 26) ? "pangram" : "not pangram ";
}
// Super Reduced String
string twinTrim(string s,int a,int b) {
    int n = s.length()-1;
    string r;
    if(a > 0) r=s.substr(0,a-1) + s.substr(b,n);
    else r = s.substr(b,n);
    return r;
}
string superReducedString(string s) {
    int pos=0;
    int n = s.length();
    bool flag = true;
    do {
        flag = false;
        pos =0;
        while(true) {
            if(s[pos] == s[pos+1]) {
                if (pos==0) {
                    s=s.substr(2,n-1);
                } else if (pos == n-2) {
                    s=s.substr(0,n-2);
                } else {
                    s=s.substr(0,pos)+s.substr(pos+2,n-1);
                }
                flag = true;
                pos+=2;
            } else pos++;
            if(pos >= n-1) break;
        }
    } while (flag);
    if (s.length() == 0) return "Empty String";
    else return s;
}
// HackerRank in a String!
string hackerrankInString(string s) {
    string word ="hackerrank";
    int pos=0;
    for(auto x : s) if (x == word[pos]) pos++;
    return (pos == word.length()) ? "YES" : "NO";
}
// Determining DNA Health
#include <bits/stdc++.h>
using namespace std;

struct trie {
    vector<int> term;
    struct trie* next[26];
    struct trie* fail;
    trie() {
        fail = NULL;
        for (int i=0; i<26; i++) next[i] = NULL;
    }
};
trie *root;
void insert(char str[], int index) {
    trie* p = root;
    int len = strlen(str);
    for (int i=0; i<len; i++) {
        int idx = str[i]-'a';
        if (p->next[idx]==NULL)
        p->next[idx] = new trie();
        p = p->next[idx];
    }
    p->term.push_back(index);
}
void buildfail() {
    queue<trie*> q;
    q.push(root);
    while(!q.empty()) {
        trie* cur = q.front();
        q.pop();
        for (int i=0; i<26; i++) if (cur->next[i] != NULL) {
            if (cur == root) cur->next[i]->fail = root;
            else {
                trie* p = cur->fail;
                while (p!=NULL && p->next[i] == NULL) p = p->fail;
                if (p==NULL) cur->next[i]->fail = root;
                else cur->next[i]->fail = p->next[i];
            }
            q.push(cur->next[i]);
        }
    }
}
vector<pair<vector<int>,int>> query(char str[]) {
    vector<pair<vector<int>,int>> ret;
    int len = strlen(str);
    trie* p = root;
    for (int i=0; i<len; i++) {
        int idx = str[i] - 'a';
        while (p->next[idx] == NULL && p!=root) p = p->fail;
        if (p->next[idx] == NULL) continue;
        p = p->next[idx];
        trie* pp = p;
        while (pp != root) {
            if (!pp->term.empty())
                ret.push_back(make_pair(pp->term, i));
            pp = pp->fail;
        }
    }
    return ret;
}
int main() {
    int n;
    int health[100000];
    char str[2000001];
    scanf("%d", &n);
    root = new trie();
    for (int i=0; i<n; i++) {
        cin >> str;
        insert(str, i);
    }
    for (int i=0; i<n; i++) cin >> health[i]; //health input;
    buildfail();
    int q;
    cin >> q;
    long long mins=9999999999999,maxs=0;
    for (int i=0; i<q; i++) {
        int a,b;
        cin >> a >> b >> str;
        vector<pair<vector<int>,int> > ret = query(str);
        long long sum = 0;
        for (int i=0; i<ret.size(); i++)
            for (int j=0; j<ret[i].first.size(); j++)
                if (ret[i].first[j] >= a && ret[i].first[j] <= b)
                    sum += health[ret[i].first[j]];
        if (sum > maxs) maxs = sum;
        if (sum < mins) mins = sum;
    }
    cout << mins << " " << maxs;
}
// Determining DNA Health (norm)
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
map<string, int> table;
int DNA_strength(vector<string> genes,vector<int> health,int first,int last,string d) {
    int g_size=genes.size();
    int d_size=d.size();
    //for(int i=0; i<n; i++) cout << table[genes[i]] << " ";
    //cout << endl;
    int sum=0;
    int pos=0;
    while(pos < g_size) {
        int health_temp=0;
        string word_check;
        health_temp=0;
        for(int i=1; i<=d_size-pos; i++) {
            
            word_check = d.substr(pos,i);
            for(int j=first; j<=last; j++) {
                if (genes[j] == word_check) {
                    health_temp += health[j];
                    //cout <<word_check<<" - "<<health_temp<<endl;
                }
                    
            } 
            
        }
        
        
        pos++;
        sum +=health_temp;
    }
    //cout << "-----------------" << endl;
    return sum;
}
int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split(rtrim(genes_temp_temp));

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split(rtrim(health_temp_temp));

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
        table.insert(make_pair(genes[i],health_item));
    }

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));
    vector<int> list(s);
    
    for (int s_itr = 0; s_itr < s; s_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int first = stoi(first_multiple_input[0]);

        int last = stoi(first_multiple_input[1]);

        string d = first_multiple_input[2];
        list[s_itr] = DNA_strength(genes,health,first,last,d);
        //cout << first << " " << last << " " << d << endl;
    }
    int list_max=-1,list_min=999999999;
    for(auto x : list ) {
        if (x > list_max) list_max =x;
        if (x < list_min) list_min =x;
    } //cout << x << " "; cout << endl;
    //for(auto x : health) cout << x << " "; cout << endl;
    cout << list_min << " " << list_max;
    //first_multiple_input
    return 0;
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}
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

// 

// 

// 

// 

// 

// 

// 

