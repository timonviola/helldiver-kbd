#include QMK_KEYBOARD_H

enum custom_keycodes {
    AAC_8_AUTOCANNON_SENTRY = QK_KB_0,
    AARC_3_TESLA_TOWER,
    AG_16_GATLING_SENTRY,
    AM_12_MORTAR_SENTRY,
    AM_23_EMS_MORTAR_SENTRY,
    AMG_43_MACHINE_GUN_SENTRY,
    AMLS_4X_ROCKET_SENTRY,
    AC_8_AUTOCANNON,
    AD_334_GUARD_DOG,
    APW_1_ANTI_MATERIEL_RIFLE,
    ARC_3_ARC_THROWER,
    EMG_101_HMG_EMPLACEMENT,
    EAT_17,
    EXO_45_PATRIOT_EXOSUIT,
    EAGLE_110MM_ROCKET_PODS,
    EAGLE_500KG_BOMB,
    EAGLE_AIRSTRIKE,
    EAGLE_CLUSTER_BOMB,
    EAGLE_NAPALM_STRIKE,
    EAGLE_REARM,
    EAGLE_SMOKE_STRIKE,
    EAGLE_STRAFING_RUN,
    FAF_14_SPEAR_LAUNCHER,
    FLAM_40_INCINERATOR,
    FX_12_SHIELD_GENERATOR_RELAY,
    GL_21_GRENADE_LAUNCHER,
    GR_8_RECOILLESS_RIFLE,
    ILLUMINATION_FLARE,
    LAS_98_LASER_CANNON,
    LAS_99_QUASAR_CANNON,
    LIFT_850_JUMP_PACK,
    M_105_STALWART,
    MD_6_ANTI_PERSONNEL_MINEFIELD,
    MD_I4_INCENDIARY_MINES,
    MG_206_HEAVY_MACHINE_GUN,
    MG_43_MACHINE_GUN,
    NUX_223_HELLBOMB,
    ORBITAL_120MM_HE_BARRAGE,
    ORBITAL_380MM_HE_BARRAGE,
    ORBITAL_AIRBURST_STRIKE,
    ORBITAL_EMS_STRIKE,
    ORBITAL_GAS_STRIKE,
    ORBITAL_GATLING_BARRAGE,
    ORBITAL_LASER,
    ORBITAL_PRECISION_STRIKE,
    ORBITAL_RAILCANNON_STRIKE,
    ORBITAL_SMOKE_STRIKE,
    ORBITAL_WALKING_BARRAGE,
    RS_422_RAILGUN,
    REINFORCE,
    RESUPPLY,
    RESUPPLY_PACK,
    SEAF_ARTILLERY,
    SH_20_BALLISTIC_SHIELD_BACKPACK,
    SH_20_SHIELD_GENERATOR_PACK,
    SOS_BEACON,
    SSSD_DELIVERY,
    SEISMIC_PROBE,
    UPLOAD_DATA
};

// Keypress macros
#define _W SS_DOWN(X_W) SS_DELAY(35) SS_UP(X_W) SS_DELAY(35)
#define _A SS_DOWN(X_A) SS_DELAY(35) SS_UP(X_A) SS_DELAY(35)
#define _S SS_DOWN(X_S) SS_DELAY(35) SS_UP(X_S) SS_DELAY(35)
#define _D SS_DOWN(X_D) SS_DELAY(35) SS_UP(X_D) SS_DELAY(35)
#define _MB1 SS_DOWN(X_BTN1) SS_DELAY(35) SS_UP(X_BTN1) SS_DELAY(35)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT(
  RESUPPLY,        REINFORCE,                EAGLE_REARM,
  EAGLE_AIRSTRIKE, EAGLE_500KG_BOMB,         EAGLE_110MM_ROCKET_PODS,
  RS_422_RAILGUN,  ORBITAL_LASER,            AAC_8_AUTOCANNON_SENTRY
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LIFT_850_JUMP_PACK:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _W _S _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case RESUPPLY_PACK:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _S _W _W _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case SH_20_BALLISTIC_SHIELD_BACKPACK:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _S _S _W _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case SH_20_SHIELD_GENERATOR_PACK:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _A _D _A _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AD_334_GUARD_DOG:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _A _W _D _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case MG_43_MACHINE_GUN:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _S _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case APW_1_ANTI_MATERIEL_RIFLE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _D _W _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case M_105_STALWART:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _S _W _W _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAT_17:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _A _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case GR_8_RECOILLESS_RIFLE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _D _D _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case FLAM_40_INCINERATOR:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _W _S _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AC_8_AUTOCANNON:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _S _W _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case RS_422_RAILGUN:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _D _S _W _A _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case FAF_14_SPEAR_LAUNCHER:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _W _S _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case GL_21_GRENADE_LAUNCHER:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _W _A _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case LAS_98_LASER_CANNON:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _S _W _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ARC_3_ARC_THROWER:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _D _S _W _A _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case REINFORCE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _S _D _A _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case SOS_BEACON:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _S _D _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case RESUPPLY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case NUX_223_HELLBOMB:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _A _S _W _D _S _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case SSSD_DELIVERY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _S _W _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case SEISMIC_PROBE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _W _A _D _S _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case UPLOAD_DATA:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _W _W _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_REARM:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _W _A _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case SEAF_ARTILLERY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _S _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EMG_101_HMG_EMPLACEMENT:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _A _D _D _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case FX_12_SHIELD_GENERATOR_RELAY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _S _A _D _A _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AARC_3_TESLA_TOWER:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _D _W _A _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case MD_6_ANTI_PERSONNEL_MINEFIELD:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _W _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case MD_I4_INCENDIARY_MINES:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _A _A _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AMG_43_MACHINE_GUN_SENTRY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _D _D _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AG_16_GATLING_SENTRY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _D _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AM_12_MORTAR_SENTRY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _D _D _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AAC_8_AUTOCANNON_SENTRY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _D _W _A _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AMLS_4X_ROCKET_SENTRY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _D _D _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case AM_23_EMS_MORTAR_SENTRY:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _S _W _D _S _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_GATLING_BARRAGE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _S _A _W _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_AIRBURST_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _D _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_120MM_HE_BARRAGE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _D _S _A _D _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_380MM_HE_BARRAGE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _S _W _W _A _S _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_WALKING_BARRAGE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _S _D _S _D _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_LASER:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _S _W _D _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_RAILCANNON_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _W _S _S _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_PRECISION_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _D _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_GAS_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _D _S _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_EMS_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _D _A _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case ORBITAL_SMOKE_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _D _D _S _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_STRAFING_RUN:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_AIRSTRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _S _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_CLUSTER_BOMB:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _S _S _D SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_NAPALM_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _S _W SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_SMOKE_STRIKE:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _W _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_110MM_ROCKET_PODS:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _W _A SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;
    case EAGLE_500KG_BOMB:
      if (record->event.pressed) {
        SEND_STRING( SS_DOWN(X_LCTL) SS_DELAY(35) _W _D _S _S _S SS_UP(X_LCTL) SS_DELAY(35) _MB1);
      } else {

      }
      break;

    }
    return true;
};
