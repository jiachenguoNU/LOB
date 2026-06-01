#pragma once

#include "Usings.hpp"

struct LevelData
{
    Quantity quantity_;
    Quantity count_;

    enum class Action
    {
        Add, Remove, Match
    };
};
