//
// Created by Romain Dufetelle on 04/09/2025.
//

#ifndef TYPES_HPP
#define TYPES_HPP

namespace bs {
    using Real = double;

    enum class OptionType { Call, Put };

    struct Params {
        Real S;
        Real K;
        Real T;
        Real r;
        Real q;
        Real sigma;
    };
}

#endif
