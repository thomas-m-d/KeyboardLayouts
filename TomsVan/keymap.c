#include "MiniVan20190622161824.h"
enum custom_keycodes {
	M_IME = SAFE_RANGE
};


//Tap Dance Setup
typedef struct {
  bool is_press_action;
  int state;
} tap;
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
};
enum {
  L_PRNS = 0,
  R_PRNS,
  VOL_BRI_DN,
  VOL_BRI_UP,
  FF_NAV_LFT,
  FF_NAV_RGT
};
int cur_dance (qk_tap_dance_state_t *state);
void lp_func (qk_tap_dance_state_t *state, void *user_data);
void rp_func (qk_tap_dance_state_t *state, void *user_data);
void vbd_func (qk_tap_dance_state_t *state, void *user_data);
void vbu_func (qk_tap_dance_state_t *state, void *user_data);
void fnl_func (qk_tap_dance_state_t *state, void *user_data);
void fnr_func (qk_tap_dance_state_t *state, void *user_data);

//Auto-Generated
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case M_IME:
				SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
				return false;
		}
	}
	else {
		switch(keycode) {
			case M_IME:
				SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
				return false;
		}
	}
	return true;
};

//Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = KEYMAP(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TT(3),
		TT(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(2, KC_QUOT), 
		LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TG(2),
		OSM(MOD_LCTL), KC_LGUI, LSFT(KC_3), TD(L_PRNS), KC_SPC, KC_BSPC, TD(R_PRNS), LSFT(KC_1), KC_BSLS, KC_LALT),
	[1] = KEYMAP(KC_TRNS, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
		KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_EQL), KC_MINS, KC_EQL, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_TRNS, KC_TRNS, LSFT(KC_7), LSFT(KC_MINS), KC_TRNS),
	[2] = KEYMAP(KC_GRV, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, LSFT(KC_HOME), LSFT(KC_UP), LSFT(KC_END), KC_TRNS, KC_TRNS,
		KC_TRNS, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT), LSFT(LCTL(KC_LEFT)), LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), LSFT(LCTL(KC_RIGHT)), KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_8), KC_SLSH, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, LSFT(KC_4), TD(VOL_BRI_DN), KC_ENT, KC_DEL, TD(VOL_BRI_UP), LSFT(KC_2), KC_TRNS, KC_TRNS),
	[3] = KEYMAP(LSFT(KC_GRV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_6), LSFT(KC_5), KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, TD(FF_NAV_LFT), LCTL(LALT(KC_SPC)), LCTL(LALT(KC_BSPC)), TD(FF_NAV_RGT), KC_TRNS, KC_TRNS, KC_TRNS),
};

//LED Controls
#define set_black rgblight_setrgb (0x00, 0x00, 0x00)
#define set_green rgblight_setrgb (0x01, 0x03, 0x00)
#define set_cyan rgblight_setrgb (0x00, 0x02, 0x02)
#define set_magenta rgblight_setrgb (0x02, 0x00, 0x02)
void matrix_init_user(void) {
	set_black;
}
uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case 1:
			set_green;
			break;
		case 2:
			set_cyan;
			break;
		case 3:
			set_magenta;
			break;
		default:
			set_black;
			break;
	}
	return state;
}




//Tap Dance Details
int cur_dance (qk_tap_dance_state_t *state) {		//Note, I have edited the logic here...
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->pressed) return DOUBLE_HOLD;
  else return DOUBLE_TAP;
}
static tap lp_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap rp_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap vbd_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap vbu_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap fnl_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap fnr_tap_state = {
  .is_press_action = true,
  .state = 0
};


void lp_func (qk_tap_dance_state_t *state, void *user_data) {
  lp_tap_state.state = cur_dance(state);
  switch (lp_tap_state.state) {
    case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_9); unregister_code(KC_9); unregister_code(KC_LSFT); break;
    case SINGLE_HOLD: register_code(KC_LBRC); unregister_code(KC_LBRC); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_LBRC); unregister_code(KC_LBRC); unregister_code(KC_LSFT); break;
    case DOUBLE_HOLD: register_code(KC_LSFT); register_code(KC_COMM); unregister_code(KC_COMM); unregister_code(KC_LSFT);
  }
  lp_tap_state.state = 0;
}

void rp_func (qk_tap_dance_state_t *state, void *user_data) {
  rp_tap_state.state = cur_dance(state);
  switch (rp_tap_state.state) {
    case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_0); unregister_code(KC_0); unregister_code(KC_LSFT); break;
    case SINGLE_HOLD: register_code(KC_RBRC); unregister_code(KC_RBRC); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_RBRC); unregister_code(KC_RBRC); unregister_code(KC_LSFT); break;
    case DOUBLE_HOLD: register_code(KC_LSFT); register_code(KC_DOT); unregister_code(KC_DOT); unregister_code(KC_LSFT);
  }
  rp_tap_state.state = 0;
}

void vbd_func (qk_tap_dance_state_t *state, void *user_data) {
  vbd_tap_state.state = cur_dance(state);
  switch (vbd_tap_state.state) {
    case SINGLE_TAP: register_code(KC_VOLD); unregister_code(KC_VOLD); break;
    case SINGLE_HOLD: register_code(KC_BRID); unregister_code(KC_BRID);
  }
  vbd_tap_state.state = 0;
}

void vbu_func (qk_tap_dance_state_t *state, void *user_data) {
  vbu_tap_state.state = cur_dance(state);
  switch (vbu_tap_state.state) {
    case SINGLE_TAP: register_code(KC_VOLU); unregister_code(KC_VOLU); break;
    case SINGLE_HOLD: register_code(KC_BRIU); unregister_code(KC_BRIU);
  }
  vbu_tap_state.state = 0;
}

void fnl_func (qk_tap_dance_state_t *state, void *user_data) {
  fnl_tap_state.state = cur_dance(state);
  switch (fnl_tap_state.state) {
    case SINGLE_TAP: register_code(KC_LCTL); register_code(KC_LBRC); unregister_code(KC_LBRC); unregister_code(KC_LCTL); break;
    case SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_LSFT); register_code(KC_TAB); unregister_code(KC_TAB); unregister_code(KC_LSFT); unregister_code(KC_LCTL);
  }
  fnl_tap_state.state =	0;
}

void fnr_func (qk_tap_dance_state_t *state, void *user_data) {
  fnr_tap_state.state = cur_dance(state);
  switch (fnr_tap_state.state) {
    case SINGLE_TAP: register_code(KC_LCTL); register_code(KC_RBRC); unregister_code(KC_RBRC); unregister_code(KC_LCTL); break;
    case SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_TAB); unregister_code(KC_TAB); unregister_code(KC_LCTL);
  }
  fnr_tap_state.state =	0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [L_PRNS] = ACTION_TAP_DANCE_FN(lp_func),
  [R_PRNS] = ACTION_TAP_DANCE_FN(rp_func),
  [VOL_BRI_DN] = ACTION_TAP_DANCE_FN(vbd_func),
  [VOL_BRI_UP] = ACTION_TAP_DANCE_FN(vbu_func),
  [FF_NAV_LFT] = ACTION_TAP_DANCE_FN(fnl_func),
  [FF_NAV_RGT] = ACTION_TAP_DANCE_FN(fnr_func)
};
