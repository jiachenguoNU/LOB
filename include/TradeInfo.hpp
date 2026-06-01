#pragma once

#include "Usings.hpp"

struct TradeInfo  //指的是每一笔trade的信息
{
    OrderID orderID_;
    Price price_;
    Quantity quantity_;

};