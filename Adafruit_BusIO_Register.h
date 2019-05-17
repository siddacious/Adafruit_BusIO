#include <Adafruit_I2CDevice.h>
#include <Arduino.h>


#ifndef Adafruit_BusIO_Register_h
#define Adafruit_BusIO_Register_h


class Adafruit_BusIO_Register {
 public:
  Adafruit_BusIO_Register(Adafruit_I2CDevice *device, uint16_t reg_addr, 
		       uint8_t width=1, uint8_t bitorder=LSBFIRST,
		       uint8_t address_width=1); 

  bool read(uint8_t *buffer, uint8_t len);
  bool read(uint8_t *value);
  bool read(uint16_t *value);
  bool read(uint32_t *value);
  uint32_t read(void);
  bool write(uint8_t *buffer, uint8_t len);
  bool write(uint32_t value, uint8_t numbytes=0);

  uint8_t width(void) { return _width; }

  void print(Stream *s=&Serial);
  void println(Stream *s=&Serial);

 private:
  Adafruit_I2CDevice *_device;
  uint16_t _address;
  uint8_t _width, _addrwidth, _bitorder;
  uint8_t _buffer[4];      // we wont support anything larger than uint32 for non-buffered read
};

class Adafruit_BusIO_RegisterBits {
 public:
  Adafruit_BusIO_RegisterBits(Adafruit_BusIO_Register *reg, uint8_t bits, uint8_t shift);
  void write(uint32_t value);
  uint32_t read(void);
 private:
  Adafruit_BusIO_Register *_register;
  uint8_t _bits, _shift;
};


#endif //Adafruit_BusIO_Register_h
