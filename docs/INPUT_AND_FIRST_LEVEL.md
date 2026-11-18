# Input and First Test Level

## Current input bindings

### Keyboard and mouse
- Move: W / A / S / D
- Camera: mouse movement
- Light attack: J
- Heavy attack: K
- Dodge: Left Shift

### Gamepad
- Move: left stick
- Camera: right stick
- Light attack: X / west face button
- Heavy attack: Y / north face button
- Dodge: B / east face button

The mappings are starter defaults in `Config/DefaultInput.ini`. They are not a finished rebinding UI. Enhanced Input Mapping Context properties can be assigned on a Blueprint subclass of `AFFRPlayerController`.

## Creating the first playable test map
1. Create a level named `L_TestStreet`.
2. Add a PlayerStart for Player 1 and a second PlayerStart for Player 2, spaced apart and facing the arena.
3. Add a NavMeshBoundsVolume covering the walkable floor and build navigation.
4. Create a Blueprint subclass of `AFFREnemyCharacter` and assign a skeletal mesh, animation blueprint, and collision settings.
5. Place several enemy Blueprint instances inside the navigation bounds.
6. Set the level's GameMode to `FFRGameMode` (or use the project default).
7. Start with one player. From a front-end Blueprint button or menu action, call `AddCoopPlayer` on the GameInstance with the desired controller ID. Pass -1 to request the next available ID.
8. Confirm that the second local player has a distinct controller ID and viewport.

## Current prototype limits
- The C++ player pawn uses a capsule and camera; it has no character mesh or animation assets yet.
- Player attacks use a short forward sphere-overlap query, not animation-driven hit windows.
- Enemy AI requires a baked NavMesh and a valid AIController.
- The enemy currently damages the closest player directly when in range. There is no telegraph, stagger, combo, or attack animation yet.
- Device enumeration, a device assignment menu, and reliable per-device reassignment are not implemented.
- This repository change has not been compiled in Unreal Editor in this environment.
