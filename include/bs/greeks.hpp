//
// Created by Romain Dufetelle on 04/09/2025.
//

#ifndef GREEKS_HPP
#define GREEKS_HPP

#include "types.hpp"

namespace bs {
    struct Greeks { double delta, gamma, vega, theta, rho; };
    Greeks greeks(const Params& p, OptionType type);
}

#endif //GREEKS_HPP
