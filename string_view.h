// Copyright (c) 2024 Irina Selyakh
//
// Данное программное обеспечение распространяется на условиях лицензии MIT.
// Подробности смотрите в файле LICENSE

#ifndef STRING_VIEW
#define STRING_VIEW
#include <cstddef>

class StringView {
  const char *str_ = "";
  const char *end_ = str_;

 public:
  StringView() : str_(nullptr), end_(nullptr) {
  }

  StringView(const char *str, size_t size) : str_(str), end_(str + size) {
  }

  StringView(const char *str) : str_(str), end_(str) {  // NOLINT
    while (*end_ != '\0') {
      ++end_;
    }
  }

  [[nodiscard]] char Front() const {  // Метод не изменяет состояние объекта Array.
                                      // Это позволяет вызывать метод для константных объектов StringView.
    return *str_;
  }

  [[nodiscard]] char Back() const {
    return *(end_ - 1);
  }

  [[nodiscard]] bool Empty() const {
    return Size() == 0;
  }

  [[nodiscard]] const char *Data() const {
    return str_;
  }

  StringView Substr(size_t pos, size_t count); // извлечение подстроки

  [[nodiscard]] size_t Size() const {
    return end_ - str_;
  }

  [[nodiscard]] size_t Length() const {
    return end_ - str_;
  }

  void RemovePrefix(size_t prefix_size) {  // сдвигает начало строки на prefix_size
    str_ += prefix_size;
  }

  void RemoveSuffix(size_t prefix_size) {  // сдвигает конец строки на suffix_size
    end_ -= prefix_size;
  }

  [[nodiscard]] char operator[](size_t index) const {
    return str_[index];
  }

  void Swap(StringView &other);
};

#endif