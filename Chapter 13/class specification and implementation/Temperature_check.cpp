#include "Temperature_check.h"

bool Temperature_check::is_ethanol_freezing() const
{
	if (temperature <= freeze_ethanol)
		return true;
	else
		return false;
}
bool Temperature_check::is_oxygen_freezing() const
{
	if (temperature <= freeze_oxygen)
		return true;
	else
		return false;
}
bool Temperature_check::is_water_freezing() const
{
	if (temperature <= freeze_water)
		return true;
	else
		return false;
}
bool Temperature_check::is_ethanol_boiling() const
{
	if (temperature >= boil_ethanol)
		return true;
	else
		return false;
}
bool Temperature_check::is_oxygen_boiling() const
{
	if (temperature >= boil_oxygen)
		return true;
	else
		return false;
}
bool Temperature_check::is_water_boiling() const
{
	if (temperature >= boil_water)
		return true;
	else
		return false;
}