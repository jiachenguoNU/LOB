#pragma once

#include "Order.hpp"
#include "Usings.hpp"
#include "OrderbookLevelInfos.hpp"
#include "Trade.hpp"
#include "OrderModify.hpp"
#include "LevelData.hpp"


#include <mutex>
#include <iostream>
#include <format>
#include <thread>
#include <atomic>
#include <map>
#include <unordered_map>
#include <condition_variable> //第一次见

class OrderBook
{
private:
    std::map<Price, LevelData> data_;
    std::map<Price, OrderPointers, std::greater<Price>> bids_;
    std::map<Price, OrderPointers, std::less<Price>> asks_;

    std::map<OrderID, OrderEntry> orders_;
    mutable std::mutex ordersMutex;                               //难道在const member fun要改吗
    std::thread ordersPruneThread;
    std::condition_variable shutdownConditionVariable;
    std::atomic<bool> shut_down{false};

    bool CanMatch(Side side, Price price) const;
    bool CanFullyFill(Side side, Price price, Quantity quantity) const;
    void PruneGoodForDayOrders();
    void CancelOrders(OrderIDs orderIDs);
    void CancelOrderInternal(OrderID orderID);   //为什么这个只cancel一个
    void OnOrderAdded(OrderPointer order);       //这个是不是因为add上后才能有orderID
    void OnCancelled(OrderPointer order);
    void OnMatched(Price price, Quantity quantity, bool isFullyFilled);   //这个为什么跟这些形参
    void UpdateLevelData(Price price, Quantity quantity, LevelData::Action action);


public:
    OrderBook(); //default constructor
    ~OrderBook();
    OrderBook(const OrderBook&) = delete;  //注意不返回，而且由于delete，没必要写形参名字
    OrderBook(OrderBook&&) = delete;

    OrderBook& operator=(const OrderBook&) = delete; //注意返回，且operator=(形参) syntax
    OrderBook& operator=(OrderBook&&) = delete;

    Trades AddOrder(OrderPointer); //这里return vector吗
    void CancelOrder(OrderID);
    Trades ModifyOrder(OrderModify); //这里直接传了一个class
    size_t Size() const;
    
    OrderbookLevelInfos GetOrderInfos() const;

};
