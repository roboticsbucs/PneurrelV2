#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"


#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

#define TRIPORTA triport{vex::PORT22}.A
#define TRIPORTA triport{vex::PORT22}.B
#define TRIPORTA triport{vex::PORT22}.C
#define TRIPORTA triport{vex::PORT22}.D
#define TRIPORTA triport{vex::PORT22}.E
#define TRIPORTA triport{vex::PORT22}.F
#define TRIPORTA triport{vex::PORT22}.G
#define TRIPORTA triport{vex::PORT22}.H
