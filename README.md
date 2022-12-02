# TCS34725

Arduino library for TCS34725 RGB Color Sensor.

## Description

This library is partially ported from this [circuitpython library](https://github.com/adafruit/Adafruit_CircuitPython_TCS34725).

- optimized performance (no suspend caused by ```delay()```)
- easily check if measurement cycle has done
- lux and color temperature calculation (ported from [here](https://github.com/adafruit/Adafruit_CircuitPython_TCS34725))
- interrupt feature is automatically enabled
- various parameter adjustment through APIs

## Examples

As with all Arduino libraries, I recommend either copying to the libaries subfolder of your sketchbook directory, or (as I prefer) create a symbolic link there to the location where you actually installed it, i.e.:
```
mklink /D C:\Users\alast\Documents\Arduino\libraries\TCS34725 C:\Users\alast\Documents\GitHub\TCS34725
```

This will enable you to load example sketches in the Arduino IDE by going to _File > Examples > Examples from Custom Libraries_

 - *ColourSensor* demonstrates basic functionality of connecting to the sensor and printing out raw colour data, gamma-adjusted RGB values, lux, and colour temperature to the serial monitor
 - *MultipleSensors* demonstrates how to read 3 TCS34725 sensors connected via a TCA9548A I2C multiplexer
 - *ColourIdentifier* demonstrates how to recognise between a set of named colours using a classification model trained through machine learning. Training data is created by copying a set of comma-delimited, floating-point values from the serial monitor, one feature per-line. This is then used to train a SciKit-Learn classification function, which is exported to a format that can be re-used in the Arduino sketch. 
Python dependencies for creating the model are as follows: 
``` 
pip install -U scikit-learn
pip install micromlgen
```
And the code to generate the model is:
```
# For loading training dataset from .csv files
import numpy as np
from glob import glob
from os.path import basename
# For classifier function
from sklearn.ensemble import RandomForestClassifier
# For exporting model to Arduino C code
from micromlgen import port

# Load training dataset from csv files 
def load_features(folder):
    dataset = None
    classmap = {}
    for class_idx, filename in enumerate(glob('%s/*.csv' % folder)):
        class_name = basename(filename)[:-4]
        classmap[class_idx] = class_name
        samples = np.loadtxt(filename, dtype=float, delimiter=',')
        labels = np.ones((len(samples), 1)) * class_idx
        samples = np.hstack((samples, labels))
        dataset = samples if dataset is None else np.vstack((dataset, samples))

    return dataset, classmap

# Apply classification function
def get_classifier(features):
    X, y = features[:, :-1], features[:, -1]
    return RandomForestClassifier(20, max_depth=10).fit(X, y)

# Load data, apply classifier, output as Arduino format 
if __name__ == '__main__':
    features, classmap = load_features('csv')
    classifier = get_classifier(features)
    c_code = port(classifier, classmap=classmap)
    print(c_code)
```
(this is also contained in the "extras" folder of the repository)

Note that the TCS34725 sensor uses a fixed I2C address of 0x29, which cannot be changed. So, if you want to use a TCS34725 on an I2C bus shared with other sensors that use the same address (such as the [common CAP1188 or VL53L0X sensors](https://i2cdevices.org/addresses/0x29)), or if you want to use more than one TCS34725 sensor, you'll need to use an I2C multiplexer such as the TCA9548A - an example is provided.

## Usage

``` C++
#include "TCS34725.h"
TCS34725 tcs;

void setup(void)
{
    Serial.begin(115200);

    Wire.begin();
    if (!tcs.attach(Wire))
        Serial.println("ERROR: TCS34725 NOT FOUND !!!");

    tcs.integrationTime(33); // ms
    tcs.gain(TCS34725::Gain::X01);

    // set LEDs...
}

void loop(void)
{
    if (tcs.available()) // if current measurement has done
    {
        TCS34725::Color color = tcs.color();
        Serial.print("Color Temp : "); Serial.println(tcs.colorTemperature());
        Serial.print("Lux        : "); Serial.println(tcs.lux());
        Serial.print("R          : "); Serial.println(color.r);
        Serial.print("G          : "); Serial.println(color.g);
        Serial.print("B          : "); Serial.println(color.b);
    }
}
```

## Parameter Adjustment

### Integration Time

Integration time for RGBC measurement can be set in millisecond.
The parameter range is from 2.4ms to 614.4ms.

``` C++
    void integrationTime(float ms) // 2.4 - 614.4 ms
```

### Gain

The gain of TCS can be set like:

``` C++
    tcs.gain(TCS34725::Gain::X01);
```

and you can choose gains as follows.

``` C++
    enum class Gain : uint8_t { X01, X04, X16, X60 };
```

### RGB Scaling

When RGB color is calculated, simple scaling by pow() is applied.

``` C++
    rgb_clr = pow(raw_rgb / raw_clear, scaling) * 255.f;
```

Default scaling parameter is 2.4, and if you want to disable it, please set to 1.0.

``` C++
    tcs.scale(2.5); // default
    tcs.scale(1.0); // disable scaling
```

### Glass Attenuation

This parameter is applied when lux and color temperature is calculated.
Please see [this library](https://github.com/adafruit/Adafruit_CircuitPython_TCS34725) for detail.

``` C++
    // The Glass Attenuation (FA) factor used to compensate for lower light
    // levels at the device due to the possible presence of glass. The GA is
    // the inverse of the glass transmissivity (T), so GA = 1/T. A transmissivity
    // of 50% gives GA = 1 / 0.50 = 2. If no glass is present, use GA = 1.
    // See Application Note: DN40-Rev 1.0 Ã¢â‚¬â€œ Lux and CCT Calculations using
    // ams Color Sensors for more details.
    tcs.glassAttenuation(1.0); // default: no glass
    tcs.glassAttenuation(0.5); // glass factor 50%
```

## APIs

``` C++
    struct Color { float r, g, b; };
    union RawData
    {
        struct
        {
            uint16_t c;
            uint16_t r;
            uint16_t g;
            uint16_t b;
        };
        uint8_t raw[sizeof(uint16_t) * 4];
    };

    bool attach(WireType& w = Wire)
    void power(bool b)
    void enableColorTempAndLuxCalculation(bool b)

    void integrationTime(float ms) // 2.4 - 614.4 ms
    void gain(Gain g)
    void scale(float s)
    void glassAttenuation(float v)
    void persistence(uint16_t data)

    bool available()

    const RawData& raw() const
    const Color& color() const
    float lux() const
    float colorTemperature() const

    void interrupt(bool b)
    void clearInterrupt()

    // to manipulate registers, please use these APIs
    void write8(Reg reg, uint8_t value)
    uint8_t read8(Reg reg)
    uint16_t read16(Reg reg)
```

## Raw Register Manipulation

``` C++
    enum class Reg : uint8_t
    {
        ENABLE = 0x00,
        ATIME = 0x01,
        WTIME = 0x03,
        AILTL = 0x04,
        AILTH = 0x05,
        AIHTL = 0x06,
        AIHTH = 0x07,
        PERS = 0x0C,
        CONFIG = 0x0D,
        CONTROL = 0x0F,
        ID = 0x12,
        STATUS = 0x13,
        CDATAL = 0x14,
        CDATAH = 0x15,
        RDATAL = 0x16,
        RDATAH = 0x17,
        GDATAL = 0x18,
        GDATAH = 0x19,
        BDATAL = 0x1A,
        BDATAH = 0x1B,
    };

    enum class Mask : uint8_t
    {
        ENABLE_AIEN = 0x10,
        ENABLE_WEN = 0x08,
        ENABLE_AEN = 0x02,
        ENABLE_PON = 0x01,
        STATUS_AINT = 0x10,
        STATUS_AVALID = 0x01
    };
```


## License

MIT
