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

#pragma once

#include <sm_pack_ml/clients/cl_subscriber/cl_subscriber.hpp>
#include <smacc2/smacc_orthogonal.hpp>

namespace sm_pack_ml
{
using namespace sm_pack_ml::cl_subscriber;

class OrSubscriber : public smacc2::Orthogonal<OrSubscriber>
{
public:
  virtual void onInitialize() override
  {
    auto subscriber_client = this->createClient<ClSubscriber>();
  }
};
}  // namespace sm_pack_ml