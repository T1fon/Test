#include "TestingClass.hpp"

Test1::Test1(const double& t_global): __t_global(t_global), __test_DVS(t_global){}

void Test1::startTest(const double& time_step, const double& max_time)
{
    for (double t = 0; t < max_time; t += time_step) 
    {
        __test_DVS.runDVS(t);
        if (__test_DVS.getT_actual() > T_final)
        {
            std::cout << "Time after begining " << t << "sec";
            break;
        }
    }
}

Test2::Test2(const double& t_global): __t_global(t_global), __test_DVS(t_global){}

void Test2::startTest(const double& time_step, const double& max_time)
{
    double n_max = 0;
    double speed = 0;
    for (double t = 0; t < max_time; t += time_step)
    {
        __test_DVS.runDVS(t);
        if (__test_DVS.getN() > n_max)
        {
            n_max = __test_DVS.getN();
            speed = __test_DVS.getSpeed();
        }
    }
    std::cout << "pover : " << n_max <<"KVt " << "; V " << speed << "r/sec";
}