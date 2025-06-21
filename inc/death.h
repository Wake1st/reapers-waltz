#ifndef DEATH
#define DEATH

#include <unordered_map>

typedef enum DeathTypes
{
  CRUSHED,
  SPIKED,
  PIT
} DeathTypes;

class Death
{
public:
  void add(DeathTypes deathType);
  bool allDead();

private:
  std::unordered_map<DeathTypes, bool> deaths;
};

void Death::add(DeathTypes deathType)
{
  deaths[deathType] = true;
}

bool allDead()
{
  return (
      (deaths[DeathTypes::CRUSHED]) &&
      (deaths[DeathTypes::SPIKED]) &&
      (deaths[DeathTypes::PIT]));
}

#endif
