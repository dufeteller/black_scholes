//
// Created by Romain Dufetelle on 04/09/2025.
//

#include <iostream>
#include "bs/black_scholes.hpp"
#include "bs/greeks.hpp"

int main() {
    bs::Params p{100.0, 100.0, 1.0, 0.02, 0.00, 0.20};
    std::cout << "Call price: " << bs::price(p, bs::OptionType::Call) << "\n";
    auto g = bs::greeks(p, bs::OptionType::Call);
    std::cout << "Delta: " << g.delta << "  Vega: " << g.vega << "\n";
}