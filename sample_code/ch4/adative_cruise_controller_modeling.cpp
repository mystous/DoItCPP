#include <iostream>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>

using namespace std;


const int dummy = 0;

class Engine {
private:
    virtual void acceleration_output() = 0;
    friend class Accelerator;
};

class ICEngine : public Engine {
private:
    virtual void acceleration_output() = 0;
};

class GSEngine : public ICEngine {
private:
    void acceleration_output() override { increasing_fuel(); };
    void increasing_fuel() { increasing_piston_speed(); };
    void increasing_piston_speed() {};
};

class ElecEngine : public Engine {
private:
    void acceleration_output() override { increasing_motor_speed(); };
    void increasing_motor_speed() {};
};

class Sensor {
public:
    int inquiring_range() { return dummy; };
    int inquiring_current_speed() { return dummy; };
};

class BreakSystem {
public:
    void pushing_break() {};
};

class Accelerator {
public:
    Accelerator(Engine& engine) : my_engine(engine) {};
    void acceleration_output() { my_engine.acceleration_output(); };
    void set_engine(Engine& engine) { my_engine = engine; };
private:
    Engine& my_engine;
};

class CruiseController {
public:
    CruiseController(Sensor& sensor, Accelerator& accelerator, BreakSystem& break_system) :
        my_sensor(sensor), my_accelerator(accelerator), my_break_system(break_system) {};
    void do_cruise();
    void stop_cruise() { keep_cruise = false; };
    void set_target_speed(int speed) { user_target_speed = speed; };
    void acceleration_adjusting(int target_speed, int current_speed);

private:
    int calculating_fit_speed(int range, int original_target_speed) { return dummy; };

    Sensor& my_sensor;
    Accelerator& my_accelerator;
    BreakSystem& my_break_system;
    
    int user_target_speed;
    int acceleration_adjusting_preriod;
    bool keep_cruise;
};

void CruiseController::do_cruise() {
    
    int range = dummy, current_speed = dummy;
    keep_cruise = true;

    while (keep_cruise) {
        range = my_sensor.inquiring_range();
        current_speed = my_sensor.inquiring_current_speed();
        acceleration_adjusting(calculating_fit_speed(range, current_speed), user_target_speed);
        Sleep(acceleration_adjusting_preriod);
    }
}

void CruiseController::acceleration_adjusting(int target_speed, int current_speed) {
    
    if (target_speed == current_speed) {
        return;
    }

    if (target_speed > current_speed) {
        my_accelerator.acceleration_output();
        return;
    }
    
    my_break_system.pushing_break();
}

class Car {
public:
    Car(Engine& engine, Sensor& sensor, BreakSystem& break_system, Accelerator& accelerator, CruiseController& cruise_controller) : 
        my_engine(engine), my_sensor(sensor), my_break_system(break_system), my_accelerator(accelerator), my_cruise_controller(cruise_controller) {};
    void do_cruise() { my_cruise_controller.do_cruise(); };
private:
    Engine& my_engine;
    Sensor& my_sensor;
    BreakSystem& my_break_system;
    Accelerator& my_accelerator;
    CruiseController& my_cruise_controller;
};

int main(int argc, char **argv) {
    
    GSEngine my_engine;
    Sensor my_sensor;
    BreakSystem my_break_system;
    Accelerator my_accelerator(my_engine);
    CruiseController my_cruise_controller(my_sensor, my_accelerator, my_break_system);
    Car my_car(my_engine, my_sensor, my_break_system, my_accelerator, my_cruise_controller);

    my_car.do_cruise();
    
    return 0;
}
