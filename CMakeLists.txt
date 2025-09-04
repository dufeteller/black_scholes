cmake_minimum_required(VERSION 3.16)
project(black_scholes LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Librairie compilée (statique) ---
add_library(bs STATIC
        src/black_scholes.cpp
        src/distributions.cpp
        src/greeks.cpp
)
target_include_directories(bs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Exécutable d'exemple ---
add_executable(pricer examples/pricer_cli.cpp)
target_link_libraries(pricer PRIVATE bs)