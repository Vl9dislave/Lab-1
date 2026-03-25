#include <iostream>
#include <chrono>
#include <thread>

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

void consumeWithTimeout(FibonacciGenerator& generator, int timeoutSeconds) {
    auto startTime = chrono::steady_clock::now();

    long long sum = 0;
    int count = 0;

    while (chrono::duration_cast<chrono::seconds>(
        chrono::steady_clock::now() - startTime).count() < timeoutSeconds) {

        long long value = generator.next();
        count++;
        sum += value;

        double average = static_cast<double>(sum) / count;

        cout << "Iteration: " << count
            << " | Value: " << value
            << " | Sum: " << sum
            << " | Average: " << average << endl;
    }
}