#include <iostream>
#include <chrono>
#include <thread>
int main() {

    using namespace std;

    class FibonacciGenerator {
    private:
        long long a;
        long long b;

    public:
        FibonacciGenerator() : a(0), b(1) {}
        long long next() {
            long long current = a;
            long long nextValue = a + b;
            a = b;
            b = nextValue;
            return current;
        }
    };



}