#include QMK_KEYBOARD_H

enum custom_keycodes {
    EAGLE_STRAFING_GUN = SAFE_RANGE,
    EAGLE_CLUSTER_BOMB,
    EAGLE_110MM_ROCKET_PODS,
    EAGLE_REARM,
    EXPANDABLE_ANTI_TANK,
    RESUPPLY,
    REINFORCE,
    ORBITAL_PRECISISON_STRIKE,
    ORBITAL_WALKING_BARRAGE,
};

#define _W SS_DOWN(X_W) SS_DELAY(35) SS_UP(X_W) SS_DELAY(35)
#define _A SS_DOWN(X_A) SS_DELAY(35) SS_UP(X_A) SS_DELAY(35)
#define _S SS_DOWN(X_S) SS_DELAY(35) SS_UP(X_S) SS_DELAY(35)
#define _D SS_DOWN(X_D) SS_DELAY(35) SS_UP(X_D) SS_DELAY(35)
#define _MB1 SS_DOWN(X_BTN1) SS_DELAY(35) SS_UP(X_BTN1) SS_DELAY(35)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT(
  RESUPPLY,                 REINFORCE,                  EAGLE_REARM,
  EAGLE_STRAFING_GUN,       EAGLE_CLUSTER_BOMB,         EAGLE_110MM_ROCKET_PODS,
  ORBITAL_WALKING_BARRAGE,  ORBITAL_PRECISISON_STRIKE,  EXPANDABLE_ANTI_TANK
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EAGLE_STRAFING_GUN:
        if (record->event.pressed) {
          SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
        } else {

        }
        break;
    case REINFORCE:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(35) _W _S _D _A _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
        } else {

        }
        break;
    case RESUPPLY:
        if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
        } else {

        }
        break;
    case EAGLE_REARM:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(35) _W _W _A _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
        } else {

        }
        break;
    case EAGLE_CLUSTER_BOMB:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _S _S _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
        } else {

        }
        break;
    case EAGLE_110MM_ROCKET_PODS:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _W _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
        } else {

        }
        break;
    case EXPANDABLE_ANTI_TANK:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _A _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
        } else {

        }
        break;
    case ORBITAL_PRECISISON_STRIKE:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(35) _D _D _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_WALKING_BARRAGE:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(35) _D _S _D _S _D _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    }
    return true;
};
