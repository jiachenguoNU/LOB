/** 
 指定type的alias
*/

#pragma once

#include <vector>
#include <cstdint>

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderID = std::uint64_t;
using OrderIDs = std::vector<OrderID>;