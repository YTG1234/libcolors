#include <Colors/Colors.h>
#include <iostream>

using namespace colors;

Color Color::RESET = Color(Colors::black).reset();

Color::Color(const Colors& code) {
    if (code == Colors::none) {
        numbers.push_back(0);
        numbers.push_back(0);
        numbers.push_back(0);
    } else {
        numbers.push_back(code);
        numbers.push_back(_internal::FG);
        numbers.push_back(0);
    }
}

Color::Color(const std::vector<int> numbers) {
    this->numbers = numbers;
}

Color Color::brighten() const {
    std::vector<int> newColors = this->numbers;
    newColors[2] = _internal::BRIGHT;

    return Color(newColors);
}

Color Color::darken() const {
    std::vector<int> newColors = this->numbers;
    newColors[2] = 0;
    
    return Color(newColors);
}

Color Color::fg() const {
    std::vector<int> newColors = this->numbers;
    newColors[1] = _internal::FG;
    
    return Color(newColors);
}

Color Color::bg() const {
    std::vector<int> newColors = this->numbers;
    newColors[1] = _internal::BG;
    
    return Color(newColors);
}

Color Color::attr(const Attributes& attr) const {
    std::vector<int> newColors = numbers;
    newColors.push_back(attr);
    
    return Color(newColors);
}

Color Color::reset() const {
    return attr(Attributes::reset);
}

std::string Color::operator!() const {
    int first = numbers[0] + numbers[1] + numbers[2];
    std::string initial = "\033[";

    if (first != 0) initial += std::to_string(first);

    for (std::vector<int>::size_type i = 3; i < numbers.size(); i++) {
        if (initial[initial.size() - 1] != ';' && initial[initial.size() - 1] != '[') initial += ";";
        initial += std::to_string(numbers[i]);
    }

    initial += "m";

    return initial;
}

std::ostream& operator<<(std::ostream& st, colors::Color clr) {
    return st << !clr;
}
