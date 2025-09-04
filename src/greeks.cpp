//
// Created by Romain Dufetelle on 04/09/2025.
//

#include "bs/greeks.hpp"
#include "bs/black_scholes.hpp"
#include "bs/distributions.hpp"
#include <cmath>

namespace bs {
    Greeks greeks(const Params& p, OptionType type) {
        double d1, d2; d1d2(p, d1, d2);
        const double df_r = std::exp(-p.r * p.T);
        const double df_q = std::exp(-p.q * p.T);
        const double pdf = norm_pdf(d1);

        Greeks g{};
        g.delta = (type == OptionType::Call) ? df_q * norm_cdf(d1) : df_q * (norm_cdf(d1) - 1.0);
        g.gamma = df_q * pdf / (p.S * p.sigma * std::sqrt(p.T));
        g.vega  = p.S * df_q * pdf * std::sqrt(p.T);
        g.theta = -(p.S * df_q * pdf * p.sigma) / (2.0 * std::sqrt(p.T))
                + (type == OptionType::Call
                   ? p.q * p.S * df_q * norm_cdf(d1) - p.r * p.K * df_r * norm_cdf(d2)
                   : -p.q * p.S * df_q * norm_cdf(-d1) + p.r * p.K * df_r * norm_cdf(-d2));
        g.rho   = (type == OptionType::Call)
                  ? p.K * p.T * df_r * norm_cdf(d2)
                  : -p.K * p.T * df_r * norm_cdf(-d2);
        return g;
    }
}