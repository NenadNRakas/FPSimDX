#pragma once

class GameTimer
{
public:
    GameTimer();

    float PlayingTime();            // Return the Elapsed time the Game has been active in seconds since Reset
    void PlayingTime(float time);   // Set the Elapsed playing time -- used for restarting in the middle of a game
    float DeltaTime();              // Return the Delta time between the last two updates

    void Reset();
    void Start();
    void Stop();
    void Update();
    bool Active() { return m_active; };

private:
    float m_secondsPerCount;  // 1.0 / Frequency
    float m_deltaTime;

    LARGE_INTEGER m_baseTime;
    LARGE_INTEGER m_pausedTime;
    LARGE_INTEGER m_stopTime;
    LARGE_INTEGER m_previousTime;
    LARGE_INTEGER m_currentTime;

    bool m_active;
};


