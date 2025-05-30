#pragma once
#include "Material.h"
#include <string>
#include <deque>

struct Brigade {
    int number;
    std::string foreman;
    std::deque<Material> materials;

    double totalCost() const {
        double total = 0;
        for (const auto& m : materials)
            total += m.cost;
        return total;
    }
};
