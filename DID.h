// DID.h

#ifndef DID_H
#define DID_H
#include <map>
#include <iostream>
#include <optional>

#include "ECUSensorData.h"

enum class TypeAccess { Write, Read, WriteRead };

class DID {
public:
    inline static std::map<int, std::pair<std::optional<float>, TypeAccess>> DIDMap;

    DID(int code, TypeAccess accessType) {
        if (DIDMap.find(code) == DIDMap.end()) {
            DIDMap[code] = {std::nullopt, accessType};
        } else {
            std::cout << "DTC " << code << " already exists.\n";
        }
    }
    ~DID()=default;
    static std::optional<std::pair<std::optional<float>,TypeAccess>> getValue(int code) {
        auto it = DIDMap.find(code);

        if (it != DIDMap.end()) {

            if (!it->second.first.has_value()) {
                auto value=ECUSensorData::ReadSensorDataByKey(code);
                if (value.has_value()) {
                    return  std::make_pair(value.value(), it->second.second);
                }
                return  std::make_pair(std::nullopt, it->second.second);



            }


            return std::make_pair(it->second.first.value(), it->second.second);
        }
        return std::nullopt;

    }

    static void setDID(int code, float value) {
        auto it = DIDMap.find(code);
        if (it != DIDMap.end()) {
            it->second.first = value;
        } else {
            std::cout << "Error: DTC " << code << " does not exist. Cannot update.\n";
        }
    }
    static void resetAll() {
        DIDMap.clear();
        std::cout << "✅ All DIDs have been cleared.\n";
    }

    static void printAllDID() {
        for (const auto& [code, item] : DIDMap) {
            std::cout << "  - Code: " << code
                      << ", Value: " << item.first.value()
                      << ", Access: "
                      << (item.second == TypeAccess::Write ? "write" :
                          (item.second == TypeAccess::Read ? "read" :
                           "write and read"))
                      << "\n";
        }
    }
};

#endif // DID_H
