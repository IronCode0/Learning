// Sherlock and Array
int sum(vector<int> arr,int from, int to) {
    int sum=0;
    for(int i=from; i<=to; i++) {
        sum +=arr[i];
    }
    return sum;
}
string balancedSums(vector<int> arr) {
    int n=arr.size();
    if (n == 1) return "YES";
    int a=0, b=sum(arr,1,n-1);
    for(int i=0;i<n;i++) {
        if (a == b) return "YES";
        a +=arr[i];
        b -=arr[i+1];
    }
    return "NO";
}
// Ice Cream Parlor
int A_find(vector<int> arr,int a,int e) {
    int n=arr.size();
    for(int i=0;i<n;i++) {
        if (arr[i]==a && i !=e) return i;
    }
    return 0;
}
vector<int> icecreamParlor(int m, vector<int> arr) {
    int n=arr.size();
    vector<int> a(2);
    
    for (int i = 0; i < n; ++i) {
        int rem = m - arr[i];
        int pos = A_find(arr, rem, i);
        if (pos) {
            a= {1+i,1+pos};
            break;
        }
    }
    return a;
    
    /*
    // m = k
    //cout << " m= " << m << endl;
    //for(int x : arr) cout << x << " "; cout << endl;
    int n=arr.size();
    vector<int> a(n);
    bool flag=true;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=n; j++){
            //cout <<arr[i] << " " << arr[j]<< endl;
            if((arr[i]+arr[j])== m){
                a = {i+1,j+1};
                //cout << arr[i] << " " << arr[j] << " " << m << endl;
                //cout << i << " " << j << " " << m << endl;
                flag=false;
            }
            if (!flag) break;
        }
        if (!flag) break;
    }
    return a;*/

}
vector<int> icecreamParlor(int m, vector<int> arr) {
    map<int, int> M;
    int n=arr.size();
    vector<int> a(2);
    for (int j = 0; j < n; ++j) {
        int diff = m - arr[j];
        if (M.count(diff)) {
            a={1+M[diff],1+j};
            //cout << 1 + M[diff] << " " << 1 + j << endl;
            break;
        }
        M[arr[j]] = j;
    }
    return a;
}
// Missing Numbers
int takeMod(int a,int b) { return (a > b) ? (a-b) : (b-a); }
int count(vector<int> a, int b) {
    int count =0;
    for(auto x : a) if ( x == b) count++; else if ( x > b) break;
    return count;
}
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    set<int> set_b(brr.begin(),brr.end());
    set<int> z;
    for(auto x : set_b)
        if (takeMod(count(arr,x),count(brr,x)) !=0) z.insert(x);
    return { z.begin(), z.end() };
}
// Hackerland Radio Transmitters
int hackerlandRadioTransmitters(vector<int> x, int k) {
    int n=x.size();
    int i=0;
    sort(x.begin(),x.end());
    int count=0;
    int loc;
    while(i<n){
        count++;
        loc=x[i]+k;
        while(i<n && x[i]<=loc) i++;
        i--;
        loc=x[i]+k;
        while(i<n && x[i]<=loc) i++;
    }
    return count;
}


