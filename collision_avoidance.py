import time
import sys
import os
import numpy as np
import pygame


# Import your modules from the library
# (make sure to run "pip install ." in the crazyflie-lib-python directory
# if the imports don't work.)
import cflib.crtp
from cflib.crazyflie.swarm import CachedCfFactory
from cflib.crazyflie.swarm import Swarm
from cflib.crazyflie.log import LogConfig


def activate_led_bit_mask(scf):
    scf.cf.param.set_value('led.bitmask', 255)

def deactivate_led_bit_mask(scf):
    scf.cf.param.set_value('led.bitmask', 0)

def light_check(scf):
    activate_led_bit_mask(scf)
    time.sleep(2)
    deactivate_led_bit_mask(scf)
    time.sleep(2)


def take_off(scf):
    commander= scf.cf.high_level_commander
    commander.takeoff(1.0, 2.0)
    time.sleep(3)

def land(scf):
    commander= scf.cf.high_level_commander
    commander.land(0.0, 2.0)
    time.sleep(2)
    commander.stop()

def hover_sequence(scf):
    take_off(scf)
    land(scf)


def run_square_sequence(scf):
    box_size = 0.5
    flight_time = 2

    commander= scf.cf.high_level_commander

    commander.go_to(box_size, 0, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)

    commander.go_to(0, box_size, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)

    commander.go_to(-box_size, 0, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)

    commander.go_to(0, -box_size, 0, 0, flight_time, relative=True)
    time.sleep(flight_time)




def log_callback(uri, timestamp, data, logconf):
    x = data['stateEstimate.x']
    y = data['stateEstimate.y']
    z = data['stateEstimate.z']
    with open("cf_log.txt", "a") as f:
        f.write(f"{timestamp} {uri} {x} {y} {z}\n")
        f.close()


def start_states_log(scf):
    log_conf = LogConfig(name="pos", period_in_ms=100)
    log_conf.add_variable("stateEstimate.x", "float")
    log_conf.add_variable("stateEstimate.y", "float")
    log_conf.add_variable("stateEstimate.z", "float")
    
    uri = scf.cf.link_uri
    scf.cf.log.add_config(log_conf)
    log_conf.data_received_cb.add_callback(lambda timestamp, data, logconf: log_callback(uri, timestamp, data, logconf))
    log_conf.start()


uris = [
    'radio://0/80/2M/8',
    'radio://0/80/2M/2',
    #'radio://0/80/2M/3'
]



def run_sequence(scf, sequence):
    cf = scf.cf

    for arguments in sequence:
        commander = scf.cf.high_level_commander

        x, y, z = arguments[0], arguments[1], arguments[2]
        duration = arguments[3]

        print('Setting position {} to cf {}'.format((x, y, z), cf.link_uri))
        commander.go_to(x, y, z, 0, duration, relative=True)
        time.sleep(duration)

u = 0.3
dt = 3

def visualize_trajectories(initial_positions, final_positions, sequences):
    # Constants
    WIDTH, HEIGHT = 800, 600
    BG_COLOR = (30, 30, 30)  # Background color
    GRID_COLOR = (50, 50, 50)  # Grid color
    AGENT_COLORS = [(255, 0, 0), (0, 255, 0), (0, 0, 255)]  # Red, Green, Blue
    AGENT_RADIUS = 13  # Radius of agents in pixels
    METER_TO_PIXEL = 100  # 1 meter = 100 pixels
    FPS = 60  # Frames per second for smooth animation
    COLLISION_THRESHOLD = 0.25  # Minimum distance in meters to trigger red text

    # Initialize Pygame
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("2D Trajectory Visualizer")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("Arial", 20)

    # Function to draw a grid
    def draw_grid():
        for x in range(0, WIDTH, METER_TO_PIXEL):  # Vertical lines
            pygame.draw.line(screen, GRID_COLOR, (x, 0), (x, HEIGHT))
        for y in range(0, HEIGHT, METER_TO_PIXEL):  # Horizontal lines
            pygame.draw.line(screen, GRID_COLOR, (0, y), (WIDTH, y))

    # Function to convert real-world coordinates to Pygame coordinates
    def to_screen_coords(x, y):
        return int(WIDTH // 2 + x * METER_TO_PIXEL), int(HEIGHT // 2 - y * METER_TO_PIXEL)

    # Initialize agent positions
    positions = [list(pos) for pos in initial_positions]  # Convert to mutable lists
    active_step = [0] * len(sequences)  # Current step for each agent
    step_progress = [0.0] * len(sequences)  # Progress in the current step (0.0 to 1.0)

    # Variable to store the minimum distance encountered so far
    global_min_distance = float("inf")

    # Main loop
    running = True
    while running:
        screen.fill(BG_COLOR)
        draw_grid()

        # Draw initial and final points
        for i in range(len(initial_positions)):
            pygame.draw.circle(screen, AGENT_COLORS[i], to_screen_coords(*initial_positions[i]), AGENT_RADIUS)
            pygame.draw.circle(screen, AGENT_COLORS[i], to_screen_coords(*final_positions[i]), AGENT_RADIUS, 1)

        # Update agent positions
        dt = clock.tick(FPS) / 1000.0  # Time elapsed in seconds since last frame
        all_finished = True

        for i, seq in enumerate(sequences):
            if active_step[i] < len(seq):  # If there are remaining steps
                all_finished = False
                dx, dy, _, step_time = seq[active_step[i]]

                # Update progress for this step
                step_progress[i] += dt / step_time
                if step_progress[i] >= 1.0:  # Step complete
                    step_progress[i] = 0.0
                    active_step[i] += 1
                    if active_step[i] < len(seq):  # Prepare for next step
                        dx, dy, _, step_time = seq[active_step[i]]
                else:
                    # Interpolate position linearly
                    positions[i][0] += (dx / step_time) * dt
                    positions[i][1] += (dy / step_time) * dt

            # Draw the agent
            pygame.draw.circle(screen, AGENT_COLORS[i], to_screen_coords(*positions[i]), AGENT_RADIUS)

        # Calculate current minimum distance between agents
        current_min_distance = float("inf")
        for i in range(len(positions)):
            for j in range(i + 1, len(positions)):
                dist = ((positions[i][0] - positions[j][0]) ** 2 + (positions[i][1] - positions[j][1]) ** 2) ** 0.5
                current_min_distance = min(current_min_distance, dist)

        # Update the global minimum distance
        global_min_distance = min(global_min_distance, current_min_distance)

        # Display the global minimum distance
        min_distance_text = f"Min Distance: {global_min_distance:.2f} m"
        text_color = (255, 0, 0) if global_min_distance < COLLISION_THRESHOLD else (255, 255, 255)
        text_surface = font.render(min_distance_text, True, text_color)
        screen.blit(text_surface, (WIDTH - 250, 10))

        # Update screen
        pygame.display.flip()

        # Handle events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        # Stop if all agents are finished
        if all_finished:
            pygame.time.wait(1000)  # Pause at the end of the animation
            running = False

    pygame.quit()










#########################
def check_collision_linear_segment(t_i1, t_f1, r_i1, r_f1, t_i2, t_f2, r_i2, r_f2, epsilon):
    """checks if two linear trajectories have a collision.
    returns:
    - times at which the collisions occur"""
    t_eval_i = np.max([t_i1, t_i2])
    t_eval_f = np.min([t_f1, t_f2])
    t = np.linspace(t_eval_i, t_eval_f, 100)
    print(f"evaluation for t in [{t_eval_i}, {t_eval_f}]")

    delta = np.zeros(len(t))
    for k in range(len(t)):
        v = r_i1-r_i2 + (r_f1-r_i1)*(t[k]-t_i1)/(t_f1-t_i1) - (r_f2-r_i2)*(t[k]-t_i2)/(t_f2-t_i2)
        delta[k] = np.sqrt(v[0]**2 + v[1]**2)

        
    indices_collisions = np.where(delta<epsilon)
    return t[indices_collisions]


def position(t, r_i, r_f, t_i, t_f):
    """returns the position of a linearly displaced object at time t"""
    return r_i + (r_f-r_i)*(t-t_i)/(t_f-t_i)


def straight_line(r_i, r_f, alpha):
    """computes a point on a straight line"""
    return r_i + (r_f-r_i)*alpha


def check_geometric_intersections(r_i1, r_f1, r_i2, r_f2, epsilon, verbose=False):
    """checks if two straight lines have a geometric intersection"""
    N_pts_alpha = 100
    alpha1 = np.linspace(0, 1, N_pts_alpha)
    alpha2 = np.linspace(0, 1, N_pts_alpha)

    # find distances delta of points of lines 
    delta = np.zeros(shape=(len(alpha1), len(alpha2)))
    for i in range(len(alpha1)):
        for j in range(len(alpha2)):
            v = straight_line(r_i1, r_f1, alpha1[i]) - straight_line(r_i2, r_f2, alpha2[j])
            delta[i, j] = np.sqrt(v[0]**2 + v[1]**2)

    # judge whether we have an intersection
    where_isc = np.where(delta < epsilon)

    if verbose:
        print(f"alpha1 at intersections= {alpha1[where_isc[0]]}")
        print(f"alpha2 at intersections= {alpha2[where_isc[1]]}")

    if len(where_isc[0]) > 0:
        return True, alpha1[where_isc[0]], alpha2[where_isc[1]]
    
    return False, alpha1[where_isc[0]], alpha2[where_isc[1]]

import numpy as np

def compute_retracted_point(r_i1, r_wp, epsilon):
    # Step 1: Compute the vector from r_i[1] to r_wp
    v = np.array(r_wp) - np.array(r_i1)
    
    # Step 2: Normalize the direction vector
    v_hat = v / np.linalg.norm(v)
    print("r_i1:")
    print(r_i1)
    print("r_wp:")
    print(r_wp)
    # Step 3: Compute the new point at distance epsilon * 2 beyond r_wp
    r_new = np.array(r_wp) - (epsilon * 2) * v_hat
    print("r_new:")
    print(r_new)
    return r_new

def construct_2_sequences(r_i, r_f, T, epsilon, clearence=1):
    """constructs a pair of sequences that avoid a crash"""
    t_i0 = 0
    t_f0 = T
    t_i1 = 0
    t_f1 = T
    dx0, dy0 = r_f[0]-r_i[0]
    sequence0 = [
        (dx0, dy0, 0, T)
    ]
    v0 = np.sqrt(dx0**2+dy0**2)/T
    t_delay = 2*epsilon/v0
    print(f"comuted delay time: {t_delay}")

    t_coll = check_collision_linear_segment(t_i0, t_f0, r_i[0], r_f[0], t_i1, t_f1, r_i[1], r_f[1], epsilon)


    if len(t_coll) > 0:
        
        r_wp = position(t_coll[0], r_i[1], r_f[1], t_i1, t_f1)
        #r_wp = position(t_coll[0], r_i[1], r_f[1], t_i1, t_f1)

        t_wp = t_coll[0] + t_delay
        #if(clearence == 2):
        #    r_wp = compute_retracted_point(r_i[1], r_wp, epsilon*2)
        #else:
        #    r_wp = compute_retracted_point(r_i[1], r_wp, epsilon)
        dx10, dy10 = r_wp - r_i[1]
        dx11, dy11 = r_f[1] - r_wp
        sequence1 = [
            (dx10, dy10, 0, t_wp),
            (dx11, dy11, 0, T-t_wp)
        ]
    
    else:
        dx1, dy1 = r_f[1]-r_i[1]
        sequence1 = [
            (dx1, dy1, 0, T)
        ]
    
    return sequence0, sequence1

def construct_sequence_segment(r_i, r_f,T):
    """constructs a pair of direct sequences that do not avoid a crash"""
    dx, dy = r_f-r_i
    sequence = [
        (dx, dy, 0, T)
    ]
    return sequence

def construct_sequences(r_i, r_f, T, epsilon):
    
    sequence0, sequence1 = construct_2_sequences(r_i, r_f, T, epsilon)

    if np.shape(r_i)[0] == 2:               # if only two drones are used
        return (sequence0, sequence1)

    elif np.shape(r_i)[0] == 3:
        intersection_values = []            # list to track with which other trajectory (0 or 1) there is an intersection with the to-construct trajectory 2
        for k in range(2):
            if check_geometric_intersections(r_i[2], r_f[2], r_i[k], r_f[k], epsilon)[0]:
                intersection_values.append(k)

            if len(intersection_values) == 0:
                #CHECK!
                dx2, dy2 = r_f[2]-r_i[2]
                sequence2 = [
                    (dx2, dy2, 0, T)
                ]
            
            if len(intersection_values) == 1:
                if 0 in intersection_values:
                    #CHECK
                    _, sequence2 = construct_2_sequences([r_i[0], r_i[2]], [r_f[0], r_f[2]], T, epsilon)

                if 1 in intersection_values:
                    if len(sequence1) == 1:
                        #CHECK
                        _, sequence2 = construct_2_sequences([r_i[1], r_i[2]], [r_f[1], r_f[2]], T, epsilon)
                    elif len(sequence1) == 2:
                        # trajectory 1 is split in 2 parts by 1 waypoint
                        #print("Intersection between 2 and 1, while 1 is splited already...")
                        # coordinates at the waypoint of trajectory 1
                        r_wp1 = r_i[1] + np.array([sequence1[0][0], sequence1[0][1]])
                        dt = sequence1[0][3]
                        t_wp1 = 0 + dt

                        r_2_at_wp1 = position(dt, r_i[2], r_f[2], 0, T)
                        # test if intersection with first part of trajectory 1
                        if check_geometric_intersections(r_i[1], r_wp1, r_i[2], r_f[2],epsilon)[0]: #CHECK!!
                            
                            #print("Detected intersection with first part of trajectory 1...")
                            #HERE I DON'T WANT TO DIRECTLY REPLACE IT
                            #_, sequence2 = construct_2_sequences([r_i[1], r_i[2]], [r_wp1, r_2_at_wp1], t_wp1, epsilon)
                            _, sequence_temp = construct_2_sequences([r_i[1], r_i[2]], [r_wp1, r_2_at_wp1], t_wp1, epsilon)
                            if len(sequence_temp) == 1:
                                sequence2 = construct_sequence_segment(r_i[2],r_f[2],T)
                            else:
                                #THIS MEANS IT WAS SPLITtED!!
                                #Sequence_temp now holds from start to waypoint of sequence2, and from waypoint to r_2_at_wp1
                                #I want to replace this last one,,, since I don't want it to stop there, but at the end of the original trajectory. 
                                #This means,,, Start point-> r_i = np.array(sequence_temp[0][0], sequence_temp[0][1]) <- THIS HAPPENS IN dt = sequence_temp[0][3]  Finish in r_f and T-dt
                                r_wp_temp = r_i[2] + np.array([sequence_temp[0][0], sequence_temp[0][1]])
                                
                                dt = sequence_temp[0][3]

                                sequence_temp[1] = construct_sequence_segment(r_wp_temp,r_f[2],T-dt)[0]
                                sequence2 = sequence_temp

                        # test if intersection with second part of trajectory 1
                        elif check_geometric_intersections(r_wp1, r_f[1], r_i[2], r_f[2],epsilon)[0]:  #CHECK!
                            #print("Intersection between traj 2 second part of trajectory 1")
                            #HERE I DON'T WANT TO DIRECTLY REPLACE IT
                            #_, sequence2 = construct_2_sequences([r_wp1, r_2_at_wp1], [r_f[1], r_f[2]], T-t_wp1, epsilon)
                     
                
                            _, sequence_temp = construct_2_sequences([r_wp1, r_2_at_wp1], [r_f[1], r_f[2]], T-t_wp1, epsilon)
                            if len(sequence_temp) == 1:
                                sequence2 = construct_sequence_segment(r_i[2],r_f[2],T)
                            else:
                          
                                #THIS MEANS IT WAS SPLITED!!
                                #Sequence_temp now holds from r_2_at_wp1 to waypoint of sequence2, and from waypoint to final
    
                                #This means,,, Start point-> r_wp_temp = r_i[2] + np.array(sequence_temp[0][0], sequence_temp[0][1]) <- THIS HAPPENS IN dt = sequence_temp[0][3]  Finish in r_f and T-dt
                                dt = sequence_temp[0][3] + t_wp1 #TIME WHEN WAYPOINT IN SEQ 2 HAPPENS
                                r_wp2_temp = r_f[2]-np.array([sequence_temp[1][0], sequence_temp[1][1]]) #FINAL POINT MINUS THE DESPLACEMENT AFTER WAYPOINT TO GET POINT IN WAYPOINT
                                sequence_temp[0] = construct_sequence_segment(r_i[2],r_wp2_temp,dt)[0]
                                sequence2 = sequence_temp
                        else:
                            print("shouldn't happen 1")

                    else: 
                        print("shouldn't happen 2")

            if len(intersection_values) == 2:
                clearence = 2
                _, alpha20, _ = check_geometric_intersections(r_i[2], r_f[2], r_i[0], r_f[0], epsilon)
                _, alpha21, _ = check_geometric_intersections(r_i[2], r_f[2], r_i[1], r_f[1], epsilon)

                if alpha21[0] > alpha20[0]:
                    #if len(sequence1) == 1:
                    #    _, sequence2 = construct_2_sequences([r_i[0], r_i[2]], [r_f[0], r_f[2]], T, epsilon)
                    _, sequence2 = construct_2_sequences([r_i[0], r_i[2]], [r_f[0], r_f[2]], T, epsilon,clearence)
                    
                    if len(sequence2) == 1:
                        
                        if len(sequence1) == 1:
                            _, sequence2 = construct_2_sequences([r_i[1], r_i[2]], [r_f[1], r_f[2]], T, epsilon,clearence)
                        else:
                            # trajectory 1 is split in 2 parts by 1 waypoint
                            
                            # coordinates at the waypoint of trajectory 1
                            r_wp1 = r_i[1] + np.array([sequence1[0][0], sequence1[0][1]])
                            dt = sequence1[0][3]  ##<<<--------ATTENTION HERE
                            t_wp1 = 0 + dt

                            r_2_at_wp1 = position(dt, r_i[2], r_f[2], 0, T)

                            # test if intersection with first part of trajectory 1
                            if check_geometric_intersections(r_i[1], r_wp1, r_i[2], r_f[2],epsilon)[0]:
                                
                                        #HERE I DON'T WANT TO DIRECTLY REPLACE IT
                                #_, sequence2 = construct_2_sequences([r_i[1], r_i[2]], [r_wp1, r_2_at_wp1], t_wp1, epsilon)
                                _, sequence_temp = construct_2_sequences([r_i[1], r_i[2]], [r_wp1, r_2_at_wp1], t_wp1, epsilon,clearence)
                                if len(sequence_temp) == 1:
                                    sequence2 = construct_sequence_segment(r_i[2],r_f[2],T)
                                else:
                                    #THIS MEANS IT WAS SPLITED!!
                                    #Sequence_temp now holds from start to waypoint of sequence2, and from waypoint to r_2_at_wp1
                                    #I want to replace this last one,,, since I don't want it to stop there, but at the end of the original trajectory. 
                                    #This means,,, Start point-> r_i = np.array(sequence_temp[0][0], sequence_temp[0][1]) <- THIS HAPPENS IN dt = sequence_temp[0][3]  Finish in r_f and T-dt
                                    r_wp_temp = r_i[2] + np.array([sequence_temp[0][0], sequence_temp[0][1]])
                                    dt = sequence_temp[0][3]

                                    sequence_temp[1] = construct_sequence_segment(r_wp_temp,r_f[2],T-dt)[0]
                                    sequence2 = sequence_temp

                            # test if intersection with second part of trajectory 1
                            elif check_geometric_intersections(r_wp1, r_f[1], r_i[2], r_f[2],epsilon)[0]:
                                
                                #HERE I DON'T WANT TO DIRECTLY REPLACE IT
                                #_, sequence2 = construct_2_sequences([r_wp1, r_2_at_wp1], [r_f[1], r_f[2]], T-t_wp1, epsilon)
                                _, sequence_temp = construct_2_sequences([r_wp1, r_2_at_wp1], [r_f[1], r_f[2]], T-t_wp1, epsilon,clearence)
                                if len(sequence_temp) == 1:
                                    sequence2 = construct_sequence_segment(r_i[2],r_f[2],T)
                                else:
                                    #THIS MEANS IT WAS SPLITED!!
                                    #Sequence_temp now holds from r_2_at_wp1 to waypoint of sequence2, and from waypoint to final
                                    #This means,,, Start point-> r_wp_temp = r_i[2] + np.array(sequence_temp[0][0], sequence_temp[0][1]) <- THIS HAPPENS IN dt = sequence_temp[0][3]  Finish in r_f and T-dt
                                    dt = sequence_temp[0][3] + t_wp1 #TIME WHEN WAYPOINT IN SEQ 2 HAPPENS
                                    r_wp2_temp = r_f[2]-np.array([sequence_temp[1][0], sequence_temp[1][1]]) #FINAL POINT MINUS THE DESPLACEMENT AFTER WAYPOINT TO GET POINT IN WAYPOINT
                                    sequence_temp[0] = construct_sequence_segment(r_i[2],r_wp2_temp,dt)[0]
                                    sequence2 = sequence_temp
                            else:
                                print("shouldn't happen 1")

                    elif len(sequence2) == 2:
                        
                        if len(sequence1) == 1: #CHECK!!
                            # trajectory 2 is split in 2 parts by 1 waypoint but trayectory 1 not. We know that the intesection with sequence 1 happens in the second segment of sequence2
                            # coordinates at the waypoint of trajectory 2
                            r_wp2 = r_i[2] + np.array([sequence2[0][0], sequence2[0][1]])
                            dt = sequence2[0][3]
                            t_wp2 = 0 + dt
                            r_1_at_wp1 = position(dt, r_i[1], r_f[1], 0, T)

                            _, sequence_temp = construct_2_sequences([r_1_at_wp1, r_wp2], [r_f[1], r_f[2]], T-t_wp2, epsilon,clearence) 
                            #Sequence temp now holds trajectory from waypoint to finish! And Sequence 2 holds trajectory from start to finish taking into account only seq 0 (Splited already)
                            #This means... I have to replace second instruction from sequence 2 to all that was just computed in sequence_temp
                            sequence2.pop()
                            sequence2.extend(sequence_temp)

                        else:
                            
                            #Both trayectory 1 and 2 are split in 2 parts by 1 waypoint. We know that the intesection with sequence 1 happens in the second segment of sequence2
                            # coordinates at the waypoint of trajectory 1
                            r_wp1 = r_i[1] + np.array([sequence1[0][0], sequence1[0][1]])
                            dt1 = sequence1[0][3] #THIS COULD HAPPEN IN DIFFERENT TIMES FOR BOTH SEQ1 AND SEQ2 
                            dt2 = sequence2[0][3] #Time that takes seq2 to reach the waypoint
                            #I ONLY CARE ON WHAT HAPPENS AFTER WAYPOINT OF SEQ 2!
                           # if dt2 >= dt1:
                                #THIS MEANS THAT AFTER THE WAYPOINT OF SEQ 2 FROM THE INTERSECTION WITH SEQ 0, SEQ 1 WILL BE ALREADY ON IT'S SECOND SEGMENT!
                                #SO POSSIBLE COLLISION ONLY BETWEEN BOTH SECOND SEGMENTS!!!
                                #Sequence 2 already holds the first instruction from start to waypoint,,, 
                                #we have to check now collision second segment from seq 2 and second segment from seq 1

                            r_wp2 = r_i[2] + np.array([sequence2[0][0], sequence2[0][1]])
                            t_wp1 = 0 + dt1
                            t_wp2 = 0 + dt2
                    

                            # test if intersection with first part of trajectory 1
                            if check_geometric_intersections(r_i[1], r_wp1, r_wp2, r_f[2],epsilon)[0]:
                                
                                #Intersection with first part...
                                
                                #Sequence 2 already holds the first instruction from start to waypoint,,, 
                                #Now I need to compute the second part... Sequence one should start from the point it currently is when waypoint of seq 2 was reached
                                r_1_at_wp2 =  position(dt2, r_i[1], r_wp1, 0, dt1)
                                _, sequence_temp = construct_2_sequences([r_1_at_wp2, r_wp2], [r_f[1], r_f[2]], T-t_wp2, epsilon,clearence)
                                sequence2.pop()
                                sequence2.extend(sequence_temp)
                                #Sequence temp now holds from waypoint to finish for  sequence 2...


                            # test if intersection with second part of trajectory 1
                            elif check_geometric_intersections(r_wp1, r_f[1], r_wp2, r_f[2],epsilon)[0]:
                               
                                #Sequence 2 already holds the first instruction from start to waypoint,,, 
                                #Now I need to compute the second part... S
                                if t_wp1>t_wp2:
                                    
                                    r_2_at_wp1 =  position(t_wp1-t_wp2, r_wp2, r_f[2], 0, T-t_wp2)
                                    _, sequence_temp = construct_2_sequences([r_wp1, r_2_at_wp1], [r_f[1], r_f[2]], T-t_wp1, epsilon,clearence) ##HERE I LEFT
                                    if len(sequence_temp)==2:
                                        print("HERE ASWELL!!") #HEREEEEEEEEEEEEEEEEEEEEEE
                                        #IT WAS SPLITTED!!
                                        #Sequence temp holds from r_2 from seq1 reaching the waypoint to the partition and after from waypoint to end
                                        #Sequence_temp now holds from r_2_at_wp1 to waypoint of sequence2, and from waypoint to final
                                        #This means,,, Start point-> r_wp_temp = r_i[2] + np.array(sequence_temp[0][0], sequence_temp[0][1]) <- THIS HAPPENS IN dt = sequence_temp[0][3]  Finish in r_f and T-dt
                                        dt = sequence_temp[0][3] + t_wp1 #TIME WHEN WAYPOINT IN SEQ 2 HAPPENS
                                        print("dt:")
                                        print(dt)
                                        r_wp2_temp = r_f[2]-np.array([sequence_temp[1][0], sequence_temp[1][1]]) #FINAL POINT MINUS THE DESPLACEMENT AFTER WAYPOINT TO GET POINT IN WAYPOINT
                                        sequence_temp[0] = construct_sequence_segment(r_wp2,r_wp2_temp,dt)[0]
                                        sequence2.pop()
                                        sequence2.extend(sequence_temp)
                                else:
                                    r_1_at_wp2 =  position(t_wp2-t_wp1, r_wp1, r_f[1], 0, T-t_wp1)
                                    _, sequence_temp = construct_2_sequences([r_1_at_wp2, r_wp2], [r_f[1], r_f[2]], T-t_wp2, epsilon,clearence) ##HERE I LEFT
                                    sequence2.pop()
                                    sequence2.extend(sequence_temp)
                                    
                            else:
                                print("shouldn't happen 1")
                else: #TRAJECTORY 2 INTERSECTS FIRST WITH SEQUENCE 1
                   
                    _, sequence2 = construct_2_sequences([r_i[0], r_i[2]], [r_f[0], r_f[2]], T, epsilon,clearence)
                    if len(sequence1) == 1:
                        _, sequence2 = construct_2_sequences([r_i[1], r_i[2]], [r_f[1], r_f[2]], T, epsilon,clearence)
                        if len(sequence2) == 1:
                            _, sequence2 = construct_2_sequences([r_i[0], r_i[2]], [r_f[0], r_f[2]], T, epsilon,clearence)
                        else:
                            r_wp2 = r_i[2] + np.array([sequence2[0][0], sequence2[0][1]])
                            dt = sequence2[0][3]
                            r_0_at_wp2 = position(dt, r_i[0], r_f[0], 0, T)
                            _,sequence_temp = construct_2_sequences([r_0_at_wp2, r_wp2], [r_f[0], r_f[2]], T-dt, epsilon,clearence)
                            sequence2.pop()
                            sequence2.extend(sequence_temp)
                    else:
                        r_wp1 = r_i[1] + np.array([sequence1[0][0], sequence1[0][1]])
                        dt = sequence1[0][3]
                        r_2_at_wp1 = position(dt, r_i[2], r_f[2], 0, T)
                        if check_geometric_intersections(r_i[1], r_wp1, r_i[2], r_f[2],epsilon)[0]:
                            _, sequence2 = construct_2_sequences([r_i[1], r_i[2]], [r_wp1, r_2_at_wp1], dt, epsilon,clearence)
                            if len(sequence2) == 1:
                                _, sequence2 = construct_2_sequences([r_i[0], r_i[2]], [r_f[0], r_f[2]], T, epsilon,clearence)
                            else:
                                r_wp2 = r_i[2] + np.array([sequence2[0][0], sequence2[0][1]])
                                dt2 = sequence2[0][3]
                                r_0_at_wp2 = position(dt2, r_i[0], r_f[0], 0, T)
                                _, sequence_temp = construct_2_sequences([r_0_at_wp2, r_wp2], [r_f[0], r_f[2]], T-dt2, epsilon,clearence)
                                sequence2.pop()
                                sequence2.extend(sequence_temp)
                        elif check_geometric_intersections(r_wp1, r_f[1], r_i[2], r_f[2],epsilon)[0]:
                            
                            _, sequence_temp = construct_2_sequences([r_wp1, r_2_at_wp1], [r_f[1], r_f[2]], T-dt, epsilon,clearence)
                            if len(sequence_temp) == 1:
                                _, sequence2 = construct_2_sequences([r_i[0], r_i[2]], [r_f[0], r_f[2]], T, epsilon,clearence)
                            else:
                                r_wp2 = r_2_at_wp1 + np.array([sequence_temp[0][0], sequence_temp[0][1]])
                                dt2 = sequence_temp[0][3] + dt
                                r_0_at_wp2 =  position(dt2, r_i[0], r_f[0], 0, T)
                                _, sequence_temp = construct_2_sequences([r_0_at_wp2, r_wp2], [r_f[0], r_f[2]], T-dt2, epsilon,clearence)
                                sequence2 = construct_sequence_segment(r_i[2],r_wp2,dt2)
                                sequence2.extend(sequence_temp)
        return (sequence0, sequence1, sequence2)

    else:
        print(f"invalid case in function construct_sequence. np.shape(r_i): {np.shape(r_i)}.")
        return None



sequence0 = [
    (0, u, 0, dt),              # dx, dy, dz, dt
    (0, -u, 0, dt)
]

sequence1 = [
    (u, 0, 0, dt),
    (-u, 0, 0, dt)
]

sequence2 = [
    (0, -u, 0, dt),
    (0, u, 0, dt)
]



def get_positions():
    data = np.genfromtxt("cf_log.txt", dtype=None, encoding=None)
    
    r = np.zeros(shape=(len(uris), 2))

    for i_uri in range(len(uris)):
        found = False
        i_data = -1
        while not found:
            if data[i_data][1] == uris[i_uri]:
                found = True
                r[i_uri] = np.array([data[i_data][2], data[i_data][3]])
            i_data -= 1           
    return r


def flight():    
    print("init drivers")
    cflib.crtp.init_drivers()

    print("create factory")
    factory = CachedCfFactory(rw_cache='./cache')

    print("create Swarm")
    with Swarm(uris, factory=factory) as swarm:
            #print("\nStarting light check")
            #swarm.sequential(light_check)            # parallel_safe will execute the function given to it as an argument for all crazyflies in the swarm
            
            print("\nreset estimators")
            swarm.reset_estimators()

            #print("\nsequential take off and landing")
            #swarm.parallel_safe(hover_sequence)

            print("Initialize logging")
            open("cf_log.txt", "w").close()
            swarm.parallel_safe(start_states_log)

            print("Run the test sequence")
            swarm.parallel_safe(take_off)
            
            T = 10
            epsilon = 0.5
            r_i = get_positions()
            r_f = np.array(
                [
                    [0, 1],
                    [1, 0],
                ]
            )

            sequences = construct_sequences(r_i, r_f, T, epsilon)
            if len(sequences) == 2:
                seq_args = {
                    uris[0]: [sequences[0]],
                    uris[1]: [sequences[1]],
                }
                print("2 sequences constructed: ")
                print(sequences[0])
                print(sequences[1])

            elif len(sequences) == 3:
                seq_args = {
                    uris[0]: [sequences[0]],
                    uris[1]: [sequences[1]],
                    uris[2]: [sequences[2]]
                }
                print("3 sequences constructed:")
                print(sequences[0])
                print(sequences[1])
                print(sequences[2])
            
            time.sleep(10)
            print("It goes on!")

            swarm.parallel_safe(run_sequence, args_dict=seq_args)
            swarm.parallel_safe(land)



def seq_constr_test():
    r_i1 = np.array([0, -1])
    r_f1 = np.array([0, 1])
    r_i2 = np.array([-1, 0])
    r_f2 = np.array([-1, 2])
    #t_i1 = 0
    #t_f1 = 10
    #t_i2 = 5
    #t_f2 = 10
    epsilon = 0.25
    T = 10



    #t_coll = check_collision_linear_segment(t_i1, t_f1, r_i1, r_f1, t_i2, t_f2, r_i2, r_f2, epsilon)
    #print(t_coll)

    r_i = np.array([r_i1, r_i2])
    r_f = np.array([r_f1, r_f2])

    seq0, seq1 = construct_sequences(r_i, r_f, T, epsilon)
    print(seq0)
    print(seq1)
    try:
        print(seq1[0][0]+seq1[1][0])
        print(seq1[0][1]+seq1[1][1])
        print(seq1[0][3]+seq1[1][3])
    except:
        print(":)")


if __name__ == "__main__":
    seq_constr_test()

    