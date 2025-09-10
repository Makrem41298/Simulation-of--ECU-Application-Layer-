//
// Created by ABDERRAZEK on 7/31/2025.
//

#ifndef DTCREADSERVICE_H
#define DTCREADSERVICE_H


#include "ECUSensorData.h"
#include "ECUService.h"
#include <chrono>
#include <cmath>
#include <thread>  // for sleep_for
#include <cstdlib> // for rand()
#include <ctime>
#include <optional>
#include <iostream>
#include <thread>

using namespace std::chrono;
using namespace std;


class DTCReadService : public ECUService {
public:
    ~DTCReadService() override = default;


   Response handleResponseService(Payload payload) override {
       try {

           return  Response {DTC::getListActiveDTC(),0x00} ;

       } catch (std::exception& e) {
           std::cout << e.what() << std::endl;
           return Response{std::nullopt, 0x10};


       }

    }


       inline  static void  runDTCSensor() {
         
        
    


       }







 
};

#endif // DTCREADSERVICE_H
