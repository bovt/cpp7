//
// Created by BVT.MI on 16.10.2022.
//

#ifndef CPP7_BULKMAN_H
#define CPP7_BULKMAN_H

#include "bulkman.h"
#include "buffhandlers.h"
#include <list>

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

        virtual void subscribe(const std::shared_ptr<Observer>& obs) = 0;
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

        void subscribe(const std::shared_ptr<Observer>& obs) override;

        void notify();

        void theEnd() { notify(); };
    private:

        size_t bulkLimit; // Размер блока команд
        IBulkHandlerPtr currentBulk; // Текущий блок команд
        std::list<std::weak_ptr<bvt::Observer>> m_subs;
    };

    class Report : public Observer, public std::enable_shared_from_this<Report> {
    public:
        static std::shared_ptr<Report> create(Observable *obs) {
            return std::shared_ptr<Report>(new Report(obs));
        };

        void update(std::string bulkOutput, std::string bulkName) override;
        void letsSubscibe(Observable *obs)
        {
            obs->subscribe(shared_from_this());
        };
    private:
        Report(Observable *obs);

    };

    class UserInterface : public Observer, public std::enable_shared_from_this<UserInterface> {
    public:
        static std::shared_ptr<UserInterface> create(Observable *obs) {
            return std::shared_ptr<UserInterface>(new UserInterface(obs));
        };

        void update(std::string bulkOutput, std::string bulkName) override;

        void letsSubscibe(Observable *obs)
        {
            obs->subscribe(shared_from_this());
        };
    private:
        UserInterface(Observable *lang);
    };


} // bvt


#endif //CPP7_BULKMAN_H
