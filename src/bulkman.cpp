//
// Created by BVT.MI on 16.10.2022.
//

#include "bulkman.h"
#include <iostream>

namespace bvt {


    void BulkMan::subscribe(const std::shared_ptr<Observer>& obs) {
        m_subs.emplace_back(obs);
    }

    std::string BulkMan::getBulkOutput() {
        return currentBulk->output();
    }

    std::string BulkMan::getBulkName() {
        return currentBulk->name();
    }

    void BulkMan::notify() {
       auto iter = m_subs.begin();
        while (iter != m_subs.end()) {
            auto ptr = iter->lock();
            if (ptr) {
                ptr->update(getBulkOutput(), getBulkName());
                ++iter;
            } else {
                m_subs.erase(iter++);
            }
        }
    }

    void BulkMan::newString(const std::string &input) {
        IBulkHandlerPtr newstate = currentBulk->push(input);
        if (newstate) {
            if (!currentBulk->output().empty()) { notify(); }
            currentBulk = std::move(newstate);
        };
    }

};