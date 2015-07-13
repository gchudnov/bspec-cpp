#pragma once

#include "bspec/spec.h"

// FALSE spec is always false
class false_spec
  : public bspec::basic_spec<bool> {
public:
  false_spec* clone() const override {
    return new false_spec;
  }

  bool is_satisfied_by(const bool& candidate) const override {
    return false;
  }
};
