//
// Created by alx on 07.11.2020.
//

#ifndef FACTORIAL_ORDINAL_H
#define FACTORIAL_ORDINAL_H

#include <utility>

#include "generic_factorial.h"

namespace factorial {
    class Ordinal : public GenericTemplateFactorial<uint16_t, uint64_t> {
    public:
        Ordinal(const uint16_t &order, std::string description)
                : GenericTemplateFactorial(order, std::move(description)){};
        uint64_t run() override;
    };
}

#endif//FACTORIAL_ORDINAL_H
