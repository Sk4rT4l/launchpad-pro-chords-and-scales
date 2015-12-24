/*
 * midi.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef MIDI_H_
#define MIDI_H_

#include "app.h"
#include "utils/layout.h"

void midi_send_note(u8 index, u8 value);
void midi_stop_note(u8 index, u8 value);
void midi_send_aftertouch(u8 index, u8 value);

#endif /* MIDI_H_ */
