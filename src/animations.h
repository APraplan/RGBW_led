// #ifndef ANIMATIONS_H
// #define ANIMATIONS_H

// #include <Arduino.h>
// #include "../lib/FastLED-3.6.0/src/FastLED.h"
// #include "../lib/FastLED-3.6.0/src/FastLED_RGBW.h"

// #define NUM_LEDS 129
// #define DATA_PIN 2

// class CLED {

// private:
//     CRGBW leds[NUM_LEDS];
//     CRGB *ledsRGB = (CRGB *) &leds[0];
	
// public:
//     CLED();
//     void addLeds();
// 	void setBrightness(uint8_t scale) { m_Scale = scale; }

// 	/// Get the current global brightness setting
// 	/// @returns the current global brightness value
// 	uint8_t getBrightness() { return m_Scale; }

// 	/// Set the maximum power to be used, given in volts and milliamps.
// 	/// @param volts how many volts the leds are being driven at (usually 5)
// 	/// @param milliamps the maximum milliamps of power draw you want
// 	inline void setMaxPowerInVoltsAndMilliamps(uint8_t volts, uint32_t milliamps) { setMaxPowerInMilliWatts(volts * milliamps); }

// 	/// Set the maximum power to be used, given in milliwatts
// 	/// @param milliwatts the max power draw desired, in milliwatts
// 	inline void setMaxPowerInMilliWatts(uint32_t milliwatts) { m_pPowerFunc = &calculate_max_brightness_for_power_mW; m_nPowerData = milliwatts; }

// 	/// Update all our controllers with the current led colors, using the passed in brightness
// 	/// @param scale the brightness value to use in place of the stored value
// 	void show(uint8_t scale);

// 	/// Update all our controllers with the current led colors
// 	void show() { show(m_Scale); }

// 	/// Clear the leds, wiping the local array of data. Optionally you can also
// 	/// send the cleared data to the LEDs.
// 	/// @param writeData whether or not to write out to the leds as well
// 	void clear(bool writeData = false);

// 	/// Clear out the local data array
// 	void clearData();

// 	/// Set all leds on all controllers to the given color/scale.
// 	/// @param color what color to set the leds to
// 	/// @param scale what brightness scale to show at
// 	void showColor(const struct CRGB & color, uint8_t scale);

// 	/// Set all leds on all controllers to the given color
// 	/// @param color what color to set the leds to
// 	void showColor(const struct CRGB & color) { showColor(color, m_Scale); }

// 	/// Delay for the given number of milliseconds.  Provided to allow the library to be used on platforms
// 	/// that don't have a delay function (to allow code to be more portable). 
// 	/// @note This will call show() constantly to drive the dithering engine (and will call show() at least once).
// 	/// @param ms the number of milliseconds to pause for
// 	void delay(unsigned long ms);

// 	/// Set a global color temperature.  Sets the color temperature for all added led strips,
// 	/// overriding whatever previous color temperature those controllers may have had.
// 	/// @param temp A CRGB structure describing the color temperature
// 	void setTemperature(const struct CRGB & temp);

// 	/// Set a global color correction.  Sets the color correction for all added led strips,
// 	/// overriding whatever previous color correction those controllers may have had.
// 	/// @param correction A CRGB structure describin the color correction.
// 	void setCorrection(const struct CRGB & correction);

// 	/// Set the dithering mode.  Sets the dithering mode for all added led strips, overriding
// 	/// whatever previous dithering option those controllers may have had.
// 	/// @param ditherMode what type of dithering to use, either BINARY_DITHER or DISABLE_DITHER
// 	void setDither(uint8_t ditherMode = BINARY_DITHER);

// 	/// Set the maximum refresh rate.  This is global for all leds.  Attempts to
// 	/// call show() faster than this rate will simply wait.
// 	/// @note The refresh rate defaults to the slowest refresh rate of all the leds added through addLeds().
// 	/// If you wish to set/override this rate, be sure to call setMaxRefreshRate() _after_
// 	/// adding all of your leds.
// 	/// @param refresh maximum refresh rate in hz
// 	/// @param constrain constrain refresh rate to the slowest speed yet set
// 	void setMaxRefreshRate(uint16_t refresh, bool constrain=false);

// 	/// For debugging, this will keep track of time between calls to countFPS(). Every
// 	/// `nFrames` calls, it will update an internal counter for the current FPS.
// 	/// @todo Make this a rolling counter
// 	/// @param nFrames how many frames to time for determining FPS
// 	void countFPS(int nFrames=25);

// 	/// Get the number of frames/second being written out
// 	/// @returns the most recently computed FPS value
// 	uint16_t getFPS() { return m_nFPS; }

// 	/// Get how many controllers have been registered
// 	/// @returns the number of controllers (strips) that have been added with addLeds()
// 	int count();

// 	/// Get a reference to a registered controller
// 	/// @returns a reference to the Nth controller
// 	CLEDController & operator[](int x);

// 	/// Get the number of leds in the first controller
// 	/// @returns the number of LEDs in the first controller
// 	int size() { return (*this)[0].size(); }

// 	/// Get a pointer to led data for the first controller
// 	/// @returns pointer to the CRGB buffer for the first controller
// 	CRGB *leds() { return (*this)[0].leds(); }
// };


//     FastLED.clear(true);
//     // FastLED.setMaxRefreshRate();
    

// void colorFill(CRGBW c, CRGBW *leds, uint8_t numLeds);
// void rainbow(CRGBW *leds, uint8_t numLeds);
// void rainbowLoop(CRGBW *leds, uint8_t numLeds);
// void lightning(CRGBW *leds, uint8_t numLeds);

// extern CLED LED;

// #endif // ANIMATIONS_H