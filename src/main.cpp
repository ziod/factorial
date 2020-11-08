//
// Created by alx on 07.11.2020.
//

#include <iostream>

#include "complie_time.h"
#include "constants/constants.h"
#include "lambda.h"
#include "ordinal.h"
#include "multiprecision.h"
#include "utils/utils.h"

using std::cout;
using std::endl;

namespace util = factorial::utils;

int main() {
    if (util::isBitWidthMultiple()) {
        cout << "Bit width is not multiple to 8, 16, 32 or 64!" << endl;
        exit(0);
    }

    factorial::Ordinal ordinal(factorial::ORDER, "Ordinal");
    ordinal.process();

    factorial::Lambda<uint64_t> lambda(factorial::ORDER, "Lambda");
    lambda.process();

    factorial::Multiprecision multiprecision(factorial::ORDER, "Boost");
    multiprecision.process();

    util::TimeDeltaMeasure time_delta;
    int64_t result;

    time_delta.begin();
    result = factorial::factorial_run(factorial::ORDER);
    time_delta.end();

    cout << setw(factorial::OUTPUT_NAME_SHIFT) << "Compile time (without class)"
         << " run in: " << setw(factorial::OUTPUT_DURATION_SHIFT) << time_delta.delta()
         << " ns. Result: " << (uint) result << endl;

    factorial::CompileTime compileTime(factorial::ORDER);
    time_delta.begin();
    result = compileTime.run();
    time_delta.end();

    cout << setw(factorial::OUTPUT_NAME_SHIFT) << "Compile time factorial"
         << " run in: " << setw(factorial::OUTPUT_DURATION_SHIFT) << time_delta.delta()
         << " ns. Result: " << (uint) result << endl;

    factorial::Multiprecision big(factorial::BOOST_ORDER, "Boost big order");
    big.process();

    return 0;
}
