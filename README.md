# FightingForceReborn

A cooperative 3D beat 'em up prototype inspired by classic arcade brawlers, built with Unreal Engine 5.8.

## Current playable foundation

- Third-person player pawn with an independent spring-arm camera.
- Horizontal two-player split-screen project configuration.
- Local-player creation API with a two-player cap and controller-ID validation.
- Starter keyboard/mouse and gamepad movement, camera, light/heavy attack, and dodge bindings.
- Team-aware character health and melee damage.
- Basic enemy AI that selects the nearest living local player, navigates toward them, and attacks at close range.
- Persistent campaign completion and unlockable Classic Fixed Camera preference.

## Engine

Unreal Engine 5.8 (C++ with Blueprint extension points).

## Current limitations

This is a code foundation, not yet a packaged or editor-verified playable build. Character meshes, animation assets, UI, device enumeration/assignment screens, animation-driven hit windows, and the authored classic camera system are not included yet. Enemy navigation requires a NavMesh in the test level.

See:
- [Game design](docs/GAME_DESIGN.md)
- [Architecture](docs/ARCHITECTURE.md)
- [Input and first test level](docs/INPUT_AND_FIRST_LEVEL.md)
- [Roadmap](docs/ROADMAP.md)
- [Changelog](CHANGELOG.md)
