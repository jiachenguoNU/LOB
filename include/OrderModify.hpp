#pragma once
#include "Side.hpp"
#include "OrderType.hpp"
#include "Usings.hpp"
#include "Order.hpp"


class OrderModify
{
private:
    OrderID orderID_;
    Price price_;
    Side side_;
    Quantity quantity_;

public:
    OrderModify(OrderID id, Side side, Price price, Quantity quantity): 
    orderID_{id}, side_{side}, price_{price}, quantity_(quantity){}

    OrderID GetOrderId() const { return orderID_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    Quantity GetQuantity() const { return quantity_; }

    OrderPointer ToOrderPointer(OrderType orderType) const
    {
        //Order newOrder = Order(orderType, orderID_, side_, price_, quantity_);
        OrderPointer newPointer = std::make_shared<Order>(orderType, orderID_, side_, price_, quantity_);
        return newPointer;
    }
};