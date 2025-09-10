#include <map>
#include <iostream>
#include <list>

class DTC {
public:
    enum class StatusBit { unactive, active_memory, unactive_memory};

    inline static std::map<int, StatusBit> DTCMap;

    // Constructor: adds DTC if it doesn't already exist
    DTC(int code) {
        if (DTCMap.find(code) == DTCMap.end()) {
            DTCMap[code] = StatusBit::unactive;
        } else {
            std::cout << "DTC " << code << " already exists.\n";
        }
    }

    // Static method to modify status
    static void setStatus(int code, StatusBit status) {
        auto it = DTCMap.find(code);
        if (it != DTCMap.end()) {
            it->second = status;
        } else {
            std::cout << "DTC " << code << " not found.\n";
        }
    }
    static auto getListActiveDTC() {
        std::list<std::optional<int>>DTCActive;
        for (const auto& [code, status] : DTCMap) {
            if (status != StatusBit::unactive) {
                DTCActive.push_back(code);
            }
        }
        return DTCActive;
    }


    // Print all DTCs
    static void printAllDTC() {
        std::cout << "Liste des DTC :\n";
        for (const auto& [code, status] : DTCMap) {
            std::cout << "  - Code: " << code
                      << ", Statut: " << (status != StatusBit::unactive ? "actif" : "inactif")
                      << "\n";
        }
    }
    static void clearBitStatusDTC() {
        for (const auto& [code, status] : DTCMap) {
            if (status != StatusBit::unactive) {
                DTCMap[code] = StatusBit::unactive;
            }
        }

    }
    static std::optional<StatusBit>  getBitStatusDTC(int code) {
        auto it =DTCMap.find(code);
        if (it != DTCMap.end()) {
            return it->second;
        }
        return std::nullopt;
    }


    // Clear all DTCs
    static void clearAllDTC() {
        DTCMap.clear();
        std::cout << "Tous les DTC ont été effacés.\n";
    }
};
