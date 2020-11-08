//
// Created by alx on 07.11.2020.
//

#ifndef FACTORIAL_COMPILE_TIME_H
#define FACTORIAL_COMPILE_TIME_H

#include <cstdint>
#include "generic_factorial.h"

namespace factorial {

    constexpr uint64_t factorial_run(const uint16_t& order) {
        return order == 1
               ? 1
               : order * factorial_run(order - 1);
    }

    class CompileTime {
    public:
        explicit constexpr CompileTime(const uint16_t& order)
                :order_{order}{};

        constexpr uint64_t run() const {
            return run(order_);
        }
    private:
        uint16_t order_;

        constexpr uint64_t run(const uint16_t& order) const {
            return order == 1
                   ? 1
                   : order * run(order - 1);
        }
    };

} // factorial

#endif//FACTORIAL_COMPILE_TIME_H
