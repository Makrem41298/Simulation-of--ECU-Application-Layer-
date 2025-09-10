//
// Created by ABDERRAZEK on 7/31/2025.
//

#ifndef ECUSENSORDATA_H
#define ECUSENSORDATA_H

#include <list>
#include <optional> // for std::optional

#include <map>        // <== manquait
#include <iostream>   // <== manquait


class ECUSensorData {
public:
    inline static std::optional<float> EvaporatorTemp =std::nullopt;
    inline static std::optional<float> VIN = std::nullopt;
    inline static std::optional<bool> EvaporatorSensorOpenCircuit = std::nullopt;
    inline static std::optional<float> CabinTemperature = std::nullopt;
    inline static std::optional<float> BlowerCurrent = std::nullopt;
    inline static std::optional<float> sensorAirQuality=std::nullopt;
    inline static std::optional<float> SunSensorUpdated = std::nullopt;
    inline static std::optional<float> FlapMotorPosition = std::nullopt;
    inline static std::optional<float> FlapMotorTargetPosition = std::nullopt;
    inline static std::optional<float> fanSpeed =std::nullopt;


    static std::optional<float>  ReadSensorDataByKey(int code) {
        const std::map<int, std::optional<float>> sensorCode = {
            {0xF190, ECUSensorData::VIN},              // std::optional<float>
            {0x1234, ECUSensorData::EvaporatorTemp},
            {0x1235, ECUSensorData::CabinTemperature},
            {0x1236, ECUSensorData::fanSpeed},
            {0x1237, ECUSensorData::FlapMotorPosition},
        };
        std::optional<float> value ;
        if (auto it = sensorCode.find(code); it != sensorCode.end()) {
            if (it->second) {
                value = *it->second;
            } else {
                std::cout << "<no value>\n";          // optional is empty
            }
        } else {
            std::cout << "unknown code 0x" << std::hex << code << "\n";
        }
        return value;
    }

};

#endif //ECUSENSORDATA_H
