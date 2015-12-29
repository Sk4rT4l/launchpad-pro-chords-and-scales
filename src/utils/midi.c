/*
 * midi.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "utils/midi.h"

/**
 * Sending midi NOTEON
 */
void midi_send_note(u8 index, u8 value){
	u8 midi_note = layout_get_midi_note(index);
	hal_send_midi(USBMIDI, NOTEON, midi_note, value);
	hal_send_midi(DINMIDI, NOTEON, midi_note, value);
}

/**
 * Sending midi NOTEOFF
 */
void midi_stop_note(u8 index, u8 value){
	u8 midi_note = layout_get_midi_note(index);
	hal_send_midi(USBMIDI, NOTEOFF, midi_note, value);
	hal_send_midi(DINMIDI, NOTEOFF, midi_note, value);
}

/**
 * Sending midi aftertouch
 */
void midi_send_aftertouch(u8 index, u8 value){
	u8 midi_note = layout_get_midi_note(index);
	hal_send_midi(USBMIDI, POLYAFTERTOUCH | 0, midi_note, value);
	hal_send_midi(DINMIDI, POLYAFTERTOUCH | 0, midi_note, value);
}

/**
 * Sending midi chord (index = root note)
 */
void midi_send_chord(u8 index, u8 value, Chord chord){
	u8 midi_note = layout_get_midi_note(index);
	for (int i = 0; i < chord.size; i++){
		hal_send_midi(USBMIDI, NOTEON, midi_note + chord.offsets[i], value);
		hal_send_midi(DINMIDI, NOTEON, midi_note + chord.offsets[i], value);
	}
}

/**
 * Stopping midi chord (index = root note)
 */
void midi_stop_chord(u8 index, u8 value, Chord chord){
	u8 midi_note = layout_get_midi_note(index);
	for (int i = 0; i < chord.size; i++){
		hal_send_midi(USBMIDI, NOTEOFF, midi_note + chord.offsets[i], value);
		hal_send_midi(DINMIDI, NOTEOFF, midi_note + chord.offsets[i], value);
	}
}
