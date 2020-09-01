#include "MultiCastDelegate.h"
#include <iostream>

class Sample {
public:
    double InstanceFunction(int i, char c, const char* cc) { 
        std::cout << cc << std::endl;
        return 0.1; 
    }
    double ConstInstanceFunction(int i, char c, const char* cc) const { 
        std::cout << cc << std::endl;
        return 0.2; 
    }
    static double StaticFunction(int i, char c, const char* cc) { 
        std::cout << cc << std::endl;
        return 0.3; }
}; //class Sample


int main()
{
    Sample sample;
    SA::delegate<double(int, char, const char*)> d;
     
    auto dInstance = decltype(d)::create<Sample, &Sample::InstanceFunction>(&sample);
    auto dConst = decltype(d)::create<Sample, &Sample::ConstInstanceFunction>(&sample);
    auto dFunc = decltype(d)::create<&Sample::StaticFunction>();
    // same thing with non-class functions
 
    dInstance(0, 'A', "Instance method call");
    dConst(1, 'B', "Constant instance method call");
    dFunc(2, 'C', "Static function call");

    int touchPoint = 1;
    auto lambda = [&touchPoint](int i, char c, const char* msg) -> double {
        std::cout << msg << std::endl;
        // touch point is captured by ref, can change:
        return (++touchPoint + (int)c) * 0.1 - i;
    }; //lambda

    decltype(d) dLambda = lambda; // lambda to delegate
    // or:
    //decltype(d) dLambda(lambda);

    //if (d == nullptr) // true
    //    d(1, '1', "lambda call"); //won't

    d = dLambda; // delegate to delegate

    if (d == dLambda) // true, and also d != nullptr
        d(1, '1', "lambda call"); //will be called

    SA::multicast_delegate<double(int, char, const char*)> md;
    SA::multicast_delegate<double(int, char, const char*)> mdSecond;
    if (md == nullptr) // true
        md(5, '6', "zero calls"); //won't
    // add some of the delegate instances:
    md += mdSecond; // nothing happens to md
    md += d; // invocation list: size=1
    md += dLambda; // invocation list: size=2
    
    if (md == dLambda) //false
        std::cout << "md == dLambda" << std::endl;
    if (dLambda == md) //false
        std::cout << "dLambda == md" << std::endl;
    if (md == mdSecond) //false
        std::cout << "md == mdSecond" << std::endl;
    //adding lambda directly:
    md += lambda; // invocation list: size=3
    md(7, '8', "call them all");
}