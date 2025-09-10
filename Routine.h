#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>
#include <vector>
#include <optional>

class Routine {
private:
    static void startRoutine() {
        std::cout << "start\n";
    }
    static void stopRoutine() {
        std::cout << "stop\n";
    }
    static void requestResults() {
        std::cout << "request result\n";
    }

public:
    inline static std::vector<std::optional<int>> RoutineMap;

    Routine(int code) {
        RoutineMap.emplace_back(code);
    }
    ~Routine() = default;

    static std::optional<int> getRoutine(int code) {
        for (const auto& item : RoutineMap) {
            if (item.has_value() && item.value() == code) {
                return code;
            }
        }
        return std::nullopt;
    }

    static Response subFunctionRoutine(const int subFunction, const int code) {
        if (code == 0x0201) {
            switch (subFunction) {
                case 0x01: startRoutine();
                    break;
                case 0x02: stopRoutine();
                    break;
                case 0x03: requestResults();
                    break;
                default: return Response{std::nullopt, 0x12};
                    break;
            }
            return Response{std::nullopt, 0x00};

        } else if (code == 0x0202) {
            if (subFunction == 0x01) {
                startRoutine();
                return Response{std::nullopt, 0x00};
            } else
                return Response{std::nullopt, 0x12};
        } else if (code == 0x0203) {
            switch (subFunction) {
                case 0x01: startRoutine();
                    break;
                case 0x02: stopRoutine();
                    break;
                default: return Response{std::nullopt, 0x12};
            }
            return Response{std::nullopt, 0x00};

        }

            return Response{std::nullopt, 0x31};
    }

    static void resetAll() {
        RoutineMap.clear();
        std::cout << "✅ All DIDs have been cleared.\n";
    }

    static void printAllRoutine() {
        for (size_t i = 0; i < RoutineMap.size(); ++i) {
            if (RoutineMap[i].has_value()) {
                std::cout << "Index=" << i << ", Value=" << *RoutineMap[i] << '\n';
            }
        }
    }
};

#endif // ROUTINE_H
