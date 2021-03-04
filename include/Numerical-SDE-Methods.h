#include "SDEs.h"

static void euler_murayama(double out[], int interval[2], int points, double x0, SDE sde);