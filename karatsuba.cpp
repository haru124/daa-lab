#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    long long numDigits = max(to_string(x).length(), to_string(y).length());
    long long m = pow(10, numDigits / 2);

    long long a = x / m;
    long long b = x % m;
    long long c = y / m;
    long long d = y % m;

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ad_bc = karatsuba((a + b), (c + d)) - ac - bd;

    return (ac * pow(10, numDigits)) + ad_bc * m + bd;
}

int main() {
    long long x = 12345;
    long long y = 6789;

    long long result = karatsuba(x, y);

    std::cout << "Product: " << result << std::endl;

    return 0;
}
