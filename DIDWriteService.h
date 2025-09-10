//
// Created by ABDERRAZEK on 8/8/2025.
//

#ifndef DIDWRITESERVICE_H
#define DIDWRITESERVICE_H
#include <ios>
#include <iostream>
#include <list>
#include <optional>

#include "DID.h"
#include "ECUService.h"


class DIDWriteService : public ECUService {
public:
    ~DIDWriteService() override = default;

    Response handleResponseService (Payload payload) override {
        try {
            std::list<std::optional<int>> response;

            if (!payload.code.has_value()) {
                std::cout << " No DID code provided.\n";
                response.emplace_back(std::nullopt);
                return Response{std::nullopt,0x13};
            }

            int code = payload.code.value();
            float newValue = payload.value.value();
            auto entryOpt = DID::getValue(code);
            if (!entryOpt) {
                std::cout << " DID 0x" << code << " not found.\n";
                response.emplace_back(std::nullopt);
                return Response{std::nullopt,0x31};
            }

            auto [value, access] = *entryOpt;
            if (access == TypeAccess::WriteRead) {
                DID::setDID(code,newValue);
                std::cout << "Write DID 0x" << std::hex << code << ": " <<std::hex << newValue<< "\n";
                response.emplace_back(newValue);
                return Response{response,0x00} ;

            } else {
                std::cout << "DID 0x" << std::hex << code << " is not writeable.\n";
                return Response{response, 0x31};

            }


        }catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            return Response{std::nullopt,0x10};

        }

    }

};



#endif //DIDWRITESERVICE_H
