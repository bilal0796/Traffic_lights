//
//  TrafficManagement.h
//  traf_lights
//

#ifndef TrafficManagement_h
#define TrafficManagement_h
enum ControlState
{
    INIT,
    RED_STATE,
    GREEN_STATE,
    AMBER_STATE
};

class TrafficFlow {
private:
    ControlState curr_state;
    time_t start_time;
    bool R1_Flag;
public:
    TrafficFlow () {
        curr_state = INIT;
        R1_Flag = false;
    }
    
    ControlState stateMachine (TrafficLight &r1_a, TrafficLight &r1_b, TrafficLight &r2_a, TrafficLight &r2_b ) {
            switch (curr_state)
            {
            case INIT:
                if (R1_Flag) R1_Flag = false;
                else R1_Flag = true;

                curr_state = RED_STATE;

                r1_a.setStatus(RED);
                r1_b.setStatus(RED);
                r2_a.setStatus(RED);
                r2_b.setStatus(RED);

                start_time = time(NULL);
                break;
            case RED_STATE:
                r1_a.setStatus(RED);
                r1_b.setStatus(RED);
                r2_a.setStatus(RED);
                r2_b.setStatus(RED);

                if ((time(NULL) - start_time) >= 2) // 2 seconds
                {
                    curr_state = GREEN_STATE;
                    start_time = time(NULL);
                }
                break;
            case GREEN_STATE:
                if (R1_Flag)
                {
                    r1_a.setStatus(GREEN);
                    r1_b.setStatus(GREEN);
                }
                else
                {
                    r2_a.setStatus(GREEN);
                    r2_b.setStatus(GREEN);
                }
                if ((time(NULL) - start_time) >= 16) // 16 seconds for green light
                {
                    curr_state = AMBER_STATE;
                    start_time = time(NULL);
                }
                break;
            case AMBER_STATE:
                if (R1_Flag)
                {
                    r1_a.setStatus(AMBER);
                    r1_b.setStatus(AMBER);
                }
                else
                {
                    r2_a.setStatus(AMBER);
                    r2_b.setStatus(AMBER);
                }
                if ((time(NULL) - start_time) >= 2) // 2 seconds
                {
                    curr_state = INIT;
                }
                break;
            }
        return curr_state;
    }


};

#endif
/* TrafficManagement_h */
