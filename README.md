TOOLCHAIN=android-ndk-r17-api-24-arm64-v8a-clang-libcxx14
CONFIG=Release
polly.py --toolchain ${TOOLCHAIN} --config-all ${CONFIG} --fwd GAUZE_ANDROID_USE_EMULATOR=ON --test --verbose --reconfig
