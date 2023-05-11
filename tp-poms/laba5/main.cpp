#include <iostream> 
#include <cmath> 

using namespace std;  

class Triangle 
{ 
    protected: int a, b, c;   

    public: Triangle(int a, int b, int c) 
    { 
        this->a = a; 
        this->b = b;
        this->c = c;
    }

    public: bool IsTriangle() 
    { 
        int a(this->a), b(this->b), c(this->c); 

        if ( a + b <= c ) return false; 
        if ( a + c <= b ) return false; 
        if ( b + c <= a ) return false; 

        return true;
    } 

    public: void LengthTriangle() 
    { 
        int a(this->a), b(this->b), c(this->c); 

        cout << "Len 1 " << a << endl; 
        cout << "Len 2 " << b << endl; 
        cout << "Len 3 " << c << endl;
    }

    public: void GetAngles() 
    { 
        int a(this->a), b(this->b), c(this->c); 

        cout << "Angle (a, b) " << acos((pow(a,2)+pow(b,2)-pow(c,2))/(float)(2*a*b))*180/M_PI << endl;
        cout << "Angle (a, c) " << acos((pow(a,2)+pow(c,2)-pow(b,2))/(float)(2*a*c))*180/M_PI << endl; 
        cout << "Angle (b, c) " << acos((pow(b,2)+pow(c,2)-pow(a,2))/(float)(2*c*b))*180/M_PI << endl; 
    } 

    public: int GetPerimetr() 
    { 
        int a(this->a), b(this->b), c(this->c);
    
        return a+b+c;  
    }

    public: void GetArea() 
    { 
        int hp = this->GetPerimetr()/2; 
        int a(this->a), b(this->b), c(this->c); 

        cout << sqrt(hp*(hp-a)*(hp-b)*(hp-c)) << endl;  
    } 
}; 

class EqTriangle: public Triangle 
{ 
    public: EqTriangle(int a, int b, int c) : Triangle(a, b, c) { }; 

    public: bool IsTriangle() 
    { 
        int hyp; 
        int a(this->a), b(this->b), c(this->c); 

        if ( a > b and a > c ) { 
            hyp = a; 
            a = 0; 
        } 
        if ( b > a and b > c ) {  
            hyp = b; 
            b = 0;
        }
        if ( c > a and c > b ) { 
            hyp = c; 
            c = 0; 
        }
        
        return (a*a + b*b + c*c == hyp*hyp); 
    }
}; 

int main() 
{ 
    cout << "Triangle Class test " << endl; 

    Triangle tr_base = Triangle(6, 8, 10); 

    cout << "IsTriangle " << tr_base.IsTriangle() << endl; 
    tr_base.LengthTriangle(); 
    tr_base.GetAngles(); 
    tr_base.GetPerimetr(); 
    tr_base.GetArea(); 

    cout << "EQ Triangle class test" << endl; 

    EqTriangle tr1 = EqTriangle(3, 4, 5); 

    cout << "IsTriangle " << tr1.IsTriangle() << endl; 
    tr1.LengthTriangle(); 
    tr1.GetAngles(); 
    tr1.GetPerimetr(); 
    tr1.GetArea(); 

    return 0;
}