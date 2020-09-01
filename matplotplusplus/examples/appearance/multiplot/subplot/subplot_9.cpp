#include <iostream>
#include <thread>
#include <vector>
#include <set>
#include <matplot/matplot.h>

int main() {
    using namespace matplot;

    figure();
    fplot("sin(x)");
    title("Line Plot 1");
    auto ax1 = gca();

    figure();
    fplot("2*sin(x)");
    title("Line Plot 2");
    auto ax2 = gca();

    auto fnew = figure();
    auto ax1_copy = ax1->copy(fnew);
    subplot(2,1,0,ax1_copy);

    auto ax2_copy = ax2->copy(fnew);
    subplot(2,1,1,ax2_copy);

    wait();
    return 0;
}