#include <iostream>
#include <chrono>

long long rpower(int x, int n) {
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result *= x;
    }
    return result;
}

long long brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    int x = 2, n = 100000;
    
    auto start1 = std::chrono::high_resolution_clock::now();
    rpower(x, n);
    auto end1 = std::chrono::high_resolution_clock::now();
    
    auto start2 = std::chrono::high_resolution_clock::now();
    brpower(x, n);
    auto end2 = std::chrono::high_resolution_clock::now();
    
    std::cout << "rpower  (O(n)): " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds\n";
    std::cout << "brpower (O(log n)): " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds\n";
    return 0;
}
