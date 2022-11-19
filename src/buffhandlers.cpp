//
// Created by BVT.MI on 16.10.2022.
//

#include "buffhandlers.h"
#include <unistd.h>

namespace bvt {

    IBulkHandlerPtr StaticBulkHandler::push(const std::string &cmd) {

        if (commands.empty()) {
            std::time_t result = std::time(nullptr);
            name_time = std::to_string(result);
        }
        sleep(1);



        commands.push_back(cmd);
        std::cout << "s-push"  << cmd << ", time =" << name_time << ", size = " << commands.size() << ", capacity = " << commands.capacity() << std::endl;

        if (commands.size() >= commands.capacity()) {
             return IBulkHandlerPtr{new StaticBulkHandler(commands.capacity())};
        } else
             return nullptr; // TODO: Посмотреть nullptr на занятиях
    };

    IBulkHandlerPtr DynamicBulkHandler::push(const std::string &cmd) {

        if (commands.empty()) {
            std::time_t result = std::time(nullptr);
            name_time = std::to_string(result);
        }
        sleep(1);

        commands.push_back(cmd);
        std::cout << "push"  << cmd << ", time =" << name_time << ", size = " << commands.size() << ", capacity = " << commands.capacity() << std::endl;

        if (commands.size() >= commands.capacity()) {
            return IBulkHandlerPtr{new StaticBulkHandler(commands.capacity())};
        } else
            return nullptr; // TODO: Посмотреть nullptr на занятиях
    };


};