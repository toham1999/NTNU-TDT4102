#pragma once

class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

// Abstract base class for different screens
class Screen {
public:
    virtual ~Screen() = default;  // Virtual destructor to ensure proper cleanup
    virtual void draw(SpaceDefender& window) = 0;
};


// ---- ScreenMenu ----
class ScreenMenu : public Screen {
public:
    void draw(SpaceDefender& window) override;
};


// ---- ScreenGame ----
class ScreenGame : public Screen {
public:
    void draw(SpaceDefender& window) override;
};


// ---- ScreenHighscore ----
class ScreenHighscore : public Screen {
public:
    void draw(SpaceDefender& window) override;
};
        

// ---- ScreenSettings ----
class ScreenSettings : public Screen {
public:
    void draw(SpaceDefender& window) override;
};