#include "keybinds_config.hpp"
#include "spdlog/spdlog.h"

#include <fstream>
#include <SFML/Window/Keyboard.hpp>

KeybindsConfig::KeybindsConfig(const FilePath binProtoFilePath) : binProtoFilePath(binProtoFilePath)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    this->read();
}

KeybindsConfig::~KeybindsConfig()
{
    google::protobuf::ShutdownProtobufLibrary();
}

bool KeybindsConfig::read()
{
    std::fstream protoBinFile(this->binProtoFilePath, std::ios::in | std::ios::binary);

    if (!protoBinFile) 
    {
      spdlog::warn("{}: {} file not found. Creating new proto bin file", __PRETTY_FUNCTION__, this->binProtoFilePath.string());
      this->initDefaultConfig();
      this->save();
      return false;
    } 
    else if (!this->keyboardBinds.ParseFromIstream(&protoBinFile)) 
    {
      spdlog::error("{}: {} file parsing failed", __PRETTY_FUNCTION__, this->binProtoFilePath.string());
      return false;
    }

    return true;
}



void KeybindsConfig::initDefaultConfig()
{
   // TODO using Key = sf::Keyboard::Key;

   this->keyboardBinds.set_close(36);
   this->keyboardBinds.set_moveup(22);
   this->keyboardBinds.set_movedown(18);
   this->keyboardBinds.set_moveleft(0);
   this->keyboardBinds.set_moveright(3);
}

bool KeybindsConfig::save() const
{
    std::fstream protoBinFile(this->binProtoFilePath, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!this->keyboardBinds.SerializeToOstream(&protoBinFile)) 
    {
      spdlog::error("{}: {} file serialization failed", __PRETTY_FUNCTION__, this->binProtoFilePath.string());
      return false;
    }

  spdlog::info("{}: {} file serialization completed", __PRETTY_FUNCTION__, this->binProtoFilePath.string());
  return true;
}