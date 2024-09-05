// Basic Data Types
/*  printf("%#.3f",d);
    cout << endl;
    printf("%#.9lf",e);
	*/
// Strings > Attribute Parser
map <string, string> tagMap;
void createMap(int &n, string pretag) {
    if(!n) return;
    
    string line, tag, attr, value;
    getline(cin, line);
    
    int i=1;
    if (line[i]=='/') {
        while(line[i] != '>') i++;
        if (pretag.size() > (i-2))
            tag = pretag.substr(0, pretag.size()-i+1);
        else
            tag = "";
    }
    else {
        while(line[i]!=' ' && line[i]!='>') i++;
        tag = line.substr(1,i-1);
        if (pretag!="") tag = pretag + "." + tag;
        
        int j;
        while(line[i] != '>') {
            j = ++i;
            while(line[i]!=' ') i++;
            attr = line.substr(j,i-j);
            
            while(line[i]!='\"') i++;
            j = ++i;
            
            while(line[i]!='\"') i++;
            value = line.substr(j,i-j); 
            i+= 1;
            
            tagMap[tag + "~" + attr] = value;
        }
    }
    createMap(--n, tag);
}
int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();
    createMap(n,"");
    
    string attr, value;
    while(q--) {
        getline(cin,attr);
        value = tagMap[attr];
        if(value=="") value = "Not Found!";
        cout << value << endl;
    }
    return 0;
}
// Introduction > Variable Sized Arrays
int main() {
    int n, q;
    cin >> n >> q;
    int** seq=new int* [n];
    
    for(int i=0; i<n; i++)
        {
        int a;
        cin >> a;
        int* b=new int [a];
        for(int j=0; j<a; j++) {
            int x;
            cin >> x;
            b[j] = x;
        }
        *(seq+i)=b;
    }

    for(int i=0; i<q; i++) {
        int r, s;
        cin >> r >> s;
        cout << seq[r][s] << endl;
    }
  
    return 0;
}
// Introduction > Arrays Introduction
int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int a=0;a < N;a++) cin >> arr[a];
    for(int b=N-1;b >= 0;b--) cout << arr[b] << " ";
     
    return 0;
}

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    char ch;
    vector<int> a;
    int x;
    while(ss >> x) {
        a.push_back(x);
        ss >> ch;
    }
    return a;
}
// Strings > StringStream
int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
        cout << integers[i] << "\n";
    return 0;
}
// Classes > Structs
struct Student {
    int age,standard;
    string first_name,last_name;
};
int main() {
    Student st;
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    return 0;
}
// Classes > Classes and Objects
class Student {
    public:
        int scores[5];
        void input() {
            for (int i=0; i<5; i++) cin >> scores[i];
        }
        int calculateTotalScore() {
            int sum =0;
            for (int i=0; i<5; i++) sum +=scores[i];
            return sum;
        }
};
// Classes > Box It!
class Box {
    int l,b,h;
    public:
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }
        Box(int l,int b,int h) {
            this->l = l;
            this->b = b;
            this->h = h;
        }
        Box(Box& B) {
           l = B.l;
            b = B.b;
            h = B.h; 
        }
        int getLength()   { return l; }
        int getBreadth () { return b; }
        int getHeight ()  { return h; }
        long long CalculateVolume() { return (long)(long)l*b*h; } // Return the volume of the box
        bool operator<(Box& B) {
            if (l < B.getLength())
                return true;
            else if (l == B.getLength()) {
                if (b < B.getBreadth())
                    return true;
                else if (b == B.getBreadth()) {
                    if (h < B.getHeight())
                        return true;
                }
            }
            return false;
        } 
};
ostream& operator << (ostream& out, Box& B) {
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
    };
//Classes > Inherited Code
class BadLengthException {
    int a;
    public:
    BadLengthException(int n) {
        a=n;
    }
    int what() {
        return a;
    }
};
// Classes > Exceptional Server
try {
            cout << Server::compute(A,B) << endl;
            
        } catch (bad_alloc& e) {
            cout << "Not enough memory" << endl;
        } catch (exception& e) {
            cout << "Exception: " << e.what() << endl;
        } catch (...) {
            cout << "Other Exception" << endl;
        }
// Classes > Virtual Functions
class Person {
    public:
    virtual void getdata() {};
    virtual void putdata() {};
    protected:
    string name;
    int age;  
};

class Professor: public Person {
    
    static int cur_id_1;
    int publications;
    
    public:
    void getdata() {
        cin >> name >> age >> publications ;
    }
    void putdata() {
       cout << name << " " << age << " " << publications << " " << cur_id_1++ << endl;
    }
    
};
class Student: public Person {
    
    static int cur_id_2;
    int marks[6];
    
    public:
    int sum=0;
    void getdata() {
        cin >> name >> age ;
        for(int i=0; i<=5; i++) {
            cin >> marks[i];
            sum +=marks[i];
        }
    }
    void putdata() {
        cout << name << " " << age << " " << sum << " " << cur_id_2++ << endl;
    }
};
int Professor::cur_id_1 = 1;
int Student::cur_id_2 = 1;
// STL > Vector-Sort
int main() {
    vector<int> a;
    int n, nums;
    cin >> n;
    
    while (cin >> nums) 
    a.push_back(nums);
 
    std::sort(a.begin(), a.end());
    
    for(int i=0; i<n; i++)
    cout << a[i] << " ";
    return 0;
}
// STL > Lower Bound-STL
int main() {
    int n,x,y,p,q;
    cin >> n;
    vector<int> v;
    for(x=0; x < n; x++) {cin >> y; v.push_back(y);}
    cin >> q;
    for(x=0; x < q; x++) {
        cin >> p;
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), p);
       if (v[low - v.begin()] == p)
           cout << "Yes " << (low - v.begin()+1) << endl;
       else
           cout << "No " << (low - v.begin()+1) << endl;
        

    }
     
    return 0;
}
// STL > Sets-STL
int main() {
    int x,y,q;
    set<int> s;
    cin >> q;
    for(int i=0; i < q; i++) {
        cin >> y >> x;
        if (y == 1) s.insert(x);
        else if ( y == 2) s.erase(x);
        else if ( y == 3) {
            if (s.count(x) == 0) cout << "No"; else cout << "Yes";
            cout << endl;
        }
    }
    return 0;
}
// STL > Maps-STL
int main() {

    map<string,int>s;
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int type,n,m;
        cin >> type;
        switch(type) {
            case 1: {
                string name;
                int marks;
                cin >> name >> marks;
                map<string,int>::iterator itr=s.find(name);
                if (itr==s.end())
                    s.insert(make_pair(name,marks));
                else
                    itr->second += marks;
                break;
            }
            case 2: {
                string name;
                cin >> name;
                s.erase(name);
                break;
            }
            case 3: {
                string name;
                cin >> name;
                map<string,int>::iterator itr=s.find(name);
                if( itr==s.end())
                    cout << "0" << endl;
                else
                    cout << itr->second << endl;
                break;
            }
        }
    }
    return 0;

}
// STL > Print Pretty
cout << resetiosflags(ios::uppercase|ios::scientific)
     << std::setiosflags (ios::left|ios::fixed)
     << setw(0)
     << std::hex
     << std::setiosflags (ios::showbase)
     << (unsigned long)A << std::endl;

cout << resetiosflags(ios::showbase)
     << setw(0xf)
     << setfill('_')
     << std::dec 
     << setiosflags (ios::showpos) << setprecision(2)
     << B << std::endl;

cout << resetiosflags(ios::fixed|ios::showpos)
     << setiosflags (ios::scientific | ios::uppercase)
     << setprecision(9)
     << C << std::endl;
// Inheritance > Multi Level Inheritance
class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};
class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};
class Equilateral : public Isosceles {
    public:
        void equilateral() {
            cout << "I am an equilateral triangle" << endl;
        }
};
int main(){
  
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
// Inheritance > Accessing Inherited Functions
class D : public A,B,C {

	int val;
	public:
		//Initially val is 1
		 D() { val = 1; }
		 //Implement this function
		 void update_val(int new_val) {
            while(new_val%2 == 0) {
                A::func(val);
                new_val /= 2;
            }
            while(new_val%3 == 0) {
                B::func(val);
                new_val /= 3;
            }
            while(new_val%5 == 0) {
                C::func(val);
                new_val /= 5;
            }
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};
// Inheritance > Magic Spells
if (Fireball *fb = dynamic_cast<Fireball*>(spell))
    fb->revealFirepower();
else if (Frostbite *fb = dynamic_cast<Frostbite*>(spell))
    fb->revealFrostpower();
else if (Thunderstorm *ts = dynamic_cast<Thunderstorm*>(spell))
    ts->revealThunderpower();
else if (Waterbolt *wb = dynamic_cast<Waterbolt*>(spell))
    wb->revealWaterpower();
else  {
    std::string strA = spell->revealScrollName();
    std::string strB = SpellJournal::read();

    int m = strA.length();
    int n = strB.length();

    vector<vector<int>> vLCSMatrix(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (strA[i - 1] == strB[j - 1])
                vLCSMatrix[i][j] = 1 + vLCSMatrix[i - 1][j - 1];
            else
                vLCSMatrix[i][j] = std::max(vLCSMatrix[i - 1][j], vLCSMatrix[i][j - 1]);
cout << vLCSMatrix[m][n] << endl;
}





