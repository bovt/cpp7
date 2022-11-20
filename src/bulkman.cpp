//
// Created by BVT.MI on 16.10.2022.
//

#include "bulkman.h"
#include <iostream>

namespace bvt {

    void BulkMan::subscribe(Observer *obs) {
        m_subs.push_back(obs);
    }

    std::string BulkMan::getBulkOutput() {
        return currentBulk->output();
    }

    std::string BulkMan::getBulkName() {
        return currentBulk->name();
    }

    void BulkMan::notify() {
        for (auto s: m_subs) {
            s->update(getBulkOutput(), getBulkName());
        }
    }

    void BulkMan::newString(const std::string &input) {
        IBulkHandlerPtr newstate = currentBulk->push(input);
        if (newstate) {
            if (currentBulk->output() != "") { notify(); }
            currentBulk = std::move(newstate);
        };
    }

};