// Copyright (c) 2024 Irina Selyakh
//
// Данное программное обеспечение распространяется на условиях лицензии MIT.
// Подробности смотрите в файле LICENSE

#include "string_view.h"
#include <algorithm>

void StringView::Swap(StringView& other) {
  std::swap(str_, other.str_);
  std::swap(end_, other.end_);
}

StringView StringView::Substr(size_t pos, size_t count) {
  if (pos > Size()) {
    return str_;
  }
  return {str_ + pos, std::min(count, Size() - pos)};
}