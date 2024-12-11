#pragma once
#include <iomanip>
#include <string>
#include <sstream>

class stringConvertible {
public:
    virtual std::string toString() const = 0;
    virtual ~stringConvertible() = default;

    static std::string formatDouble(double value)  {
        std::string result = std::to_string(value);
        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] == '.') {
                if(result[i + 1] == '0')
                    result = result.substr(0, i);
                else if(result[i + 1] != '0' && result[i + 2] == '0')
                    result = result.substr(0, i);
                else
                    result = result.substr(0, i + 3);
                
                break;
            }
            if (result[i] != '0') {
                result = result.substr(0, i + 1);
                break;
            }
        }

        return result;
    }
};