# PID Project Reflection
Kelly Smith

## Effects of P,I,D terms
*Describe the effect each of the P, I, D components had in your implementation.*

The final values of the PID gains that I used were: $$K_P = 0.085$$, $$K_I = 0.00085$$, and $$K_D = 0.765$$.  

The proportional term helped to track short term deviations from the centerline.  The derivative term helped to slow rapid changes in the cross track error (CTE) which tended to smoothen the driving.  The integral term helped to eliminate systemic bias.


## Design
*Describe how the final hyperparameters were chosen.*

I manually tuned the PID values via trial and error.  

Initially, I set all control gain terms to 0 except for the proportional term $$K_P$$.  Then I manually iterated on the magnitude of the proportional term until the steering commands produced were of the correct order of magnitude (not saturating the steering commands).  

At this stage, I knew that the vehicle steering dynamics would be marginally stable at best.

Next, I started adding in the damping term $$K_D$$ until the oscillations about the centerline began to dampen (dynamically stable).  It's easy to overdamp the system to produce smooth driving behavior, but this introduces lag into the steering commands during turns.

With only proportional and derivative controller gains, the vehicle tended to stay on the "outside" portion of the lane due to systemic steering bias caused by the lag in the steering command (almost always turning left in the test track).  As a result, I added in a small integral correction term to help eliminate the systemic bias.