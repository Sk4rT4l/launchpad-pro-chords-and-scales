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

#define BT_FIRST_MIDI_CHANNEL 71
#define BT_LAST_MIDI_CHANNEL 88

/**
 * Send midi NOTEON on the current midi channel
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void midi_send_note(u8 index, u8 value);

/**
 * Send midi NOTEOFF on the current midi channel
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void midi_stop_note(u8 index, u8 value);

/**
 * Send midi POLYAFTERTOUCH on the current midi channel
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void midi_send_aftertouch(u8 index, u8 value);

/**
 * Send midi NOTEON on the current midi channel for all midi notes in the specified chord
 * @param u8 index Button index (root note for the specified chord)
 * @param u8 value Velocity value
 * @param Chord chord Selected chord
 */
void midi_send_chord(u8 index, u8 value, Chord chord);

/**
 * Send midi NOTEOFF on the current midi channel for all midi notes in the specified chord
 * @param u8 index Button index (root note for the specified chord)
 * @param u8 value Velocity value
 * @param Chord chord Selected chord
 */
void midi_stop_chord(u8 index, u8 value, Chord chord);

/**
 * Send midi POLYAFTERTOUCH on the current midi channel for all midi notes in the specified chord
 * @param u8 index Button index (root note for the specified chord)
 * @param u8 value Velocity value
 * @param Chord chord Selected chor
 */
void midi_send_chord_aftertouch(u8 index, u8 value, Chord chord);

extern int current_midi_channel;

#endif /* MIDI_H_ */
