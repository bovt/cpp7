//
// Created by BVT.MI on 16.10.2022.
//

#include "buffhandlers.h"
#include <unistd.h>

namespace bvt {

    IBulkHandlerPtr StaticBulkHandler::push(const std::string &cmd) {

        if (cmd == "{") {
            return IBulkHandlerPtr{new DynamicBulkHandler()};
        } else {
            if (commands.empty()) {
                sleep(1);
                std::time_t result = std::time(nullptr);
                name_time = std::to_string(result);
            }
            commands.push_back(cmd);
        };

        //       std::cout << "s-push"  << cmd << ", time =" << name_time << ", size = " << commands.size() << ", capacity = " << commands.capacity() << std::endl;

        if (commands.size() >= commands.capacity()) {
            return IBulkHandlerPtr{new StaticBulkHandler(commands.capacity())};
        } else
            return nullptr;
    };

    IBulkHandlerPtr DynamicBulkHandler::push(const std::string &cmd) {

        sleep(1);
        if (commands.empty()) {
            std::time_t result = std::time(nullptr);
            name_time = std::to_string(result);
            nesting_count++;
        }

        if (cmd == "{") { nesting_count++; }
        else {
            if (cmd == "}") { nesting_count--; }
            else {
                commands.push_back(cmd);
            }
        }

        //       std::cout << "d-push"  << cmd << ", time =" << name_time << ", size = " << commands.size() << ", capacity = " << commands.capacity() << ", capacity = " << output() << std::endl;

        if (!nesting_count) {
            return IBulkHandlerPtr{new StaticBulkHandler(commands.capacity())};
        } else {
            return nullptr;
        }
    };


};