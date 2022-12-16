# EC545 - Smart Home Security
### Boston University - EC545 Cyber Physical System Project on Smart Home Security


#### The motivation of the project is twofold:
1. Simulate some aspects of a smart home at small scale - both daily life and security functions.
2. Simulate how both smarthome and home-owner might respond to an attack from a malicious hacker. 

#### The goal:
1. Create a functional floor-plan model, on which the homeowner and the hacker will play a game of “cat and mouse”. 
2. The goal of the hacker is to access a room and retrieve a specific item without getting caught by the homeowner.

#### Demonstrate core concepts learned in class. 
1. Sensors and Actuators
2. Temporal Logic Specification
3. UPPAAL
4. Scheduling (Preemptive Priority-Based)
5. Security

#### Objective
1. The Internet of Things (IoT) is everywhere, but its security isn’t, which is a problem - a growing problem.
2. Demonstrate how smart home systems are vulnerable to different verticals of cyberattacks
3. Identify security faults in RF-based ‘authentication’ systems 
4. Unauthorized external access(intruders) through cloning RFID keys.
5. Design model that replicates some of the components used within a real smart home system. 
6. Explore existing and possible new solutions to these vulnerabilities
7. Suggest possible mitigation strategies

#### Specification of Attack Vectors
1. Smart light of the rooms working on 433MHz relay switch is to be attacked based on either jamming or replay attack using HackRF One.
2. Door access management system having RFID as security layer is to be attacked using Proxmark3 to clone the mifare cards.
3. Functionality of IR controlled led lights to be replicated using FlipperZero.
4. Attack strategy against victim in different cases: house owner present(safety first); house owner absent;
5. Arduino-mega using WiFi to control the system need to be dissociated using Alfa WiFi chip / ESP8266 in promiscuous mode. 

#### Specifications of System
1. When a person present in room, lights won’t turn off unless there is manual control through the app/remote controller/switch.
2. When there is no one in the house, all the light should turned off within 5 minutes after the person leave the house.
3. Can distinct between the intruder and house owner, hence trigger the defence mode.
4. Defence strategy against intruder in different cases: house owner present(safety first); house owner absent; 
5. Also, for different kind of invasion : physical/cyber;
6. Two Arduinos: MEGA used for automated functions (e.g. occupancy-based lighting), Wifi-Module Arduino interfaces with the MEGA - overwrites automated commands based on input through phone application. 
