#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

// Class for representing fractions
class Fraction {
public:
    // constructors
    Fraction():a(1),b(1){}; 
    Fraction(int a,int b);
    Fraction(const Fraction & obj);

    // Arithmetic operators
    Fraction add(const Fraction& m);
    Fraction minus(const Fraction& m);
    Fraction multiple(const Fraction& m);
    Fraction divide(const Fraction& m);

    // Relational operators
    bool equal(const Fraction& m);
    bool unequal(const Fraction& m);
    bool less(const Fraction& m);
    bool greater(const Fraction& m);
    bool less_equal(const Fraction& m);
    bool greater_equal(const Fraction& m);

    
    double doubleer(){// Typecast to double
        return (double)a/b;
    }
    string stringer(){// Typecast to string
        return to_string(a)+"/"+to_string(b);
    }
    void inserter(){
        cin>>a>>b;
    }
    void extractor(){
        cout<<a<<"/"<<b<<endl;
    }

    // Conversion from a finite decimal string
    void from_decimal(string s);

private:
    int a,b; // Numerator and Denominator
};



Fraction::Fraction(int a,int b){// Constructor with parameters
    int gcd=__gcd(a,b); // Calculate the greatest common divisor
    this->a=a/gcd; // Reduce the fraction
    this->b=b/gcd;
}
Fraction::Fraction(const Fraction & obj){// Copy constructor
    a=obj.a;
    b=obj.b;
}


// Arithmetic operators
Fraction Fraction::add(const Fraction& m){
    Fraction temp;
    int up,down,gcd;
    up=this->a*m.b+this->b*m.a; // Cross multiplication
    down=this->b*m.b;
    gcd=__gcd(up,down);
    temp.a=up/gcd; // Reduce the fraction
    temp.b=down/gcd;
    return temp;
}
Fraction Fraction::minus(const Fraction& m){
    Fraction temp;
    int up,down,gcd;
    up=this->a*m.b-this->b*m.a; // Cross multiplication
    down=this->b*m.b;
    gcd=__gcd(up,down);
    temp.a=up/gcd; // Reduce the fraction
    temp.b=down/gcd;
    return temp;
}
Fraction Fraction::multiple(const Fraction& m){
    Fraction temp;
    int up,down,gcd;
    up=this->a*m.a; // Multiply numerators
    down=this->b*m.b; // Multiply denominators
    gcd=__gcd(up,down);
    temp.a=up/gcd; // Reduce the fraction
    temp.b=down/gcd;
    return temp;
}
Fraction Fraction::divide(const Fraction& m){
    Fraction temp;
    int up,down,gcd;
    up=this->a*m.b; // Multiply by the reciprocal
    down=this->b*m.a;
    gcd=__gcd(up,down);
    temp.a=up/gcd; // Reduce the fraction
    temp.b=down/gcd;
    return temp;
}

// Relational operators
bool Fraction::equal(const Fraction& m){
    return this->a==m.a && this->b==m.b;
}
bool Fraction::unequal(const Fraction& m){
    return this->a!=m.a || this->b!=m.b;
}
bool Fraction::less(const Fraction& m){
    return this->a*m.b<this->b*m.a; // Cross multiplication
}
bool Fraction::greater(const Fraction& m){
    return this->a*m.b>this->b*m.a; // Cross multiplication
}
bool Fraction::less_equal(const Fraction& m){
    return this->a*m.b<=this->b*m.a; // Cross multiplication
}
bool Fraction::greater_equal(const Fraction& m){
    return this->a*m.b>=this->b*m.a; // Cross multiplication
}


// Conversion from a finite decimal string
void Fraction::from_decimal(string s){
    int pos=s.find("."); // Find the position of the decimal point
    int len=s.length();
    int a=stoi(s.substr(0,pos)); // Extract the integer part
    int b=stoi(s.substr(pos+1,len-pos-1)); // Extract the decimal part
    int len2=len-pos-1;
    this->a=a*pow(10,len2)+b; // Combine integer and decimal parts
    this->b=pow(10,len2); // Denominator is a power of 10
    int gcd=__gcd(this->a,this->b); // Calculate the greatest common divisor
    this->a/=gcd; // Reduce the fraction
    this->b/=gcd;
}





int main(){
    //Test constructors
    Fraction f1; // Create a fraction object f1 with numerator 1 and denominator 1
    Fraction f2(2,4); // Create a fraction object f2 with numerator 2 and denominator 3
    Fraction f3(f2); // Create a fraction object f3 as a copy of f2
    f1.extractor(); // Output f1
    f2.extractor(); // Output f2
    f3.extractor(); // Output f3
    cout<<endl;

    Fraction m(2,3); // Create a fraction object m with numerator 2 and denominator 3
    Fraction n(3,4); // Create a fraction object n with numerator 3 and denominator 4

    // Test arithmetic operators
    Fraction sum=m.add(n); // Add m and n
    Fraction difference=m.minus(n); // Subtract n from m
    Fraction product=m.multiple(n); // Multiply m and n
    Fraction quotient=m.divide(n); // Divide m by n
    sum.extractor(); // Output the sum
    difference.extractor(); // Output the difference
    product.extractor(); // Output the product
    quotient.extractor(); // Output the quotient
    cout<<endl;

    // Test relational operators
    bool eq=m.equal(n); // Check if m equals n
    bool neq=m.unequal(n); // Check if m is not equal to n
    bool lt=m.less(n); // Check if m is less than n
    bool gt=m.greater(n); // Check if m is greater than n
    bool le=m.less_equal(n); // Check if m is less than or equal to n
    bool ge=m.greater_equal(n); // Check if m is greater than or equal to n
    cout<<eq<<" "<<neq<<" "<<lt<<" "<<gt<<" "<<le<<" "<<ge<<endl;
    cout<<endl;

    // Test typecasting
    double d=m.doubleer(); // Typecast m to double
    string s=m.stringer(); // Typecast m to string
    cout<<d<<" "<<typeid(d).name()<<endl;
    cout<<s<<" "<<typeid(s).name()<<endl;
    cout<<endl;

    // Test input and output
    m.inserter(); // Input a fraction
    m.extractor(); // Output a fraction
    cout<<endl;

    // Test conversion from a finite decimal string
    Fraction f;
    f.from_decimal("3.14"); // Convert the decimal string "3.14" to a fraction
    f.extractor(); // Output the fraction
    return 0;
}
