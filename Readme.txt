# Arduino Memory Game 🎮

A simple memory game built using an Arduino Uno, 4 LEDs, and 5 push buttons.

## Game Idea

The Arduino generates a random sequence of LEDs.

The player must memorize the sequence and press the corresponding buttons in the same order.

Each successful round adds one new random LED to the sequence, making the game progressively harder.

If the player presses the wrong button, the game ends and all LEDs blink three times.

To start a new game, the player must press the START button again.

## Components

- Arduino Uno
- Breadboard
- 5 Push Buttons
- 4 LEDs
- 4 × 220Ω or 330Ω Resistors
- Jumper Wires

## Pin Connections

### Buttons

| Component | Arduino Pin |
|---|---|
| START Button | D2 |
| Button 1 | D3 |
| Button 2 | D4 |
| Button 3 | D5 |
| Button 4 | D6 |

All buttons are connected to GND and use `INPUT_PULLUP`.

### LEDs

| Component | Arduino Pin |
|---|---|
| LED 1 | D7 |
| LED 2 | D8 |
| LED 3 | D9 |
| LED 4 | D10 |

Each LED is connected through its own 220Ω or 330Ω resistor.

## How to Play

1. Press the START button.
2. Watch the LED sequence carefully.
3. Wait until the sequence finishes.
4. Press the buttons corresponding to the LEDs in the same order.
5. If the sequence is correct, a new LED is added.
6. The sequence becomes longer after every successful round.
7. If a wrong button is pressed, the game ends.
8. Press START again to play a new game.

## Example

Round 1:

LED 2

Player presses:

Button 2 ✓

Round 2:

LED 2 → LED 4

Player presses:

Button 2 → Button 4 ✓

Round 3:

LED 2 → LED 4 → LED 1

The game continues until the player makes a mistake.

## Project Purpose

This project demonstrates:

- Arduino digital input and output
- Push button handling
- LED control
- Arrays
- Random number generation
- Loops and conditions
- Basic game logic