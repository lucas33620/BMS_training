# Example ARM toolchain file.
# Training only - not used by the project.

# Target system:
# set(CMAKE_SYSTEM_NAME Generic)

# Target architecture:
# set(CMAKE_SYSTEM_PROCESSOR arm)

# Cross compilers:
# set(CMAKE_C_COMPILER ...)
# set(CMAKE_CXX_COMPILER ...)

# Real embedded toolchains may also configure:
# - CPU / FPU flags
# - linker script
# - startup code
# - target-specific libraries

# Use this toolchain file with the following command:
# cmake -S . -B build-arm \ -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/arm_example.cmake