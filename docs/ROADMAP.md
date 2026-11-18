# Roadmap

## M0 - Project foundation
- [x] Unreal Engine 5.8 C++ project skeleton
- [x] Save-game profile and campaign-completion unlock
- [x] Persist preferred camera mode and enforce lock
- [x] Enhanced Input PlayerController foundation
- [x] Local co-op player creation entry point
- [x] Shared character health/damage base
- [ ] Generate project files and compile in Unreal Engine 5.8

## M1 - Two-player local co-op
- [x] C++ API to create a second local player with a selected controller ID
- [x] Two-player horizontal split-screen project setting
- [x] Third-person player pawn with an independent spring-arm camera per local player
- [x] Keyboard/gamepad starter movement and combat bindings
- [ ] Front-end device assignment screen and connected-device enumeration
- [ ] Physical device reservation UI and reassignment handling
- [ ] Per-player HUD, pause, and disconnect handling
- [ ] Verify simultaneous keyboard + two-gamepad routing on target hardware

## M2 - Combat prototype
- [x] Player movement, light/heavy attacks, and dodge
- [x] Team-aware health and damage handling
- [x] Basic enemy AI selects the nearest living local player
- [x] Enemy pursues target and attacks at close range
- [ ] Attack animation windows, hitboxes, hit reactions, knockdown, and recovery
- [ ] Grunt, Heavy, and Agile enemy archetypes
- [ ] Encounter director and coordinated enemy pressure

## M3 - Campaign vertical slice
- [ ] One complete stage and encounter flow
- [ ] Pickups, breakable props, and environmental weapons
- [ ] Checkpoints and campaign completion flow
- [ ] Save versioning and regression tests

## M4 - Unlockable classic camera
- [ ] Authored fixed-camera anchors/volumes
- [ ] Camera transitions and two-player framing rules
- [ ] Unlock notification and settings UI
- [ ] Save/load tests for locked and unlocked states

## M5 - Polish
- [ ] Audio, VFX, accessibility, rebinding, and performance
- [ ] Windows packaging and controller QA
