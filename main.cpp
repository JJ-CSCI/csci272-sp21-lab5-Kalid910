//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real {
protected:
    double num;
public:
    Real(double num) {
        this->num = num; 
    }

    double GetReal() {
        return num;
    }

     Real operator*(double n) {
        num = num * n;
        Real r(GetReal());
        return r;
    }
};



class Complex : public Real {
protected:
    double imaginary;

public:

    Complex(double real, double imag) : Real(real), imaginary(imag) {}


    double GetImaginary() {
        return imaginary;
    }

    Complex operator*(double n) {
        Complex r(GetReal() * n, GetImaginary() * n);
        return r;
    }
};


class Surreal : public Complex {
    private:
    double surr;

    public:

    Surreal(double real, double imag, double sur) : Complex(real, imag), surr(sur) {}

    double GetSurreal() {
        return surr;
    }

    Surreal operator*(double n)  {
        Surreal r(GetReal() * n, GetImaginary() * n, GetSurreal() * n);
        return r;
    }
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
