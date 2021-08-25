
#pragma once
#include <smacc/client_bases/smacc_subscriber_client.h>
#include <std_msgs/msg/u_int16.hpp>

namespace sm_respira_1
{
namespace cl_subscriber
{
class ClSubscriber : public smacc::client_bases::SmaccSubscriberClient<std_msgs::msg::UInt16>
{
};
}  // namespace cl_subscriber
}  // namespace sm_respira_1
