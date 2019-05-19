#ifndef TEAM_LEADER_H
#define TEAM_LEADER_H
#include "production_worker.h"

class TeamLeader : public ProductionWorker
{
private:
  double monthly_bonus_;
  int annual_training_hour_required_;
  int annual_training_hour_;
public:
  /* Constructor */
  // default constructor
  TeamLeader();
  // constructor 
  TeamLeader(std::string n, std::string id, std::string date, int shift, double rate, double m_b, int t_h_r, int t_h);
  
  /* Accessor */
  double monthly_bonus() const 
  { return monthly_bonus_; }
  int annual_training_hour_required() const 
  { return annual_training_hour_required_; }
  int annual_training_hour() const 
  { return annual_training_hour_; }
  
  /* Mutator */
  void set_monthly_bonus(double m_b)
  { monthly_bonus_ = m_b; }
  void set_required_training_hour(int t_h_r)
  { annual_training_hour_required_ = t_h_r; }
  void set_training_hour(int t_h)
  { annual_training_hour_ = t_h; }
};


#endif