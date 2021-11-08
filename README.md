
# Waspmote: measure & graph lux by time with the tsl2561 sensor

This project is fairly simple. It captures the amount of light shone onto the tsl2561 sensor, then graphs this by time.



## Hardware Requirements

    1. Waspmote v1.5 with SensorBoard
    2. MicroSD Card
    3. TSL2561
## Installation

Install Waspmote_tsl2561_lux_by_time with GIT

```bash
  git clone https://github.com/montygole/Waspmote_tsl2561_lux_by_time.git
  cd Waspmote_tsl2561_lux_by_time
```
Install the Waspmote API & IDE from: https://development.libelium.com/waspmote/software

## Usage

1. Insert MicroSD Card into Waspmote. Place the tsl2561 into socket 5 of your sensorboard. Then compile and upload LUXbyTIME.cpp in your Waspmote IDE.
2. After collecting your data, turn your Waspmote off, and remove the MicroSD Card, place this into your computer.
3. Run Python File, make sure to point to the correct directory of your .TXT data file

