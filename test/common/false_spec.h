#pragma once

#include "bspec/spec.h"

// FALSE spec is always false
class false_spec
  : public bspec::basic_spec<bool> {
public:
  using spec_type = basic_spec<bool>;

  std::shared_ptr<spec_type> clone() const override {
    return std::make_shared<false_spec>();
  }

  bool is_satisfied_by(const bool& candidate) const override {
    return false;
  }
};
