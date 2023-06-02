// Copyright 2021 RobosoftAI Inc.
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
 ******************************************************************************************************************/

#include <moveit2z_client/cl_moveit2z.hpp>
#include <moveit2z_client/client_behaviors/cb_detach_object.hpp>

namespace cl_moveit2z
{
void CbDetachObject::onEntry()
{
  RCLCPP_INFO_STREAM(getLogger(), "[" << getName() << "] requesting components");

  cl_moveit2z::CpGraspingComponent * graspingComponent;
  this->requiresComponent(graspingComponent);

  cl_moveit2z::ClMoveit2z * moveGroupClient;
  this->requiresClient(moveGroupClient);

  auto & planningSceneInterface = moveGroupClient->planningSceneInterface;

  RCLCPP_INFO_STREAM(getLogger(), "[" << getName() << "] requesting detach object");

  auto res = moveGroupClient->moveGroupClientInterface->detachObject(
    *(graspingComponent->currentAttachedObjectName));
  planningSceneInterface->removeCollisionObjects({*(graspingComponent->currentAttachedObjectName)});

  RCLCPP_INFO_STREAM(getLogger(), "[" << getName() << "] detach result: " << res);

  if (res)
    this->postSuccessEvent();
  else
    this->postFailureEvent();
}

void CbDetachObject::onExit() {}
}  // namespace cl_moveit2z