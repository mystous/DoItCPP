#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
  
using namespace std;

map<string, int> color_priority;
map<string, int> model_priority;

const string white_color("흰색");
const string blue_color("파란색");
const string red_color("빨간색");
const string gray_color("회색");

const string grace_model("고급 모델");
const string soft_model("부드러운 모델");
const string young_model("젋은 모델");
const string generation_model("세대 모델");
const string beautiful_model("미적 모델");

const string new_gen_brand("신식 회사");
const string elec_brand("전기 발명가");

class car_model {
public:
  car_model(string brand, string model, string color)
    : brand_name(brand), model_name(model), color_name(color) {
  };

  string get_brand() { return brand_name; };
  string get_model() { return model_name; };
  string get_color() { return color_name; };

private:
  string brand_name;
  string model_name;
  string color_name;
};

void init_color_priority() {
  color_priority[white_color] = 1;
  color_priority[blue_color] = 3;
  color_priority[red_color] = 4;
  color_priority[gray_color] = 2;
}

void print_car_list(vector<car_model>& car_list) {
  for (auto& car : car_list) {
    cout << "[" << car.get_brand() << "] 회사의 "
      << "\"" << car.get_model() << "\" 은 "
      << "'" << car.get_color() << "'입니다."
      << endl;
  }
  cout << endl;
}

bool compare_color(car_model car_1, car_model car_2) {
  return color_priority[car_1.get_color()] < color_priority[car_2.get_color()];
}

int main(void) {
  vector<car_model> car_list{ {new_gen_brand, beautiful_model, white_color},
                              {new_gen_brand, grace_model, white_color},
                              {new_gen_brand, generation_model, gray_color},
                              {elec_brand, soft_model, red_color},
                              {elec_brand, young_model, blue_color} };

  init_color_priority();
  print_car_list(car_list);

  sort(car_list.begin(), car_list.end(), compare_color);
  sort(car_list.begin(), car_list.end(), [](car_model car_1, car_model car_2) 
    { return color_priority[car_1.get_color()] < color_priority[car_2.get_color()]; }
  );
  print_car_list(car_list);

  return 0;
}