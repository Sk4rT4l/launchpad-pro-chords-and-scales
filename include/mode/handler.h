/*
 * handler.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef HANDLER_H_
#define HANDLER_H_

#include "app.h"
#include "mode/note.h"
#include "utils/buttons.h"

typedef enum {
	MODE_DISABLED,
	MODE_SESSION,
	MODE_NOTE,
	MODE_DEVICE,
	MODE_USER
} Mode;

extern int setup_mode_flag;
extern Mode current_mode;

/**
 * Handle mode buttons pressure to change the current mode
 * @param u8 index Button index
 */
void change_current_mode(u8 index);

/**
 * Dispatch the surface event to the current mode
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void mode_handle(u8 index, u8 value);

/**
 * Toggle the setup mode
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void mode_setup_toggle(u8 index, u8 value);

/**
 * Dispatch the aftertouch event to the current mode
 * @param u8 index Button index
 * @param u8 value Velocity value
 */
void mode_aftertouch(u8 index, u8 value);

#endif /* HANDLER_H_ */
