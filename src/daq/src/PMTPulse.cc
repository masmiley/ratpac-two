#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <RAT/PMTPulse.hh>
#include <RAT/Log.hh>
#include <TMath.h>

namespace RAT {

double PMTPulse::GetPulseHeight(double utime){

  double height = 0.0;
  double start_time = fStartTime + fPulseTimeOffset;
  double delta_t = utime - start_time;

  if (delta_t > 0.0) {
    height = fPulseOffset - (fPulseCharge*TMath::LogNormal(delta_t, fPulseWidth, 0., fPulseMean));
  }
  if(abs(height) < fPulseMin){
    height = 0;
  }

  return height;
}

} // namespace RAT
