// This class plays a sound using XAudio2. It uses a mastering voice provided
// from the Audio class. The sound data can be read from disk using the MediaReader
// class.
#pragma once

class SoundEffect
{
public:
    SoundEffect();

    void Initialize(
        _In_ IXAudio2* masteringEngine,
        _In_ WAVEFORMATEX* sourceFormat,
        _In_ std::vector<byte> const& soundData
    );

    void PlaySound(_In_ float volume);

private:
    bool                 m_audioAvailable;
    IXAudio2SourceVoice* m_sourceVoice;
    std::vector<byte>    m_soundData;
};