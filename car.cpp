
#include "car.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_CARS 6

struct CarData{
  enum CarType type;
  int max_speed;
  double fill_level;
  double acceleration_rate;
  double speed;
  double lowest_acceleration_rate;
  double highest_acceleration_rate;
};

struct CarImplementation{
  enum Color color;
  struct CarData car_data;
  bool is_rented;
};

struct CarData aixam={AIXAM,45,16.0,0.0,0,-8.0,1.0};
struct CarData fiat_multipla={FIAT_MULTIPLA,170,65.0,0.0,0,-8.0,2.26};
struct CarData jeep={JEEP,196,80.0,0.0,0,-8.0,3.14};

struct CarImplementation aixam1={RED,aixam,false};
struct CarImplementation fiat_multipla1={GREEN,fiat_multipla,false};
struct CarImplementation fiat_multipla2={BLUE,fiat_multipla,false};
struct CarImplementation fiat_multipla3={ORANGE,fiat_multipla,false};
struct CarImplementation jeep1={SILVER,jeep,false};
struct CarImplementation jeep2={BLACK,jeep,false};

static Car car_park[]={&aixam1,&fiat_multipla1,&fiat_multipla2,&fiat_multipla3,&jeep1,&jeep2};

Car get_car(enum CarType type){
    for (int i = 0; i < NUMBER_OF_CARS; i++) {
    if((car_park[i]->car_data.type==type)&&(!car_park[i]->is_rented))
    {
        car_park[i]->is_rented = true;
        return car_park[i];
    }
  }
  return 0;
}

enum CarType get_type(Car car){
    return car->car_data.type;
}

enum Color get_color(Car car){
    return car->color;
}

double get_fill_level(Car car){
    return car->car_data.fill_level;
}

double get_acceleration_rate(Car car){
    return car->car_data.acceleration_rate;
}

int get_speed(Car car){
    if (car->car_data.speed-(int)car->car_data.speed>=.5) {
      return (int)car->car_data.speed+1;
    }
    return (int)car->car_data.speed;
}


void init(){
    for (int i = 0; i < NUMBER_OF_CARS; i++) {
    car_park[i]->is_rented = false;
    car_park[i]->car_data.speed= 0;
    car_park[i]->car_data.acceleration_rate = 0;
  }
}


void set_acceleration_rate(Car car, double acceleration_rate){
    if(acceleration_rate>=car->car_data.lowest_acceleration_rate
        && acceleration_rate<=car->car_data.highest_acceleration_rate)
      {
        car->car_data.acceleration_rate=acceleration_rate;
      }
      else if(acceleration_rate<car->car_data.lowest_acceleration_rate)
      {
        car->car_data.acceleration_rate=car->car_data.lowest_acceleration_rate;
      }
      else{
        car->car_data.acceleration_rate=car->car_data.highest_acceleration_rate;
      }
}
void accelerate(Car car){
    double temp = car->car_data.acceleration_rate * 3.6;
    if(temp + car->car_data.speed < car->car_data.max_speed)
    {
      car->car_data.speed+=temp;
    }else if(car->car_data.speed < car->car_data.max_speed){
      double difference = car->car_data.max_speed - car->car_data.speed;
      car->car_data.speed+=difference;
    }
  }
