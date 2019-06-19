#ifndef xAI01_h
#define xAI01_h

#include "xCore.h"

#define AI01_AD0 0x70
#define AI01_AD1 0x71
#define AI01_AD2 0x72
#define AI01_AD3 0x73
#define AI01_AD4 0x74
#define AI01_AD5 0x75
#define AI01_AD6 0x76
#define AI01_AD7 0x77

#define MUX_W 3
#define MUX_S 2
#define MUX_E 1
#define MUX_N 0


class xAI01: public xCoreClass
{
	public:
		xAI01();
		xAI01(uint8_t addr);

		bool begin(void);
		bool enableMuxPort(byte portNumber);
		bool disableMuxPort(byte portNumber);

	private:
	
		// PCA9548 Device I2C Address
		uint8_t PCA9548_I2C_ADDRESS;
};

#endif
