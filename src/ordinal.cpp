//
// Created by alx on 07.11.2020.
//

#include "ordinal.h"

using namespace factorial;

uint64_t Ordinal::run() {
    for (uint16_t i{1}; i <= order_; ++i) {
        result_ *= i;
    }
    return result_;
}
