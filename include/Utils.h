#include <algorithm>
#include <cmath>
#include <iterator>
#include <limits>

template <typename T>
bool isClose(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) {
  if constexpr (std::is_floating_point<T>::value) {
    return std::fabs(a - b) <= epsilon;
  } else {
    return std::abs(a - b) <= epsilon;
  }
}
