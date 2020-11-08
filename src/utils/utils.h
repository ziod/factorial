//
// Created by alx on 07.11.2020.
//

#ifndef FACTORIAL_UTILS_H
#define FACTORIAL_UTILS_H

#include <climits>
#include <time.h>

namespace factorial {
    namespace utils {
        /**
     * BIT_WIDTH contains bit width for integer type
     */
        constexpr int BIT_WIDTH = sizeof(int) * CHAR_BIT;

        /**
     * Count "ones" in the bit_width
     * @param bit_width bit width for integer type
     * @param bit actual bit
     * @return "ones" number in the bit_width
     */
        constexpr int recursiveBitCheck(const int &bit_width, const int &bit) {
            return bit > 0
                           ? recursiveBitCheck(bit_width, bit - 1) + (bit_width && (1 << bit))
                           : bit_width != 0;
        }

        /**
     * Checks is bit width multiple to the power of two
     * @return true if BIT_WIDTH is power of two, otherwise false
     */
        constexpr bool isBitWidthMultiple() {
            return recursiveBitCheck(BIT_WIDTH, BIT_WIDTH - 1) == 1;
        }

        /**
         * Utility to measure time periods
         */
        class TimeDeltaMeasure {
        public:
            TimeDeltaMeasure() = default;
            virtual ~TimeDeltaMeasure() = default;
            inline void begin() {
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &bgn_);
            }
            inline void end() {
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_);
            }
            long delta() const {
                return end_.tv_nsec - bgn_.tv_nsec;
            }

        private:
            timespec bgn_{};
            timespec end_{};
        };

    }// namespace utils
}// namespace factorial

#endif//FACTORIAL_UTILS_H
