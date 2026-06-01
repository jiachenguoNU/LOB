#pragma once

#include "Usings.hpp"

struct LevelInfo //指的是orderbook里面的东西
{
    Price price_;
    Quantity quantity;

};

using LevelInfos = std::vector<LevelInfo>;