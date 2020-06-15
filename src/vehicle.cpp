#include <mylibrary/vehicle.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

using cinder::vec2;

namespace traffic_rush {
  Vehicle::Vehicle() {}

  void Vehicle::Initialize(b2World *this_world_, b2Vec2 start_p, b2Vec2 start_v) {
    float32 radius = 10;
    shape_.m_radius = Conversions::ToMeters(radius);

    b2BodyDef def_;
    def_.position.Set(start_p.x, start_p.y);
    shape_.m_p = b2Vec2(0, 0);

    vehicle_body_ = this_world_->CreateBody(&def_);

    b2FixtureDef fix_def_;
    fix_def_.density = 1.0f;
    fix_def_.shape = &shape_;
    fix_def_.restitution = 0.7f;
    vehicle_body_->CreateFixture(&fix_def_);
    vehicle_body_->SetType(b2_dynamicBody);

    double velocity = (rand() % vel_buffer) + vel_start;
    vehicle_body_->SetLinearVelocity(b2Vec2(start_v.x * velocity, start_v.y * velocity));

    color = Conversions::ColorChooser(-1);
    color = Conversions::ToCinderRBG(color);
  }

  void Vehicle::DrawVehicle() {
    cinder::gl::color(color[0], color[1], color[2]);
    b2Vec2 curr_loc = vehicle_body_->GetPosition();
    vec2 c_loc = vec2(traffic_rush::Conversions::ToPixels(curr_loc.x),
                      traffic_rush::Conversions::ToPixels(curr_loc.y));
    cinder::gl::drawSolidCircle(vec2(c_loc[0], c_loc[1]),
                                traffic_rush::Conversions::ToPixels(shape_.m_radius));
  }
}