/**
 @file FT8xx.h
 */
/*
 * ============================================================================
 * History
 * =======
 * Nov 2019        Initial beta for FT81x and FT80x
 * Mar 2020        Updated beta - added BT815/6 commands
 * Mar 2021        Beta with BT817/8 support added
 * Nov 2023        Added BT88x definitions, added CMD_FLASHPROGRAM
 *
 *
 *
 *
 * (C) Copyright,  Bridgetek Pte. Ltd.
 * ============================================================================
 *
 * This source code ("the Software") is provided by Bridgetek Pte Ltd
 * ("Bridgetek") subject to the licence terms set out
 * http://www.ftdichip.com/FTSourceCodeLicenceTerms.htm ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar) in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of Bridgetek liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on Bridgetek's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, Bridgetek
 * has no liability in relation to those amendments.
 * ============================================================================
 */

#ifndef _FT8XX_H_
#define    _FT8XX_H_

/* Definitions used for target device selection */
#define FT800 800
#define FT801 801
#define FT810 810
#define FT811 811
#define FT812 812
#define FT813 813
#define BT880 880
#define BT881 881
#define BT882 882
#define BT883 883
#define BT815 815
#define BT816 816
#define BT817 817
#define BT818 818
#define BT820 820

/* For capacitive versions */
#define CTOUCH_MODE_COMPATIBILITY 1
#define CTOUCH_MODE_EXTENDED 0

#undef EVE_API
#undef EVE_SUB_API

#if (FT8XX_TYPE == FT800)
#define EVE_API 1

#elif (FT8XX_TYPE == FT801)
#define EVE_API 1

#elif (FT8XX_TYPE == FT810)
#define EVE_API 2
#define EVE_SUB_API 1

#elif (FT8XX_TYPE == FT811)
#define EVE_API 2
#define EVE_SUB_API 1

#elif (FT8XX_TYPE == FT812)
#define EVE_API 2
#define EVE_SUB_API 1

#elif (FT8XX_TYPE == FT813)
#define EVE_API 2
#define EVE_SUB_API 1

#elif (FT8XX_TYPE == BT880)
#define EVE_API 2
#define EVE_SUB_API 2

#elif (FT8XX_TYPE == BT881)
#define EVE_API 2
#define EVE_SUB_API 2

#elif (FT8XX_TYPE == BT882)
#define EVE_API 2
#define EVE_SUB_API 2

#elif (FT8XX_TYPE == BT883)
#define EVE_API 2
#define EVE_SUB_API 2

#elif (FT8XX_TYPE == BT815)
#define EVE_API 3

#elif (FT8XX_TYPE == BT816)
#define EVE_API 3

#elif (FT8XX_TYPE == BT817)
#define EVE_API 4

#elif (FT8XX_TYPE == BT818)
#define EVE_API 4

#elif (FT8XX_TYPE == BT820)
#define EVE_API 5

#else
#warning FT8XX_TYPE definition not recognised.
#endif

#undef EVE1_ENABLE // deprecated
#undef EVE2_ENABLE // deprecated
#undef EVE3_ENABLE // deprecated
#undef EVE4_ENABLE // deprecated
#undef EVE5_ENABLE // deprecated
#if EVE_API == 1
#undef EVE1_ENABLE // deprecated
#elif EVE_API == 2
#undef EVE2_ENABLE // deprecated
#elif EVE_API == 3
#undef EVE3_ENABLE // deprecated
#elif EVE_API == 4
#undef EVE4_ENABLE // deprecated
#elif EVE_API == 5
#undef EVE5_ENABLE // deprecated
#endif

/** Macros to allow us to select which API a command applies to.
 * For APIs supported use the following:
 *  
 * #if IS_EVE_API(api1, api2, ...)
 * 
 * Where the APIs supported are in the macro parenthesis. The EVE 
 * API is set in the EVE_API macro.
 * So, to support BT815, BT817, BT820 this will need EVE APIs 3, 4, and 5.
 *
 * #if IS_EVE_API(3,4,5)
  */
#define _NUM_ARGS2(X,X5,X4,X3,X2,X1,N,...) N
#define NUM_ARGS(...) _NUM_ARGS2(0, __VA_ARGS__ ,5,4,3,2,1,0)

#define IS_EVE_API_1(a)     (a == EVE_API)
#define IS_EVE_API_2(a,b)   (IS_EVE_API_1(a) | IS_EVE_API_1(b))
#define IS_EVE_API_3(a,...) (IS_EVE_API_1(a) | IS_EVE_API_2(__VA_ARGS__))
#define IS_EVE_API_4(a,...) (IS_EVE_API_1(a) | IS_EVE_API_3(__VA_ARGS__))
#define IS_EVE_API_5(a,...) (IS_EVE_API_1(a) | IS_EVE_API_4(__VA_ARGS__))

#define _IS_EVE_API_N(N, ...) IS_EVE_API_ ## N(__VA_ARGS__)
#define _IS_EVE_API(N, ...)  _IS_EVE_API_N(N, __VA_ARGS__)
#define IS_EVE_API(...)      _IS_EVE_API(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)

/** EVE API definitions. */

#if IS_EVE_API(1)

//###########################################################################
//#####################################  EVE 1 ##############################
//###########################################################################

/* For FT81x enable the switch in platform.h file */

// Clock lower boundary of trimming
#define EVE_LOW_FREQ_BOUND             47040000L//98% of 48Mhz

// Memory Map

#define EVE_RAM_G                      0x0ul           // RAM_G
#define EVE_RAM_G_SIZE                 (256*1024L)
#define EVE_ROM_CHIPID                 0x0c0000UL      // Chip ID
#define EVE_ROM_FONT                   0x0bb23cUL      // Font table and bitmap
#define EVE_ROMFONT_TABLEADDRESS       0x0ffffcUL      // Font table pointer address
#define EVE_RAM_DL                     0x100000UL      // RAM_DL
#define EVE_RAM_DL_SIZE                (8*1024L)
#define EVE_RAM_PAL                    0x102000UL      // Palette RAM
#define EVE_RAM_REG                    0x102400UL      // Registers
#define EVE_RAM_CMD                    0x108000UL      // RAM_CMD
#define EVE_RAM_CMD_SIZE               (4*1024L)

// Display Registers 

#define EVE_REG_PCLK                   0x10246cUL
#define EVE_REG_PCLK_POL               0x102468UL
#define EVE_REG_CSPREAD                0x102464UL
#define EVE_REG_SWIZZLE                0x102460UL
#define EVE_REG_DITHER                 0x10245cUL
#define EVE_REG_OUTBITS                0x102458UL
#define EVE_REG_ROTATE                 0x102454UL
#define EVE_REG_VSYNC1                 0x10244cUL
#define EVE_REG_VSYNC0                 0x102448UL
#define EVE_REG_VSIZE                  0x102444UL
#define EVE_REG_VOFFSET                0x102440UL
#define EVE_REG_VCYCLE                 0x10243cUL
#define EVE_REG_HSYNC1                 0x102438UL
#define EVE_REG_HSYNC0                 0x102434UL
#define EVE_REG_HSIZE                  0x102430UL
#define EVE_REG_HOFFSET                0x10242cUL
#define EVE_REG_HCYCLE                 0x102428UL

#define EVE_REG_TAP_MASK               0x102424UL
#define EVE_REG_TAP_CRC                0x102420UL

#define EVE_REG_DLSWAP                 0x102450UL

// Touch Registers 

#define EVE_REG_TAG                    0x102478UL
#define EVE_REG_TAG_Y                  0x102474UL
#define EVE_REG_TAG_X                  0x102470UL

#define EVE_REG_TOUCH_ADC_MODE         0x1024f4UL
#define EVE_REG_TOUCH_SCREEN_XY        0x102510UL
#define EVE_REG_TOUCH_RAW_XY           0x102508UL
#define EVE_REG_TOUCH_DIRECT_XY        0x102574UL
#define EVE_REG_TOUCH_DIRECT_Z1Z2      0x102578UL
#define EVE_REG_ANALOG                 0x102538UL
#define EVE_REG_TOUCH_RZ               0x10250cUL
#define EVE_REG_TOUCH_TRANSFORM_A      0x10251cUL
#define EVE_REG_TOUCH_TRANSFORM_B      0x102520UL
#define EVE_REG_TOUCH_TRANSFORM_C      0x102524UL
#define EVE_REG_TOUCH_TRANSFORM_D      0x102528UL
#define EVE_REG_TOUCH_TRANSFORM_E      0x10252cUL
#define EVE_REG_TOUCH_TRANSFORM_F      0x102530UL
#define EVE_REG_TOUCH_TAG              0x102518UL
// FT801 specific mapped to same addresses as FT800 above
#define EVE_REG_CTOUCH_EXTENDED        0x1024f4UL
#define EVE_REG_CTOUCH_TOUCH0_XY       0x102510UL
#define EVE_REG_CTOUCH_RAW_XY          0x102508UL   // FT801 Compatibility mode
#define EVE_REG_CTOUCH_TOUCH1_XY       0x102508UL   // FT801 Extended mode
#define EVE_REG_CTOUCH_TOUCH2_XY       0x102574UL   // FT801 Extended mode
#define EVE_REG_CTOUCH_TOUCH3_XY       0x102578UL   // FT801 Extended mode
#define EVE_REG_CTOUCH_TOUCH4_X        0x102538UL   // FT801 Extended mode
#define EVE_REG_CTOUCH_TOUCH4_Y        0x10250cUL   // FT801 Extended mode
#define EVE_REG_CTOUCH_TRANSFORM_A     0x10251cUL
#define EVE_REG_CTOUCH_TRANSFORM_B     0x102520UL
#define EVE_REG_CTOUCH_TRANSFORM_C     0x102524UL
#define EVE_REG_CTOUCH_TRANSFORM_D     0x102528UL
#define EVE_REG_CTOUCH_TRANSFORM_E     0x10252cUL
#define EVE_REG_CTOUCH_TRANSFORM_F     0x102530UL
#define EVE_REG_CTOUCH_TAG             0x102518UL

#define EVE_REG_TOUCH_TAG_XY           0x102514UL
#define EVE_REG_TOUCH_RZTHRESH         0x102504UL
#define EVE_REG_TOUCH_OVERSAMPLE       0x102500UL
#define EVE_REG_TOUCH_SETTLE           0x1024fcUL
#define EVE_REG_TOUCH_CHARGE           0x1024f8UL
#define EVE_REG_TOUCH_MODE             0x1024f0UL

// Media Registers

#define EVE_REG_PLAY                   0x102488UL
#define EVE_REG_SOUND                  0x102484UL
#define EVE_REG_VOL_SOUND              0x102480UL
#define EVE_REG_VOL_PB                 0x10247cUL
#define EVE_REG_PLAYBACK_PLAY          0x1024bcUL
#define EVE_REG_PLAYBACK_LOOP          0x1024b8UL
#define EVE_REG_PLAYBACK_FORMAT        0x1024b4UL
#define EVE_REG_PLAYBACK_FREQ          0x1024b0UL
#define EVE_REG_PLAYBACK_READPTR       0x1024acUL
#define EVE_REG_PLAYBACK_LENGTH        0x1024a8UL
#define EVE_REG_PLAYBACK_START         0x1024a4UL

// Display List Registers

#define EVE_REG_CMD_DL                 0x1024ecUL
#define EVE_REG_CMD_WRITE              0x1024e8UL
#define EVE_REG_CMD_READ               0x1024e4UL

// Tracking Registers

#define EVE_REG_TRACK                  0x109000UL

// PWM Registers

#define EVE_REG_PWM_DUTY               0x1024c4UL
#define EVE_REG_PWM_HZ                 0x1024c0UL

// Interrupt Registers

#define EVE_REG_INT_MASK               0x1024a0UL
#define EVE_REG_INT_EN                 0x10249cUL
#define EVE_REG_INT_FLAGS              0x102498UL
#define EVE_REG_GPIO                   0x102490UL
#define EVE_REG_GPIO_DIR               0x10248cUL
#define EVE_REG_CPURESET               0x10241cUL

// Screenshot Registers

#define EVE_REG_SCREENSHOT_READ        0x102554UL
#define EVE_REG_SCREENSHOT_BUSY        0x1024d8UL
#define EVE_REG_SCREENSHOT_START       0x102418UL   //
#define EVE_REG_SCREENSHOT_Y           0x102414UL   //
#define EVE_REG_SCREENSHOT_EN          0x102410UL   //

// Clock Registers

#define EVE_REG_FREQUENCY              0x10240cUL
#define EVE_REG_CLOCK                  0x102408UL
#define EVE_REG_FRAMES                 0x102404UL
#define EVE_REG_ID                     0x102400UL
#define EVE_REG_TRIM                   0x10256cUL

// Macro Registers

#define EVE_REG_MACRO_0                0x1024c8UL
#define EVE_REG_MACRO_1                0x1024ccUL

#define EVE_REG_ROMSUB_SEL             0x1024e0UL

// Bitmap Address Mask 

#define EVE_ENC_BITMAP_ADDR_MASK       0xfffffUL

// Encoded Command Macros

#define EVE_ENC_ALPHA_FUNC(func,ref)        ((0x9UL << 24)|(((func) & 0x7UL) << 8)|(((ref) & 0xffUL) << 0))
#define EVE_ENC_BEGIN(prim)                 ((0x1fUL << 24)|(((prim) & 0xFUL) << 0))
#define EVE_ENC_BITMAP_HANDLE(handle)       ((0x5UL << 24)|(((handle) & 0x1fUL) << 0))
#define EVE_ENC_BITMAP_LAYOUT(format,linestride,height) ((0x7UL << 24)|(((format) & 0x1fUL) << 19)|(((linestride) & 0x3ffUL) << 9)|(((height) & 0x1ffUL) << 0))
#define EVE_ENC_BITMAP_SIZE(filter,wrapx,wrapy,width,height) ((0x8UL << 24)|(((filter) & 0x1UL) << 20)|(((wrapx) & 0x1UL) << 19)|(((wrapy) & 0x1UL) << 18)|(((width) & 0x1ffUL) << 9)|(((height) & 0x1ffUL) << 0))
#define EVE_ENC_BITMAP_SOURCE(addr)         ((0x1UL << 24) | ((addr)&EVE_ENC_BITMAP_ADDR_MASK))
#define EVE_ENC_BITMAP_TRANSFORM_A(a)       ((0x15UL << 24)|((((uint32_t)(a)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_B(b)       ((0x16UL << 24)|((((uint32_t)(b)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_C(c)       ((0x17UL << 24)|((((uint32_t)(c)) & 0xFFFFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_D(d)       ((0x18UL << 24)|((((uint32_t)(d)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_E(e)       ((0x19UL << 24)|((((uint32_t)(e)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_F(f)       ((0x1aUL << 24)|((((uint32_t)(f)) & 0xFFFFFFUL) << 0))
#define EVE_ENC_BLEND_FUNC(src,dst)         ((0xbUL << 24)|(((src) & 0x7UL) << 3)|(((dst) & 0x7UL) << 0))
#define EVE_ENC_CALL(dest)                  ((0x1dUL << 24)|(((dest) & 0xFFFFUL) << 0))
#define EVE_ENC_CELL(cell)                  ((0x6UL << 24)|(((cell) & 0x7fUL) << 0))
#define EVE_ENC_CLEAR_COLOR_A(alpha)        ((0xfUL << 24)|(((alpha) & 0xffUL) << 0))
#define EVE_ENC_CLEAR_COLOR_RGB(red,green,blue) ((0x2UL << 24)|(((red) & 0xffUL) << 16)|(((green) & 0xffUL) << 8)|(((blue) & 0xffUL) << 0))
#define EVE_ENC_CLEAR_COLOR(c)              ((0x2UL << 24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_CLEAR_STENCIL(s)            ((0x11UL << 24)|((((uint32_t)(s)) & 0xffUL) << 0))
#define EVE_ENC_CLEAR_TAG(s)                ((0x12UL << 24)|((((uint32_t)(s)) & 0xffUL) << 0))
#define EVE_ENC_CLEAR(c,s,t)                ((0x26UL << 24)|((((uint32_t)(c)) & 0x1UL) << 2)|((((uint32_t)(s)) & 0x1UL) << 1)|((((uint32_t)(t)) & 0x1UL) << 0))
#define EVE_ENC_COLOR_A(alpha)              ((0x10UL << 24)|(((alpha) & 0xffUL) << 0))
#define EVE_ENC_COLOR_MASK(r,g,b,a)         ((0x20UL << 24)|((((uint32_t)(r)) & 0x1UL) << 3)|((((uint32_t)(g)) & 0x1UL) << 2)|((((uint32_t)(b)) & 0x1UL) << 1)|((((uint32_t)(a)) & 0x1UL) << 0))
#define EVE_ENC_COLOR_RGB(red,green,blue)   ((0x4UL << 24)|(((red) & 0xffUL) << 16)|(((green) & 0xffUL) << 8)|(((blue) & 0xffUL) << 0))
#define EVE_ENC_COLOR(c)                    ((0x4UL << 24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_DISPLAY()                   ((0x0UL << 24))
#define EVE_ENC_END()                       ((0x21UL << 24))
#define EVE_ENC_JUMP(dest)                  ((0x1eUL << 24)|(((dest) & 0xFFFFUL) << 0))
#define EVE_ENC_LINE_WIDTH(width)           ((0xeUL << 24)|(((width) & 0xFFFUL) << 0))
#define EVE_ENC_MACRO(m)                    ((0x25UL << 24)|((((uint32_t)(m)) & 0x1UL) << 0))
#define EVE_ENC_POINT_SIZE(size)            ((0xdUL << 24)|(((size) & 0x1FFFUL) << 0))
#define EVE_ENC_RESTORE_CONTEXT()           ((0x23UL << 24))
#define EVE_ENC_RETURN()                    ((0x24UL << 24))
#define EVE_ENC_SAVE_CONTEXT()              ((0x22UL << 24))
#define EVE_ENC_SCISSOR_SIZE(width,height)  ((0x1cUL << 24)|(((width) & 0x3ffUL) << 10)|(((height) & 0x3ffUL) << 0))
#define EVE_ENC_SCISSOR_XY(x,y)             ((0x1bUL << 24)|((((uint32_t)(x)) & 0x1ffUL) << 9)|((((uint32_t)(y)) & 0x1ffUL) << 0))
#define EVE_ENC_STENCIL_FUNC(func,ref,mask) ((0xaUL << 24)|(((func) & 0x7UL) << 16)|(((ref) & 0xffUL) << 8)|(((mask) & 0xffUL) << 0))
#define EVE_ENC_STENCIL_MASK(mask)          ((0x13UL << 24)|(((mask) & 0xffUL) << 0))
#define EVE_ENC_STENCIL_OP(sfail,spass)     ((0xcUL << 24)|(((sfail) & 0x7UL) << 3)|(((spass) & 0x7UL) << 0))
#define EVE_ENC_TAG_MASK(mask)              ((0x14UL << 24)|(((mask) & 0x1UL) << 0))
#define EVE_ENC_TAG(s)                      ((0x3UL << 24)|((((uint32_t)(s)) & 0xffUL) << 0))
#define EVE_ENC_VERTEX2F(x,y)               ((0x1UL << 30)|((((uint32_t)(x)) & 0xffffUL) << 15)|((((uint32_t)(y)) & 0xffffUL) << 0))
#define EVE_ENC_VERTEX2II(x,y,handle,cell)  ((0x2UL << 30)|((((uint32_t)(x)) & 0x1ffUL) << 21)|((((uint32_t)(y)) & 0x1ffUL) << 12)|(((handle) & 0x1fUL) << 7)|(((cell) & 0x7fUL) << 0))

// Co-processor Commands

#define EVE_ENC_CMD_APPEND             0xffffff1eUL
#define EVE_ENC_CMD_BGCOLOR            0xffffff09UL
#define EVE_ENC_CMD_BITMAP_TRANSFORM   0xffffff21UL
#define EVE_ENC_CMD_BUTTON             0xffffff0dUL
#define EVE_ENC_CMD_CALIBRATE          0xffffff15UL
#define EVE_ENC_CMD_CLOCK              0xffffff14UL
#define EVE_ENC_CMD_COLDSTART          0xffffff32UL
#define EVE_ENC_CMD_CRC                0xffffff03UL
#define EVE_ENC_CMD_CSKETCH            0xffffff35UL
#define EVE_ENC_CMD_DIAL               0xffffff2dUL
#define EVE_ENC_CMD_DLSTART            0xffffff00UL
#define EVE_ENC_CMD_EXECUTE            0xffffff07UL
#define EVE_ENC_CMD_FGCOLOR            0xffffff0aUL
#define EVE_ENC_CMD_GAUGE              0xffffff13UL
#define EVE_ENC_CMD_GETMATRIX          0xffffff33UL
#define EVE_ENC_CMD_GETPOINT           0xffffff08UL
#define EVE_ENC_CMD_GETPROPS           0xffffff25UL
#define EVE_ENC_CMD_GETPTR             0xffffff23UL
#define EVE_ENC_CMD_GRADCOLOR          0xffffff34UL
#define EVE_ENC_CMD_GRADIENT           0xffffff0bUL
#define EVE_ENC_CMD_HAMMERAUX          0xffffff04UL
#define EVE_ENC_CMD_IDCT               0xffffff06UL
#define EVE_ENC_CMD_INFLATE            0xffffff22UL
#define EVE_ENC_CMD_INTERRUPT          0xffffff02UL
#define EVE_ENC_CMD_KEYS               0xffffff0eUL
#define EVE_ENC_CMD_LOADIDENTITY       0xffffff26UL
#define EVE_ENC_CMD_LOADIMAGE          0xffffff24UL
#define EVE_ENC_CMD_LOGO               0xffffff31UL
#define EVE_ENC_CMD_MARCH              0xffffff05UL
#define EVE_ENC_CMD_MEMCPY             0xffffff1dUL
#define EVE_ENC_CMD_MEMCRC             0xffffff18UL
#define EVE_ENC_CMD_MEMSET             0xffffff1bUL
#define EVE_ENC_CMD_MEMWRITE           0xffffff1aUL
#define EVE_ENC_CMD_MEMZERO            0xffffff1cUL
#define EVE_ENC_CMD_NUMBER             0xffffff2eUL
#define EVE_ENC_CMD_PROGRESS           0xffffff0fUL
#define EVE_ENC_CMD_REGREAD            0xffffff19UL
#define EVE_ENC_CMD_ROTATE             0xffffff29UL
#define EVE_ENC_CMD_SCALE              0xffffff28UL
#define EVE_ENC_CMD_SCREENSAVER        0xffffff2fUL
#define EVE_ENC_CMD_SCROLLBAR          0xffffff11UL
#define EVE_ENC_CMD_SETFONT            0xffffff2bUL
#define EVE_ENC_CMD_SETMATRIX          0xffffff2aUL
#define EVE_ENC_CMD_SKETCH             0xffffff30UL
#define EVE_ENC_CMD_SLIDER             0xffffff10UL
#define EVE_ENC_CMD_SNAPSHOT           0xffffff1fUL
#define EVE_ENC_CMD_SPINNER            0xffffff16UL
#define EVE_ENC_CMD_STOP               0xffffff17UL
#define EVE_ENC_CMD_SWAP               0xffffff01UL
#define EVE_ENC_CMD_TEXT               0xffffff0cUL
#define EVE_ENC_CMD_TOGGLE             0xffffff12UL
#define EVE_ENC_CMD_TOUCH_TRANSFORM    0xffffff20UL
#define EVE_ENC_CMD_TRACK              0xffffff2cUL
#define EVE_ENC_CMD_TRANSLATE          0xffffff27UL

// Bitmap Formats

#define EVE_FORMAT_ARGB1555            0x0UL
#define EVE_FORMAT_ARGB2               0x5UL
#define EVE_FORMAT_ARGB4               0x6UL
#define EVE_FORMAT_BARGRAPH            0xbUL
#define EVE_FORMAT_L1                  0x1UL
#define EVE_FORMAT_L4                  0x2UL
#define EVE_FORMAT_L8                  0x3UL
#define EVE_FORMAT_PALETTED            0x8UL
#define EVE_FORMAT_RGB332              0x4UL
#define EVE_FORMAT_RGB565              0x7UL
#define EVE_FORMAT_TEXT8X8             0x9UL
#define EVE_FORMAT_TEXTVGA             0xaUL

// Command Options

#define EVE_BEGIN_BITMAPS              0x1UL
#define EVE_BEGIN_EDGE_STRIP_A         0x7UL
#define EVE_BEGIN_EDGE_STRIP_B         0x8UL
#define EVE_BEGIN_EDGE_STRIP_L         0x6UL
#define EVE_BEGIN_EDGE_STRIP_R         0x5UL
#define EVE_BEGIN_LINE_STRIP           0x4UL
#define EVE_BEGIN_LINES                0x3UL
#define EVE_BEGIN_POINTS               0x2UL
#define EVE_BEGIN_RECTS                0x9UL

#define EVE_TEST_ALWAYS                0x7UL
#define EVE_TEST_EQUAL                 0x5UL
#define EVE_TEST_GEQUAL                0x4UL
#define EVE_TEST_GREATER               0x3UL
#define EVE_TEST_LEQUAL                0x2UL
#define EVE_TEST_LESS                  0x1UL
#define EVE_TEST_NEVER                 0x0UL
#define EVE_TEST_NOTEQUAL              0x6UL

#define EVE_FILTER_BILINEAR            0x1UL
#define EVE_FILTER_NEAREST             0x0UL

#define EVE_WRAP_BORDER                0x0UL
#define EVE_WRAP_REPEAT                0x1UL

#define EVE_BLEND_DST_ALPHA            0x3UL
#define EVE_BLEND_ONE                  0x1UL
#define EVE_BLEND_ONE_MINUS_DST_ALPHA  0x5UL
#define EVE_BLEND_ONE_MINUS_SRC_ALPHA  0x4UL
#define EVE_BLEND_SRC_ALPHA            0x2UL
#define EVE_BLEND_ZERO                 0x0UL

#define EVE_STENCIL_DECR               0x4UL
#define EVE_STENCIL_INCR               0x3UL
#define EVE_STENCIL_INVERT             0x5UL
#define EVE_STENCIL_KEEP               0x1UL
#define EVE_STENCIL_REPLACE            0x2UL
#define EVE_STENCIL_ZERO               0x0UL

#define EVE_OPT_3D                     0x0UL
#define EVE_OPT_CENTER                 0x600UL
#define EVE_OPT_CENTERX                0x200UL
#define EVE_OPT_CENTERY                0x400UL
#define EVE_OPT_FLAT                   0x100UL
#define EVE_OPT_MONO                   0x1UL
#define EVE_OPT_NOBACK                 0x1000UL
#define EVE_OPT_NODL                   0x2UL
#define EVE_OPT_NOHANDS                0xc000UL
#define EVE_OPT_NOHM                   0x4000UL
#define EVE_OPT_NOPOINTER              0x4000UL
#define EVE_OPT_NOSECS                 0x8000UL
#define EVE_OPT_NOTICKS                0x2000UL
#define EVE_OPT_RGB565                 0x0UL
#define EVE_OPT_RIGHTX                 0x800UL
#define EVE_OPT_SIGNED                 0x100UL

#define EVE_DLSWAP_DONE                0x0UL
#define EVE_DLSWAP_FRAME               0x2UL
#define EVE_DLSWAP_LINE                0x1UL

#define EVE_INT_CMDEMPTY               0x20UL
#define EVE_INT_CMDFLAG                0x40UL
#define EVE_INT_CONVCOMPLETE           0x80UL
#define EVE_INT_PLAYBACK               0x10UL
#define EVE_INT_SOUND                  0x8UL
#define EVE_INT_SWAP                   0x1UL
#define EVE_INT_TAG                    0x4UL
#define EVE_INT_TOUCH                  0x2UL

#define EVE_TOUCHMODE_CONTINUOUS       0x3UL
#define EVE_TOUCHMODE_FRAME            0x2UL
#define EVE_TOUCHMODE_OFF              0x0UL
#define EVE_TOUCHMODE_ONESHOT          0x1UL

#define EVE_LINEAR_SAMPLES             0x0UL   // Audio playback
#define EVE_ULAW_SAMPLES               0x1UL
#define EVE_ADPCM_SAMPLES              0x2UL
#define EVE_VOL_ZERO                   0x0UL

#define EVE_ADC_DIFFERENTIAL           0x1UL
#define EVE_ADC_SINGLE_ENDED           0x0UL

#elif IS_EVE_API(2)

//###########################################################################
//#####################################  EVE 2 ##############################
//###########################################################################

/* For FT801 enable the switch in platform.h file */

// Clock lower boundary of trimming
#define EVE_LOW_FREQ_BOUND             58800000L //98% of 60Mhz

// Memory Map

#define EVE_RAM_CMD                    0x308000UL
#define EVE_RAM_CMD_SIZE               (4*1024L)
#define EVE_RAM_DL                     0x300000UL
#define EVE_RAM_DL_SIZE                (8*1024L)
#define EVE_RAM_G                      0x0UL

#if EVE_SUB_API == 2
#define EVE_RAM_G_SIZE                 (256*1024L)
#elif EVE_SUB_API == 1
#define EVE_RAM_G_SIZE                 (1024*1024L)
#endif

#define EVE_RAM_REG                    0x302000UL
#define EVE_RAM_ROMSUB                 0x30A000UL

#define EVE_ROMFONT_TABLEADDRESS       0x2ffffcUL

// Registers

#define EVE_REG_ANA_COMP               0x302184UL
#define EVE_REG_ANALOG                 0x30216cUL
#define EVE_REG_BIST_EN                0x302174UL
#define EVE_REG_BUSYBITS               0x3020e8UL
#define EVE_REG_CLOCK                  0x302008UL
#define EVE_REG_CMD_DL                 0x302100UL
#define EVE_REG_CMD_READ               0x3020f8UL
#define EVE_REG_CMD_WRITE              0x3020fcUL
#define EVE_REG_CMDB_SPACE             0x302574UL
#define EVE_REG_CMDB_WRITE             0x302578UL
#define EVE_REG_CPURESET               0x302020UL
#define EVE_REG_CRC                    0x302178UL
#define EVE_REG_CSPREAD                0x302068UL
#define EVE_REG_CTOUCH_EXTENDED        0x302108UL
#define EVE_REG_CTOUCH_TOUCH0_XY       0x302124UL
#define EVE_REG_CTOUCH_TOUCH1_XY       0x30211cUL
#define EVE_REG_CTOUCH_TOUCH2_XY       0x30218cUL
#define EVE_REG_CTOUCH_TOUCH3_XY       0x302190UL
#define EVE_REG_CTOUCH_TOUCH4_X        0x30216cUL
#define EVE_REG_CTOUCH_TOUCH4_Y        0x302120UL
#define EVE_REG_CYA_TOUCH              0x302168UL
#define EVE_REG_DATESTAMP              0x302564UL
#define EVE_REG_DITHER                 0x302060UL
#define EVE_REG_DLSWAP                 0x302054UL
#define EVE_REG_FRAMES                 0x302004UL
#define EVE_REG_FREQUENCY              0x30200cUL
#define EVE_REG_GPIO                   0x302094UL
#define EVE_REG_GPIO_DIR               0x302090UL
#define EVE_REG_GPIOX                  0x30209cUL
#define EVE_REG_GPIOX_DIR              0x302098UL
#define EVE_REG_HCYCLE                 0x30202cUL
#define EVE_REG_HOFFSET                0x302030UL
#define EVE_REG_HSIZE                  0x302034UL
#define EVE_REG_HSYNC0                 0x302038UL
#define EVE_REG_HSYNC1                 0x30203cUL
#define EVE_REG_ID                     0x302000UL
#define EVE_REG_INT_EN                 0x3020acUL
#define EVE_REG_INT_FLAGS              0x3020a8UL
#define EVE_REG_INT_MASK               0x3020b0UL
#define EVE_REG_MACRO_0                0x3020d8UL
#define EVE_REG_MACRO_1                0x3020dcUL
#define EVE_REG_MEDIAFIFO_READ         0x309014UL
#define EVE_REG_MEDIAFIFO_WRITE        0x309018UL
#define EVE_REG_OUTBITS                0x30205cUL
#define EVE_REG_PATCHED_ANALOG         0x302170UL
#define EVE_REG_PATCHED_TOUCH_FAULT    0x30216cUL
#define EVE_REG_PCLK                   0x302070UL
#define EVE_REG_PCLK_POL               0x30206cUL
#define EVE_REG_PLAY                   0x30208cUL
#define EVE_REG_PLAYBACK_FORMAT        0x3020c4UL
#define EVE_REG_PLAYBACK_FREQ          0x3020c0UL
#define EVE_REG_PLAYBACK_LENGTH        0x3020b8UL
#define EVE_REG_PLAYBACK_LOOP          0x3020c8UL
#define EVE_REG_PLAYBACK_PLAY          0x3020ccUL
#define EVE_REG_PLAYBACK_READPTR       0x3020bcUL
#define EVE_REG_PLAYBACK_START         0x3020b4UL
#define EVE_REG_PWM_DUTY               0x3020d4UL
#define EVE_REG_PWM_HZ                 0x3020d0UL
#define EVE_REG_RENDERMODE             0x302010UL
#define EVE_REG_ROMSUB_SEL             0x3020f0UL
#define EVE_REG_ROTATE                 0x302058UL
#define EVE_REG_SNAPFORMAT             0x30201cUL
#define EVE_REG_SNAPSHOT               0x302018UL
#define EVE_REG_SNAPY                  0x302014UL
#define EVE_REG_SOUND                  0x302088UL
#define EVE_REG_SPI_EARLY_TX           0x30217cUL
#define EVE_REG_SPI_WIDTH              0x302188UL
#define EVE_REG_SWIZZLE                0x302064UL
#define EVE_REG_TAG                    0x30207cUL
#define EVE_REG_TAG_X                  0x302074UL
#define EVE_REG_TAG_Y                  0x302078UL
#define EVE_REG_TAP_CRC                0x302024UL
#define EVE_REG_TAP_MASK               0x302028UL
#define EVE_REG_TOUCH_ADC_MODE         0x302108UL
#define EVE_REG_TOUCH_CHARGE           0x30210cUL
#define EVE_REG_TOUCH_DIRECT_XY        0x30218cUL
#define EVE_REG_TOUCH_DIRECT_Z1Z2      0x302190UL
#define EVE_REG_TOUCH_FAULT            0x302170UL
#define EVE_REG_TOUCH_MODE             0x302104UL
#define EVE_REG_TOUCH_OVERSAMPLE       0x302114UL
#define EVE_REG_TOUCH_RAW_XY           0x30211cUL
#define EVE_REG_TOUCH_RZ               0x302120UL
#define EVE_REG_TOUCH_RZTHRESH         0x302118UL
#define EVE_REG_TOUCH_SCREEN_XY        0x302124UL
#define EVE_REG_TOUCH_SETTLE           0x302110UL
#define EVE_REG_TOUCH_TAG              0x30212cUL
#define EVE_REG_TOUCH_TAG_XY           0x302128UL
#define EVE_REG_TOUCH_TAG1             0x302134UL
#define EVE_REG_TOUCH_TAG1_XY          0x302130UL
#define EVE_REG_TOUCH_TAG2             0x30213cUL
#define EVE_REG_TOUCH_TAG2_XY          0x302138UL
#define EVE_REG_TOUCH_TAG3             0x302144UL
#define EVE_REG_TOUCH_TAG3_XY          0x302140UL
#define EVE_REG_TOUCH_TAG4             0x30214cUL
#define EVE_REG_TOUCH_TAG4_XY          0x302148UL
#define EVE_REG_TOUCH_TRANSFORM_A      0x302150UL
#define EVE_REG_TOUCH_TRANSFORM_B      0x302154UL
#define EVE_REG_TOUCH_TRANSFORM_C      0x302158UL
#define EVE_REG_TOUCH_TRANSFORM_D      0x30215cUL
#define EVE_REG_TOUCH_TRANSFORM_E      0x302160UL
#define EVE_REG_TOUCH_TRANSFORM_F      0x302164UL
#define EVE_REG_TRACKER                0x309000UL
#define EVE_REG_TRACKER_1              0x309004UL
#define EVE_REG_TRACKER_2              0x309008UL
#define EVE_REG_TRACKER_3              0x30900cUL
#define EVE_REG_TRACKER_4              0x309010UL
#define EVE_REG_TRIM                   0x302180UL
#define EVE_REG_VCYCLE                 0x302040UL
#define EVE_REG_VOFFSET                0x302044UL
#define EVE_REG_VOL_PB                 0x302080UL
#define EVE_REG_VOL_SOUND              0x302084UL
#define EVE_REG_VSIZE                  0x302048UL
#define EVE_REG_VSYNC0                 0x30204cUL
#define EVE_REG_VSYNC1                 0x302050UL

// Bitmap Address Mask 

#define EVE_ENC_BITMAP_ADDR_MASK       0x3fffffUL

// Encoded Command Macros

#define EVE_ENC_ALPHA_FUNC(func,ref)        ((0x9UL << 24)|(((func) & 0x7UL) << 8)|(((ref) & 0xffUL) << 0))
#define EVE_ENC_BEGIN(prim)                 ((0x1fUL << 24)|(((prim)&0xfUL) << 0))
#define EVE_ENC_BITMAP_HANDLE(handle)       ((0x5UL << 24)|(((handle) & 0x1fUL) << 0))
#define EVE_ENC_BITMAP_LAYOUT(format,linestride,height) ((0x7UL << 24)|(((format) & 0x1fUL) << 19)|(((linestride) & 0x3ffUL) << 9)|(((height) & 0x1ffUL) << 0))
#define EVE_ENC_BITMAP_LAYOUT_H(linestride,height) ((0x28UL << 24)|(((linestride) & 0x3UL) << 2)|(((height) & 0x3UL) << 0))
#define EVE_ENC_BITMAP_SIZE(filter,wrapx,wrapy,width,height) ((0x8UL << 24)|(((filter) & 0x1UL) << 20)|(((wrapx) & 0x1UL) << 19)|(((wrapy) & 0x1UL) << 18)|(((width) & 0x1ffUL) << 9)|(((height) & 0x1ffUL) << 0))
#define EVE_ENC_BITMAP_SIZE_H(width,height) ((0x29UL << 24)|(((width) & 0x3UL) << 2)|(((height) & 0x3UL) << 0))
#define EVE_ENC_BITMAP_SOURCE(addr)         ((0x1UL << 24) | ((addr)&EVE_ENC_BITMAP_ADDR_MASK))
#define EVE_ENC_BITMAP_TRANSFORM_A(a)       ((0x15UL << 24)|((((uint32_t)(a)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_B(b)       ((0x16UL << 24)|((((uint32_t)(b)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_C(c)       ((0x17UL << 24)|((((uint32_t)(c)) & 0xFFFFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_D(d)       ((0x18UL << 24)|((((uint32_t)(d)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_E(e)       ((0x19UL << 24)|((((uint32_t)(e)) & 0x1FFFFUL) << 0))
#define EVE_ENC_BITMAP_TRANSFORM_F(f)       ((0x1aUL << 24)|((((uint32_t)(f)) & 0xFFFFFFUL) << 0))
#define EVE_ENC_BLEND_FUNC(src,dst)         ((0xbUL << 24)|(((src) & 0x7UL) << 3)|(((dst) & 0x7UL) << 0))
#define EVE_ENC_CALL(dest)                  ((0x1dUL << 24)|(((dest) & 0xFFFFUL) << 0))
#define EVE_ENC_CELL(cell)                  ((0x6UL << 24)|(((cell) & 0x7fUL) << 0))
#define EVE_ENC_CLEAR(c,s,t)                ((0x26UL << 24)|((((uint32_t)(c)) & 0x1UL) << 2)|((((uint32_t)(s)) & 0x1UL) << 1)|((((uint32_t)(t)) & 0x1UL) << 0))
#define EVE_ENC_CLEAR_COLOR_A(alpha)        ((0xfUL << 24)|(((alpha) & 0xffUL) << 0))
#define EVE_ENC_CLEAR_COLOR_RGB(red,green,blue) ((0x2UL << 24)|(((red) & 0xffUL) << 16)|(((green) & 0xffUL) << 8)|(((blue) & 0xffUL) << 0))
#define EVE_ENC_CLEAR_COLOR(c)              ((0x2UL << 24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_CLEAR_STENCIL(s)            ((0x11UL << 24)|((((uint32_t)(s)) & 0xffUL) << 0))
#define EVE_ENC_CLEAR_TAG(s)                ((0x12UL << 24)|((((uint32_t)(s)) & 0xffUL) << 0))
#define EVE_ENC_COLOR_A(alpha)              ((0x10UL << 24)|(((alpha) & 0xffUL) << 0))
#define EVE_ENC_COLOR_MASK(r,g,b,a)         ((0x20UL << 24)|((((uint32_t)(r)) & 0x1UL) << 3)|((((uint32_t)(g)) & 0x1UL) << 2)|((((uint32_t)(b)) & 0x1UL) << 1)|((((uint32_t)(a)) & 0x1UL) << 0))
#define EVE_ENC_COLOR_RGB(red,green,blue)   ((0x4UL << 24)|(((red) & 0xffUL) << 16)|(((green) & 0xffUL) << 8)|(((blue) & 0xffUL) << 0))
#define EVE_ENC_COLOR(c)                    ((0x4UL << 24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_DISPLAY()                   ((0x0UL << 24))
#define EVE_ENC_END()                       ((0x21UL << 24))
#define EVE_ENC_JUMP(dest)                  ((0x1eUL << 24)|(((dest) & 0xFFFFUL) << 0))
#define EVE_ENC_LINE_WIDTH(width)           ((0xeUL << 24)|(((width) & 0xFFFUL) << 0))
#define EVE_ENC_MACRO(m)                    ((0x25UL << 24)|((((uint32_t)(m)) & 0x1UL) << 0))
#define EVE_ENC_NOP()                       ((0x2dUL << 24))
#define EVE_ENC_PALETTE_SOURCE(addr)        ((0x2aUL << 24)|(((addr) & 0x3FFFFFUL) << 0))
#define EVE_ENC_POINT_SIZE(size)            ((0xdUL << 24)|(((size) & 0x1FFFUL) << 0))
#define EVE_ENC_RESTORE_CONTEXT()           ((0x23UL << 24))
#define EVE_ENC_RETURN()                    ((0x24UL << 24))
#define EVE_ENC_SAVE_CONTEXT()              ((0x22UL << 24))
#define EVE_ENC_SCISSOR_SIZE(width,height)  ((0x1cUL << 24)|(((width) & 0xFFFUL) << 12)|(((height) & 0xFFFUL) << 0))
#define EVE_ENC_SCISSOR_XY(x,y)             ((0x1bUL << 24)|((((uint32_t)(x)) & 0x7FFUL) << 11)|((((uint32_t)(y)) & 0x7FFUL) << 0))
#define EVE_ENC_STENCIL_FUNC(func,ref,mask) ((0xaUL << 24)|(((func) & 0x7UL) << 16)|(((ref) & 0xffUL) << 8)|(((mask) & 0xffUL) << 0))
#define EVE_ENC_STENCIL_MASK(mask)          ((0x13UL << 24)|(((mask) & 0xffUL) << 0))
#define EVE_ENC_STENCIL_OP(sfail,spass)     ((0xcUL << 24)|(((sfail) & 0x7UL) << 3)|(((spass) & 0x7UL) << 0))
#define EVE_ENC_TAG_MASK(mask)              ((0x14UL << 24)|(((mask) & 0x1UL) << 0))
#define EVE_ENC_TAG(s)                      ((0x3UL << 24)|((((uint32_t)(s)) & 0xffUL) << 0))
#define EVE_ENC_VERTEX_FORMAT(frac)         ((0x27UL << 24)|(((frac) & 0x7UL) << 0))
#define EVE_ENC_VERTEX_TRANSLATE_X(x)       ((0x2bUL << 24)|((((uint32_t)(x)) & 0x1FFFFUL) << 0))
#define EVE_ENC_VERTEX_TRANSLATE_Y(y)       ((0x2cUL << 24)|((((uint32_t)(y)) & 0x1FFFFUL) << 0))
#define EVE_ENC_VERTEX2F(x,y)               ((0x1UL << 30)|((((uint32_t)(x)) & 0xffffUL) << 15)|((((uint32_t)(y)) & 0xffffUL) << 0))
#define EVE_ENC_VERTEX2II(x,y,handle,cell)  ((0x2UL << 30)|((((uint32_t)(x)) & 0x1ffUL) << 21)|((((uint32_t)(y)) & 0x1ffUL) << 12)|(((handle) & 0x1fUL) << 7)|(((cell) & 0x7fUL) << 0))

// Co-processor Commands

#define EVE_ENC_CMD_APPEND             0xffffff1eUL
#define EVE_ENC_CMD_BGCOLOR            0xffffff09UL
#define EVE_ENC_CMD_BITMAP_TRANSFORM   0xffffff21UL
#define EVE_ENC_CMD_BUTTON             0xffffff0dUL
#define EVE_ENC_CMD_CALIBRATE          0xffffff15UL
#define EVE_ENC_CMD_CLOCK              0xffffff14UL
#define EVE_ENC_CMD_COLDSTART          0xffffff32UL
#define EVE_ENC_CMD_CRC                0xffffff03UL
#define EVE_ENC_CMD_CSKETCH            0xffffff35UL
#define EVE_ENC_CMD_DIAL               0xffffff2dUL
#define EVE_ENC_CMD_DLSTART            0xffffff00UL
#define EVE_ENC_CMD_EXECUTE            0xffffff07UL
#define EVE_ENC_CMD_FGCOLOR            0xffffff0aUL
#define EVE_ENC_CMD_GAUGE              0xffffff13UL
#define EVE_ENC_CMD_GETMATRIX          0xffffff33UL
#define EVE_ENC_CMD_GETPOINT           0xffffff08UL
#define EVE_ENC_CMD_GETPROPS           0xffffff25UL
#define EVE_ENC_CMD_GETPTR             0xffffff23UL
#define EVE_ENC_CMD_GRADCOLOR          0xffffff34UL
#define EVE_ENC_CMD_GRADIENT           0xffffff0bUL
#define EVE_ENC_CMD_HAMMERAUX          0xffffff04UL
#define EVE_ENC_CMD_IDCT_DELETED       0xffffff06UL
#define EVE_ENC_CMD_INFLATE            0xffffff22UL
#define EVE_ENC_CMD_INT_RAMSHARED      0xffffff3dUL
#define EVE_ENC_CMD_INT_SWLOADIMAGE    0xffffff3eUL
#define EVE_ENC_CMD_INTERRUPT          0xffffff02UL
#define EVE_ENC_CMD_KEYS               0xffffff0eUL
#define EVE_ENC_CMD_LOADIDENTITY       0xffffff26UL
#define EVE_ENC_CMD_LOADIMAGE          0xffffff24UL
#define EVE_ENC_CMD_LOGO               0xffffff31UL
#define EVE_ENC_CMD_MARCH              0xffffff05UL
#define EVE_ENC_CMD_MEDIAFIFO          0xffffff39UL
#define EVE_ENC_CMD_MEMCPY             0xffffff1dUL
#define EVE_ENC_CMD_MEMCRC             0xffffff18UL
#define EVE_ENC_CMD_MEMSET             0xffffff1bUL
#define EVE_ENC_CMD_MEMWRITE           0xffffff1aUL
#define EVE_ENC_CMD_MEMZERO            0xffffff1cUL
#define EVE_ENC_CMD_NUMBER             0xffffff2eUL
#define EVE_ENC_CMD_PLAYVIDEO          0xffffff3aUL
#define EVE_ENC_CMD_PROGRESS           0xffffff0fUL
#define EVE_ENC_CMD_REGREAD            0xffffff19UL
#define EVE_ENC_CMD_ROMFONT            0xffffff3fUL
#define EVE_ENC_CMD_ROTATE             0xffffff29UL
#define EVE_ENC_CMD_SCALE              0xffffff28UL
#define EVE_ENC_CMD_SCREENSAVER        0xffffff2fUL
#define EVE_ENC_CMD_SCROLLBAR          0xffffff11UL
#define EVE_ENC_CMD_SETBASE            0xffffff38UL
#define EVE_ENC_CMD_SETBITMAP          0xffffff43UL
#define EVE_ENC_CMD_SETFONT            0xffffff2bUL
#define EVE_ENC_CMD_SETFONT2           0xffffff3bUL
#define EVE_ENC_CMD_SETMATRIX          0xffffff2aUL
#define EVE_ENC_CMD_SETROTATE          0xffffff36UL
#define EVE_ENC_CMD_SETSCRATCH         0xffffff3cUL
#define EVE_ENC_CMD_SKETCH             0xffffff30UL
#define EVE_ENC_CMD_SLIDER             0xffffff10UL
#define EVE_ENC_CMD_SNAPSHOT           0xffffff1fUL
#define EVE_ENC_CMD_SNAPSHOT2          0xffffff37UL
#define EVE_ENC_CMD_SPINNER            0xffffff16UL
#define EVE_ENC_CMD_STOP               0xffffff17UL
#define EVE_ENC_CMD_SWAP               0xffffff01UL
#define EVE_ENC_CMD_SYNC               0xffffff42UL
#define EVE_ENC_CMD_TEXT               0xffffff0cUL
#define EVE_ENC_CMD_TOGGLE             0xffffff12UL
#define EVE_ENC_CMD_TOUCH_TRANSFORM    0xffffff20UL
#define EVE_ENC_CMD_TRACK              0xffffff2cUL
#define EVE_ENC_CMD_TRANSLATE          0xffffff27UL
#define EVE_ENC_CMD_VIDEOFRAME         0xffffff41UL
#define EVE_ENC_CMD_VIDEOSTART         0xffffff40UL

// Bitmap Formats

#define EVE_FORMAT_ARGB1555            0x0UL
#define EVE_FORMAT_ARGB2               0x5UL
#define EVE_FORMAT_ARGB4               0x6UL
#define EVE_FORMAT_BARGRAPH            0xbUL
#define EVE_FORMAT_L1                  0x1UL
#define EVE_FORMAT_L2                  0x11UL
#define EVE_FORMAT_L4                  0x2UL
#define EVE_FORMAT_L8                  0x3UL
#define EVE_FORMAT_PALETTED            0x8UL
#define EVE_FORMAT_PALETTED4444        0xfUL
#define EVE_FORMAT_PALETTED565         0xeUL
#define EVE_FORMAT_PALETTED8           0x10UL
#define EVE_FORMAT_RGB332              0x4UL
#define EVE_FORMAT_RGB565              0x7UL
#define EVE_FORMAT_TEXT8X8             0x9UL
#define EVE_FORMAT_TEXTVGA             0xaUL

// Command Options

#define EVE_BEGIN_BITMAPS              0x1UL
#define EVE_BEGIN_EDGE_STRIP_A         0x7UL
#define EVE_BEGIN_EDGE_STRIP_B         0x8UL
#define EVE_BEGIN_EDGE_STRIP_L         0x6UL
#define EVE_BEGIN_EDGE_STRIP_R         0x5UL
#define EVE_BEGIN_LINE_STRIP           0x4UL
#define EVE_BEGIN_LINES                0x3UL
#define EVE_BEGIN_POINTS               0x2UL
#define EVE_BEGIN_RECTS                0x9UL

#define EVE_TEST_ALWAYS                0x7UL
#define EVE_TEST_EQUAL                 0x5UL
#define EVE_TEST_GEQUAL                0x4UL
#define EVE_TEST_GREATER               0x3UL
#define EVE_TEST_LEQUAL                0x2UL
#define EVE_TEST_LESS                  0x1UL
#define EVE_TEST_NEVER                 0x0UL
#define EVE_TEST_NOTEQUAL              0x6UL

#define EVE_FILTER_BILINEAR            0x1UL
#define EVE_FILTER_NEAREST             0x0UL

#define EVE_WRAP_BORDER                0x0UL
#define EVE_WRAP_REPEAT                0x1UL

#define EVE_BLEND_DST_ALPHA            0x3UL
#define EVE_BLEND_ONE                  0x1UL
#define EVE_BLEND_ONE_MINUS_DST_ALPHA  0x5UL
#define EVE_BLEND_ONE_MINUS_SRC_ALPHA  0x4UL
#define EVE_BLEND_SRC_ALPHA            0x2UL
#define EVE_BLEND_ZERO                 0x0UL

#define EVE_STENCIL_DECR               0x4UL
#define EVE_STENCIL_INCR               0x3UL
#define EVE_STENCIL_INVERT             0x5UL
#define EVE_STENCIL_KEEP               0x1UL
#define EVE_STENCIL_REPLACE            0x2UL
#define EVE_STENCIL_ZERO               0x0UL

#define EVE_OPT_CENTER                 0x600UL
#define EVE_OPT_CENTERX                0x200UL
#define EVE_OPT_CENTERY                0x400UL
#define EVE_OPT_FLAT                   0x100UL
#define EVE_OPT_FULLSCREEN             0x8UL
#define EVE_OPT_MEDIAFIFO              0x10UL
#define EVE_OPT_MONO                   0x1UL
#define EVE_OPT_NOBACK                 0x1000UL
#define EVE_OPT_NODL                   0x2UL
#define EVE_OPT_NOHANDS                0xc000UL
#define EVE_OPT_NOHM                   0x4000UL
#define EVE_OPT_NOPOINTER              0x4000UL
#define EVE_OPT_NOSECS                 0x8000UL
#define EVE_OPT_NOTEAR                 0x4UL
#define EVE_OPT_NOTICKS                0x2000UL
#define EVE_OPT_RIGHTX                 0x800UL
#define EVE_OPT_SIGNED                 0x100UL
#define EVE_OPT_SOUND                  0x20UL

#define EVE_DLSWAP_DONE                0x0UL
#define EVE_DLSWAP_FRAME               0x2UL
#define EVE_DLSWAP_LINE                0x1UL

#define EVE_INT_CMDEMPTY               0x20UL
#define EVE_INT_CMDFLAG                0x40UL
#define EVE_INT_CONVCOMPLETE           0x80UL
#define EVE_INT_G8                     0x12UL
#define EVE_INT_L8C                    0xcUL
#define EVE_INT_PLAYBACK               0x10UL
#define EVE_INT_SOUND                  0x8UL
#define EVE_INT_SWAP                   0x1UL
#define EVE_INT_TAG                    0x4UL
#define EVE_INT_TOUCH                  0x2UL
#define EVE_INT_VGA                    0xdUL
#define EVE_LINEAR_SAMPLES             0x0UL

#define EVE_TOUCHMODE_CONTINUOUS       0x3UL
#define EVE_TOUCHMODE_FRAME            0x2UL
#define EVE_TOUCHMODE_OFF              0x0UL
#define EVE_TOUCHMODE_ONESHOT          0x1UL

#define EVE_ULAW_SAMPLES               0x1UL
#define EVE_VOL_ZERO                   0x0UL

#define EVE_ADC_DIFFERENTIAL           0x1UL //?
#define EVE_ADC_SINGLE_ENDED           0x0UL //?
#define EVE_ADPCM_SAMPLES              0x2UL //?

#elif IS_EVE_API(3,4)

//###########################################################################
//###################################  EVE 3/4 ##############################
//###########################################################################

// Clock lower boundary of trimming
#define EVE_LOW_FREQ_BOUND  58800000L    //98% of 60Mhz

// Memory Map

#define EVE_RAM_G                      0x0UL
#define EVE_RAM_G_SIZE                 (1024*1024L)
#define EVE_RAM_BIST                   0x380000UL
#define EVE_RAM_CMD                    0x308000UL
#define EVE_RAM_DL                     0x300000UL
#define EVE_RAM_REG                    0x302000UL
#define EVE_RAM_ROMSUB                 0x30a000UL
#define EVE_RAM_TOP                    0x304000UL
#define EVE_CMDBUF_SIZE                0x1000UL
#define EVE_RAM_CMD_SIZE               (4*1024L)
#define EVE_RAM_ERR_REPORT             0x309800
#define EVE_ROMFONT_TABLEADDRESS       0x2ffffcUL

// Registers

#define EVE_REG_ADAPTIVE_FRAMERATE     0x30257cUL
#define EVE_REG_ANALOG                 0x30216cUL
#define EVE_REG_ANA_COMP               0x302184UL
#define EVE_REG_ANIM_ACTIVE            0x30902cUL
#define EVE_REG_BIST_EN                0x302174UL
#define EVE_REG_BUSYBITS               0x3020e8UL
#define EVE_REG_CLOCK                  0x302008UL
#define EVE_REG_CMDB_SPACE             0x302574UL
#define EVE_REG_CMDB_WRITE             0x302578UL
#define EVE_REG_CMD_DL                 0x302100UL
#define EVE_REG_CMD_READ               0x3020f8UL
#define EVE_REG_CMD_WRITE              0x3020fcUL
#define EVE_REG_CPURESET               0x302020UL
#define EVE_REG_CRC                    0x302178UL
#define EVE_REG_CSPREAD                0x302068UL
#define EVE_REG_CTOUCH_EXTENDED        0x302108UL
#define EVE_REG_CTOUCH_TOUCH0_XY       0x302124UL
#define EVE_REG_CTOUCH_TOUCH4_X        0x30216cUL
#define EVE_REG_CTOUCH_TOUCH4_Y        0x302120UL
#define EVE_REG_CTOUCH_TOUCH1_XY       0x30211cUL
#define EVE_REG_CTOUCH_TOUCH2_XY       0x30218cUL
#define EVE_REG_CTOUCH_TOUCH3_XY       0x302190UL
#define EVE_REG_TOUCH_CONFIG           0x302168UL
#define EVE_REG_DATESTAMP              0x302564UL
#define EVE_REG_DF_TUNED               0x309030UL
#define EVE_REG_DITHER                 0x302060UL
#define EVE_REG_DLSWAP                 0x302054UL
#define EVE_REG_EHOST_TOUCH_ACK        0x302170UL
#define EVE_REG_EHOST_TOUCH_ID         0x302114UL
#define EVE_REG_EHOST_TOUCH_X          0x30210cUL
#define EVE_REG_EHOST_TOUCH_Y          0x302118UL
#define EVE_REG_EJPG_ACC               0x302358UL
#define EVE_REG_EJPG_BUSY              0x302198UL
#define EVE_REG_EJPG_DAT               0x30219cUL
#define EVE_REG_EJPG_DCC               0x302340UL
#define EVE_REG_EJPG_DEBUG             0x30255cUL
#define EVE_REG_EJPG_DST               0x3021a4UL
#define EVE_REG_EJPG_FORMAT            0x3021b0UL
#define EVE_REG_EJPG_H                 0x3021acUL
#define EVE_REG_EJPG_HT                0x302240UL
#define EVE_REG_EJPG_OPTIONS           0x3021a0UL
#define EVE_REG_EJPG_Q                 0x3021c0UL
#define EVE_REG_EJPG_READY             0x302194UL
#define EVE_REG_EJPG_RI                0x3021b4UL
#define EVE_REG_EJPG_SCALE             0x302558UL
#define EVE_REG_EJPG_TDA               0x3021bcUL
#define EVE_REG_EJPG_TQ                0x3021b8UL
#define EVE_REG_EJPG_W                 0x3021a8UL
#define EVE_REG_ESPIM_ADD              0x30259cUL
#define EVE_REG_ESPIM_COUNT            0x3025a0UL
#define EVE_REG_ESPIM_DUMMY            0x3025e4UL
#define EVE_REG_ESPIM_READSTART        0x302588UL
#define EVE_REG_ESPIM_SEQ              0x30258cUL
#define EVE_REG_ESPIM_TRIG             0x3025e8UL
#define EVE_REG_ESPIM_WINDOW           0x3025a4UL
#define EVE_REG_FLASH_SIZE             0x309024UL
#define EVE_REG_FLASH_STATUS           0x3025f0UL
#define EVE_REG_FRAMES                 0x302004UL
#define EVE_REG_FREQUENCY              0x30200cUL
#define EVE_REG_FULLBUSYBITS           0x3025f4UL
#define EVE_REG_GPIO                   0x302094UL
#define EVE_REG_GPIOX                  0x30209cUL
#define EVE_REG_GPIOX_DIR              0x302098UL
#define EVE_REG_GPIO_DIR               0x302090UL
#define EVE_REG_HCYCLE                 0x30202cUL
#define EVE_REG_HOFFSET                0x302030UL
#define EVE_REG_HSIZE                  0x302034UL
#define EVE_REG_HSYNC0                 0x302038UL
#define EVE_REG_HSYNC1                 0x30203cUL
#define EVE_REG_ID                     0x302000UL
#define EVE_REG_INT_EN                 0x3020acUL
#define EVE_REG_INT_FLAGS              0x3020a8UL
#define EVE_REG_INT_MASK               0x3020b0UL
#define EVE_REG_MACRO_0                0x3020d8UL
#define EVE_REG_MACRO_1                0x3020dcUL
#define EVE_REG_MEDIAFIFO_BASE         0x30901cUL
#define EVE_REG_MEDIAFIFO_READ         0x309014UL
#define EVE_REG_MEDIAFIFO_SIZE         0x309020UL
#define EVE_REG_MEDIAFIFO_WRITE        0x309018UL
#define EVE_REG_OUTBITS                0x30205cUL
#define EVE_REG_PCLK                   0x302070UL
#define EVE_REG_PCLK_POL               0x30206cUL
#define EVE_REG_PLAY                   0x30208cUL
#define EVE_REG_PLAYBACK_FORMAT        0x3020c4UL
#define EVE_REG_PLAYBACK_FREQ          0x3020c0UL
#define EVE_REG_PLAYBACK_LENGTH        0x3020b8UL
#define EVE_REG_PLAYBACK_LOOP          0x3020c8UL
#define EVE_REG_PLAYBACK_PAUSE         0x3025ecUL
#define EVE_REG_PLAYBACK_PLAY          0x3020ccUL
#define EVE_REG_PLAYBACK_READPTR       0x3020bcUL
#define EVE_REG_PLAYBACK_START         0x3020b4UL
#define EVE_REG_PLAY_CONTROL           0x30914eUL
#define EVE_REG_COPRO_PATCH_PTR        0x309162UL
#define EVE_REG_PWM_DUTY               0x3020d4UL
#define EVE_REG_PWM_HZ                 0x3020d0UL
#define EVE_REG_RAM_FOLD               0x3020f4UL
#define EVE_REG_RASTERY                0x302560UL
#define EVE_REG_RENDERMODE             0x302010UL
#define EVE_REG_ROMSUB_SEL             0x3020f0UL
#define EVE_REG_ROTATE                 0x302058UL
#define EVE_REG_SNAPFORMAT             0x30201cUL
#define EVE_REG_SNAPSHOT               0x302018UL
#define EVE_REG_SNAPY                  0x302014UL
#define EVE_REG_SOUND                  0x302088UL
#define EVE_REG_SPIM                   0x302584UL
#define EVE_REG_SPIM_DIR               0x302580UL
#define EVE_REG_SPI_EARLY_TX           0x30217cUL
#define EVE_REG_SPI_WIDTH              0x302188UL
#define EVE_REG_SWIZZLE                0x302064UL
#define EVE_REG_TAG                    0x30207cUL
#define EVE_REG_TAG_X                  0x302074UL
#define EVE_REG_TAG_Y                  0x302078UL
#define EVE_REG_TAP_CRC                0x302024UL
#define EVE_REG_TAP_MASK               0x302028UL
#define EVE_REG_TOUCH_ADC_MODE         0x302108UL
#define EVE_REG_TOUCH_CHARGE           0x30210cUL
#define EVE_REG_TOUCH_DIRECT_XY        0x30218cUL
#define EVE_REG_TOUCH_DIRECT_Z1Z2      0x302190UL
#define EVE_REG_TOUCH_FAULT            0x302170UL
#define EVE_REG_TOUCH_MODE             0x302104UL
#define EVE_REG_TOUCH_OVERSAMPLE       0x302114UL
#define EVE_REG_TOUCH_RAW_XY           0x30211cUL
#define EVE_REG_TOUCH_RZ               0x302120UL
#define EVE_REG_TOUCH_RZTHRESH         0x302118UL
#define EVE_REG_TOUCH_SCREEN_XY        0x302124UL
#define EVE_REG_TOUCH_SETTLE           0x302110UL
#define EVE_REG_TOUCH_TAG              0x30212cUL
#define EVE_REG_TOUCH_TAG1             0x302134UL
#define EVE_REG_TOUCH_TAG1_XY          0x302130UL
#define EVE_REG_TOUCH_TAG2             0x30213cUL
#define EVE_REG_TOUCH_TAG2_XY          0x302138UL
#define EVE_REG_TOUCH_TAG3             0x302144UL
#define EVE_REG_TOUCH_TAG3_XY          0x302140UL
#define EVE_REG_TOUCH_TAG4             0x30214cUL
#define EVE_REG_TOUCH_TAG4_XY          0x302148UL
#define EVE_REG_TOUCH_TAG_XY           0x302128UL
#define EVE_REG_TOUCH_TRANSFORM_A      0x302150UL
#define EVE_REG_TOUCH_TRANSFORM_B      0x302154UL
#define EVE_REG_TOUCH_TRANSFORM_C      0x302158UL
#define EVE_REG_TOUCH_TRANSFORM_D      0x30215cUL
#define EVE_REG_TOUCH_TRANSFORM_E      0x302160UL
#define EVE_REG_TOUCH_TRANSFORM_F      0x302164UL
#define EVE_REG_TRACKER                0x309000UL
#define EVE_REG_TRACKER_1              0x309004UL
#define EVE_REG_TRACKER_2              0x309008UL
#define EVE_REG_TRACKER_3              0x30900cUL
#define EVE_REG_TRACKER_4              0x309010UL
#define EVE_REG_TRIM                   0x302180UL
#define EVE_REG_VCYCLE                 0x302040UL
#define EVE_REG_VOFFSET                0x302044UL
#define EVE_REG_VOL_PB                 0x302080UL
#define EVE_REG_VOL_SOUND              0x302084UL
#define EVE_REG_VSIZE                  0x302048UL
#define EVE_REG_VSYNC0                 0x30204cUL
#define EVE_REG_VSYNC1                 0x302050UL

// Bitmap Address Mask 

#define EVE_ENC_BITMAP_ADDR_MASK       0x7FFFFFUL

// Encoded Command Macros

#define EVE_ENC_ALPHA_FUNC(func,ref)        ((0x9UL<<24)|(((func)&0x7UL)<<8)|(((ref)&0xffUL)<<0))
#define EVE_ENC_BEGIN(prim)                 ((0x1fUL<<24)|(((prim)&0xfUL)<<0))
#define EVE_ENC_BITMAP_EXT_FORMAT(format)   ((0x2eUL<<24)|(((format)&0xffffUL)<<0))
#define EVE_ENC_BITMAP_HANDLE(handle)       ((0x5UL<<24)|(((handle)&0x1fUL)<<0))
#define EVE_ENC_BITMAP_LAYOUT(format,linestride,height) ((0x7UL<<24)|(((format)&0x1fUL)<<19)|(((linestride)&0x3ffUL)<<9)|(((height)&0x1FFUL)<<0))
#define EVE_ENC_BITMAP_LAYOUT_H(linestride,height) ((0x28UL<<24)|(((linestride)&0x3UL)<<2)|(((height)&0x3UL)<<0))
#define EVE_ENC_BITMAP_SIZE(filter,wrapx,wrapy,width,height) ((0x8UL<<24)|(((filter)&0x1UL)<<20)|(((wrapx)&0x1UL)<<19)|(((wrapy)&0x1UL)<<18)|(((width)&0x1FFUL)<<9)|(((height)&0x1FFUL)<<0))
#define EVE_ENC_BITMAP_SIZE_H(width,height) ((0x29UL<<24)|(((width)&0x3UL)<<2)|(((height)&0x3UL)<<0))
#define EVE_ENC_BITMAP_SOURCE(addr)         ((0x1UL << 24) | ((addr)&EVE_ENC_BITMAP_ADDR_MASK))
#define EVE_ENC_BITMAP_SOURCE2(flash_or_ram, addr) ((0x1UL << 24) | ((flash_or_ram) << 23) | (((addr) & (EVE_ENC_BITMAP_ADDR_MASK >> 1)) << 0))
#define EVE_ENC_BITMAP_SWIZZLE(r,g,b,a)     ((0x2fUL<<24)|(((r)&0x7UL)<<9)|(((g)&0x7UL)<<6)|(((b)&0x7UL)<<3)|(((a)&0x7UL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_A(p,v)     ((0x15UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_B(p,v)     ((0x16UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_C(c)       ((0x17UL<<24)|(((c)&0xFFFFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_D(p,v)     ((0x18UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_E(p,v)     ((0x19UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_F(f)       ((0x1aUL<<24)|(((f)&0xFFFFFFUL)<<0))
#define EVE_ENC_BLEND_FUNC(src,dst)         ((0xbUL<<24)|(((src)&0x7UL)<<3)|(((dst)&0x7UL)<<0))
#define EVE_ENC_CALL(dest)                  ((0x1dUL<<24)|(((dest)&0xffffUL)<<0))
#define EVE_ENC_CELL(cell)                  ((0x6UL<<24)|(((cell)&0x7FUL)<<0))
#define EVE_ENC_CLEAR(c,s,t)                ((0x26UL<<24)|(((c)&0x1UL)<<2)|(((s)&0x1UL)<<1)|(((t)&0x1UL)<<0))
#define EVE_ENC_CLEAR_COLOR(c)              ((0x2UL<<24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_CLEAR_COLOR_A(alpha)        ((0xfUL<<24)|(((alpha)&0xffUL)<<0))
#define EVE_ENC_CLEAR_COLOR_RGB(red,green,blue)    ((0x2UL<<24)|(((red)&0xffUL)<<16)|(((green)&0xffUL)<<8)|(((blue)&0xffUL)<<0))
#define EVE_ENC_CLEAR_STENCIL(s)            ((0x11UL<<24)|(((s)&0xffUL)<<0))
#define EVE_ENC_CLEAR_TAG(s)                ((0x12UL<<24)|(((s)&0xffUL)<<0))
#define EVE_ENC_COLOR(c)                    ((0x4UL<<24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_COLOR_A(alpha)              ((0x10UL<<24)|(((alpha)&0xffUL)<<0))
#define EVE_ENC_COLOR_MASK(r,g,b,a)         ((0x20UL<<24)|(((r)&0x1UL)<<3)|(((g)&0x1UL)<<2)|(((b)&0x1UL)<<1)|(((a)&0x1UL)<<0))
#define EVE_ENC_COLOR_RGB(red,green,blue)   ((0x4UL<<24)|(((red)&0xffUL)<<16)|(((green)&0xffUL)<<8)|(((blue)&0xffUL)<<0))
#define EVE_ENC_DISPLAY()                   ((0x0UL<<24))
#define EVE_ENC_END()                       ((0x21UL<<24))
#define EVE_ENC_JUMP(dest)                  ((0x1fUL<<24)|(((dest)&0xffffUL)<<0))
#define EVE_ENC_LINE_WIDTH(width)           ((0xeUL<<24)|(((width)&0xFFFUL)<<0))
#define EVE_ENC_MACRO(m)                    ((0x25UL<<24)|(((m)&0x1UL)<<0))
#define EVE_ENC_NOP()                       ((0x2dUL<<24))
#define EVE_ENC_PALETTE_SOURCE(addr)        ((0x2aUL<<24)|(((addr)&0x3FFFFFUL)<<0))
#define EVE_ENC_POINT_SIZE(size)            ((0xdUL<<24)|(((size)&0x1FFFUL)<<0))
#define EVE_ENC_RESTORE_CONTEXT()           ((0x23UL<<24))
#define EVE_ENC_RETURN()                    ((0x24UL<<24))
#define EVE_ENC_SAVE_CONTEXT()              ((0x22UL<<24))
#define EVE_ENC_SCISSOR_SIZE(width,height)  ((0x1cUL<<24)|(((width)&0xFFFUL)<<12)|(((height)&0xFFFUL)<<0))
#define EVE_ENC_SCISSOR_XY(x,y)             ((0x1bUL<<24)|(((x)&0x7FFUL)<<11)|(((y)&0x7FFUL)<<0))
#define EVE_ENC_STENCIL_FUNC(func,ref,mask) ((0xaUL<<24)|(((func)&0x7UL)<<16)|(((ref)&0xffUL)<<8)|(((mask)&0xffUL)<<0))
#define EVE_ENC_STENCIL_MASK(mask)          ((0x13UL<<24)|(((mask)&0xffUL)<<0))
#define EVE_ENC_STENCIL_OP(sfail,spass)     ((0xcUL<<24)|(((sfail)&0x7UL)<<3)|(((spass)&0x7UL)<<0))
#define EVE_ENC_TAG(s)                      ((0x3UL<<24)|(((s)&0xffUL)<<0))
#define EVE_ENC_TAG_MASK(mask)              ((0x14UL<<24)|(((mask)&0x1UL)<<0))
#define EVE_ENC_VERTEX2F(x,y)               ((0x1UL<<30)|(((x)&0x7fffUL)<<15)|(((y)&0x7fffUL)<<0))
#define EVE_ENC_VERTEX2II(x,y,handle,cell)  ((0x2UL<<30)|(((x)&0x1FFUL)<<21)|(((y)&0x1FFUL)<<12)|(((handle)&0x1fUL)<<7)|(((cell)&0x7FUL)<<0))
#define EVE_ENC_VERTEX_FORMAT(frac)         ((0x27UL<<24)|(((frac)&0x7UL)<<0))
#define EVE_ENC_VERTEX_TRANSLATE_X(x)       ((0x2bUL<<24)|(((x)&0x1FFFFUL)<<0))
#define EVE_ENC_VERTEX_TRANSLATE_Y(y)       ((0x2cUL<<24)|(((y)&0x1FFFFUL)<<0))

// Co-processor Commands

#define EVE_ENC_CMD_ANIMDRAW           0xffffff56UL
#define EVE_ENC_CMD_ANIMFRAME          0xffffff5aUL
#define EVE_ENC_CMD_ANIMSTART          0xffffff53UL
#define EVE_ENC_CMD_ANIMSTOP           0xffffff54UL
#define EVE_ENC_CMD_ANIMXY             0xffffff55UL
#define EVE_ENC_CMD_APPEND             0xffffff1eUL
#define EVE_ENC_CMD_APPENDF            0xffffff59UL
#define EVE_ENC_CMD_BGCOLOR            0xffffff09UL
#define EVE_ENC_CMD_BITMAP_TRANSFORM   0xffffff21UL
#define EVE_ENC_CMD_BUTTON             0xffffff0dUL
#define EVE_ENC_CMD_CALIBRATE          0xffffff15UL
#define EVE_ENC_CMD_CLEARCACHE         0xffffff4fUL
#define EVE_ENC_CMD_CLOCK              0xffffff14UL
#define EVE_ENC_CMD_COLDSTART          0xffffff32UL
#define EVE_ENC_CMD_CRC                0xffffff03UL
#define EVE_ENC_CMD_DEPRECATED_CSKETCH 0xffffff35UL
#define EVE_ENC_CMD_DIAL               0xffffff2dUL
#define EVE_ENC_CMD_DLSTART            0xffffff00UL
#define EVE_ENC_CMD_EXECUTE            0xffffff07UL
#define EVE_ENC_CMD_FGCOLOR            0xffffff0aUL
#define EVE_ENC_CMD_FILLWIDTH          0xffffff58UL
#define EVE_ENC_CMD_FLASHATTACH        0xffffff49UL
#define EVE_ENC_CMD_FLASHDETACH        0xffffff48UL
#define EVE_ENC_CMD_FLASHERASE         0xffffff44UL
#define EVE_ENC_CMD_FLASHFAST          0xffffff4aUL
#define EVE_ENC_CMD_FLASHREAD          0xffffff46UL
#define EVE_ENC_CMD_FLASHPROGRAM       0xffffff70UL
#define EVE_ENC_CMD_FLASHSOURCE        0xffffff4eUL
#define EVE_ENC_CMD_FLASHSPIDESEL      0xffffff4bUL
#define EVE_ENC_CMD_FLASHSPIRX         0xffffff4dUL
#define EVE_ENC_CMD_FLASHSPITX         0xffffff4cUL
#define EVE_ENC_CMD_FLASHUPDATE        0xffffff47UL
#define EVE_ENC_CMD_FLASHWRITE         0xffffff45UL
#define EVE_ENC_CMD_GAUGE              0xffffff13UL
#define EVE_ENC_CMD_GETMATRIX          0xffffff33UL
#define EVE_ENC_CMD_GETPOINT           0xffffff08UL
#define EVE_ENC_CMD_GETPROPS           0xffffff25UL
#define EVE_ENC_CMD_GETPTR             0xffffff23UL
#define EVE_ENC_CMD_GRADCOLOR          0xffffff34UL
#define EVE_ENC_CMD_GRADIENT           0xffffff0bUL
#define EVE_ENC_CMD_GRADIENTA          0xffffff57UL
#define EVE_ENC_CMD_HAMMERAUX          0xffffff04UL
#define EVE_ENC_CMD_HMAC               0xffffff5dUL
#define EVE_ENC_CMD_IDCT_DELETED       0xffffff06UL
#define EVE_ENC_CMD_INFLATE            0xffffff22UL
#define EVE_ENC_CMD_INFLATE2           0xffffff50UL
#define EVE_ENC_CMD_INTERRUPT          0xffffff02UL
#define EVE_ENC_CMD_INT_RAMSHARED      0xffffff3dUL
#define EVE_ENC_CMD_INT_SWLOADIMAGE    0xffffff3eUL
#define EVE_ENC_CMD_KEYS               0xffffff0eUL
#define EVE_ENC_CMD_LAST_              0xffffff5eUL
#define EVE_ENC_CMD_LOADIDENTITY       0xffffff26UL
#define EVE_ENC_CMD_LOADIMAGE          0xffffff24UL
#define EVE_ENC_CMD_LOGO               0xffffff31UL
#define EVE_ENC_CMD_MARCH              0xffffff05UL
#define EVE_ENC_CMD_MEDIAFIFO          0xffffff39UL
#define EVE_ENC_CMD_MEMCPY             0xffffff1dUL
#define EVE_ENC_CMD_MEMCRC             0xffffff18UL
#define EVE_ENC_CMD_MEMSET             0xffffff1bUL
#define EVE_ENC_CMD_MEMWRITE           0xffffff1aUL
#define EVE_ENC_CMD_MEMZERO            0xffffff1cUL
#define EVE_ENC_CMD_NOP                0xffffff5bUL
#define EVE_ENC_CMD_NUMBER             0xffffff2eUL
#define EVE_ENC_CMD_PLAYVIDEO          0xffffff3aUL
#define EVE_ENC_CMD_PROGRESS           0xffffff0fUL
#define EVE_ENC_CMD_REGREAD            0xffffff19UL
#define EVE_ENC_CMD_RESETFONTS         0xffffff52UL
#define EVE_ENC_CMD_ROMFONT            0xffffff3fUL
#define EVE_ENC_CMD_ROTATE             0xffffff29UL
#define EVE_ENC_CMD_ROTATEAROUND       0xffffff51UL
#define EVE_ENC_CMD_SCALE              0xffffff28UL
#define EVE_ENC_CMD_SCREENSAVER        0xffffff2fUL
#define EVE_ENC_CMD_SCROLLBAR          0xffffff11UL
#define EVE_ENC_CMD_SETBASE            0xffffff38UL
#define EVE_ENC_CMD_SETBITMAP          0xffffff43UL
#define EVE_ENC_CMD_SETFONT            0xffffff2bUL
#define EVE_ENC_CMD_SETFONT2           0xffffff3bUL
#define EVE_ENC_CMD_SETMATRIX          0xffffff2aUL
#define EVE_ENC_CMD_SETROTATE          0xffffff36UL
#define EVE_ENC_CMD_SETSCRATCH         0xffffff3cUL
#define EVE_ENC_CMD_SHA1               0xffffff5cUL
#define EVE_ENC_CMD_SKETCH             0xffffff30UL
#define EVE_ENC_CMD_SLIDER             0xffffff10UL
#define EVE_ENC_CMD_SNAPSHOT           0xffffff1fUL
#define EVE_ENC_CMD_SNAPSHOT2          0xffffff37UL
#define EVE_ENC_CMD_SPINNER            0xffffff16UL
#define EVE_ENC_CMD_STOP               0xffffff17UL
#define EVE_ENC_CMD_SWAP               0xffffff01UL
#define EVE_ENC_CMD_SYNC               0xffffff42UL
#define EVE_ENC_CMD_TEXT               0xffffff0cUL
#define EVE_ENC_CMD_TOGGLE             0xffffff12UL
#define EVE_ENC_CMD_TOUCH_TRANSFORM    0xffffff20UL
#define EVE_ENC_CMD_TRACK              0xffffff2cUL
#define EVE_ENC_CMD_TRANSLATE          0xffffff27UL
#define EVE_ENC_CMD_VIDEOFRAME         0xffffff41UL
#define EVE_ENC_CMD_VIDEOSTART         0xffffff40UL
#define EVE_ENC_CMD_VIDEOSTARTF        0xffffff5fUL

// Bitmap Formats

#define EVE_FORMAT_L1                  0x1UL
#define EVE_FORMAT_L2                  0x11UL
#define EVE_FORMAT_L4                  0x2UL
#define EVE_FORMAT_L8                  0x3UL
#define EVE_FORMAT_PALETTED            0x8UL
#define EVE_FORMAT_PALETTED4444        0xfUL
#define EVE_FORMAT_PALETTED565         0xeUL
#define EVE_FORMAT_PALETTED8           0x10UL
#define EVE_FORMAT_ARGB1555            0x0UL
#define EVE_FORMAT_ARGB2               0x5UL
#define EVE_FORMAT_ARGB4               0x6UL
#define EVE_FORMAT_BARGRAPH            0xbUL
#define EVE_FORMAT_RGB332              0x4UL
#define EVE_FORMAT_RGB565              0x7UL

#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93bbUL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_10x5_KHR  0x93b8UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_10x6_KHR  0x93b9UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_10x8_KHR  0x93baUL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93bcUL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93bdUL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_4x4_KHR   0x93b0UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_5x4_KHR   0x93b1UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_5x5_KHR   0x93b2UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_6x5_KHR   0x93b3UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_6x6_KHR   0x93b4UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_8x5_KHR   0x93b5UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_8x6_KHR   0x93b6UL
#define EVE_FORMAT_COMPRESSED_RGBA_ASTC_8x8_KHR   0x93b7UL

#define EVE_GLFORMAT                   0x1fUL

// Command Options

#define EVE_BEGIN_BITMAPS              0x1UL
#define EVE_BEGIN_EDGE_STRIP_A         0x7UL
#define EVE_BEGIN_EDGE_STRIP_B         0x8UL
#define EVE_BEGIN_EDGE_STRIP_L         0x6UL
#define EVE_BEGIN_EDGE_STRIP_R         0x5UL
#define EVE_BEGIN_LINE_STRIP           0x4UL
#define EVE_BEGIN_LINES                0x3UL
#define EVE_BEGIN_POINTS               0x2UL
#define EVE_BEGIN_RECTS                0x9UL

#define EVE_TEST_ALWAYS                0x7UL
#define EVE_TEST_EQUAL                 0x5UL
#define EVE_TEST_GEQUAL                0x4UL
#define EVE_TEST_GREATER               0x3UL
#define EVE_TEST_LEQUAL                0x2UL
#define EVE_TEST_LESS                  0x1UL
#define EVE_TEST_NEVER                 0x0UL
#define EVE_TEST_NOTEQUAL              0x6UL

#define EVE_FILTER_BILINEAR            0x1UL
#define EVE_FILTER_NEAREST             0x0UL

#define EVE_WRAP_BORDER                0x0UL
#define EVE_WRAP_REPEAT                0x1UL

#define EVE_BLEND_DST_ALPHA            0x3UL
#define EVE_BLEND_ONE                  0x1UL
#define EVE_BLEND_ONE_MINUS_DST_ALPHA  0x5UL
#define EVE_BLEND_ONE_MINUS_SRC_ALPHA  0x4UL
#define EVE_BLEND_SRC_ALPHA            0x2UL
#define EVE_BLEND_ZERO                 0x0UL

#define EVE_STENCIL_DECR               0x4UL
#define EVE_STENCIL_INCR               0x3UL
#define EVE_STENCIL_INVERT             0x5UL
#define EVE_STENCIL_KEEP               0x1UL
#define EVE_STENCIL_REPLACE            0x2UL
#define EVE_STENCIL_ZERO               0x0UL

#define EVE_OPT_3D                     0x0UL
#define EVE_OPT_CENTER                 0x600UL
#define EVE_OPT_CENTERX                0x200UL
#define EVE_OPT_CENTERY                0x400UL
#define EVE_OPT_FILL                   0x2000UL
#define EVE_OPT_FLASH                  0x40UL
#define EVE_OPT_FLAT                   0x100UL
#define EVE_OPT_FORMAT                 0x1000UL
#define EVE_OPT_FULLSCREEN             0x8UL
#define EVE_OPT_MEDIAFIFO              0x10UL
#define EVE_OPT_MONO                   0x1UL
#define EVE_OPT_NOBACK                 0x1000UL
#define EVE_OPT_NODL                   0x2UL
#define EVE_OPT_NOHANDS                0xc000UL
#define EVE_OPT_NOHM                   0x4000UL
#define EVE_OPT_NOPOINTER              0x4000UL
#define EVE_OPT_NOSECS                 0x8000UL
#define EVE_OPT_NOTEAR                 0x4UL
#define EVE_OPT_NOTICKS                0x2000UL
#define EVE_OPT_OVERLAY                0x80UL
#define EVE_OPT_RGB565                 0x0UL
#define EVE_OPT_RIGHTX                 0x800UL
#define EVE_OPT_SIGNED                 0x100UL
#define EVE_OPT_SOUND                  0x20UL

#define EVE_DLSWAP_DONE                0x0UL
#define EVE_DLSWAP_FRAME               0x2UL
#define EVE_DLSWAP_LINE                0x1UL

#define EVE_INT_CMDEMPTY               0x20UL
#define EVE_INT_CMDFLAG                0x40UL
#define EVE_INT_CONVCOMPLETE           0x80UL
#define EVE_INT_G8                     0x12UL
#define EVE_INT_L8C                    0xcUL
#define EVE_INT_PLAYBACK               0x10UL
#define EVE_INT_SOUND                  0x8UL
#define EVE_INT_SWAP                   0x1UL
#define EVE_INT_TAG                    0x4UL
#define EVE_INT_TOUCH                  0x2UL
#define EVE_INT_VGA                    0xdUL

#define EVE_LINEAR_SAMPLES             0x0UL   // Audio playback
#define EVE_ULAW_SAMPLES               0x1UL
#define EVE_ADPCM_SAMPLES              0x2UL
#define EVE_VOL_ZERO                   0x0UL

#define EVE_ADC_DIFFERENTIAL           0x1UL
#define EVE_ADC_SINGLE_ENDED           0x0UL

#define EVE_ANIM_HOLD                  0x2UL
#define EVE_ANIM_LOOP                  0x1UL
#define EVE_ANIM_ONCE                  0x0UL

#define EVE_ALPHA                      0x5UL
#define EVE_BLUE                       0x4UL
#define EVE_GREEN                      0x3UL
#define EVE_RED                        0x2UL

#define EVE_FLASH_STATUS_BASIC         0x2UL
#define EVE_FLASH_STATUS_DETACHED      0x1UL
#define EVE_FLASH_STATUS_FULL          0x3UL
#define EVE_FLASH_STATUS_INIT          0x0UL

#define EVE_SS_A0                      0x13UL
#define EVE_SS_A1                      0x14UL
#define EVE_SS_A2                      0x15UL
#define EVE_SS_A3                      0x16UL
#define EVE_SS_A4                      0x17UL
#define EVE_SS_A5                      0x18UL
#define EVE_SS_A6                      0x19UL
#define EVE_SS_A7                      0x1aUL
#define EVE_SS_PAUSE                   0x12UL
#define EVE_SS_Q0                      0x0UL
#define EVE_SS_Q1                      0x1UL
#define EVE_SS_Q2                      0x2UL
#define EVE_SS_Q3                      0x3UL
#define EVE_SS_Q4                      0x4UL
#define EVE_SS_Q5                      0x5UL
#define EVE_SS_Q6                      0x6UL
#define EVE_SS_Q7                      0x7UL
#define EVE_SS_Q8                      0x8UL
#define EVE_SS_Q9                      0x9UL
#define EVE_SS_QA                      0xaUL
#define EVE_SS_QB                      0xbUL
#define EVE_SS_QC                      0xcUL
#define EVE_SS_QD                      0xdUL
#define EVE_SS_QE                      0xeUL
#define EVE_SS_QF                      0xfUL
#define EVE_SS_QI                      0x1fUL
#define EVE_SS_S0                      0xaUL
#define EVE_SS_S1                      0xbUL

#define EVE_TEXT8EVE_SS                0x9UL
#define EVE_TEXTVGA                    0xaUL

#define EVE_TOUCHMODE_CONTINUOUS       0x3UL
#define EVE_TOUCHMODE_FRAME            0x2UL
#define EVE_TOUCHMODE_OFF              0x0UL
#define EVE_TOUCHMODE_ONESHOT          0x1UL

#define FTPOINTS                       POINTS

#undef EVE_ENC_BITMAP_TRANSFORM_A //New BT815 file do not compatible with the legacy code
#undef EVE_ENC_BITMAP_TRANSFORM_B //New BT815 file do not compatible with the legacy code
#undef EVE_ENC_BITMAP_TRANSFORM_D //New BT815 file do not compatible with the legacy code
#undef EVE_ENC_BITMAP_TRANSFORM_E //New BT815 file do not compatible with the legacy code

#define EVE_ENC_BITMAP_TRANSFORM_A_EXT(p,v) ((0x15UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_B_EXT(p,v) ((0x16UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_D_EXT(p,v) ((0x18UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_E_EXT(p,v) ((0x19UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))

// Added to ensure previous macros are fine
#define EVE_ENC_BITMAP_TRANSFORM_A(a) EVE_ENC_BITMAP_TRANSFORM_A_EXT(0,a)
#define EVE_ENC_BITMAP_TRANSFORM_B(b) EVE_ENC_BITMAP_TRANSFORM_B_EXT(0,b)
#define EVE_ENC_BITMAP_TRANSFORM_D(d) EVE_ENC_BITMAP_TRANSFORM_D_EXT(0,d)
#define EVE_ENC_BITMAP_TRANSFORM_E(e) EVE_ENC_BITMAP_TRANSFORM_E_EXT(0,e)

#if IS_EVE_API(4)

#define EVE_REG_UNDERRUN               0x30260C
#define EVE_REG_AH_HCYCLE_MAX          0x302610
#define EVE_REG_PCLK_FREQ              0x302614
#define EVE_REG_PCLK_2X                0x302618

#define EVE_ENC_CMD_ANIMFRAMERAM       0xffffff6d
#define EVE_ENC_CMD_ANIMSTARTRAM       0xffffff6e
#define EVE_ENC_CMD_RUNANIM            0xffffff6f
#define EVE_ENC_CMD_APILEVEL           0xffffff63
#define EVE_ENC_CMD_CALIBRATESUB       0xffffff60
#define EVE_ENC_CMD_TESTCARD           0xffffff61
#define EVE_ENC_CMD_WAIT               0xffffff65
#define EVE_ENC_CMD_NEWLIST            0xffffff68
#define EVE_ENC_CMD_ENDLIST            0xffffff69
#define EVE_ENC_CMD_CALLLIST           0xffffff67
#define EVE_ENC_CMD_RETURN             0xffffff66
#define EVE_ENC_CMD_FONTCACHE          0xffffff6b
#define EVE_ENC_CMD_FONTCACHEQUERY     0xffffff6c
#define EVE_ENC_CMD_GETIMAGE           0xffffff64
#define EVE_ENC_CMD_HSF                0xffffff62
#define EVE_ENC_CMD_PCLKFREQ           0xffffff6a

#endif

#elif IS_EVE_API(5)

//###########################################################################
//#####################################  EVE 5 ##############################
//###########################################################################

// Memory Map

#define EVE_RAM_G                      0x0UL
#define EVE_RAM_G_SIZE                 0x07ffffffUL
#define EVE_RAM_BIST                   0x7f8001c0
#define EVE_RAM_CMD                    0x7f000000UL
#define EVE_RAM_DL                     0x7f008000UL
#define EVE_RAM_REG                    0x7f006000UL
#define EVE_RAM_ROMSUB                 0x7f027800UL
#define EVE_RAM_TOP                    0x00304000UL
#define EVE_CMDBUF_SIZE                0x8000UL
#define EVE_RAM_CMD_SIZE               (16*1024L)
#define EVE_RAM_ERR_REPORT             0x309800
#define EVE_ROMFONT_TABLEADDRESS       0x07ffff00

// Registers

#define EVE_REG_TRACKER                0x7f004000   //  Tracker register 0
#define EVE_REG_TRACKER_1              0x7f004004   //  Tracker register 1
#define EVE_REG_TRACKER_2              0x7f004008   //  Tracker register 2
#define EVE_REG_TRACKER_3              0x7f00400c   //  Tracker register 3
#define EVE_REG_TRACKER_4              0x7f004010   //  Tracker register 4
#define EVE_REG_MEDIAFIFO_READ         0x7f004014   //  media FIFO read offset
#define EVE_REG_MEDIAFIFO_WRITE        0x7f004018   //  media FIFO write offset
#define EVE_REG_FLASH_SIZE             0x7f004024   //  Detected flash capacity, in Mbytes
#define EVE_REG_ANIM_ACTIVE            0x7f00402c   //  32-bit mask of currently playing animations
#define EVE_REG_OBJECT_COMPLETE        0x7f004038   //  Used with OPT_COMPLETEREG
#define EVE_REG_EXTENT_X0              0x7f00403c   //  Previous widget pixel extents
#define EVE_REG_EXTENT_Y0              0x7f004040   //  Previous widget pixel extents
#define EVE_REG_EXTENT_X1              0x7f004044   //  Previous widget pixel extents
#define EVE_REG_EXTENT_Y1              0x7f004048   //  Previous widget pixel extents
#define EVE_REG_PLAY_CONTROL           0x7f004050   //  Video playback control
#define EVE_REG_ID                     0x7f006000   //  Identification register, always reads as 0x7c
#define EVE_REG_FRAMES                 0x7f006004   //  Frame counter, since reset
#define EVE_REG_CLOCK                  0x7f006008   //  Clock cycles, since reset
#define EVE_REG_FREQUENCY              0x7f00600c   //  Main clock frequency
#define EVE_REG_RE_DEST                0x7f006010   //  RE destination address
#define EVE_REG_RE_FORMAT              0x7f006014   //  RE format, as bitmap format
#define EVE_REG_RE_ROTATE              0x7f006018   //  RE rotate control
#define EVE_REG_RE_W                   0x7f00601c   //  RE target width, in pixels
#define EVE_REG_RE_H                   0x7f006020   //  RE target height, in pixels
#define EVE_REG_RE_DITHER              0x7f006024   //  RE target dither enable
#define EVE_REG_RE_ACTIVE              0x7f006028   //  RE write path active
#define EVE_REG_RE_RENDERS             0x7f00602c   //  RE render counter
#define EVE_REG_RE_TESTMODE            0x7f006030
#define EVE_REG_SC0_RESET              0x7f006034   //  Swapchain 0, write to reset
#define EVE_REG_SC0_SIZE               0x7f006038   //  Swapchain 0, ring size 1-4
#define EVE_REG_SC0_PTR0               0x7f00603c   //  Swapchain 0, pointer 0
#define EVE_REG_SC0_PTR1               0x7f006040   //  Swapchain 0, pointer 1
#define EVE_REG_SC0_PTR2               0x7f006044   //  Swapchain 0, pointer 2
#define EVE_REG_SC0_PTR3               0x7f006048   //  Swapchain 0, pointer 3
#define EVE_REG_SC1_RESET              0x7f00604c   //  Swapchain 0, write to reset
#define EVE_REG_SC1_SIZE               0x7f006050   //  Swapchain 0, ring size 1-4
#define EVE_REG_SC1_PTR0               0x7f006054   //  Swapchain 0, pointer 0
#define EVE_REG_SC1_PTR1               0x7f006058   //  Swapchain 0, pointer 1
#define EVE_REG_SC1_PTR2               0x7f00605c   //  Swapchain 0, pointer 2
#define EVE_REG_SC1_PTR3               0x7f006060   //  Swapchain 0, pointer 3
#define EVE_REG_SC2_RESET              0x7f006064   //  Swapchain 0, write to reset
#define EVE_REG_SC2_SIZE               0x7f006068   //  Swapchain 0, ring size 1-4
#define EVE_REG_SC2_PTR0               0x7f00606c   //  Swapchain 0, pointer 0
#define EVE_REG_SC2_PTR1               0x7f006070   //  Swapchain 0, pointer 1
#define EVE_REG_SC2_PTR2               0x7f006074   //  Swapchain 0, pointer 2
#define EVE_REG_SC2_PTR3               0x7f006078   //  Swapchain 0, pointer 3
#define EVE_REG_SC1_I_VALID            0x7f00607c   //  Swapchain 1, input valid (rd)
#define EVE_REG_SC1_I_READY            0x7f006080   //  Swapchain 1, input ready (wr)
#define EVE_REG_SC1_I_PTR              0x7f006084   //  Swapchain 1, input pointer (rd)
#define EVE_REG_CPURESET               0x7f006088   //  Coprocessor reset bits 2:JA 1:JT 0:J1
#define EVE_REG_HCYCLE                 0x7f00608c   //  Horizontal total cycle count
#define EVE_REG_HOFFSET                0x7f006090   //  Horizontal display start offset
#define EVE_REG_HSIZE                  0x7f006094   //  Horizontal display pixel count
#define EVE_REG_HSYNC0                 0x7f006098   //  Horizontal sync fall offset
#define EVE_REG_HSYNC1                 0x7f00609c   //  Horizontal sync rise offset
#define EVE_REG_VCYCLE                 0x7f0060a0   //  Vertical total cycle count
#define EVE_REG_VOFFSET                0x7f0060a4   //  Vertical display start offset
#define EVE_REG_VSIZE                  0x7f0060a8   //  Vertical display line count
#define EVE_REG_VSYNC0                 0x7f0060ac   //  Vertical sync fall offset
#define EVE_REG_VSYNC1                 0x7f0060b0   //  Vertical sync rise offset
#define EVE_REG_DLSWAP                 0x7f0060b4   //  Display list swap control
#define EVE_REG_PCLK_POL               0x7f0060b8   //  PCLK polarity, 0 = clock on rising, 1 = falling
#define EVE_REG_TAG_X                  0x7f0060bc   //  Tag query X coordinate
#define EVE_REG_TAG_Y                  0x7f0060c0   //  Tag query Y coordinate
#define EVE_REG_TAG                    0x7f0060c4   //  Tag query result
#define EVE_REG_VOL_L_PB               0x7f0060c8   //  Volume for playback left
#define EVE_REG_VOL_R_PB               0x7f0060cc   //  Volume for playback right
#define EVE_REG_VOL_SOUND              0x7f0060d0   //  Volume for synth sound
#define EVE_REG_SOUND                  0x7f0060d4   //  Sound effect select
#define EVE_REG_PLAY                   0x7f0060d8   //  Start effect playback
#define EVE_REG_GPIO_DIR               0x7f0060dc   //  GPIO pin direction, 1 = output
#define EVE_REG_GPIO                   0x7f0060e0   //  GPIO read/write
#define EVE_REG_DISP                   0x7f0060e4   //  DISP output
#define EVE_REG_INT_FLAGS              0x7f006100   //  Interrupt flags
#define EVE_REG_INT_EN                 0x7f006104   //  Global interrupt enable
#define EVE_REG_INT_MASK               0x7f006108   //  Interrupt enable mask
#define EVE_REG_PLAYBACK_START         0x7f00610c   //  Audio playback RAM start address
#define EVE_REG_PLAYBACK_LENGTH        0x7f006110   //  Audio playback sample length (bytes)
#define EVE_REG_PLAYBACK_READPTR       0x7f006114   //  Audio playback current read pointer
#define EVE_REG_PLAYBACK_FREQ          0x7f006118   //  Audio playback frequency (Hz)
#define EVE_REG_PLAYBACK_FORMAT        0x7f00611c   //  Audio playback format
#define EVE_REG_PLAYBACK_LOOP          0x7f006120   //  Audio playback loop enable
#define EVE_REG_PLAYBACK_PLAY          0x7f006124   //  Start audio playback
#define EVE_REG_PWM_HZ                 0x7f006128   //  PWM output frequency (Hz)
#define EVE_REG_PWM_DUTY               0x7f00612c   //  PWM output duty cycle 0=0\%, 128=100\%
#define EVE_REG_MACRO_0                0x7f006130   //  Display list macro command 0
#define EVE_REG_MACRO_1                0x7f006134   //  Display list macro command 1
#define EVE_REG_CYA1                   0x7f00613c   //  bit 0: disable audio filter bank, 2: true PWM out, 3: e0ready testmode
#define EVE_REG_CMD_READ               0x7f00614c   //  Command buffer read pointer
#define EVE_REG_CMD_WRITE              0x7f006150   //  Command buffer write pointer
#define EVE_REG_CMD_DL                 0x7f006154   //  Command DL offset
#define EVE_REG_TOUCH_MODE             0x7f006158   //  Touchscreen sampling mode
#define EVE_REG_CTOUCH_EXTENDED        0x7f00615c   //  0: single-touch, 1: multi-touch
#define EVE_REG_CTOUCH_TOUCH0_XY       0x7f006160   //  Touchscreen screen $(x,y)$ (16, 16)
#define EVE_REG_TOUCH_SCREEN_XY        0x7f006160   //  Touchscreen screen $(x,y)$ (16, 16)
#define EVE_REG_CTOUCH_TOUCHA_XY       0x7f006164   //  Touchscreen raw $(x,y)$ (16, 16)
#define EVE_REG_TOUCH_RAW_XY           0x7f006164   //  Touchscreen raw $(x,y)$ (16, 16)
#define EVE_REG_CTOUCH_TOUCHB_XY       0x7f006168   //  Touchscreen touch 2
#define EVE_REG_CTOUCH_TOUCHC_XY       0x7f00616c   //  Touchscreen touch 3
#define EVE_REG_CTOUCH_TOUCH4_XY       0x7f006170   //  Touchscreen touch 4
#define EVE_REG_TOUCH_TAG_XY           0x7f006174   //  Touchscreen screen $(x,y)$ used for tag lookup
#define EVE_REG_TOUCH_TAG              0x7f006178   //  Touchscreen tag result 0
#define EVE_REG_TOUCH_TAG1_XY          0x7f00617c   //  Touchscreen screen $(x,y)$ used for tag lookup
#define EVE_REG_TOUCH_TAG1             0x7f006180   //  Touchscreen tag result 1
#define EVE_REG_TOUCH_TAG2_XY          0x7f006184   //  Touchscreen screen $(x,y)$ used for tag lookup
#define EVE_REG_TOUCH_TAG2             0x7f006188   //  Touchscreen tag result 2
#define EVE_REG_TOUCH_TAG3_XY          0x7f00618c   //  Touchscreen screen $(x,y)$ used for tag lookup
#define EVE_REG_TOUCH_TAG3             0x7f006190   //  Touchscreen tag result 3
#define EVE_REG_TOUCH_TAG4_XY          0x7f006194   //  Touchscreen screen $(x,y)$ used for tag lookup
#define EVE_REG_TOUCH_TAG4             0x7f006198   //  Touchscreen tag result 4
#define EVE_REG_TOUCH_TRANSFORM_A      0x7f00619c   //  Touchscreen transform coefficient (s15.16)
#define EVE_REG_TOUCH_TRANSFORM_B      0x7f0061a0   //  Touchscreen transform coefficient (s15.16)
#define EVE_REG_TOUCH_TRANSFORM_C      0x7f0061a4   //  Touchscreen transform coefficient (s15.16)
#define EVE_REG_TOUCH_TRANSFORM_D      0x7f0061a8   //  Touchscreen transform coefficient (s15.16)
#define EVE_REG_TOUCH_TRANSFORM_E      0x7f0061ac   //  Touchscreen transform coefficient (s15.16)
#define EVE_REG_TOUCH_TRANSFORM_F      0x7f0061b0   //  Touchscreen transform coefficient (s15.16)
#define EVE_REG_CRC                    0x7f0061b8   //  CPU CRC
#define EVE_REG_DATESTAMP              0x7f006584   //  Compilation datestamp
#define EVE_REG_CMDB_SPACE             0x7f006594   //  Command DL (bulk) space available
#define EVE_REG_PLAYBACK_PAUSE         0x7f0065d0   //  audio playback pause, 0=play 1=pause
#define EVE_REG_FLASH_STATUS           0x7f0065d4   //  Flash status 0=INIT 1=DETACHED 2=BASIC 3=FULL
#define EVE_REG_FLASH_DTR              0x7f0065ec   //  Flash DTR (Double Transfer Rate) enable
#define EVE_REG_SO_MODE                0x7f0065f4   //  Scanout pixel mode
#define EVE_REG_SO_SOURCE              0x7f0065f8   //  Scanout 0 source
#define EVE_REG_SO_FORMAT              0x7f0065fc   //  Scanout 0 format
#define EVE_REG_SO_EN                  0x7f006600   //  Scanout 0 enable
#define EVE_REG_BOOT_CONTROL           0x7f006628   //  Boot control byte
#define EVE_REG_I2S_EN                 0x7f006714   //  I2S interface enable
#define EVE_REG_I2S_FREQ               0x7f006718   //  I2S sample frequency
#define EVE_REG_FREQUENCY_A            0x7f00671c   //  I2S adjusted main frequency
#define EVE_REG_SC2_STATUS             0x7f006780   //  Swapchain 2 status, write to reset
#define EVE_REG_SC2_ADDR               0x7f006784   //  Swapchain 2 status, write to reset

#define EVE_REG_BRIDGE_EN              0x7f00669c
#define EVE_REG_LVDS_EN                0x7f800300
#define EVE_REG_LVDSPLL_CFG            0x7f800304
#define EVE_REG_LVDS_CFG               0x7f800308
#define EVE_BOOT_STATUS                0x7f80044c

// Bitmap Address Mask 

#define EVE_ENC_BITMAP_ADDR_MASK       0xffffffffUL

// Encoded Command Macros

#define EVE_ENC_ALPHA_FUNC(func,ref)        ((0x9UL<<24)|(((func)&0x7UL)<<8)|(((ref)&0xffUL)<<0))
#define EVE_ENC_BEGIN(prim)                 ((0x1fUL<<24)|(((prim)&0xfUL)<<0))
#define EVE_ENC_BITMAP_EXT_FORMAT(format)   ((0x2eUL<<24)|(((format)&0xffffUL)<<0))
#define EVE_ENC_BITMAP_HANDLE(handle)       ((0x5UL<<24)|(((handle)&0x3fUL)<<0))
#define EVE_ENC_BITMAP_LAYOUT(format,linestride,height) ((0x7UL<<24)|(((format)&0x1fUL)<<19)|(((linestride)&0x3ffUL)<<9)|(((height)&0x1FFUL)<<0))
#define EVE_ENC_BITMAP_LAYOUT_H(linestride,height) ((0x28UL<<24)|(((linestride)&0x3UL)<<2)|(((height)&0x3UL)<<0))
#define EVE_ENC_BITMAP_SIZE(filter,wrapx,wrapy,width,height) ((0x8UL<<24)|(((filter)&0x1UL)<<20)|(((wrapx)&0x1UL)<<19)|(((wrapy)&0x1UL)<<18)|(((width)&0x1FFUL)<<9)|(((height)&0x1FFUL)<<0))
#define EVE_ENC_BITMAP_SIZE_H(width,height) ((0x29UL<<24)|(((width)&0x3UL)<<2)|(((height)&0x3UL)<<0))
#define EVE_ENC_BITMAP_SOURCE(addr)         ((0x1UL << 24) | ((addr)&0xFFFFFFUL))
#define EVE_ENC_BITMAP_SOURCE_H(addr)       ((0x31UL << 24) | ((addr >> 24)&0xFFUL))
#define EVE_ENC_BITMAP_SWIZZLE(r,g,b,a)     ((0x2fUL<<24)|(((r)&0x7UL)<<9)|(((g)&0x7UL)<<6)|(((b)&0x7UL)<<3)|(((a)&0x7UL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_A(p,v)     ((0x15UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_B(p,v)     ((0x16UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_C(c)       ((0x17UL<<24)|(((c)&0xFFFFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_D(p,v)     ((0x18UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_E(p,v)     ((0x19UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_F(f)       ((0x1aUL<<24)|(((f)&0xFFFFFFUL)<<0))
#define EVE_ENC_BLEND_FUNC(src,dst)         ((0xbUL<<24)|(((src)&0x7UL)<<3)|(((dst)&0x7UL)<<0))
#define EVE_ENC_CALL(dest)                  ((0x1dUL<<24)|(((dest)&0xffffUL)<<0))
#define EVE_ENC_CELL(cell)                  ((0x6UL<<24)|(((cell)&0x7FUL)<<0))
#define EVE_ENC_CLEAR(c,s,t)                ((0x26UL<<24)|(((c)&0x1UL)<<2)|(((s)&0x1UL)<<1)|(((t)&0x1UL)<<0))
#define EVE_ENC_CLEAR_COLOR(c)              ((0x2UL<<24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_CLEAR_COLOR_A(alpha)        ((0xfUL<<24)|(((alpha)&0xffUL)<<0))
#define EVE_ENC_CLEAR_COLOR_RGB(red,green,blue) ((0x2UL<<24)|(((red)&0xffUL)<<16)|(((green)&0xffUL)<<8)|(((blue)&0xffUL)<<0))
#define EVE_ENC_CLEAR_STENCIL(s)            ((0x11UL<<24)|(((s)&0xffUL)<<0))
#define EVE_ENC_CLEAR_TAG(s)                ((0x12UL<<24)|(((s)&0xffUL)<<0))
#define EVE_ENC_COLOR(c)                    ((0x4UL<<24)|(((uint32_t)(c)) & 0x00ffffffUL))
#define EVE_ENC_COLOR_A(alpha)              ((0x10UL<<24)|(((alpha)&0xffUL)<<0))
#define EVE_ENC_COLOR_MASK(r,g,b,a)         ((0x20UL<<24)|(((r)&0x1UL)<<3)|(((g)&0x1UL)<<2)|(((b)&0x1UL)<<1)|(((a)&0x1UL)<<0))
#define EVE_ENC_COLOR_RGB(red,green,blue)   ((0x4UL<<24)|(((red)&0xffUL)<<16)|(((green)&0xffUL)<<8)|(((blue)&0xffUL)<<0))
#define EVE_ENC_DISPLAY()                   ((0x0UL<<24))
#define EVE_ENC_END()                       ((0x21UL<<24))
#define EVE_ENC_JUMP(dest)                  ((0x1fUL<<24)|(((dest)&0xffffUL)<<0))
#define EVE_ENC_LINE_WIDTH(width)           ((0xeUL<<24)|(((width)&0xFFFUL)<<0))
#define EVE_ENC_MACRO(m)                    ((0x25UL<<24)|(((m)&0x1UL)<<0))
#define EVE_ENC_NOP()                       ((0x2dUL<<24))
#define EVE_ENC_PALETTE_SOURCE(addr)        ((0x2aUL<<24)|(((addr)&0x3FFFFFUL)<<0))
#define EVE_ENC_POINT_SIZE(size)            ((0xdUL<<24)|(((size)&0x1FFFUL)<<0))
#define EVE_ENC_RESTORE_CONTEXT()           ((0x23UL<<24))
#define EVE_ENC_RETURN()                    ((0x24UL<<24))
#define EVE_ENC_SAVE_CONTEXT()              ((0x22UL<<24))
#define EVE_ENC_SCISSOR_SIZE(width,height)  ((0x1cUL<<24)|(((width)&0xFFFUL)<<12)|(((height)&0xFFFUL)<<0))
#define EVE_ENC_SCISSOR_XY(x,y)             ((0x1bUL<<24)|(((x)&0x7FFUL)<<11)|(((y)&0x7FFUL)<<0))
#define EVE_ENC_STENCIL_FUNC(func,ref,mask) ((0xaUL<<24)|(((func)&0x7UL)<<16)|(((ref)&0xffUL)<<8)|(((mask)&0xffUL)<<0))
#define EVE_ENC_STENCIL_MASK(mask)          ((0x13UL<<24)|(((mask)&0xffUL)<<0))
#define EVE_ENC_STENCIL_OP(sfail,spass)     ((0xcUL<<24)|(((sfail)&0x7UL)<<3)|(((spass)&0x7UL)<<0))
#define EVE_ENC_TAG(s)                      ((0x3UL<<24)|(((s)&0xffUL)<<0))
#define EVE_ENC_TAG_MASK(mask)              ((0x14UL<<24)|(((mask)&0x1UL)<<0))
#define EVE_ENC_VERTEX2F(x,y)               ((0x1UL<<30)|(((x)&0x7fffUL)<<15)|(((y)&0x7fffUL)<<0))
#define EVE_ENC_VERTEX2II(x,y,handle,cell)  ((0x2UL<<30)|(((x)&0x1FFUL)<<21)|(((y)&0x1FFUL)<<12)|(((handle)&0x1fUL)<<7)|(((cell)&0x7FUL)<<0))
#define EVE_ENC_VERTEX_FORMAT(frac)         ((0x27UL<<24)|(((frac)&0x7UL)<<0))
#define EVE_ENC_VERTEX_TRANSLATE_X(x)       ((0x2bUL<<24)|(((x)&0x1FFFFUL)<<0))
#define EVE_ENC_VERTEX_TRANSLATE_Y(y)       ((0x2cUL<<24)|(((y)&0x1FFFFUL)<<0))

#undef EVE_ENC_BITMAP_TRANSFORM_A //New BT815 file do not compatible with the legacy code
#undef EVE_ENC_BITMAP_TRANSFORM_B //New BT815 file do not compatible with the legacy code
#undef EVE_ENC_BITMAP_TRANSFORM_D //New BT815 file do not compatible with the legacy code
#undef EVE_ENC_BITMAP_TRANSFORM_E //New BT815 file do not compatible with the legacy code

#define EVE_ENC_BITMAP_TRANSFORM_A_EXT(p,v) ((0x15UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_B_EXT(p,v) ((0x16UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_D_EXT(p,v) ((0x18UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))
#define EVE_ENC_BITMAP_TRANSFORM_E_EXT(p,v) ((0x19UL<<24)|(((p)&0x1UL)<<17)|(((v)&0x1FFFFUL)<<0))

// Added to ensure previous macros are fine
#define EVE_ENC_BITMAP_TRANSFORM_A(a) EVE_ENC_BITMAP_TRANSFORM_A_EXT(0,a)
#define EVE_ENC_BITMAP_TRANSFORM_B(b) EVE_ENC_BITMAP_TRANSFORM_B_EXT(0,b)
#define EVE_ENC_BITMAP_TRANSFORM_D(d) EVE_ENC_BITMAP_TRANSFORM_D_EXT(0,d)
#define EVE_ENC_BITMAP_TRANSFORM_E(e) EVE_ENC_BITMAP_TRANSFORM_E_EXT(0,e)

// Co-processor Commands

#define EVE_ENC_CMD_ANIMDRAW           0xffffff4f
#define EVE_ENC_CMD_ANIMFRAME          0xffffff5e
#define EVE_ENC_CMD_ANIMSTART          0xffffff5f
#define EVE_ENC_CMD_ANIMSTOP           0xffffff4d
#define EVE_ENC_CMD_ANIMXY             0xffffff4e
#define EVE_ENC_CMD_APBREAD            0xffffff62
#define EVE_ENC_CMD_APBTHRASH          0xffffff6a
#define EVE_ENC_CMD_APBWRITE           0xffffff63
#define EVE_ENC_CMD_APPEND             0xffffff1c
#define EVE_ENC_CMD_APPENDF            0xffffff52
#define EVE_ENC_CMD_ARC                0xffffff87
#define EVE_ENC_CMD_BGCOLOR            0xffffff07
#define EVE_ENC_CMD_BITMAP_TRANSFORM   0xffffff1f
#define EVE_ENC_CMD_BUTTON             0xffffff0b
#define EVE_ENC_CMD_CALIBRATE          0xffffff13
#define EVE_ENC_CMD_CALIBRATESUB       0xffffff56
#define EVE_ENC_CMD_CALLLIST           0xffffff5b
#define EVE_ENC_CMD_CGRADIENT          0xffffff8a
#define EVE_ENC_CMD_CLEARCACHE         0xffffff49
#define EVE_ENC_CMD_CLOCK              0xffffff12
#define EVE_ENC_CMD_COLDSTART          0xffffff2e
#define EVE_ENC_CMD_COPYLIST           0xffffff88
#define EVE_ENC_CMD_CRC                0xffffff03
#define EVE_ENC_CMD_DDRSHUTDOWN        0xffffff65
#define EVE_ENC_CMD_DDRSTARTUP         0xffffff66
#define EVE_ENC_CMD_DEBUGINFO          0xffffff73
#define EVE_ENC_CMD_DIAL               0xffffff29
#define EVE_ENC_CMD_DLSTART            0xffffff00
#define EVE_ENC_CMD_ENABLEREGION       0xffffff7e
#define EVE_ENC_CMD_ENDLIST            0xffffff5d
#define EVE_ENC_CMD_ENDREGION          0xffffff90
#define EVE_ENC_CMD_EVALUATE           0xffffff72
#define EVE_ENC_CMD_EXECUTE            0xffffff05
#define EVE_ENC_CMD_FENCE              0xffffff68
#define EVE_ENC_CMD_FGCOLOR            0xffffff08
#define EVE_ENC_CMD_FILLWIDTH          0xffffff51
#define EVE_ENC_CMD_FLASHATTACH        0xffffff43
#define EVE_ENC_CMD_FLASHDETACH        0xffffff42
#define EVE_ENC_CMD_FLASHERASE         0xffffff3e
#define EVE_ENC_CMD_FLASHFAST          0xffffff44
#define EVE_ENC_CMD_FLASHPROGRAM       0xffffff64
#define EVE_ENC_CMD_FLASHREAD          0xffffff40
#define EVE_ENC_CMD_FLASHSOURCE        0xffffff48
#define EVE_ENC_CMD_FLASHSPIDESEL      0xffffff45
#define EVE_ENC_CMD_FLASHSPIRX         0xffffff47
#define EVE_ENC_CMD_FLASHSPITX         0xffffff46
#define EVE_ENC_CMD_FLASHUPDATE        0xffffff41
#define EVE_ENC_CMD_FLASHWRITE         0xffffff3f
#define EVE_ENC_CMD_FSDIR              0xffffff8e
#define EVE_ENC_CMD_FSOPTIONS          0xffffff6d
#define EVE_ENC_CMD_FSREAD             0xffffff71
#define EVE_ENC_CMD_FSSIZE             0xffffff80
#define EVE_ENC_CMD_FSSOURCE           0xffffff7f
#define EVE_ENC_CMD_GAUGE              0xffffff11
#define EVE_ENC_CMD_GETIMAGE           0xffffff58
#define EVE_ENC_CMD_GETMATRIX          0xffffff2f
#define EVE_ENC_CMD_GETPOINT           0xffffff06
#define EVE_ENC_CMD_GETPROPS           0xffffff22
#define EVE_ENC_CMD_GETPTR             0xffffff20
#define EVE_ENC_CMD_GLOW               0xffffff8b
#define EVE_ENC_CMD_GRADCOLOR          0xffffff30
#define EVE_ENC_CMD_GRADIENT           0xffffff09
#define EVE_ENC_CMD_GRADIENTA          0xffffff50
#define EVE_ENC_CMD_GRAPHICSFINISH     0xffffff6b
#define EVE_ENC_CMD_HAMMERAUX          0xffffff04
#define EVE_ENC_CMD_HMAC               0xffffff55
#define EVE_ENC_CMD_I2SSTARTUP         0xffffff69
#define EVE_ENC_CMD_INFLATE            0xffffff4a
#define EVE_ENC_CMD_INTERRUPT          0xffffff02
#define EVE_ENC_CMD_INT_RAMSHARED      0xffffff38
#define EVE_ENC_CMD_KEYS               0xffffff0c
#define EVE_ENC_CMD_LAST_              0xffffff8f
#define EVE_ENC_CMD_LOADASSET          0xffffff81
#define EVE_ENC_CMD_LOADIDENTITY       0xffffff23
#define EVE_ENC_CMD_LOADIMAGE          0xffffff21
#define EVE_ENC_CMD_LOADPATCH          0xffffff82
#define EVE_ENC_CMD_LOADQRCODE         0xffffff7b
#define EVE_ENC_CMD_LOADWAV            0xffffff85
#define EVE_ENC_CMD_LOGO               0xffffff2d
#define EVE_ENC_CMD_MEDIAFIFO          0xffffff34
#define EVE_ENC_CMD_MEMCPY             0xffffff1b
#define EVE_ENC_CMD_MEMCRC             0xffffff16
#define EVE_ENC_CMD_MEMSET             0xffffff19
#define EVE_ENC_CMD_MEMWRITE           0xffffff18
#define EVE_ENC_CMD_MEMZERO            0xffffff1a
#define EVE_ENC_CMD_NEWLIST            0xffffff5c
#define EVE_ENC_CMD_NOP                0xffffff53
#define EVE_ENC_CMD_NUMBER             0xffffff2a
#define EVE_ENC_CMD_OTPRD              0xffffff74
#define EVE_ENC_CMD_OTPWR              0xffffff75
#define EVE_ENC_CMD_PLAYVIDEO          0xffffff35
#define EVE_ENC_CMD_PLAYWAV            0xffffff79
#define EVE_ENC_CMD_PROGRESS           0xffffff0d
#define EVE_ENC_CMD_QRCODE             0xffffff7a
#define EVE_ENC_CMD_REGION             0xffffff8f
#define EVE_ENC_CMD_REGREAD            0xffffff17
#define EVE_ENC_CMD_REGWRITE           0xffffff86
#define EVE_ENC_CMD_RENDERTARGET       0xffffff8d
#define EVE_ENC_CMD_RESETFONTS         0xffffff4c
#define EVE_ENC_CMD_RESTORECONTEXT     0xffffff7d
#define EVE_ENC_CMD_RESULT             0xffffff89
#define EVE_ENC_CMD_RETURN             0xffffff5a
#define EVE_ENC_CMD_ROMFONT            0xffffff39
#define EVE_ENC_CMD_ROTATE             0xffffff26
#define EVE_ENC_CMD_ROTATEAROUND       0xffffff4b
#define EVE_ENC_CMD_RUNANIM            0xffffff60
#define EVE_ENC_CMD_SAVECONTEXT        0xffffff7c
#define EVE_ENC_CMD_SCALE              0xffffff25
#define EVE_ENC_CMD_SCREENSAVER        0xffffff2b
#define EVE_ENC_CMD_SCROLLBAR          0xffffff0f
#define EVE_ENC_CMD_SDATTACH           0xffffff6e
#define EVE_ENC_CMD_SDBLOCKREAD        0xffffff6f
#define EVE_ENC_CMD_SDBLOCKWRITE       0xffffff70
#define EVE_ENC_CMD_SETBASE            0xffffff33
#define EVE_ENC_CMD_SETBITMAP          0xffffff3d
#define EVE_ENC_CMD_SETFONT            0xffffff36
#define EVE_ENC_CMD_SETMATRIX          0xffffff27
#define EVE_ENC_CMD_SETROTATE          0xffffff31
#define EVE_ENC_CMD_SETSCRATCH         0xffffff37
#define EVE_ENC_CMD_SHA1               0xffffff54
#define EVE_ENC_CMD_SKETCH             0xffffff2c
#define EVE_ENC_CMD_SKIPCOND           0xffffff8c
#define EVE_ENC_CMD_SLIDER             0xffffff0e
#define EVE_ENC_CMD_SNAPSHOT           0xffffff1d
#define EVE_ENC_CMD_SNAPSHOT2          0xffffff32
#define EVE_ENC_CMD_SOFTBOOT           0xffffff61
#define EVE_ENC_CMD_SPINNER            0xffffff14
#define EVE_ENC_CMD_STOP               0xffffff15
#define EVE_ENC_CMD_SWAP               0xffffff01
#define EVE_ENC_CMD_SYNC               0xffffff3c
#define EVE_ENC_CMD_TESTCARD           0xffffff57
#define EVE_ENC_CMD_TEXT               0xffffff0a
#define EVE_ENC_CMD_TEXTDIM            0xffffff84
#define EVE_ENC_CMD_TOGGLE             0xffffff10
#define EVE_ENC_CMD_TOUCHRD            0xffffff76
#define EVE_ENC_CMD_TOUCHWR            0xffffff77
#define EVE_ENC_CMD_TOUCH_TRANSFORM    0xffffff1e
#define EVE_ENC_CMD_TRACK              0xffffff28
#define EVE_ENC_CMD_TRANSLATE          0xffffff24
#define EVE_ENC_CMD_VIDEOFRAME         0xffffff3b
#define EVE_ENC_CMD_VIDEOSTART         0xffffff3a
#define EVE_ENC_CMD_WAIT               0xffffff59
#define EVE_ENC_CMD_WAITCHANGE         0xffffff67
#define EVE_ENC_CMD_WAITCOND           0xffffff78
#define EVE_ENC_CMD_WATCHDOG           0xffffff83
#define EVE_ENC_CMD_WORKAREA           0xffffff6c

// Bitmap Formats

#define EVE_FORMAT_ARGB1555            0x0UL
#define EVE_FORMAT_ARGB2               0x5UL
#define EVE_FORMAT_ARGB4               0x6UL
#define EVE_FORMAT_BARGRAPH            0xbUL
#define EVE_FORMAT_L1                  0x1UL
#define EVE_FORMAT_L2                  0x11UL
#define EVE_FORMAT_L4                  0x2UL
#define EVE_FORMAT_L8                  0x3UL
#define EVE_FORMAT_PALETTED            0x8UL
#define EVE_FORMAT_PALETTED4444        0xfUL
#define EVE_FORMAT_PALETTED565         0xeUL
#define EVE_FORMAT_PALETTED8           0x10UL
#define EVE_FORMAT_RGB332              0x4UL
#define EVE_FORMAT_RGB565              0x7UL
#define EVE_FORMAT_RGB6                0x16UL
#define EVE_GLFORMAT                   0x1fUL

// Command Options

#define EVE_BEGIN_BITMAPS              0x1UL
#define EVE_BEGIN_EDGE_STRIP_A         0x7UL
#define EVE_BEGIN_EDGE_STRIP_B         0x8UL
#define EVE_BEGIN_EDGE_STRIP_L         0x6UL
#define EVE_BEGIN_EDGE_STRIP_R         0x5UL
#define EVE_BEGIN_LINE_STRIP           0x4UL
#define EVE_BEGIN_LINES                0x3UL
#define EVE_BEGIN_POINTS               0x2UL
#define EVE_BEGIN_RECTS                0x9UL

#define EVE_TEST_ALWAYS                0x7UL
#define EVE_TEST_EQUAL                 0x5UL
#define EVE_TEST_GEQUAL                0x4UL
#define EVE_TEST_GREATER               0x3UL
#define EVE_TEST_LEQUAL                0x2UL
#define EVE_TEST_LESS                  0x1UL
#define EVE_TEST_NEVER                 0x0UL
#define EVE_TEST_NOTEQUAL              0x6UL

#define EVE_FILTER_BILINEAR            0x1UL
#define EVE_FILTER_NEAREST             0x0UL

#define EVE_WRAP_BORDER                0x0UL
#define EVE_WRAP_REPEAT                0x1UL

#define EVE_BLEND_DST_ALPHA            0x3UL
#define EVE_BLEND_ONE                  0x1UL
#define EVE_BLEND_ONE_MINUS_DST_ALPHA  0x5UL
#define EVE_BLEND_ONE_MINUS_SRC_ALPHA  0x4UL
#define EVE_BLEND_SRC_ALPHA            0x2UL
#define EVE_BLEND_ZERO                 0x0UL

#define EVE_STENCIL_DECR               0x4UL
#define EVE_STENCIL_INCR               0x3UL
#define EVE_STENCIL_INVERT             0x5UL
#define EVE_STENCIL_KEEP               0x1UL
#define EVE_STENCIL_REPLACE            0x2UL
#define EVE_STENCIL_ZERO               0x0UL

#define EVE_OPT_3D                     0x0UL
#define EVE_OPT_CENTER                 0x600UL
#define EVE_OPT_CENTERX                0x200UL
#define EVE_OPT_CENTERY                0x400UL
#define EVE_OPT_FILL                   0x2000UL
#define EVE_OPT_FLASH                  0x40UL
#define EVE_OPT_FLAT                   0x100UL
#define EVE_OPT_FORMAT                 0x1000UL
#define EVE_OPT_FULLSCREEN             0x8UL
#define EVE_OPT_MEDIAFIFO              0x10UL
#define EVE_OPT_MONO                   0x1UL
#define EVE_OPT_NOBACK                 0x1000UL
#define EVE_OPT_NODL                   0x2UL
#define EVE_OPT_NOHANDS                0xc000UL
#define EVE_OPT_NOHM                   0x4000UL
#define EVE_OPT_NOPOINTER              0x4000UL
#define EVE_OPT_NOSECS                 0x8000UL
#define EVE_OPT_NOTEAR                 0x4UL
#define EVE_OPT_NOTICKS                0x2000UL
#define EVE_OPT_OVERLAY                0x80UL
#define EVE_OPT_RIGHTX                 0x800UL
#define EVE_OPT_SIGNED                 0x100UL
#define EVE_OPT_SOUND                  0x20UL

#define EVE_DLSWAP_DONE                0x0UL
#define EVE_DLSWAP_FRAME               0x2UL
#define EVE_DLSWAP_LINE                0x1UL

#define EVE_INT_CMDEMPTY               0x20UL
#define EVE_INT_CMDFLAG                0x40UL
#define EVE_INT_CONVCOMPLETE           0x80UL
#define EVE_INT_G8                     0x12UL
#define EVE_INT_L8C                    0xcUL
#define EVE_INT_PLAYBACK               0x10UL
#define EVE_INT_SOUND                  0x8UL
#define EVE_INT_SWAP                   0x1UL
#define EVE_INT_TAG                    0x4UL
#define EVE_INT_TOUCH                  0x2UL
#define EVE_INT_VGA                    0xdUL

#define EVE_LINEAR_SAMPLES             0x0UL
#define EVE_ADPCM_SAMPLES              0x2UL
#define EVE_ULAW_SAMPLES               0x1UL
#define EVE_VOL_ZERO                   0x0UL

#define EVE_ADC_DIFFERENTIAL           0x1UL
#define EVE_ADC_SINGLE_ENDED           0x0UL

#define EVE_ANIM_HOLD                  0x2UL
#define EVE_ANIM_LOOP                  0x1UL
#define EVE_ANIM_ONCE                  0x0UL

#define EVE_ALPHA                      0x5UL
#define EVE_BLUE                       0x4UL
#define EVE_GREEN                      0x3UL
#define EVE_RED                        0x2UL

#define EVE_FLASH_STATUS_BASIC         0x2UL
#define EVE_FLASH_STATUS_DETACHED      0x1UL
#define EVE_FLASH_STATUS_FULL          0x3UL
#define EVE_FLASH_STATUS_INIT          0x0UL

#define EVE_SS_A0                      0x13UL
#define EVE_SS_A1                      0x14UL
#define EVE_SS_A2                      0x15UL
#define EVE_SS_A3                      0x16UL
#define EVE_SS_A4                      0x17UL
#define EVE_SS_A5                      0x18UL
#define EVE_SS_A6                      0x19UL
#define EVE_SS_A7                      0x1aUL
#define EVE_SS_PAUSE                   0x12UL
#define EVE_SS_Q0                      0x0UL
#define EVE_SS_Q1                      0x1UL
#define EVE_SS_Q2                      0x2UL
#define EVE_SS_Q3                      0x3UL
#define EVE_SS_Q4                      0x4UL
#define EVE_SS_Q5                      0x5UL
#define EVE_SS_Q6                      0x6UL
#define EVE_SS_Q7                      0x7UL
#define EVE_SS_Q8                      0x8UL
#define EVE_SS_Q9                      0x9UL
#define EVE_SS_QA                      0xaUL
#define EVE_SS_QB                      0xbUL
#define EVE_SS_QC                      0xcUL
#define EVE_SS_QD                      0xdUL
#define EVE_SS_QE                      0xeUL
#define EVE_SS_QF                      0xfUL
#define EVE_SS_QI                      0x1fUL
#define EVE_SS_S0                      0xaUL
#define EVE_SS_S1                      0xbUL

#define EVE_TEXT8EVE_SS                0x9UL
#define EVE_TEXTVGA                    0xaUL

#define EVE_TOUCHMODE_CONTINUOUS       0x3UL
#define EVE_TOUCHMODE_FRAME            0x2UL
#define EVE_TOUCHMODE_OFF              0x0UL
#define EVE_TOUCHMODE_ONESHOT          0x1UL

#define FTPOINTS                       POINTS

#define EVE_SWAPCHAIN_0                0xffff00ffUL 
#define EVE_SWAPCHAIN_1                0xffff01ffUL
#define EVE_SWAPCHAIN_2                0xffff02ffUL 

#define EVE_OPT_TOUCHMODE_CONTINUOUS   0x3
#define EVE_OPT_TOUCHMODE_FRAME        0x2
#define EVE_OPT_TOUCHMODE_OFF          0x0
#define EVE_OPT_TOUCHMODE_ONESHOT      0x1
#define EVE_OPT_TOUCH_100KHZ           0x800
#define EVE_OPT_TOUCH_AR1021           0x3
#define EVE_OPT_TOUCH_FOCALTECH        0x1
#define EVE_OPT_TOUCH_GOODIX           0x2
#define EVE_OPT_TOUCH_ILI2511          0x4
#define EVE_OPT_TOUCH_QUICKSIM         0x8000
#define EVE_OPT_TOUCH_TSC2007          0x5

#else

#error No EVE support level selected. FT8XX_TYPE must be set to a supported device.

#endif

#define FT_GPU_NUMCHAR_PERFONT         (128)
#define FT_GPU_FONT_TABLE_SIZE         (148)

/* BT81x, FT81x and FT80x font table structure */
/* Font table address in ROM can be found by reading the address from 0xFFFFC location. */
/* 16 font tables are present at the address read from location 0xFFFFC. */
/* On EVE4 this is called the Legacy Font Structure. */
typedef struct
{
    /* All the values are in bytes */
    /* Width of each character font from 0 to 127 */
    uint8_t    FontWidth[FT_GPU_NUMCHAR_PERFONT];
    /* Bitmap format of font wrt bitmap formats supported by FT800 - L1, L4, L8 */
    uint32_t    FontBitmapFormat;
    /* Font line stride in FT800 ROM */
    uint32_t    FontLineStride;
    /* Font width in pixels */
    uint32_t    FontWidthInPixels;
    /* Font height in pixels */
    uint32_t    FontHeightInPixels;
    /* Pointer to font graphics raw data */
    uint32_t    PointerToFontGraphicsData;
} EVE_GPU_FONT_HEADER;

/* Nothing beyond this */

#endif    /* _FT8XX_H_ */

