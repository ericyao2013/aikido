#include "aikido/planner/ConfigurationToTSR.hpp"

#include "aikido/constraint/Testable.hpp"

namespace aikido {
namespace planner {

//==============================================================================
ConfigurationToTSR::ConfigurationToTSR(
    statespace::ConstStateSpacePtr stateSpace,
    dart::dynamics::ConstBodyNodePtr endEffectorBodyNode,
    const statespace::StateSpace::State* startState,
    constraint::dart::ConstTSRPtr goalTSR,
    constraint::ConstTestablePtr constraint)
  : Problem(std::move(stateSpace), std::move(constraint))
  , mEndEffectorBodyNode(std::move(endEffectorBodyNode))
  , mStartState(startState)
  , mGoalTSR(goalTSR)
{
  // Do nothing
}

//==============================================================================
const std::string& ConfigurationToTSR::getType() const
{
  return getStaticType();
}

//==============================================================================
const std::string& ConfigurationToTSR::getStaticType()
{
  static std::string name("ConfigurationToTSR");
  return name;
}

//==============================================================================
dart::dynamics::ConstBodyNodePtr ConfigurationToTSR::getEndEffectorBodyNode()
    const
{
  return mEndEffectorBodyNode;
}

//==============================================================================
const statespace::StateSpace::State* ConfigurationToTSR::getStartState() const
{
  return mStartState;
}

//==============================================================================
constraint::dart::ConstTSRPtr ConfigurationToTSR::getGoalTSR() const
{
  return mGoalTSR;
}

} // namespace planner
} // namespace aikido
