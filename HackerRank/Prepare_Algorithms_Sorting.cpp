// Big Sorting
bool check(const string& a, const string& b) {
    return (a.length() != b.length()) ? a.length() < b.length() : a < b;
}
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(),unsorted.end(), check);
    return unsorted;
}
// Intro to Tutorial Challenges
int introTutorial(int V, vector<int> arr) {
    return find (arr.begin(), arr.end(), V) - arr.begin();
}
// Insertion Sort - Part 1
void insertionSort1(int n, vector<int> arr) {
    int x = *(arr.end() - 1);
    int i;
    for (i = arr.size()-1; i > 0; i--)
        if(x < arr[i-1]) {
            arr[i] = arr[i-1];
            for (int y : arr) cout << y << " ";
            cout << endl;
        } else break;
    arr[i] = x;
    for (int y : arr) cout << y << " ";
    cout << endl;
}
// Insertion Sort - Part 2
void insertionSort2(int n, vector<int> arr) {
    for (int i = 1; i < n; i++) {
        int val = arr[i], pre = i - 1;
        while (pre >= 0 && arr[pre] > val) {
            arr[pre + 1] = arr[pre];
            pre--;
        }
        arr[pre + 1] = val;
        for (int i : arr) cout << i << " "; cout << endl;
    }
}
// Correctness and the Loop Invariant
void insertionSort(int N, int arr[]) {
    for(int i=1, j, value ; i<N ; i++) {
        value=arr[i];
        j=i-1;
        while(j>=0 && value<arr[j]) {
            arr[j+1]=arr[j];
            j-- ;
        }
        arr[j+1]=value;        
    }
    for(int j=0; j<N; j++){
        printf("%d",arr[j]);
        printf(" ");
    }
}



