#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Box {
    private:
        int l, b, h;
    public:
        Box() : l(0), b(0), h(0) {}
        Box(const int& l, const int& b, const int& h) : l(l), b(b), h(h) {}
        Box(const Box& B) : l(B.getLength()), b(B.getBreadth()), h(B.getHeight()) {}
        
        int getLength() const {return l;};
        int getBreadth() const {return b;};
        int getHeight() const {return h;};
        
        bool operator<(const Box& B) const {
            int Bl = B.getLength();
            int Bb = B.getBreadth();
            int Bh = B.getHeight();
            if ((this->l<Bl) || (this->b<Bb && this->l==Bl) || (this->h<Bh && this->b==Bb && this->l==Bl)) return true;
            return false;
        }
        
        long long CalculateVolume() {
            return 1LL*l*b*h;
        }
        
        friend ostream& operator << (ostream& out, const Box& B);
};

ostream& operator << (ostream& out, const Box& B) {
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight() << endl;
    return out;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n; cin >> n;
    Box current;
    while (n--) {
        int query; cin >> query;
        switch (query) {
            case 1: {
                cout << current;
                break;
            }
            case 2: {
                int l, b, h;
                cin >> l >> b >> h;
                current = Box(l,b,h);
                cout << current;
                break;
            }
            case 3: {
                int l, b, h;
                cin >> l >> b >> h;
                cout << ((Box(l,b,h) < current) ? "Lesser" : "Greater") << endl;
                break;
            }
            case 4: {
                cout << current.CalculateVolume() << endl;
                break;
            }
            case 5: {
                current = Box(current);
                cout << current;
                break;
            }
        }
    }  
    return 0;
}
