//
// Created by alx on 07.11.2020.
//

#ifndef FACTORIAL_LAMBDA_H
#define FACTORIAL_LAMBDA_H

#include <algorithm>
#include <utility>
#include <vector>

#include "generic_factorial.h"

namespace factorial {

    template <typename V>
    class Lambda : public GenericTemplateFactorial<uint16_t, uint64_t> {
    public:
        explicit Lambda(const uint16_t &order, const std::string &description)
            : GenericTemplateFactorial(order, description)
            , numbers_(order)
            , out_(order) {
                V g{1};
                std::generate(numbers_.begin(), numbers_.end(), [&g] { return g++; });
        };
        uint64_t run() override;

    private:
        std::vector<V> numbers_;
        std::vector<V> out_;
    };

    template <typename V>
    uint64_t factorial::Lambda<V>::run() {
        std::transform(numbers_.begin(), numbers_.end(), out_.begin(),
                       [this](const V& i) {
                         result_ *= i;
                         return result_;
                       });
        return result_;
    }
}// namespace factorial

#endif//FACTORIAL_LAMBDA_H
