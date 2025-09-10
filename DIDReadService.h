// DIDReadService.h

#ifndef DIDREADSERVICE_H
#define DIDREADSERVICE_H

#include <list>
#include <optional>
#include <iostream>
#include "ECUService.h"
#include "DID.h"

class DIDReadService : public ECUService {
public:
    ~DIDReadService() override = default;

    Response handleResponseService(Payload payload) override {
        try {
            std::list<std::optional<int> > response;

            if (!payload.code.has_value()) {
                std::cout << " No DID code provided.\n";
                response.emplace_back(std::nullopt);
                return Response{std::nullopt, 0x13};
            }
            int code = payload.code.value();

            auto entryOpt = DID::getValue(code);
            if (!entryOpt.has_value()) {
                std::cout << " DID 0x" << code << " not found.\n";
                response.emplace_back(std::nullopt);
                return Response{std::nullopt, 0x31};
            }

            auto [value, access] = *entryOpt;
            if (access == TypeAccess::Read || access == TypeAccess::WriteRead) {
                if (value.has_value()) {
                    std::cout << "Read DID 0x" << std::hex << code << ": " << std::hex << value.value() << "\n";
                    response.emplace_back(value.value());
                    return Response{response, 0x00};
                } else {
                    response.emplace_back(std::nullopt);
                    return Response{std::nullopt, 0x22};
                }
            } else {
                std::cout << "DID 0x" << std::hex << code << " is not readable.\n";
                return Response{response, 0x31};
            }
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
            return Response{std::nullopt, 0x10};
        }
    }
};

#endif // DIDREADSERVICE_H
