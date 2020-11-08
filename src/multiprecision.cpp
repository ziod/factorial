//
// Created by alx on 08.11.2020.
//

#include "multiprecision.h"

using namespace factorial;

cpp_int Multiprecision::run() {
    for (uint16_t i{1}; i <= order_; ++i) {
        result_ *= i;
    }
    return result_;
}

void Multiprecision::print() const {
    cout << setw(OUTPUT_NAME_SHIFT) << descriptor_ << " run in: "
         << setw(factorial::OUTPUT_DURATION_SHIFT) << time_delta_.delta()
         << " ns. Result: " << result_ << endl;
}

cpp_int boost_factorial(const uint16_t &order) {
    cpp_int result = 1;
    for (uint16_t i = 1; i < order; ++i) {
        result *= i;
    }
    return result;
}
