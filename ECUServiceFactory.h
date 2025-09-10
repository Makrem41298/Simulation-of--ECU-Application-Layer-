// ECUServiceFactory.h
#ifndef ECUSERVICEFACTORY_H
#define ECUSERVICEFACTORY_H

#include <map>
#include <memory>

#include "ClearDiagnosticDTC.h"
#include "DIDReadService.h"
#include "DIDWriteService.h"
#include "DTCReadService.h"
#include "ECUService.h"
#include "RoutineService.h"

class ECUServiceFactory {
public:
    virtual ~ECUServiceFactory() = default;

    static std::unique_ptr<ECUService> handleRequest(int serviceId) {
        std::map<int, std::unique_ptr<ECUService> > services;
        services[0x19] = std::make_unique<DTCReadService>();
        services[0x14] = std::make_unique<ClearDiagnosticDTC>();
        services[0x31] = std::make_unique<RoutineService>();
        services[0x22] = std::make_unique<DIDReadService>();
        services[0x2E] = std::make_unique<DIDWriteService>();


        auto it = services.find(serviceId);
        if (it != services.end())
            return std::move(it->second);
        else
            return nullptr;
    }
};

#endif
