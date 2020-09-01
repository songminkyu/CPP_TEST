#include <random>
#include <cmath>
#include <matplot/matplot.h>

int main() {
    using namespace matplot;

    std::vector<double> codelines = {200,120,555,608,1024,101,57,687};
    std::vector<std::string> coders = {"Fred","Ginger","Norman","Max","Julia","Wally","Heidi","Pat"};

    pareto(codelines, coders);
    title("Lines of Code by Programmer");

    wait();
    return 0;
}