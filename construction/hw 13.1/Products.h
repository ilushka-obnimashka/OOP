#ifndef PRODUCTS_H
#define PRODUCTS_H
#include <string>
#include <vector>

class House
{
private:
    std::vector<std::string> house_parts_;

public:
    void AddParts(std::string part)
    {
        house_parts_.push_back(part);
    }

    std::string PartsToString() const
    {
        std::string result = "Houses with parts: ";

        for (auto it = house_parts_.begin(); it != house_parts_.end(); ++it) {
            result += *it;
            if (std::next(it) != house_parts_.end()) {
                result += ", ";
            }
        }
        return result;
    }
};


class Documentation
{
private:
    std::vector<std::string> documentation_parts_;
public:
    void AddParts(std::string part)
    {
        documentation_parts_.push_back(part);
    }

    std::string PartsToString() const
    {
        std::string result = "Documentation with parts: ";

        for (auto it = documentation_parts_.begin(); it != documentation_parts_.end(); ++it) {
            result += *it;
            if (std::next(it) != documentation_parts_.end()) {
                result += ", ";
            }
        }
        return result;
    }
};

#endif //PRODUCTS_H
