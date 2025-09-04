//
// Created by Romain Dufetelle on 04/09/2025.
//

#ifndef BLACK_SCHOLES_HPP
#define BLACK_SCHOLES_HPP

#include "types.hpp"

namespace bs {
    void d1d2(const Params& p, double& d1, double& d2);
    double price(const Params& p, OptionType type);
}

#endif //BLACK_SCHOLES_HPP
