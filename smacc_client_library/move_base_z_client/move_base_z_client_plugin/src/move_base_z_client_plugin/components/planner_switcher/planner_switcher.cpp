/*****************************************************************************************************************
 * ReelRobotix Inc. - Software License Agreement      Copyright (c) 2018
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#include <move_base_z_client_plugin/components/planner_switcher/planner_switcher.h>
#include <move_base_z_client_plugin/move_base_z_client_plugin.h>

namespace cl_move_base_z
{

PlannerSwitcher::PlannerSwitcher()
{
}

void PlannerSwitcher::onInitialize()
{
  auto client_ = dynamic_cast<ClMoveBaseZ *>(owner_);
  //auto nh(client_->name_);
  //dynrecofSub_ = this->getNode()..subscribe<dynamic_reconfigure::Config>("/move_base/parameter_updates", 1, boost::bind(&PlannerSwitcher::dynreconfCallback, this, _1));
}

void PlannerSwitcher::setUndoPathBackwardPlanner()
{
  RCLCPP_INFO(getNode()->get_logger(),"[PlannerSwitcher] Planner Switcher: Trying to set BackwardPlanner");
  desired_global_planner_ = "undo_path_global_planner/UndoPathGlobalPlanner";
  desired_local_planner_ = "backward_local_planner/BackwardLocalPlanner";
  updatePlanners();
}

void PlannerSwitcher::setBackwardPlanner()
{
  RCLCPP_INFO(getNode()->get_logger(),"[PlannerSwitcher] Planner Switcher: Trying to set BackwardPlanner");
  desired_global_planner_ = "backward_global_planner/BackwardGlobalPlanner";
  desired_local_planner_ = "backward_local_planner/BackwardLocalPlanner";
  updatePlanners();
}

void PlannerSwitcher::setForwardPlanner()
{
  RCLCPP_INFO(getNode()->get_logger(),"[PlannerSwitcher] Planner Switcher: Trying to set ForwardPlanner");
  desired_global_planner_ = "forward_global_planner/ForwardGlobalPlanner";
  desired_local_planner_ = "forward_local_planner/ForwardLocalPlanner";
  updatePlanners();
}

void PlannerSwitcher::setPureSpinningPlanner()
{
  RCLCPP_INFO(getNode()->get_logger(),"[PlannerSwitcher] Planner Switcher: Trying to set PureSpinningPlanner");
  desired_global_planner_ = "forward_global_planner/ForwardGlobalPlanner";
  desired_local_planner_ = "pure_spinning_local_planner/PureSpinningLocalPlanner";
  updatePlanners();
}

void PlannerSwitcher::setDefaultPlanners()
{
  desired_global_planner_ = "navfn/NavfnROS";
  desired_local_planner_ = "base_local_planner/TrajectoryPlannerROS";
  updatePlanners();
}

void PlannerSwitcher::updatePlanners(bool subscribecallback)
{
  // RCLCPP_INFO_STREAM(getNode()->get_logger(), "[PlannerSwitcher] Setting global planner: " << desired_global_planner_);
  // RCLCPP_INFO_STREAM(getNode()->get_logger(), "[PlannerSwitcher] Setting local planner: " << desired_local_planner_);

  // // dynamic_reconfigure::ReconfigureRequest srv_req;
  // // dynamic_reconfigure::ReconfigureResponse srv_resp;
  // // dynamic_reconfigure::StrParameter local_planner, global_planner;
  // // dynamic_reconfigure::Config conf;

  // rclcpp::Parameter local_planner, global_planner;
  // std::vector<rclcpp::Parameter> conf;

  // local_planner.name = "base_local_planner";
  // local_planner.value = desired_local_planner_;
  // conf.push_back(local_planner);

  // global_planner.name = "base_global_planner";
  // global_planner.value = desired_global_planner_;
  // conf.push_back(global_planner);

  // //srv_req.config = conf;
  // RCLCPP_INFO(getNode()->get_logger(),"seting values of the dynamic reconfigure server");
  // bool error;
  // do
  // {
  //   bool res = ros::service::call("/move_base/set_parameters", srv_req, srv_resp);
  //   rclcpp::spinOnce();
  //   rclcpp::Duration(0.5).sleep();
    
  //   error = false;
  //   auto baselocalPlannerIt = std::find_if(srv_resp.config.strs.begin(), srv_resp.config.strs.end(), [](auto sp){return sp.name == "base_local_planner";});
  //   auto baseglobalPlannerIt = std::find_if(srv_resp.config.strs.begin(), srv_resp.config.strs.end(), [](auto sp){return sp.name == "base_global_planner";});

  //   auto updatedLocalPlanner = baselocalPlannerIt->value;
  //   auto updatedGlobalPlanner = baseglobalPlannerIt->value;
  //   RCLCPP_INFO_STREAM(getNode()->get_logger(), "[PlannerSwitcher] Selected base local planner: " << updatedLocalPlanner);
  //   RCLCPP_INFO_STREAM(getNode()->get_logger(), "[PlannerSwitcher] Selected base global planner: " << updatedGlobalPlanner);

  //   if(updatedGlobalPlanner != desired_global_planner_ || updatedLocalPlanner!= desired_local_planner_)
  //   {
  //     RCLCPP_WARN(getNode()->get_logger(),"[PlannerSwitcher] Planners not correctly configured. Waiting 1 second and retrying...");
  //     RCLCPP_INFO_STREAM(getNode()->get_logger(), "[PlannerSwitcher] Response: " << srv_resp);
  //     error = true;
  //   }

  // }while(error);

}

//void PlannerSwitcher::dynreconfCallback(const dynamic_reconfigure::Config::ConstPtr &configuration_update)
//{
  // auto gp = std::find_if(configuration_update->strs.begin(), configuration_update->strs.begin(),
  //                        [&](const dynamic_reconfigure::StrParameter &p) {
  //                          return p.name == "base_global_planner" && p.value == desired_global_planner_;
  //                        });

  // auto lp = std::find_if(configuration_update->strs.begin(), configuration_update->strs.begin(),
  //                        [&](const dynamic_reconfigure::StrParameter &p) {
  //                          return p.name == "base_local_planner" && p.value == desired_local_planner_;
  //                        });

  // if (gp == configuration_update->strs.end() || lp == configuration_update->strs.end())
  // {
  //   RCLCPP_INFO(getNode()->get_logger(),"[PlannerSwitcher] After planner update it is noticed an incorrect move_base planner configuration. Resending request.");
  //   set_planners_mode_flag = false;
  //   updatePlanners(false);
  // }
  // else
  // {
  //   RCLCPP_INFO(getNode()->get_logger(),"[PlannerSwitcher] Planners correctly configured according to parameter update callback");
  //   set_planners_mode_flag = true;
  // }
//}
}; // namespace cl_move_base_z