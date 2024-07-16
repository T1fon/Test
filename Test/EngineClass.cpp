#include "EngineClass.hpp"


DVS::DVS(const double& t_global)
{
    __T_actual = t_global;
    __t_global = t_global;
}
void DVS::_engineHeating(const double& m_value, const double& v_value)
{
    __Vh = m_value * Hm + pow(v_value, 2) * Hv;
}
void DVS::_engineCooling()
{
    __Vc = C * (__t_global - __T_actual);
}

void DVS::_engineTemperature(const double& time_step, const double& m_value, const double& v_value)
{
    _engineHeating(m_value, v_value);
    _engineCooling();

    __T_actual += (__Vh - __Vc) * time_step;
}
void DVS::_enginePover(const double& m_value, const double& v_value)
{
    __N = m_value * v_value / 1000;
}

double DVS::__interpolateM(double v) 
{
    if (v <= V.front()) return M.front();
    if (v >= V.back()) return M.back();

    auto it = std::lower_bound(V.begin(), V.end(), v);
    int idx = it - V.begin();
    double v1 = V[idx - 1], v2 = V[idx];
    double m1 = M[idx - 1], m2 = M[idx];

    return m1 + (m2 - m1) * (v - v1) / (v2 - v1);
}

void DVS::_engineAcceleration(const double& time_step)
{
    __a = __interpolateM(__speed) / I;
    __speed += __a * time_step;
    __position += __speed * time_step;
}

void DVS::runDVS(const double& time_step)
{
    double m_value = __interpolateM(__speed);
    _engineTemperature(time_step, m_value, __speed);
    _enginePover(m_value, __speed);
    _engineAcceleration(time_step);
}

double DVS::getT_actual() const { return __T_actual; }
double DVS::geta() const { return __a; }
double DVS::getN() const { return __N; }
double DVS::getSpeed() const{ return __speed; }

