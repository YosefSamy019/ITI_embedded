/*
 * LCD_patterns.h
 *
 * Created: 2024-01-28 3:10:32 PM
 *  Author: asus
 */ 


#ifndef LCD_PATTERNS_H_
#define LCD_PATTERNS_H_

#define HLCD_PATTERN_SMILEY_5X8			{0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};  // smiley
#define HLCD_PATTERN_ROBO_5X8			{0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x0A};  // Robo
#define HLCD_PATTERN_ARROW_5X8			{0x08, 0x0C, 0x0E, 0x0F, 0x0E, 0x0C, 0x08, 0x00};  // arrow
#define HLCD_PATTERN_BELL_5X8			{0x00, 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x04, 0x00};  // bell
#define HLCD_PATTERN_HEART_5X8			{0x00, 0x00, 0x0A, 0x15, 0x11, 0x0E, 0x04, 0x00};  // Heart
#define HLCD_PATTERN_OMEGA_5X8			{0x00, 0x0E, 0x11, 0x11, 0x11, 0x0A, 0x1B, 0x00};  // omega
#define HLCD_PATTERN_CT_5X8				{0x0E, 0x10, 0x17, 0x12, 0x12, 0x12, 0x10, 0x0E};  // CT
#define HLCD_PATTERN_PLUS_MINUS_5X8		{0x04, 0x04, 0x1F, 0x04, 0x04, 0x00, 0x1F, 0x00};  //+-
#define HLCD_PATTERN_CROSS_5X8			{0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00, 0x00};  // cross x
#define HLCD_PATTERN_MUSICAL_NOTE_5X8	{0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x04, 0x04, 0x00};  // musical note
#define HLCD_PATTERN_STAR_5X8			{0x04, 0x0E, 0x1F, 0x0E, 0x04, 0x00, 0x00, 0x00};  // star

//arrow go up animation
#define LCD_PATTERN_ARROW_UP_ANIM_1_5X8 {0x04,0x0A,0x11,0x04,0x0A,0x11,0x00,0x00};
#define LCD_PATTERN_ARROW_UP_ANIM_2_5X8	{0x0A,0x11,0x04,0x0A,0x11,0x04,0x0A,0x00};
#define LCD_PATTERN_ARROW_UP_ANIM_3_5X8 {0x11,0x04,0x0A,0x11,0x04,0x0A,0x11,0x00};
	
#endif /* LCD_PATTERNS_H_ */