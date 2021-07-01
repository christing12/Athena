#include <iostream>
#include "AthenaAPI.h"

using namespace std;

long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

#define M_PI 3.14159265358979323846
int main()
{
    athena:: Timer timer;
    timer.Start();
    int counter = 0;
    double test, test2;
    while (timer.ElapsedSeconds() < 2.0)
    {
        counter++;
        test = std::cos(counter / M_PI);
        test2 = std::sin(counter / M_PI);
    }
    timer.Stop();

    std::cout << counter << std::endl;
    std::cout << "Seconds: " << timer.ElapsedSeconds() << std::endl;
    std::cout << "Milliseconds: " << timer.ElapsedMilliseconds() << std::endl;

    return 0;
}