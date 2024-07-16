#pragma once
#include <iostream>
#include <vector>

const double I = 10.0;
const std::vector<double> M = { 20, 75, 100, 105, 75, 0 };
const std::vector<double> V = { 0, 75, 150, 200, 250, 300 };
const double T_final = 110.0;
const double Hm = 0.01;
const double Hv = 0.0001;
const double C = 0.1;

class EngineClass
{
public:
	virtual ~EngineClass() = default;
protected:
	virtual void _engineHeating(const double& m_value, const double& v_value) = 0;
	virtual void _engineCooling() = 0;
	virtual void _engineTemperature(const double& time_step, const double& m_value, const double& v_value) = 0;
	virtual void _enginePover(const double& m_value, const double& v_value) = 0;
	virtual void _engineAcceleration(const double& time_step) = 0;
};

class DVS : public EngineClass
{
public:
	DVS(const double& t_global);
	double getT_actual() const;
	double geta() const;
	double getN() const;
	double getSpeed() const;
	void runDVS(const double& time_step);

protected:
	void _engineHeating(const double& m_value, const double& v_value) override;
	void _engineCooling() override;
	void _engineTemperature(const double& time_step, const double& m_value, const double& v_value) override;
	void _enginePover(const double& m_value, const double& v_value) override;
	void _engineAcceleration(const double& time_step) override;

private:
	double __interpolateM(double v);
	
	double __T_actual = 0;
	double __Vh = 0;
	double __Vc = 0;
	double __a = 0;
	double __N = 0;
	double __speed = 0;
	double __position = 0;
	double __t_global = 0;
};

