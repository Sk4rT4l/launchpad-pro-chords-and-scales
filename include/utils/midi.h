/*
 * midi.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef MIDI_H_
#define MIDI_H_

#include "app.h"
#include "music/chord.h"
#include "utils/layout.h"

void midi_send_note(u8 index, u8 value);
void midi_stop_note(u8 index, u8 value);
void midi_send_aftertouch(u8 index, u8 value);
void midi_send_chord(u8 index, u8 value, Chord chord);
void midi_stop_chord(u8 index, u8 value, Chord chord);

#endif /* MIDI_H_ */
