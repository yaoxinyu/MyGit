#pragma once

class IModule
{
public:
    IModule() {}
    virtual ~IModule() {}

    virtual bool Start(void) = 0;
    virtual bool Stop(void) = 0;
};