cmake_minimum_required(VERSION 3.18)
project(DJI_Payload_GPIO LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ─── bring in DJI Payload-SDK ───────────────────────────────────────────────
add_subdirectory(Payload-SDK)            # builds psdk_core and friends

include_directories(Payload-SDK/include) # SDK headers

# ─── gpio_payload (GPIO 17 toggle) ──────────────────────────────────────────
add_executable(gpio_payload
    src/main.cpp
)
target_link_libraries(gpio_payload
    psdk_core        # from the SDK build
    gpiod            # GPIO access
    pthread rt dl
)

# ─── listener (prints inbound traffic) ──────────────────────────────────────
add_executable(listener
    src/listener.cpp
)
target_link_libraries(listener
    psdk_core
    pthread rt dl
)




#                 sudo apt install build-essential cmake libgpiod-dev
#                 cd DJI-Payload-SDK-Pi-Zero
#                 cmake -B build
#                 cmake --build build -j4        # builds SDK + both apps
                
#                 # 1. Toggle GPIO test (needs sudo for /dev/gpiochip0)
#                 sudo ./build/gpio_payload
                
#                 # 2. Raw listener – check traffic from FlyCart 30
#                 sudo ./build/listener
