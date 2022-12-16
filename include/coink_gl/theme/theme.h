//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include <memory>
#include <string>

#include "type/type.h"
#include "type/duck.h"


// details : https://nimajjj.notion.site/Theme-System-9f93a1451248481697b65e354ff926c6
class Theme {
 public:
  // properties
  const DUCK ID;


  // main
  Theme(const std::string& name);
  ~Theme() = default;

  // getters
  const DUCK& GetID() const { return ID; }
  const std::string& GetName() const { return theme_name; }
  const uint& GetFontSize() const { return font_size; }
  const uint& GetFontSizeH1() const { return font_size_h1; }
  const uint& GetFontSizeH2() const { return font_size_h2; }
  const Color& GetTextColor() const { return text_color; }
  const Color& GetHighlightColor() const { return highlight_color; }
  const Color& GetBGColor1() const { return bg_color_1; }
  const Color& GetBGColor2() const { return bg_color_2; }
  const Color& GetBorderColor1() const { return border_color_1; }
  const Color& GetBorderColor2() const { return border_color_2; }

  // setters
  void SetName(const std::string& name) { theme_name = name; }
  void SetFontSize(const uint& size) { font_size = size; }
  void SetFontSizeH1(const uint& size) { font_size_h1 = size; }
  void SetFontSizeH2(const uint& size) { font_size_h2 = size; }
  void SetTextColor(const Color& col) { text_color = col; }
  void SetHighlightColor(const Color& col) { highlight_color = col; }
  void SetBGColor1(const Color& col) { bg_color_1 = col; }
  void SetBGColor2(const Color& col) { bg_color_2 = col; }
  void SetBorderColor1(const Color& col) { border_color_1 = col; }
  void SetBorderColor2(const Color& col) { border_color_2 = col; }


 private:
  // properties
  std::string theme_name;
  uint font_size;
  uint font_size_h1;
  uint font_size_h2;
  Color text_color;
  Color highlight_color;
  Color bg_color_1;
  Color bg_color_2;
  Color border_color_1;
  Color border_color_2;



};

using ThemePtr = std::shared_ptr<Theme>;
