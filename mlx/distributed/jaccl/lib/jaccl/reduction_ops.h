// Copyright © 2025 Apple Inc.

#pragma once

#include <cstddef>

#include "jaccl/types.h"

namespace jaccl {

template <typename T>
struct SumOp {
  void operator()(const T* input, T* output, size_t N) const {
    for (size_t i = 0; i < N; i++) {
      output[i] = output[i] + input[i];
    }
  }
};

template <typename T>
struct MaxOp {
  void operator()(const T* input, T* output, size_t N) const {
    for (size_t i = 0; i < N; i++) {
      output[i] = (output[i] > input[i]) ? output[i] : input[i];
    }
  }
};

template <typename T>
struct MinOp {
  void operator()(const T* input, T* output, size_t N) const {
    for (size_t i = 0; i < N; i++) {
      output[i] = (output[i] < input[i]) ? output[i] : input[i];
    }
  }
};

} // namespace jaccl
