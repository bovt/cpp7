//
// Created by BVT.MI on 16.10.2022.
//

#include "bulkman.h"
#include <iostream>

namespace bvt {

        void BulkMan :: subscribe(Observer *obs) {
            m_subs.push_back(obs);
        }

        void BulkMan :: set_language() {
            newString("sdfsdfasdf");
            notify();
        }

        void BulkMan :: notify() {
 //TODO: заменнить на умн указатель           for (auto s : m_subs) {
//TODO: заменнить на умн указатель                s->update(currentBulk);
//            }
        }
    void BulkMan::newString(const std::string& input) {
        IBulkHandlerPtr newstate = currentBulk->push(input);
        if (newstate)
        {
            notify();
            currentBulk = std::move (newstate);
        };
    }

};