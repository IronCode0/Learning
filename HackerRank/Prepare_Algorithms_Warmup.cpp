// Diagonal Difference
int diagonalDifference(vector<vector<int>> arr) {
    int n=arr.size(),m=n; 
     int l_diagonal_sum = 0, r_diagonal_sum = 0; 
     for(int i=0;i <n;i++)
         for(int j=0;j<m;j++){
             if(i==j)         l_diagonal_sum+=arr[i][j];
             if((i+j)==(m-1)) r_diagonal_sum+=arr[i][j];
         }
     return abs(l_diagonal_sum - r_diagonal_sum);
}
// Plus Minus
void plusMinus(vector<int> arr) {
    int a=0,b=0,c=0;
    int n=arr.size();
    for (int i=0;i < n; i++) {
        if (arr[i] < 0) a++;
        else if (arr[i] == 0) b++;
        else if (arr[i] > 0) c++;
    }
    cout << (double)c/n <<endl;
    cout << (double)a/n <<endl;
    cout << (double)b/n <<endl;
}
// Staircase
void staircase(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if (j <= n-i) cout << " ";
            else cout << "#";
        } cout << endl;
    }    
}
// Mini-Max Sum
void miniMaxSum(vector<int> arr) {
    long int n=arr.size();
    long int sum=0;
    long int min=arr[0];
    long int max=arr[0];
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(arr[i]<min) min=arr[i];
        if(arr[i]>max) max=arr[i];
    }
    cout<<(sum-max)<<" "<<(sum-min);
}
// Birthday Cake Candles
int birthdayCakeCandles(vector<int> candles) {
    int max=candles[0],count=candles.size(),sum=0;
    for(int i=0; i<count;i++)
        if (candles[i] > max) max =candles[i];
    for(int i=0; i<count;i++)
        if (candles[i] == max) sum++;
    return sum;    
}
// Time Conversion
string timeConversion(string s) {
    int hr=0;
    if(s[8] == 'P') {
        hr = 10*(s[0]-'0')+(s[1]-'0');
        if (hr < 12) hr += 12;
    } else {
        hr = 10*(s[0]-'0')+(s[1]-'0');
        if(hr == 12) hr = 0;
    }
    
    s[0] = hr/10 + '0';
    s[1] = hr%10 + '0';
    
    return s.substr(0,8);
}
int main() {
    int h, m, s ;
    char tz[3];
    scanf("%d:%d:%d%s", &h, &m, &s, tz) ;
        
    if (strcmp(tz,"PM")==0 && h!=12) h += 12 ;
    if (strcmp(tz,"AM")==0 && h==12) h = 0 ;
        
    printf("%02d:%02d:%02d", h, m, s) ;
    return 0;
}














