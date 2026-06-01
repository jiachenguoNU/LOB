#pragma once

#include "OrderType.hpp"
#include "Side.hpp"
#include "Usings.hpp"
#include "Constants.hpp"
#include <memory> //shared_ptr
#include <stdexcept> //throw
#include <format>

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
    Order(OrderType orderType, OrderID orderID, Side side, Price price, Quantity quantity):
    orderType_{orderType}, orderID_(orderID), side_(side), price_(price), initialQuantity_(quantity), remainingQuantity_(quantity){}

    Order(OrderID orderID, Side side, Quantity quantity): 
    Order(OrderType::Market, orderID, side, Constants::InvalidPrice, quantity) {}

    OrderID GetOrderId() const { return orderID_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    OrderType GetOrderType() const { return orderType_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const {return initialQuantity_ - remainingQuantity_; }
    bool IsFilled() const {return remainingQuantity_ == 0; }
    void Fill(Quantity quantity)
    {
        if (quantity > remainingQuantity_){
            throw std::logic_error(std::format("Order {} cannot be filled since it's larger than remaining\n", orderID_));
        }
        remainingQuantity_ = initialQuantity_ - quantity;
    }
    void ToGoodTillCancel(Price price){
        if (orderType_ != OrderType::Market){
            throw std::logic_error(std::format("Order {} can not because it works for martket type\n", orderID_)); 
        }

        price_ = price;
        orderType_ = OrderType::GoodTillCancel;
    }
};



using OrderPointer = std::shared_ptr<Order>;  //只是定义了这个类型的别名，并没有声明任何东西
using OrderPointers = std::vector<OrderPointer>;

struct OrderEntry
{
    OrderPointer order_{nullptr};
    OrderPointers::iterator  location_;
};