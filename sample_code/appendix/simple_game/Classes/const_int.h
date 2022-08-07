#pragma once

constexpr int move_step_offset = 10;
constexpr int move_step_car_offset = 30;
constexpr int move_step_motor_cycle_offset = 20;
constexpr int move_step_horse_offset = 15;
constexpr int move_interval = 0.5;
constexpr int bullet_speed = 900;
constexpr float move_frequency = 0.02f;
constexpr int menu_margin = 10;

enum class riding_menu_id : int { riding_unselect, riding_obj_car, riding_obj_motor_cycle, riding_obj_horse};