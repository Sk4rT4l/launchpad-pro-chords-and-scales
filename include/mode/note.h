/*
 * note.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef NOTE_H_
#define NOTE_H_

#include <stdlib.h>

#include "app.h"
#include "music/chord.h"
#include "music/scale.h"
#include "utils/buttons.h"
#include "utils/colors.h"
#include "utils/layout.h"
#include "utils/midi.h"

/**
 * Initialize the note mode
 */
void note_mode_open();

/**
 * Close the note mode
 */
void note_mode_close();

/**
 * Initialize the setup for the note mode
 */
void note_mode_setup_open();

/**
 * Close the setup for the note mode
 */
void note_mode_setup_close();

/**
 * Handle surface events
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void note_mode_handle(u8 index, u8 value);

/**
 * Handle surface events in setup
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void note_mode_setup_handle(u8 index, u8 value);

/**
 * Handle aftertouch events
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void note_mode_aftertouch(u8 index, u8 value);

/**
 * Color and update play buttons for stored chords 
 */
void note_mode_refresh_stored_chords();

#endif /* NOTE_H_ */
