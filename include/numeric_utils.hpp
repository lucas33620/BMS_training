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
}