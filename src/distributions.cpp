//
// Created by Romain Dufetelle on 04/09/2025.
//

#include "bs/distributions.hpp"
#include <cmath>

namespace bs {
    constexpr double inv_sqrt_2pi = 0.39894228040143267794;

    double norm_pdf(double x) {
        return inv_sqrt_2pi * std::exp(-0.5 * x * x);
    }

    double norm_cdf(double x) {
        return 0.5 * std::erfc(-x * M_SQRT1_2);
    }
}