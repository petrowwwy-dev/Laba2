#pragma once

class IPrintable {
public:
    virtual void printInfo() const = 0;

    virtual ~IPrintable() = default;
};
