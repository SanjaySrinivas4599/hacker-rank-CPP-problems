
#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
  private:
    int age;
    string first_name;
    string last_name;
    int standard;  
  public:
    void get_age();
    void set_age();
    void get_first_name();
    void set_first_name();
    void get_last_name();
    void set_last_name();
    void get_standard();
    void set_standard();
};

void Student :: get_age(){
    cin >> age;
}
void Student :: get_first_name(){
    cin >> first_name;
}
void Student :: get_last_name(){
    cin >> last_name;
}
void Student :: get_standard(){
    cin >> standard;
}
void Student :: set_age(){
    cout << age;
}
void Student :: set_first_name(){
    cout << first_name;
}
void Student :: set_last_name(){
    cout << last_name;
}
void Student :: set_standard(){
    cout << standard;
}

int main() {
    Student st;
    st.get_age();
    st.get_first_name();
    st.get_last_name();
    st.get_standard();
    
    st.set_age();
    cout << endl;
    st.set_last_name();
    cout << ", ";
    st.set_first_name();
    cout << endl;
    st.set_standard();
    
    cout << endl << endl;
    
    st.set_age();
    cout << ",";
    st.set_first_name();
    cout << ",";
    st.set_last_name();
    cout << ",";
    st.set_standard();
    
    return 0;
}

