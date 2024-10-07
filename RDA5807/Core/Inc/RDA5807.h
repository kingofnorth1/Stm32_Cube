/*
**==============================================================================
** RDA5807.H:            -- by Dr. ZhuoQing, 2020-01-30
**
**  Description:
**
**==============================================================================
*/
#ifndef __RDA5807__
#define __RDA5807__
//------------------------------------------------------------------------------
#ifdef RDA5807_GLOBALS
   #define RDA5807_EXT
#else
   #define RDA5807_EXT extern
#endif // RDA5807_GLOBALS
//------------------------------------------------------------------------------
//==============================================================================

void RDA5807Init(void);

//------------------------------------------------------------------------------

RDA5807_EXT uint16_t g_nRDA5807Channel;

//------------------------------------------------------------------------------
void RDA5807Setup(void);
void RDA5807I2CWrite(uint8_t * pucData, int nLength);
void RDA5807SetChannel(float freq);



//==============================================================================
//             END OF THE FILE : RDA5807.H
//------------------------------------------------------------------------------
#endif // __RDA5807__
