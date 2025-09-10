//
// Created by ABDERRAZEK on 8/3/2025.
//

#ifndef CLEARDIAGNOSTICDTC_H
#define CLEARDIAGNOSTICDTC_H
#include "DTC.h"
#include "ECUService.h"
#include <list>


class ClearDiagnosticDTC : public ECUService {


    public:
    ClearDiagnosticDTC() = default;
    virtual ~ClearDiagnosticDTC() override = default;

    Response handleResponseService(Payload payload) override {
        try {
            std::list<std::optional<int>>  response;
            DTC::clearBitStatusDTC();
            std::cout<<"Clear Diagnostic DTC"<<std::endl;
            return Response{response,0x00};
        }catch (std::exception& e) {
            std::cout<<e.what()<<std::endl;
            return Response{std::nullopt,0x01};
        }

    }

};



#endif //CLEARDIAGNOSTICDTC_H
