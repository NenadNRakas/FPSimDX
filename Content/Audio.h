// This class uses XAudio2 to provide sound output. It creates two
// engines - one for music and the other for sound effects - each as
// a separate mastering voice.
// The SuspendAudio and ResumeAudio methods can be used to stop
// and start all audio playback.
#pragma once

class Audio
{
public:
    Audio();

    void Initialize();
    void CreateDeviceIndependentResources();
    IXAudio2* MusicEngine();
    IXAudio2* SoundEffectEngine();
    void SuspendAudio();
    void ResumeAudio();

private:
    bool                        m_audioAvailable;
    winrt::com_ptr<IXAudio2>    m_musicEngine;
    winrt::com_ptr<IXAudio2>    m_soundEffectEngine;
    IXAudio2MasteringVoice* m_musicMasteringVoice;
    IXAudio2MasteringVoice* m_soundEffectMasteringVoice;
};