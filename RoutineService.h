//
// Created by ABDERRAZEK on 7/30/2025.
//

#ifndef ROUTINESERVICE_H
#define ROUTINESERVICE_H
#include "ECUService.h"
#include "Routine.h"


class RoutineService:public ECUService{
    public:
    ~RoutineService() override = default;

   Response  handleResponseService(Payload payload) override {
       try {
           return   Routine::subFunctionRoutine(payload.functionCode.value(),payload.code.value()) ;
       }catch (const std::exception& e) {
           std::cout << e.what() << std::endl;
           return Response{std::nullopt,0x10}  ;
       }
    }

    
};



#endif
