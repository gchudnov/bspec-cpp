#pragma once

#include "bspec/spec.h"

// TRUE spec is always true
class true_spec
  : public bspec::basic_spec<bool> {
public:
  using spec_type = basic_spec<bool>;
  
  std::shared_ptr<spec_type> clone() const override {
    return std::make_shared<true_spec>();
  }

  bool is_satisfied_by(const bool& candidate) const override {
    return true;
  }
};
