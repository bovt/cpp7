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
#include <iostream>

namespace bvt {

    class IBulkHandler {
    public:
        virtual std::unique_ptr<IBulkHandler> push(const std::string &cmd) = 0;

        std::string name() const { return name_time; };

        size_t size() const { return commands.size(); }

        std::string output() const {
            std::string res;
            std::for_each(commands.begin(), commands.end(), [&](const auto &a) {
                res += a + ", ";
            });
            if (res.length() > 1) {
                res.pop_back();
                res.pop_back();
            };
            return res;
        }

    protected:
        std::vector<std::string> commands;
        std::string name_time;
    };

    using IBulkHandlerPtr = std::unique_ptr<IBulkHandler>;


    class StaticBulkHandler : public IBulkHandler {
    public:
        StaticBulkHandler(size_t sz) {
            commands.reserve(sz);
        };

        IBulkHandlerPtr push(const std::string &cmd);
    };

    class DynamicBulkHandler : public IBulkHandler {
    public:
        IBulkHandlerPtr push(const std::string &cmd);

    private:
        int nesting_count = 0;
    };


};


#endif //CPP7_BUFFHANDLERS_H
