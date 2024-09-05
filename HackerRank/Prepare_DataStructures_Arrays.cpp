// Arrays - DS
vector<int> reverseArray(vector<int> a) {
    int n=a.size();
    vector<int> b(n);
    for(int i=0; i<n; b[n-i-1]=a[i] , i++);
    return b;
}
// 2D Array - DS
int hourglassSum(vector<vector<int>> arr) {
    int n=arr.size(), m=arr[0].size();
    int max=-100, sum=0;
    for(int i=0,z =0; i<n-2; i++) for(int j=0; j<n-2; j++) {
        sum=arr[i][j] + arr[i][j+1] + arr[i][j+2]
                           + arr[i+1][j+1]
             + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (sum > max) max = sum;
    }
    return max;
}
// Dynamic Array
vector<int> ADD(vector<int> a, int b) {
    int n=a.size();
    vector<int> out(n+1);
    for(int i=0; i <n; i++) out[i]=a[i];
    out[n]=b;
    return out;
}
vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int lastAnswer=0, m=0, z=0;
    for(auto x : queries) if (x[0]==2) m++;
    vector<vector<int>> arr(n);
    vector<int> answer(m);
    for(auto row : queries) {
        int x=row[1], y=row[2];
        int idx;
        if(row[0]==1) {
            idx=((x^lastAnswer)%n);
            arr[idx] = ADD(arr[idx],y);
        } else if (row[0]==2) {
            idx=((x^lastAnswer)%n);
            lastAnswer =arr[idx][y% arr[idx].size() ];
            answer[z++]=lastAnswer;
        }
    }
    return answer;
}
// Left Rotation
vector<int> rotateLeft(int d, vector<int> arr) {
    int n=arr.size();
    d= d%n;
    vector<int> temp(n);
    int z=0;
    for(int i=d;i<n;i++){
        temp[z++]=arr[i];
    }
    
    for(int i=0;i<d;i++){
        temp[z++]=arr[i];
    }

    return temp;
}
// 

// 

// 

// 

// 

// 

// 

