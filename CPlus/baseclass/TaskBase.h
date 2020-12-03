#pragma once

#include <memory>

class CTaskBase
{
public:
    CTaskBase();
    virtual ~CTaskBase();

    virtual void DoWork();
};

typedef std::shared_ptr<CTaskBase> CTaskBasePtr;