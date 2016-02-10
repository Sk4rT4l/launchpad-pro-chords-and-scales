/*
 * layout.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef LAYOUT_H_
#define LAYOUT_H_

#include "app.h"
#include "music/scale.h"
#include "utils/buttons.h"
#include "utils/midi.h"

#define GRID_SIZE 8
#define DEFAULT_OCTAVE 3
#define DEFAULT_ROOT_NOTE 36

typedef struct {
	int x;
	int y;
} PadCoordinate;

typedef struct {
	// 0-127
	u8 root_note;
	// 0-10
	u8 octave;
} Layout;

extern Layout current_layout;

/**
 * Initialize X and Y coordinates for each pads
 */
void layout_initialize_pad_coordinates();

/**
 * Initialize indexes for each pads (0-64)
 */
void layout_initialize_pad_indexes();

/**
 * Get the index (0-64) for specified button index
 * @param u8 bt_index Button index
 * @return u8 Pad index/number
 */
u8 layout_get_pad_index(u8 bt_index);

/**
 * Get the pad/button index (11-88) for the specified pad index/number (0-64)
 * @param u8 index Pad index/number
 * @return u8 Button index
 */
u8 layout_get_pad_button(u8 index);

/**
 * Calculate the midi notes associated to each pads
 */
void layout_recalculate_pad_notes();

/**
 * Initialize the array for storing the scale associated to each pads. Used in setup.
 */
void layout_initialize_pad_scales();

/**
 * Initialize an array containing midi channels
 */
void layout_initialize_pad_midi_channels();

/**
 * Get the midi note for the specified pad
 * @param u8 index Button index
 * @return u8 Midi note
 */
u8 layout_get_midi_note(u8 index);

/**
 * Draw the current scale on pads
 */
void layout_draw_scale();

/**
 * Update the UI for octave buttons (UP/DOWN)
 */
void layout_refresh_octave_buttons();

/**
 * Draw the list of implemented scales. The current scale is brighter. Used in setup mode.
 */
void layout_list_scales();

/**
 * Set the current scale corresponding to the specified button index
 * @param u8 index Button index
 */
void layout_set_scale(u8 index);

/**
 * Draw the list of midi channels. The current midi channel is brighter. Used in setup mode.
 */
void layout_list_midi_channels();

/**
 * Set the current midi channel corresponding to the specified button index
 * @param u8 index Button index
 */
void layout_set_midi_channel(u8 index);

#endif /* LAYOUT_H_ */
