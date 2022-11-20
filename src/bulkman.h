//
// Created by BVT.MI on 16.10.2022.
//

#ifndef CPP7_BULKMAN_H
#define CPP7_BULKMAN_H

#include "bulkman.h"
#include "buffhandlers.h"
#include <vector>

namespace bvt {
    class Observer {
    public:
        virtual ~Observer() = default;

        virtual void update(std::string bulkOutput, std::string bulkName) = 0;
    };

    class Observable {
    public:
        virtual ~Observable() = default;

        virtual std::string getBulkOutput() = 0;

        virtual std::string getBulkName() = 0;

        virtual void subscribe(bvt::Observer *obs) = 0;
    };

    class BulkMan : public Observable {
    public:
        BulkMan(size_t sz) : bulkLimit(sz) {
            currentBulk = std::move(IBulkHandlerPtr{new StaticBulkHandler(sz)});
        }

        size_t getBulkSize() const { return currentBulk->size(); }

        std::string getBulkOutput() override;

        std::string getBulkName() override;

        void newString(const std::string &input);

        void subscribe(bvt::Observer *obs) override;

        void notify();

        void theEnd() { notify(); };
    private:

        size_t bulkLimit; // Размер блока команд
        IBulkHandlerPtr currentBulk; // Текущий блок команд
        std::vector<bvt::Observer *> m_subs;
    };

    class Report : public Observer {
    public:
        Report(Observable *lang);

        void update(std::string bulkOutput, std::string bulkName) override;
    };

    class UserInterface : public Observer {
    public:
        UserInterface(Observable *lang);

        void update(std::string bulkOutput, std::string bulkName) override;
    };


} // bvt


#endif //CPP7_BULKMAN_H
