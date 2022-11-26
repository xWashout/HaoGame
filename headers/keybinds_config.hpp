#pragma once

#include "keybinds_config.pb.h"
#include <filesystem>

class KeybindsConfig
{
    using FilePath = std::filesystem::path;

private:
    KeyboardBinds keyboardBinds;
    const FilePath binProtoFilePath;

public:
    KeybindsConfig(const FilePath binProtoFilePath);
    ~KeybindsConfig();

    bool read();
    void initDefaultConfig();
    bool save() const;
};