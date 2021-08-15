#include QMK_KEYBOARD_H

#define _MAIN 0

static uint8_t keymode = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder*/
    switch (keymode) {
      case 0:
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;
      case 1:
        // This is a mode for setting the RGB behavior
        if (clockwise) {
          rgblight_step_noeeprom();
        } else {
          rgblight_step_reverse_noeeprom();
        }
        rgblight_set();
        break;
      case 2:
        if (clockwise) {
          rgblight_increase_hue_noeeprom();
        } else {
          rgblight_decrease_hue_noeeprom();
        }
        rgblight_set();
        break;
    }
  } else if (index == 1) { /* Second encoder*/
    if (clockwise) {
      tap_code(KC_3);
    } else {
      tap_code(KC_4);
    }
  } else if (index == 2) { /* Third encoder*/
    if (clockwise) {
      tap_code(KC_5);
    } else {
      tap_code(KC_6);
    }
  } else if (index == 3) { /* Fourth encoder*/
    if (clockwise) {
      tap_code(KC_7);
    } else {
      tap_code(KC_8);
    }
  } else if (index == 4) { /* Fifth encoder*/
    if (clockwise) {
      tap_code(KC_9);
    } else {
      tap_code(KC_0);
    }
  }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //buttion closest to usb is first
  [_MAIN] = LAYOUT_ortho_1x5(
     KC_MUTE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP
  )
};

enum combo_events {
  ANIM_COMBO,
  COLOR_COMBO,
  FWRV_COMBO,
  FOUR_COMBO
};

const uint16_t PROGMEM animation_combo[] = {KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP, COMBO_END};
const uint16_t PROGMEM color_combo[] = {KC_MEDIA_NEXT_TRACK, KC_MEDIA_STOP, COMBO_END};
const uint16_t PROGMEM lighttoggle_combo[] = {KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, COMBO_END};
const uint16_t PROGMEM save_combo[] = {KC_MUTE, KC_MEDIA_STOP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ANIM_COMBO] = COMBO_ACTION(animation_combo),
  [COLOR_COMBO] = COMBO_ACTION(color_combo),
  [FWRV_COMBO] = COMBO_ACTION(lighttoggle_combo),
  [FOUR_COMBO] = COMBO_ACTION(save_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ANIM_COMBO:
      if (pressed) {
        keymode = 1;
      }
      else {
        keymode = 0;
      }
      break;
    case COLOR_COMBO:
      if (pressed) {
        keymode = 2;
      }
      else {
        keymode = 0;
      }
      break;
    case FWRV_COMBO:
      if (pressed) {
        rgblight_toggle_noeeprom();
      }
      break;
    case FOUR_COMBO:
      if (pressed) {
        //rgblight_toggle_noeeprom();
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
        rgblight_mode(rgblight_get_mode());
        if (rgblight_is_enabled()) {
          rgblight_enable();
        }
        else {
          rgblight_disable();
        }
      }
  }
}