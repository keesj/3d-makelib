M&M sorting machine

See http://youtu.be/gFbJhNDCt2I for a demo


"Schematics"
  5v ------------------------------------------------------
                                    |                     |
                                   LDR                    |
                                    |                     |
  Arduino    - A0 (analog int)------+-----[10K]--GND      |
                                                          |
                                  Red LED                 |
             - 3  -----------------|>----[330]--GND       |
                                                          |
                                  Blue LED                |
             - 4  -----------------|>----[330]--GND       |
                                                          |
             - 9 ---------------------------------------Servo--GND

