//
// Created by BVT.MI on 04.11.2022.
//

#ifndef CMD7_BULK_H
#define CMD7_BULK_H

#pragma once

#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

/// @brief Класс предназначенный для хранения блоков команд
struct bulk {
public:
    bulk(size_t sz) { commands.reserve(sz); }

    bulk* push(const std::string& cmd)  {
        if (commands.empty()) {
            std::time_t result = std::time(nullptr);
            name_time = std::to_string(result);
        }
        commands.push_back(cmd);
        if (commands.size() >= commands.max_size())
        {
            return new bulk(commands.size());
        }
        else
            return nullptr; // TODO: Посмотреть nullptr на занятиях
    };
    std::string output() const {
        std::string res;
        std::for_each(commands.begin(), commands.end(), [&](const auto& a) {
            res += a + " ";
        });
        return res;
    };
    std::string name() const { return name_time;  };
    size_t size() const { return commands.size(); }
    void clear() { commands.clear(); name_time = ""; }
private:
    std::vector<std::string> commands;
    std::string name_time;
};




#endif //CMD7_BULK_H
