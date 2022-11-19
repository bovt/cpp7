//
// Created by BVT.MI on 16.10.2022.
//

#include "bulkman.h"
#include <unistd.h>
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
            std::cout << "bulk: " << currentBulk->output() << std::endl;
//            for (auto s : m_subs) {
//                s->update(currentBulk);
//            }
        }
    void BulkMan::newString(const std::string& input) {
        IBulkHandlerPtr newstate = currentBulk->push(input);
        if (newstate)
        {
            if (currentBulk->output() != "") { notify(); }
            currentBulk = std::move (newstate);
        };
    }

};