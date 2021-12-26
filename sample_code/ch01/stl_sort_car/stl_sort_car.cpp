#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::map<std::string, int> color_priority;
std::map<std::string, int> model_priority;

const std::string white_color("흰색");
const std::string blue_color("파란색");
const std::string red_color("빨간색");
const std::string gray_color("회색");

const std::string grace_model("고급 모델");
const std::string soft_model("부드러운 모델");
const std::string young_model("젋은 모델");
const std::string generation_model("세대 모델");
const std::string beautiful_model("미적 모델");

const std::string new_gen_brand("신식 회사");
const std::string elec_brand("전기 발명가");

class car_model {
public:
  car_model(std::string brand, std::string model, std::string color)
    : brand_name(brand), model_name(model), color_name(color)
  {};

  std::string get_brand() { return brand_name; };
  std::string get_model() { return model_name; };
  std::string get_color() { return color_name; };

private:
  std::string brand_name;
  std::string model_name;
  std::string color_name;
};

void init_car_list(std::vector<car_model>& car_list)
{
  car_list.push_back(car_model(new_gen_brand, beautiful_model, white_color));
  car_list.push_back(car_model(new_gen_brand, grace_model, white_color));
  car_list.push_back(car_model(new_gen_brand, generation_model, gray_color));
  car_list.push_back(car_model(elec_brand, soft_model, red_color));
  car_list.push_back(car_model(elec_brand, young_model, blue_color));
}

void init_color_priority()
{
  color_priority[white_color] = 1;
  color_priority[blue_color] = 3;
  color_priority[red_color] = 4;
  color_priority[gray_color] = 2;
}

void init_model_priority()
{
  model_priority[grace_model] = 1;
  model_priority[soft_model] = 5;
  model_priority[young_model] = 2;
  model_priority[generation_model] = 4;
  model_priority[beautiful_model] = 3;
}

void print_car_list(std::vector<car_model>& car_list)
{
  for (auto& car : car_list) {
    std::cout << "[" << car.get_brand() << "] 회사의 "
      << "\"" << car.get_model() << "\" 은 "
      << "'" << car.get_color() << "'입니다."
      << std::endl;
  }
  std::cout << std::endl;
}

bool compare_color(car_model car_1, car_model car_2)
{
  return color_priority[car_1.get_color()] < color_priority[car_2.get_color()];
}

bool compare_model(car_model car_1, car_model car_2)
{
  return model_priority[car_1.get_model()] < model_priority[car_2.get_model()];
}
int main(void)
{
  std::vector<car_model> car_list;

  init_color_priority();
  init_model_priority();
  init_car_list(car_list);
  print_car_list(car_list);

  std::sort(car_list.begin(), car_list.end(), compare_color);
  print_car_list(car_list);

  std::sort(car_list.begin(), car_list.end(), compare_model);
  print_car_list(car_list);

  std::sort(car_list.begin(), car_list.end(), compare_color);
  print_car_list(car_list);
    
  return 0;
}