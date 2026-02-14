#include <iostream>

class Complex
{
public:
    Complex() = default;
    Complex(int a, int b)
        : m_a {a}, m_b {b}
    {
    }
    
    friend Complex operator+(const Complex& c1, const Complex& c2)
    {
        return {c1.m_a + c2.m_a, c1.m_b + c2.m_b};
    }   
    
    friend std::ostream& operator<<(std::ostream& out, const Complex& c)
    {
        out << c.m_a << "+i" << c.m_b; 
        return out;
    }     
    
    friend std::istream& operator>>(std::istream& in, Complex& c)
    {
        in >> c.m_a;
        in.ignore(2); // Ignores '+i'
        in >> c.m_b;
        
        return in;
    }
        
private:
    int m_a {};
    int m_b {};
};

int main() 
{
    Complex c1 {};
    Complex c2 {};
    
    std::cin >> c1 >> c2;
    
    std::cout << c1 + c2;
    
    return 0;
}
