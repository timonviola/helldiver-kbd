# helldiver

helldiver is 9key macro-keyboard.

*why?*

- democracy

*how?*

1. Set up your qmk build env.
1. Add this repo under keyboards/helldiver
1. To flash the firmware run:

`qmk flash -kb helldiver -km default`


To customize the keymap, edit `keymaps/default/keymap.c`:
  - change the LAYOUT to edit your keymap (use keycodes from custom_keycodes)


# todo
- via or some UI way of editing keymap so it's more approachable
- verify generated keymaps
- (?) add hardware repo for a 3x3 macropad
