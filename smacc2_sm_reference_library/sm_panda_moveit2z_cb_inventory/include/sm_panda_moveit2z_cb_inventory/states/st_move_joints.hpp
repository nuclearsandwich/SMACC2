// Copyright 2021 MyName/MyCompany Inc.
// Copyright 2021 RobosoftAI Inc. (template)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 *****************************************************************************************************************/

#pragma once

namespace sm_panda_moveit2z_cb_inventory
{
// SMACC2 classes
using smacc2::EvStateRequestFinish;
using smacc2::Transition;
using smacc2::default_transition_tags::SUCCESS;
using namespace smacc2;
using namespace cl_moveit2z;

// STATE DECLARATION
struct StMoveJoints : smacc2::SmaccState<StMoveJoints, SmPandaMoveit2zCbInventory>
{
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef boost::mpl::list<
    Transition<EvCbSuccess<CbMoveJoints, OrArm>, StMoveEndEffector, SUCCESS>
    ,Transition<EvCbFailure<CbMoveJoints, OrArm>, StMoveJoints, ABORT>

    >
    reactions;

  // STATE FUNCTIONS
  static void staticConfigure()
  {
    std::map<std::string, double> jointValues{
      {"panda_joint1", 0.0},
      {"panda_joint2", 0.0},
      {"panda_joint3", 0.0},
      {"panda_joint4", -M_PI/2},
      {"panda_joint5", 0.0},
      {"panda_joint6", M_PI/2},
      {"panda_joint7", 0.0}
      };

    // panda_joint6:
    // panda_joint7:
    // panda_finger_joint1:
    // panda_finger_joint2:

    configure_orthogonal<OrArm, CbMoveJoints>(jointValues);
  };

  void runtimeConfigure()
  {
    ClMoveit2z * moveGroupClient;
    this->requiresClient(moveGroupClient);
    this->getClientBehavior<OrArm,CbMoveJoints>()->scalingFactor_ = 1;
  }
};
}  // namespace sm_panda_moveit2z_cb_inventory
