#pragma once

#include "TradeInfo.hpp"
#include <vector>

class Trade
{
private:
    TradeInfo bidTrade_;
    TradeInfo askTrade_;

public:
    Trade(TradeInfo newbid, TradeInfo newask):
        bidTrade_(std::move(newbid)), askTrade_(std::move(newask)) {}
    
    const TradeInfo& GetBidTrade() const {return bidTrade_;}
    const TradeInfo& GetAskTrade() const {return askTrade_;}

};


using Trades = std::vector<Trade>;