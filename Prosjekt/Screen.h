#pragma once


class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

// Abstract base class for different screens
class Screen {
public:
    virtual ~Screen() = default;  // Virtual destructor to ensure proper cleanup

    // Virtual method to draw the screen's content
    virtual void draw(SpaceDefender& window) = 0;

    // Virtual method to handle user input (e.g., button clicks, key presses)
    virtual void handleInput(SpaceDefender& window) = 0;
};