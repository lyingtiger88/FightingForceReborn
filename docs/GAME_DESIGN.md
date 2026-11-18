# Game Design: Core Decisions

## Genre
A 3D cooperative beat 'em up inspired by classic arcade brawlers. All characters, stages, story, animations, and assets will be original.

## Local co-op
- One or two local players.
- Independent PlayerController and Enhanced Input mapping context per player.
- Front-end assignment of keyboard/mouse or a gamepad to each player.
- First campaign uses third-person split screen with independent camera control.
- A physical gamepad must not be assigned to both players at once.

## Camera progression
- New profile: Third Person Split Screen is the default and only available mode.
- Completing the main campaign permanently unlocks Classic Fixed Camera.
- Unlocked mode can be selected in Settings and saved as preferred mode.
- Classic mode uses authored camera anchors/volumes and transitions, not a visual filter.
- Camera mode must not alter movement, combat simulation, collision, or enemy targeting.

## Combat pillars
Responsive light/heavy attacks, combo chains, dodge/block, grabs/throws, hit reactions, knockdowns, and enemies that coordinate pressure across both players.
