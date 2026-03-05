#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    if(dynamic_cast<Fireball*>(spell)){
        Fireball* f=(Fireball*)spell;
        f->revealFirepower();
    }else if(dynamic_cast<Frostbite*>(spell)){
        Frostbite* f=(Frostbite*)spell;
        f->revealFrostpower();
    }else if(dynamic_cast<Thunderstorm*>(spell)){
        Thunderstorm* f=(Thunderstorm*)spell;
        f->revealThunderpower();
    }else if(dynamic_cast<Waterbolt*>(spell)){
        Waterbolt* f=(Waterbolt*)spell;
        f->revealWaterpower();
    }else{
        //cout<<"here"<<endl;
    string s2=spell->revealScrollName();
    string s1=SpellJournal::journal;
    vector<vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1] +1;
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()]<<endl; 
    }
    
  /* Enter your code here */

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
