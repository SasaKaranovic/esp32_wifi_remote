#ifndef SK_IR_CODES_H
#define SK_IR_CODES_H

// Define Samsung TV IR remote structure
typedef struct Samsung_Remote_t {
  unsigned int  codeLen;
  unsigned long btnOnOff;
  unsigned long btn123;
  unsigned long btnExtra;
  unsigned long btnUp;
  unsigned long btnDown;
  unsigned long btnLeft;
  unsigned long btnRight;
  unsigned long btnOK;
  unsigned long btnReturn;
  unsigned long btnHome;
  unsigned long btnPlayPause;
  unsigned long btnVolUp;
  unsigned long btnVolDown;
  unsigned long btnVolEnter;
  unsigned long btnChUp;
  unsigned long btnChDown;
  unsigned long btnChEnter;
} Samsung_Remote_t;


const Samsung_Remote_t RemoteCodes =
{
  .codeLen      = 32,
  .btnOnOff     = 0xE0E040BF,
  .btn123       = 0xE0E0807f,
  .btnExtra     = 0xE0E0738C,
  .btnUp        = 0xE0E006F9,
  .btnDown      = 0xE0E08679,
  .btnLeft      = 0xE0E0A659,
  .btnRight     = 0xE0E046B9,
  .btnOK        = 0xE0E016E9,
  .btnReturn    = 0xE0E01AE5,
  .btnHome      = 0xE0E09E61,
  .btnPlayPause = 0xE0E09D62,
  .btnVolUp     = 0xE0E0E01F,
  .btnVolDown   = 0xE0E0D02F,
  .btnVolEnter  = 0xE0E0F00F,
  .btnChUp      = 0xE0E048B7,
  .btnChDown    = 0xE0E008F7,
  .btnChEnter   = 0xE0E0F20D,
};

#endif