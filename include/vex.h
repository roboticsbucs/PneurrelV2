#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#define waitUntil(condition)       \
  do                               \
  {                                \
    wait(5, vex::timeUnits::msec); \
  } while (!(condition))

#define repeat(iterations) \
  for (int iterator = 0; iterator < iterations; iterator++)

#define TRIPORTA triport{vex::PORT22}.A
#define TRIPORTB triport{vex::PORT22}.B
#define TRIPORTC triport{vex::PORT22}.C
#define TRIPORTD triport{vex::PORT22}.D
#define TRIPORTE triport{vex::PORT22}.E
#define TRIPORTF triport{vex::PORT22}.F
#define TRIPORTG triport{vex::PORT22}.G
#define TRIPORTH triport{vex::PORT22}.H
