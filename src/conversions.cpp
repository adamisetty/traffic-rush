#include <mylibrary/conversions.h>

namespace traffic_rush {

  float32 traffic_rush::Conversions::ToPixels(float32 b2_number) {
    return b2_number * 50.0f;
  }

  float32 traffic_rush::Conversions::ToMeters(float32 cinder_number) {
    return cinder_number * 0.02;
  }

  vector<double> Conversions::ColorChooser(int position) {
    //Specific RBG values of colors that form a pastel color scheme
    vector<vector<double>> colors{{197, 113, 227}, {193, 179, 215},
                                  {165, 137, 193}, {227, 113, 172}, {251, 182, 209}, {249, 140, 182},
                                  {113, 200, 227}, {154, 206, 233}, {111, 183, 214}, {191, 213, 232},
                                  {148, 168, 208}, {117, 137, 191}, {113, 227, 132}, {181, 255, 174},
                                  {145, 210, 144}, {109, 180, 201}, {134, 207, 190}, {72, 181, 163},
                                  {191, 228, 118}, {133, 202, 93}};
    size_t num_colors = 20;

    //returns specific color if a valid index is provided
    if (position >= 0 && position < num_colors) {
      return colors[position];
    } else{
      unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
      std::default_random_engine generator(seed);
      std::uniform_int_distribution<int> distributionInteger(0, num_colors - 1);
      size_t pos = distributionInteger(generator);
      return colors[pos];
    }
  }

  vector<double> Conversions::ToCinderRBG(vector<double> regular_RBG) {
    //cinder color function uses 1/255 ratio for RBG values
    double converter = 255;
    for (size_t i = 0; i < regular_RBG.size(); i++) {
      regular_RBG[i] = regular_RBG[i]/converter;
    }
    return regular_RBG;
  }
}