//
// Created by BVT.MI on 16.10.2022.
//

#ifndef CPP7_BUFFHANDLERS_H
#define CPP7_BUFFHANDLERS_H

#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class IBulkHandler {
public:
    IBulkHandler(size_t sz) { commands.reserve(sz); }

    auto push(const std::string& cmd);

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

using IBulkHandlerPtr =  std::unique_ptr<IBulkHandler>;



class StaticBulkHandler : public IBulkHandler {
public:
    IBulkHandlerPtr push(const std::string& cmd)  {
        if (commands.empty()) {
            std::time_t result = std::time(nullptr);
            name_time = std::to_string(result);
        }
        commands.push_back(cmd);
        if (commands.size() >= commands.max_size())
        {
            return nullptr; // TODO: наладить new StaticBulkHandler(commands.size());
        }
        else
            return nullptr; // TODO: Посмотреть nullptr на занятиях
    };
private:
    std::vector<std::string> commands;
    std::string name_time;
};

#endif //CPP7_BUFFHANDLERS_H
