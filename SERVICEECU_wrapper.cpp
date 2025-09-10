
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "DID.h"
#include "ECUServiceFactory.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define u_1_width 1
#define u_2_width 1
#define u_3_width 1
#define u_4_width 1
#define u_5_width 1
#define u_6_width 1
#define u_7_width 1
#define u_8_width 1
#define u_9_width 1
#define u_10_width 1
#define u_11_width 1
#define u_12_width 1
#define u_13_width 1
#define u_14_width 1
#define y_width 10
#define y_1_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
 static double lastValueCabineTemp;
            static double lastChangeTimeCabineTemp;

            static double lastChangeFlapPosition;
            static double lastValueFlapPosition;
            
            
            static double lastValueSunSensor ;
            static double lastChangeTimeSunSensor ;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void SERVICEECU_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
     static DTC dtc1(0xB10001);
    static DTC dtc2(0xB10002);
    static DTC dtc3(0xB10003);
    static DTC dtc4(0xB10004);
    static DTC dtc5(0xB10005);
    static DTC dtc6(0xB10006);

    static DID did1(0xF190, TypeAccess::Read);
    static DID did2(0x1234, TypeAccess::WriteRead);
    static DID did3(0x1235, TypeAccess::Read);
    static DID did4(0x1236, TypeAccess::WriteRead);
    static DID did5(0x1237, TypeAccess::Read);

    static Routine routine1(0x0201);
    static Routine routine2(0x0202);
    static Routine routine3(0x0203);
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void SERVICEECU_Outputs_wrapper(const real_T *sensorCabineTemp,
			const real_T *targetPosition,
			const real_T *FlapMotorPosition,
			const real_T *sensorSun,
			const real_T *blowerMotorCurrent,
			const real_T *sensorAirQuality,
			const int32_T *evaporatorSensorOpenCircuit,
			const real_T *evaporatorTemp,
			const real_T *fanSpeed,
			const int32_T *VIN,
			const real_T *time,
			const real_T *value,
			const int32_T *functionCode,
			const int32_T *code,
			const int32_T *serviceId,
			int32_T *response,
			int32_T *responseStatusCode)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
     double t = *time; 
   ECUSensorData::fanSpeed=static_cast<float>(*fanSpeed);
   ECUSensorData::VIN=static_cast<float>(*VIN);
   ECUSensorData::CabinTemperature=static_cast<float>(*sensorCabineTemp);
if (ECUSensorData::CabinTemperature.value()!= lastValueCabineTemp) {
  if (DTC::getBitStatusDTC(0xB10002).value()== DTC::StatusBit::active_memory)
            DTC::setStatus(0xB10002, DTC::StatusBit::unactive_memory);
  
    lastValueCabineTemp = ECUSensorData::CabinTemperature.value();
    lastChangeTimeCabineTemp = t;
}

if ((t - lastChangeTimeCabineTemp) >= 10.0) {
    DTC::setStatus(0xB10002, DTC::StatusBit::active_memory);
} 

/////
ECUSensorData::FlapMotorPosition= static_cast<float>(*FlapMotorPosition);
ECUSensorData::FlapMotorTargetPosition= static_cast<float>(*targetPosition);

if (ECUSensorData::FlapMotorTargetPosition.value()==DID::getValue(0x1237).value().first) {
       if (DTC::getBitStatusDTC(0xB10006).value()== DTC::StatusBit::active_memory)
            DTC::setStatus(0xB10006, DTC::StatusBit::unactive_memory);
    lastChangeFlapPosition = t;
}

if ((t - lastChangeFlapPosition) >= 2.0) {
    DTC::setStatus(0xB10006, DTC::StatusBit::active_memory);
} 




////
    ECUSensorData::SunSensorUpdated= static_cast<float>(*sensorSun);


if (ECUSensorData::SunSensorUpdated.value()!= lastValueSunSensor) {
       if (DTC::getBitStatusDTC(0xB10005).value()== DTC::StatusBit::active_memory)
            DTC::setStatus(0xB10005, DTC::StatusBit::unactive_memory);
    lastValueSunSensor = ECUSensorData::SunSensorUpdated.value();
    lastChangeTimeSunSensor = t;
}

if ((t - lastChangeTimeSunSensor) >= 5.0) {
    DTC::setStatus(0xB10005, DTC::StatusBit::active_memory);
} 


//

   ECUSensorData::BlowerCurrent= static_cast<float>(*blowerMotorCurrent);
if (ECUSensorData::BlowerCurrent.value()> 15.0f) {
    DTC::setStatus(0xB10003, DTC::StatusBit::active_memory);
}else  if (DTC::getBitStatusDTC(0xB10003).value()== DTC::StatusBit::active_memory)
            DTC::setStatus(0xB10003, DTC::StatusBit::unactive_memory);
//

ECUSensorData::sensorAirQuality=static_cast<float>(*sensorAirQuality);

if (!ECUSensorData::sensorAirQuality.has_value()) {
    DTC::setStatus(0xB10004, DTC::StatusBit::active_memory);
} else  if (DTC::getBitStatusDTC(0xB10004).value()== DTC::StatusBit::active_memory)
            DTC::setStatus(0xB10004, DTC::StatusBit::unactive_memory);
    
    //
ECUSensorData::EvaporatorSensorOpenCircuit=static_cast<bool>(*evaporatorSensorOpenCircuit);
ECUSensorData::EvaporatorTemp=static_cast<float>(*evaporatorTemp);
  
 if (DID::getValue(0x1234).value().first< -40.0f) {
    DTC::setStatus(0xB10001, DTC::StatusBit::active_memory);
    }else  if (DTC::getBitStatusDTC(0xB10001)== DTC::StatusBit::active_memory)
            DTC::setStatus(0xB10001, DTC::StatusBit::unactive_memory);


    
      Payload payload;



    payload.value = static_cast<float>(*value);
    payload.code = static_cast<int>(*code);
    payload.functionCode = static_cast<int>(*functionCode);



  

    // Get the service
    auto service = ECUServiceFactory::handleRequest(*serviceId);

    
   std::fill(response, response + 10, static_cast<int8_T>(-1));
    *responseStatusCode = -1;
    // Initialize outputs to default values
    for (int i = 0; i < 10; ++i) {
        response[i] = -1;   // -1 means "no data"
    }
    

    if (service) {
        Response res = service->handleResponseService(payload);

        // Fill response values (up to 10)
        if (res.values.has_value()) {
            int idx = 0;
            for (const auto &v : res.values.value()) {
                if (idx >= 10) break; // avoid overflow
                response[idx] = v.has_value() ? static_cast<int8_T>(v.value())
                                              : -1; // missing value
                ++idx;
            }
        }
    
      if (res.codeStatus.has_value()) {
            *responseStatusCode = static_cast<int8_T>(res.codeStatus.value());
        
    } 
    
    }else {
        *responseStatusCode = 0x11; // Pas de service trouvé
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


