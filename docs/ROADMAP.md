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
- [ ] Device assignment screen and connected-device enumeration
- [ ] Reserve keyboard/mouse or gamepad per player
- [ ] Spawn Player 2 only after explicit assignment
- [ ] Third-person split-screen camera and independent camera controls
- [ ] Per-player HUD, pause, and disconnect handling

## M2 - Combat prototype
- [ ] Movement, light/heavy attacks, dodge, and block
- [ ] Hit detection, hit reactions, knockdown, and recovery
- [ ] Enemy AI target selection across both players
- [ ] Grunt, Heavy, and Agile enemy archetypes

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
