cmake_minimum_required(VERSION 3.18)
project(DJI_Payload_GPIO LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ─── Bring in DJI Payload SDK ────────────────────────────────────────────────
# The SDK repo already contains its own CMakeLists.txt,
# so adding the directory builds the SDK and exposes targets such as psdk_core.
add_subdirectory(Payload-SDK)

# ─── Your executable ─────────────────────────────────────────────────────────
add_executable(gpio_payload
    src/main.cpp
)

target_include_directories(gpio_payload PRIVATE
    Payload-SDK/include            # PSDK headers
)

target_link_libraries(gpio_payload
    psdk_core                      # built by add_subdirectory()
    gpiod                          # GPIO control
    pthread rt dl                  # common Pi libs
)
 