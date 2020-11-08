//
// Created by alx on 07.11.2020.
//

#ifndef FACTORIAL_GENERIC_FACTORIAL_H
#define FACTORIAL_GENERIC_FACTORIAL_H

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <utility>

#include "constants/constants.h"
#include "utils/utils.h"

using std::cout;
using std::endl;
using std::setw;

namespace factorial {
    /**
     * Describes factorial interface
     * @tparam O order type
     * @tparam R result type
     */
    template<typename O, typename R>
    class GenericTemplateFactorial {
    public:
        /**
         * Describes factorial interface
         * @param order factorial order
         * @param descriptor string that defines concrete factorial solution
         */
        explicit GenericTemplateFactorial(const O &order, std::string descriptor)
            : order_{order}, result_{1}, descriptor_{std::move(descriptor)}, time_delta_{} {};

        virtual R run() = 0;

        void process() {
            time_delta_.begin();
            result_ = run();
            time_delta_.end();
            print();
        }

    protected:
        O order_;
        R result_;
        std::string descriptor_;
        factorial::utils::TimeDeltaMeasure time_delta_;

        virtual void print() const {
            cout << setw(OUTPUT_NAME_SHIFT) << descriptor_ << " run in: "
                 << setw(factorial::OUTPUT_DURATION_SHIFT) << time_delta_.delta()
                 << " ns. Result: " << (uint) result_ << endl;
        };
    };
}// namespace factorial

#endif//FACTORIAL_GENERIC_FACTORIAL_H
