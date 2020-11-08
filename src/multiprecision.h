//
// Created by alx on 08.11.2020.
//

#ifndef FACTORIAL_MULTIPRECISION_H
#define FACTORIAL_MULTIPRECISION_H

#include <boost/multiprecision/cpp_int.hpp>
#include <utility>

#include "generic_factorial.h"
#include "constants/constants.h"

namespace factorial {
    using namespace boost::multiprecision;

    cpp_int boost_factorial(const uint16_t &order);

    class Multiprecision : public GenericTemplateFactorial<uint16_t, cpp_int> {
    public:
        explicit Multiprecision(const uint16_t &order, std::string descriptor)
            : GenericTemplateFactorial(order, std::move(descriptor)){};

        cpp_int run() override;
        void print() const override;
    };
}// namespace factorial
#endif//FACTORIAL_MULTIPRECISION_H
