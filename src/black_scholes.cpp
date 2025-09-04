//
// Created by Romain Dufetelle on 04/09/2025.
//

#include "bs/black_scholes.hpp"
#include "bs/distributions.hpp"
#include <cmath>

namespace bs {
    void d1d2(const Params& p, double& d1, double& d2) {
        const double vs = p.sigma * std::sqrt(p.T);
        d1 = (std::log(p.S / p.K) + (p.r - p.q + 0.5 * p.sigma * p.sigma) * p.T) / vs;
        d2 = d1 - vs;
    }

    double price(const Params& p, OptionType type) {
        double d1, d2; d1d2(p, d1, d2);
        const double df_r = std::exp(-p.r * p.T), df_q = std::exp(-p.q * p.T);
        if (type == OptionType::Call)
            return p.S * df_q * norm_cdf(d1) - p.K * df_r * norm_cdf(d2);
        else
            return p.K * df_r * norm_cdf(-d2) - p.S * df_q * norm_cdf(-d1);
    }
}
