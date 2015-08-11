//===----------------------------------------------------------------------===//
//
//                         PelotonDB
//
// ddl_utils.h
//
// Identification: src/backend/bridge/ddl/ddl_utils.h
//
// Copyright (c) 2015, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include "backend/planner/abstract_plan.h"
#include "backend/bridge/dml/mapper/dml_raw_structures.h"

#include "postgres.h"
#include "c.h"
#include "nodes/execnodes.h"

namespace peloton {
namespace bridge {

//===--------------------------------------------------------------------===//
// DML UTILS
//===--------------------------------------------------------------------===//

class DMLUtils {
 public:
  DMLUtils(const DMLUtils &) = delete;
  DMLUtils &operator=(const DMLUtils &) = delete;
  DMLUtils(DMLUtils &&) = delete;
  DMLUtils &operator=(DMLUtils &&) = delete;

  static AbstractPlanState *BuildPlanState(
      AbstractPlanState *root,
      PlanState *planstate,
      bool left_child);

  static AbstractPlanState *peloton_prepare_data(
      PlanState *planstate);

 private:

  static ModifyTablePlanState *PrepareModifyTableState(
      ModifyTableState *mt_planstate);

  static ResultPlanState *PrepareResultState(
      ResultState *result_planstate);

  static void PrepareAbstractScanState(
      AbstractScanPlanState* ss_planstate,
      ScanState *ss_state);

  static SeqScanPlanState *PrepareSeqScanState(
      SeqScanState *ss_planstate);

  static PelotonProjectionInfo *BuildProjectInfo(
      ProjectionInfo *proj_info,
      int column_count);

};

}  // namespace bridge
}  // namespace peloton