#pragma once

#include <memory>

namespace bspec {

  template<typename T>
  class spec_holder;

  template<typename T>
  class not_spec;

  template<typename T>
  class and_spec;

  template<typename T>
  class or_spec;


  template<typename T>
  class basic_spec {
  public:
    using spec_type = basic_spec<T>;

  public:
    virtual ~basic_spec() {
    }

    virtual basic_spec* clone() const = 0;

  public:
    virtual bool is_satisfied_by(const T& candidate) const = 0;

  public:
    spec_holder<T> Not() {
      return spec_holder<T>(not_spec<T>(*this));
    }

    spec_holder<T> And(const spec_type& other) {
      return spec_holder<T>(and_spec<T>(*this, other));
    }

    spec_holder<T> Or(const spec_type& other) {
      return spec_holder<T>(or_spec<T>(*this, other));
    }
  };


  template<typename T>
  class spec_holder
    : public basic_spec<T> {
  public:
    using spec_type = typename basic_spec<T>::spec_type;

  private:
    std::shared_ptr<spec_type> value_;

  public:
    spec_holder(const spec_type& other)
      : value_(other.clone()) {
    }

    spec_type* clone() const override {
      return new spec_holder(*value_);
    }

  public:
    bool is_satisfied_by(const T& candidate) const override {
      return value_->is_satisfied_by(candidate);
    }
  };

  /**
  * NOT
  */
  template<typename T>
  class not_spec
    : public basic_spec<T> {
  public:
    using spec_type = typename basic_spec<T>::spec_type;

  private:
    std::shared_ptr<spec_type> wrapped_;

  public:
    not_spec(const spec_type& other)
      : wrapped_(other.clone()) {
    }

    spec_type* clone() const override {
      return new not_spec(*wrapped_);
    }

    bool is_satisfied_by(const T& candidate) const override {
      return !wrapped_->is_satisfied_by(candidate);
    }
  };

  /**
  * AND
  */
  template<typename T>
  class and_spec
    : public basic_spec<T> {
  public:
    using spec_type = typename basic_spec<T>::spec_type;

  private:
    std::shared_ptr<spec_type> lhs_;
    std::shared_ptr<spec_type> rhs_;

  public:
    and_spec(const spec_type& x, const spec_type& y)
      : lhs_(x.clone()), rhs_(y.clone()) {
    }

    spec_type* clone() const override {
      return new and_spec(*lhs_, *rhs_);
    }

    bool is_satisfied_by(const T& candidate) const override {
      return (lhs_->is_satisfied_by(candidate) && rhs_->is_satisfied_by(candidate));
    }
  };

  /**
  * OR
  */
  template<typename T>
  class or_spec
    : public basic_spec<T> {
  public:
    using spec_type = typename basic_spec<T>::spec_type;
    
  private:
    std::shared_ptr<spec_type> lhs_;
    std::shared_ptr<spec_type> rhs_;

  public:
    or_spec(const spec_type& x, const spec_type& y)
      : lhs_(x.clone()), rhs_(y.clone()) {
    }

    spec_type* clone() const override {
      return new or_spec(*lhs_, *rhs_);
    }

    bool is_satisfied_by(const T& candidate) const override {
      return (lhs_->is_satisfied_by(candidate) || rhs_->is_satisfied_by(candidate));
    }
  };

}
