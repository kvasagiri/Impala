// Copyright (c) 2011 Cloudera, Inc. All rights reserved.

#include "exprs/binary-predicate.h"
#include "exprs/functions.h"

#include "gen-cpp/Exprs_types.h"

namespace impala {

BinaryPredicate::BinaryPredicate(const TExprNode& node)
  : Predicate(node), op_(node.op) {
}

void BinaryPredicate::Prepare(RuntimeState* state) {
  switch (op_) {
    case TExprOperator::EQ:
      switch (type()) {
        case TYPE_TINYINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_eq_char;
          return;
        case TYPE_SMALLINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_eq_short;
          return;
        case TYPE_INT:
          compute_function_ = GetValueFunctions::BinaryPredicate_eq_int;
          return;
        case TYPE_BIGINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_eq_long;
          return;
        case TYPE_FLOAT:
          compute_function_ = GetValueFunctions::BinaryPredicate_eq_float;
          return;
        case TYPE_DOUBLE:
          compute_function_ = GetValueFunctions::BinaryPredicate_eq_double;
          return;
        case TYPE_STRING:
          compute_function_ = GetValueFunctions::BinaryPredicate_eq_fn_StringValue;
          return;
        //default:
          // assert(false);
      }
      return;

    case TExprOperator::NE:
      switch (type()) {
        case TYPE_TINYINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ne_char;
          return;
        case TYPE_SMALLINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ne_short;
          return;
        case TYPE_INT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ne_int;
          return;
        case TYPE_BIGINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ne_long;
          return;
        case TYPE_FLOAT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ne_float;
          return;
        case TYPE_DOUBLE:
          compute_function_ = GetValueFunctions::BinaryPredicate_ne_double;
          return;
        case TYPE_STRING:
          compute_function_ = GetValueFunctions::BinaryPredicate_ne_fn_StringValue;
          return;
        //default:
          // assert(false);
      }
      return;

    case TExprOperator::LE:
      switch (type()) {
        case TYPE_TINYINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_le_char;
          return;
        case TYPE_SMALLINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_le_short;
          return;
        case TYPE_INT:
          compute_function_ = GetValueFunctions::BinaryPredicate_le_int;
          return;
        case TYPE_BIGINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_le_long;
          return;
        case TYPE_FLOAT:
          compute_function_ = GetValueFunctions::BinaryPredicate_le_float;
          return;
        case TYPE_DOUBLE:
          compute_function_ = GetValueFunctions::BinaryPredicate_le_double;
          return;
        case TYPE_STRING:
          compute_function_ = GetValueFunctions::BinaryPredicate_le_fn_StringValue;
          return;
        //default:
          // assert(false);
      }
      return;

    case TExprOperator::GE:
      switch (type()) {
        case TYPE_TINYINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ge_char;
          return;
        case TYPE_SMALLINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ge_short;
          return;
        case TYPE_INT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ge_int;
          return;
        case TYPE_BIGINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ge_long;
          return;
        case TYPE_FLOAT:
          compute_function_ = GetValueFunctions::BinaryPredicate_ge_float;
          return;
        case TYPE_DOUBLE:
          compute_function_ = GetValueFunctions::BinaryPredicate_ge_double;
          return;
        case TYPE_STRING:
          compute_function_ = GetValueFunctions::BinaryPredicate_ge_fn_StringValue;
          return;
        //default:
          // assert(false);
      }
      return;

    case TExprOperator::LT:
      switch (type()) {
        case TYPE_TINYINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_lt_char;
          return;
        case TYPE_SMALLINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_lt_short;
          return;
        case TYPE_INT:
          compute_function_ = GetValueFunctions::BinaryPredicate_lt_int;
          return;
        case TYPE_BIGINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_lt_long;
          return;
        case TYPE_FLOAT:
          compute_function_ = GetValueFunctions::BinaryPredicate_lt_float;
          return;
        case TYPE_DOUBLE:
          compute_function_ = GetValueFunctions::BinaryPredicate_lt_double;
          return;
        case TYPE_STRING:
          compute_function_ = GetValueFunctions::BinaryPredicate_lt_fn_StringValue;
          return;
        //default:
          // assert(false);
      }
      return;

    case TExprOperator::GT:
      switch (type()) {
        case TYPE_TINYINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_gt_char;
          return;
        case TYPE_SMALLINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_gt_short;
          return;
        case TYPE_INT:
          compute_function_ = GetValueFunctions::BinaryPredicate_gt_int;
          return;
        case TYPE_BIGINT:
          compute_function_ = GetValueFunctions::BinaryPredicate_gt_long;
          return;
        case TYPE_FLOAT:
          compute_function_ = GetValueFunctions::BinaryPredicate_gt_float;
          return;
        case TYPE_DOUBLE:
          compute_function_ = GetValueFunctions::BinaryPredicate_gt_double;
          return;
        case TYPE_STRING:
          compute_function_ = GetValueFunctions::BinaryPredicate_gt_fn_StringValue;
          return;
        //default:
          // assert(false);
      }
      return;

  }
}

}
