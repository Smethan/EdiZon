#pragma once

#include "gui.hpp"
#include "widget.hpp"
#include "json.hpp"

using json = nlohmann::json;

#define CONFIG_ROOT "/EdiZon/editor/"

class GuiEditor : public Gui {
public:
  GuiEditor();
  ~GuiEditor();

  void draw();
  void onInput(u32 kdown);
  void onTouch(touchPosition &touch);

  static u8 *g_currSaveFile;
  static std::string g_currSaveFileName;

private:
  WidgetList m_widgets;
  json m_offsetFile;
  void createWidgets();
  bool loadConfigFile(json &j);

  void updateSaveFileList(const char *saveFilePath);
};
