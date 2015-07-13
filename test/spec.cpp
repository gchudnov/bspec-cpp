#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "./common/true_spec.h"
#include "./common/false_spec.h"

using namespace std;

class ASpecification : public ::testing::Test {
public:
  true_spec truthy;
  false_spec falsy;
};

TEST_F(ASpecification, SupportsAndOperaion) {
  ASSERT_TRUE(truthy.And(truthy).is_satisfied_by(true));
  ASSERT_FALSE(truthy.And(falsy).is_satisfied_by(true));
  ASSERT_FALSE(falsy.And(truthy).is_satisfied_by(true));
  ASSERT_FALSE(falsy.And(falsy).is_satisfied_by(true));
}

TEST_F(ASpecification, SupportsOrOperation) {
  ASSERT_TRUE(truthy.Or(truthy).is_satisfied_by(true));
  ASSERT_TRUE(truthy.Or(falsy).is_satisfied_by(true));
  ASSERT_TRUE(falsy.Or(truthy).is_satisfied_by(true));
  ASSERT_FALSE(falsy.Or(falsy).is_satisfied_by(true));
}

TEST_F(ASpecification, SupportsNotOperation) {
  ASSERT_FALSE(truthy.Not().is_satisfied_by(true));
  ASSERT_TRUE(falsy.Not().is_satisfied_by(true));
}

TEST_F(ASpecification, CanBeChained) {
  ASSERT_TRUE(truthy.Or(falsy).And(truthy).is_satisfied_by(true));
  ASSERT_FALSE(truthy.Or(falsy).And(truthy).Not().is_satisfied_by(true));
}