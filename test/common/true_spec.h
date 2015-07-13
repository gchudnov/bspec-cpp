#pragma once

#include "bspec/spec.h"

// TRUE spec is always true
class true_spec
  : public bspec::basic_spec<bool> {
public:
  true_spec* clone() const override {
    return new true_spec;
  }

  bool is_satisfied_by(const bool& candidate) const override {
    return true;
  }
};
