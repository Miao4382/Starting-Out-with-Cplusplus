#include "team_leader.h"

/* Constructor */
// default constructor
TeamLeader::TeamLeader() : ProductionWorker()
{
  monthly_bonus_ = 0.0;
  annual_training_hour_required_ = 0;
  annual_training_hour_ = 0;
}
// constructor 
TeamLeader::TeamLeader(std::string n, std::string id, std::string date, int shift, double rate, double m_b, int t_h_r, int t_h) : ProductionWorker(n, id, date, shift, rate)
{
  monthly_bonus_ = m_b;
  annual_training_hour_required_ = t_h_r;
  annual_training_hour_ = t_h;  
}