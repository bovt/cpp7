//
// Created by BVT.MI on 16.10.2022.
//

#ifndef CPP7_BULKMAN_H
#define CPP7_BULKMAN_H

#include "bulk.h"
#include "bulkman.h"
#include "buffhandlers.h"
#include <vector>




namespace bvt {
    class Observer {
    public:
        virtual ~Observer() = default;

        virtual void update(const bulk& b) = 0;
    };

    class Observable {
    public:
        virtual ~Observable() = default;

        virtual void subscribe(bvt::Observer* obs) = 0;
    };

    class BulkMan : public Observable {
    public:
        BulkMan(size_t sz) : bulkLimit(sz) {
            currentBulk = std::move(IBulkHandlerPtr{new StaticBulkHandler(sz)});
// TODO:            subs.push_back(std::make_unique<printer>());
// TODO:            subs.push_back(std::make_unique<filer>());
        }
        size_t getBulkSize() const {return currentBulk->size(); }
        std::string getBulkOutput() const {return currentBulk->output(); }
        void newString(const std::string& input);
        void subscribe(bvt::Observer *obs) override;
        void set_language(); // TODO: Убрать (здесь пока что только notify живёт)
        void notify();
    private:
//        Language m_lang{Language::ru};
        size_t bulkLimit; //< Размер блока команд
        IBulkHandlerPtr currentBulk; //< Текущий блок команд
        std::vector<bvt::Observer *> m_subs;
    };

    class Report : public Observer {
    public:
        Report(Observable *lang);

        void update(const bulk& b) override;
    };

    class UserInterface : public Observer {
    public:
        UserInterface(Observable *lang);

        void update(const bulk& b) override;
    };


} // bvt


#endif //CPP7_BULKMAN_H
