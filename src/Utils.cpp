#include "../include/Utils.h"

bool isClose(double a, double b, double epsilon) {
    return std::fabs(a - b) < epsilon;
}
