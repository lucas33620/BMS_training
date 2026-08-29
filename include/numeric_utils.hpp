#pragma once

namespace bms
{
    template <typename T>
    T clamp_value(T value, T min_value, T max_value)
    {
        if (value < min_value)
        {
            return min_value;
        }
        else if (value > max_value)
        {
            return max_value;
        }
        else
        {
            return value;
        }
    }

    template <typename T, std::size_t N>
    T min_value(const std::array<T, N>& arr)
    {
        static_assert(N > 0, "min_value requires a non-empty array");

        T min_val = arr[0];

        for (std::size_t i = 1; i < N; ++i)
        {
            if (arr[i] < min_val)
            {
                min_val = arr[i];
            }
        }

        return min_val;
    }

    template <typename T, std::size_t N>
    T max_value(const std::array<T, N>& arr)
    {
        static_assert(N > 0, "max_value requires a non-empty array");

        T max_val = arr[0];

        for (std::size_t i = 1; i < N; ++i)
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
            }
        }

        return max_val;
    }
}