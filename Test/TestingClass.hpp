#pragma once
#include <iostream>
#include "EngineClass.hpp"
class TestingClass
{
public:
    virtual void startTest(const double& time_step, const double& max_time) = 0;
    virtual ~TestingClass() = default;
};

class Test1 : public TestingClass
{
public:
    Test1(const double& t_global);
    void startTest(const double& time_step, const double& max_time) override;
private:
    double __t_global;
    DVS __test_DVS;
};

class Test2 : public TestingClass
{
public:
    Test2(const double& t_global);
    void startTest(const double& time_step, const double& max_time) override;
private:
    double __t_global;
    DVS __test_DVS;

};
