/******************************************************************************/
/* Mednafen Sega Saturn Emulation Module                                      */
/******************************************************************************/
/* sound.h:
**  Copyright (C) 2015-2016 Mednafen Team
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef __MDFN_SS_SOUND_H
#define __MDFN_SS_SOUND_H

#include <stdint.h>

extern int16_t IBuffer[1024][2];

void SOUND_Init(void) MDFN_COLD;
void SOUND_Reset(bool powering_up) MDFN_COLD;
void SOUND_Kill(void) MDFN_COLD;

void SOUND_Set68KActive(bool active);
void SOUND_Reset68K(void);

void SOUND_SetClockRatio(uint32 ratio); // Ratio between SH-2 clock and 68K clock (sound clock / 2)
sscpu_timestamp_t SOUND_Update(sscpu_timestamp_t timestamp);
void SOUND_ResetTS(void);
int32 SOUND_FlushOutput(void);
void SOUND_StateAction(StateMem *sm, const unsigned load, const bool data_only);

uint16 SOUND_Read16(uint32 A);
void SOUND_Write8(uint32 A, uint8 V);
void SOUND_Write16(uint32 A, uint16 V);

uint8 SOUND_PeekRAM(uint32 A);
void SOUND_PokeRAM(uint32 A, uint8 V);

#endif
