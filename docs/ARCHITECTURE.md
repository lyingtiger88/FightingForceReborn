# Architecture

## Runtime module
Single C++ game module: `FightingForceReborn`.

## Core classes
- `UFFRGameInstance`: loads profile, exposes campaign completion and camera preference, and provides a local-player creation entry point.
- `UFFRSaveGame`: persistent campaign unlock and settings.
- `AFFRPlayerController`: one controller per local player, with an Enhanced Input mapping-context slot.
- `AFFRCharacter`: shared health and damage response base for player/enemy character Blueprints.
- `AFFRGameMode`: selects the project PlayerController class.

## Input assignment
Create separate Enhanced Input Mapping Context assets for keyboard/mouse and gamepad. The front-end must enumerate devices, reserve each physical device for one player, and create Player 2 only after confirmation. Device enumeration and per-device routing are platform integration work and are not complete in this scaffold.

## Split screen
Unreal local players and PlayerControllers form the ownership boundary. The front-end creates Player 2 after assignment. Per-player HUD, split-screen layout, and independent camera tuning are part of M1.

## Camera progression
Third Person is enforced until the campaign completion flag is saved. Classic preference cannot be selected while locked. The actual fixed-camera anchor/volume system and shared two-player framing policy remain a later milestone.

## Combat
Keep health/damage state in C++; expose hit reactions and death presentation through Blueprint events. Add attack traces, combo windows, and enemy behavior as separate components.
