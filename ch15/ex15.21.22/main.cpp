//!
//! Exercise 15.21:
//! Choose one of the following general abstractions containing a family of
//! types (or choose one of your own). Organize the types into an inheritance
//! hierarchy:
//!     (a) Graphical file formats (such as gif, tiff, jpeg, bmp)
//!     (b) Geometric primitives (such as box, circle, sphere, cone)
//!     (c) C++ language types (such as class, function, member function)
//!
//! Exercise 15.22:
//! For the class you chose in the previous exercise, identify some of the
//! likely virtual functions as well as public and protected members.
//!

#include <utility>
#include <string>
using namespace std;

//! just for 2D shape
class Shape {
public:
    typedef pair<double, double> Coordinate;

    Shape() = default;
    Shape(const string& n) : name(n) { }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() = default;

private:
    string name;
};

class Rectangle : public Shape {
public:
    Rectangle() = default;
    Rectangle(const string& n, const Coordinate& a, const Coordinate& b, const Coordinate& c,const Coordinate& d) : Shape(n), a(a), b(b), c(c), d(d) { }

    ~Rectangle() = default;

protected:
    Coordinate  a;
    Coordinate  b;
    Coordinate  c;
    Coordinate  d;
};

class Square : public Rectangle {
public:
    Square() = default;
    Square(const string& n, const Coordinate& a, const Coordinate& b, const Coordinate& c, const Coordinate& d) : Rectangle(n,a,b,c,d) { }

    ~Square() = default;
};


int main()
{
    return 0;
}
