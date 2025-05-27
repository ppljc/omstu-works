#include "functions.h"

static constexpr int SAMPLE_RATE = 44100;
static constexpr int NUM_KEYS = 7;
static constexpr float GLOBAL_VOLUME = 0.3f;
static constexpr int CHUNK_SIZE = 512;

static const double noteFreq[NUM_KEYS] = {
    261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88
};

static bool keyActive[NUM_KEYS] = { false };
static double phase[NUM_KEYS] = { 0.0 };

static void SDLCALL FeedAudio(void* userdata, SDL_AudioStream* astream, int additional_amount, int total_amount) {
    int samplesNeeded = additional_amount / static_cast<int>(sizeof(float));

    while (samplesNeeded > 0) {
        int chunk = (samplesNeeded > CHUNK_SIZE) ? CHUNK_SIZE : samplesNeeded;
        float buffer[CHUNK_SIZE];

        for (int i = 0; i < chunk; ++i) {
            float sampleValue = 0.0f;
            for (int k = 0; k < NUM_KEYS; ++k) {
                if (keyActive[k]) {
                    double angular = 2.0 * M_PI * noteFreq[k] / SAMPLE_RATE;
                    sampleValue += static_cast<float>(sin(phase[k]) * GLOBAL_VOLUME);
                    phase[k] += angular;
                    if (phase[k] > 2.0 * M_PI) {
                        phase[k] -= 2.0 * M_PI;
                    }
                }
            }
            if (sampleValue > 1.0f) sampleValue = 1.0f;
            else if (sampleValue < -1.0f) sampleValue = -1.0f;
            buffer[i] = sampleValue;
        }

        SDL_PutAudioStreamData(astream, buffer, chunk * sizeof(float));
        samplesNeeded -= chunk;
    }
}

void ShowSynth(HWND hwnd)
{
    HDC hdc = GetDC(hwnd);

    RECT window;
    GetClientRect(hwnd, &window);
    FillRect(hdc, &window, (HBRUSH)GetStockObject(BLACK_BRUSH));

    HFONT hFontTitle = CreateFontW(
        28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial"
    );
    SelectObject(hdc, hFontTitle);

    SetTextColor(hdc, RGB(255, 255, 255));
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);

    TextOutA(hdc, window.right / 2, window.bottom / 2 - 100, "Звуковой синтезатор.", 19);

    HFONT hFontText = CreateFontW(
        20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
        DEFAULT_PITCH, L"Arial"
    );
    SelectObject(hdc, hFontText);

    TextOutA(hdc, window.right / 2, window.bottom / 2 - 50, "Клавиши 1-7 соответствуют нотам.", 29);

    DeleteObject(hFontTitle);
    DeleteObject(hFontText);
    ReleaseDC(hwnd, hdc);

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);

    SDL_Window* sdlWindow = SDL_CreateWindow(
        "Piano",
        640, 480,
        0
    );

    SDL_SetWindowOpacity(sdlWindow, 0.0f);
    SDL_RaiseWindow(sdlWindow);

    SDL_AudioSpec spec;
    SDL_zero(spec);
    spec.freq = SAMPLE_RATE;
    spec.format = SDL_AUDIO_F32;
    spec.channels = 1;

    SDL_AudioStream* stream = SDL_OpenAudioDeviceStream(
        SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
        &spec,
        FeedAudio,
        nullptr
    );

    SDL_ResumeAudioStreamDevice(stream);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN: {
                    SDL_Keycode key = event.key.scancode;
                    switch (key) {
                        case SDL_SCANCODE_ESCAPE:
                            running = false;
                            break;
                        case SDL_SCANCODE_1: keyActive[0] = true; break;
                        case SDL_SCANCODE_2: keyActive[1] = true; break;
                        case SDL_SCANCODE_3: keyActive[2] = true; break;
                        case SDL_SCANCODE_4: keyActive[3] = true; break;
                        case SDL_SCANCODE_5: keyActive[4] = true; break;
                        case SDL_SCANCODE_6: keyActive[5] = true; break;
                        case SDL_SCANCODE_7: keyActive[6] = true; break;
                        default: break;
                    }
                    break;
                }
                case SDL_EVENT_KEY_UP: {
                    SDL_Keycode key = event.key.scancode;
                    switch (key) {
                        case SDL_SCANCODE_1:
                            keyActive[0] = false;
                            phase[0] = 0.0;
                            break;
                        case SDL_SCANCODE_2:
                            keyActive[1] = false;
                            phase[1] = 0.0;
                            break;
                        case SDL_SCANCODE_3:
                            keyActive[2] = false;
                            phase[2] = 0.0;
                            break;
                        case SDL_SCANCODE_4:
                            keyActive[3] = false;
                            phase[3] = 0.0;
                            break;
                        case SDL_SCANCODE_5:
                            keyActive[4] = false;
                            phase[4] = 0.0;
                            break;
                        case SDL_SCANCODE_6:
                            keyActive[5] = false;
                            phase[5] = 0.0;
                            break;
                        case SDL_SCANCODE_7:
                            keyActive[6] = false;
                            phase[6] = 0.0;
                            break;
                        default: break;
                    }
                    break;
                }
                default: break;
            }
        }
        SDL_Delay(10);
    }

    SDL_DestroyAudioStream(stream);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
}
