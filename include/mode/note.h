/*
 * note.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef NOTE_H_
#define NOTE_H_

#include "app.h"
#include "music/chord.h"
#include "music/scale.h"
#include "utils/buttons.h"
#include "utils/colors.h"
#include "utils/layout.h"
#include "utils/midi.h"

void note_mode_open();
void note_mode_close();
void note_mode_setup_open();
void note_mode_setup_close();
void note_mode_handle(u8 index, u8 value);
void note_mode_setup_handle(u8 index, u8 value);
void note_mode_aftertouch(u8 index, u8 value);

#endif /* NOTE_H_ */
