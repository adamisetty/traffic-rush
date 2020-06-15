#ifndef FINALPROJECT_VEHICLE_H
#define FINALPROJECT_VEHICLE_H

#include <Box2D/Box2D.h>
#include <mylibrary/conversions.h>

#include <random>

const size_t num_positions = 4;
const size_t vel_buffer = 2;
const double vel_start = .5;

namespace traffic_rush {
  class Vehicle {
   public:
    Vehicle();

    // should set initial position and velocity
    void Initialize(b2World *this_world_, b2Vec2 start_p, b2Vec2 start_v);
    void DrawVehicle();

    //~Vehicle;

   private:
    b2CircleShape shape_;
    b2Body *vehicle_body_;
    vector<double> color;
  };
}
#endif  // FINALPROJECT_VEHICLE_H