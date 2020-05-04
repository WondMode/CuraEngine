//Copyright (c) 2019 Ultimaker B.V.


#ifndef DISTRIBUTED_BEADING_STRATEGY_H
#define DISTRIBUTED_BEADING_STRATEGY_H

#include "BeadingStrategy.h"

namespace arachne
{
    using namespace cura;

/*!
 * Beading strategy which evenly subdivides the thickness and tries to stay close to the optimal width.
 */
class DistributedBeadingStrategy : public BeadingStrategy
{
public:
    DistributedBeadingStrategy(const coord_t optimal_width, coord_t default_transition_length, float transitioning_angle)
    : BeadingStrategy(optimal_width, default_transition_length, transitioning_angle)
    {
        name = "DistributedBeadingStrategy";
    }
    virtual ~DistributedBeadingStrategy() override
    {}
    Beading compute(coord_t thickness, coord_t bead_count) const override;
    coord_t optimal_thickness(coord_t bead_count) const override;
    coord_t transition_thickness(coord_t lower_bead_count) const override;
    coord_t optimal_bead_count(coord_t thickness) const override;
};

} // namespace arachne
#endif // DISTRIBUTED_BEADING_STRATEGY_H