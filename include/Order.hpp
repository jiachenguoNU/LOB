#pragma once

#include "OrderType.hpp"
#include "Side.hpp"
#include "Usings.hpp"

class Order
{
private:
    OrderType orderType_;
    OrderID orderID_;
    Side side_;
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;
    
public:
    
};