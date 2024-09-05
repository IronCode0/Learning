#include <bits/stdc++.h>

using namespace std;

int player_count (string a,string b) {
    int count=0;
    int n=a.length();
    for(int i=0; i < n; i++) {
        if (a[i] == '1' || b[i] == '1') count++;
        cout << a[i] << "-" << b[i] << "   " ;
    } cout << n << endl;
    return count;
}
vector<int> acmTeam(vector<string> topic) {
    int n=topic.size();
    vector<int> arr(topic[1].length()+1);
    for (int i=0;i <n; i++) for (int j=i+1; j <n; j++) {
        //if (i == j) continue;
        //cout << i << " " << j << " - ";
        player_count(topic[i],topic[j]);
    }
    
    return arr;
}

int main()
{
    
    acmTeam({"10101","11100","11010","00101"});

    return 0;
}


