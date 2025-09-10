//
// Created by ABDERRAZEK on 7/30/2025.
//

#ifndef ECUSERVICE_H
#define ECUSERVICE_H

#include <iomanip> // for std::hex
#include <list>
#include <optional>

struct Payload {
    std::optional<float> value;
    std::optional<int> code;
    std::optional<int> functionCode;
};
struct Response {
    std::optional<std::list<std::optional<int>>> values;
    std::optional<int> codeStatus;
};
class ECUService {
public:
    virtual ~ECUService() = default;
    virtual Response  handleResponseService(Payload payload) =0;

};



#endif //ECUSERVICE_H
