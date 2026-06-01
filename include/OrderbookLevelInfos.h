#pragma once

#include "LevelInfo.hpp"
class OrderbookLevelInfos
{
private:
    LevelInfos bids_;
    LevelInfos asks_;

public:
    //constructor
    OrderbookLevelInfos(LevelInfos newBids, LevelInfos newAsks): 
        bids_(std::move(newBids)),               //注意，传参是不拷贝的如果用&，但是这里的赋值如果直接给的话是需要拷贝的
        asks_(std::move(newAsks)) {}             //函数没有冒号
    
    
    const LevelInfos& GetBids() const {return bids_;}  //const member function
    const LevelInfos& GetAsks() const {return asks_;}  //而且返回const 引用，这样不但避免copy，也避免被外边改

};