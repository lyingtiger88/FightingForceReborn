# Changelog

## 2026-11-18
- Initialized Unreal Engine 5.8 C++ project structure.
- Added save profile and campaign-completion unlock for Classic Fixed Camera.
- Added preferred camera mode persistence with lock enforcement.
- Added local co-op player creation entry point and Enhanced Input PlayerController foundation.
- Added shared character health/damage base and GameMode.
- Added game design, architecture, and roadmap documentation.

## 2026-11-18 - M1/M2 gameplay foundation
- Added a third-person player character with an independent spring-arm camera.
- Added starter keyboard/mouse and gamepad movement, camera, attack, and dodge bindings.
- Enabled horizontal two-player split-screen in project settings.
- Expanded local-player creation to enforce a two-player limit, reject duplicate controller IDs, and restart the new player's pawn.
- Added team-aware damage filtering and basic player melee overlap attacks.
- Added a basic enemy character that finds the nearest living local player, pursues using navigation, and attacks at close range.
- Added first test-level setup instructions and documented prototype limitations.
- Not yet compiled or tested in Unreal Editor.
