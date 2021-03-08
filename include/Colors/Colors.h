#ifndef LIB_LIBCOLORS_H
#define LIB_LIBCOLORS_H

#include <vector>
#include <string>
#include <iosfwd>

namespace colors {
    enum Colors {
        black = 0,
        red = 1,
        green = 2,
        yellow = 3,
        blue = 4,
        magenta = 5,
        cyan = 6,
        white = 7,
        
        none = -1
    };

    enum Attributes {
        reset = 0,
        bold = 1,
        dim = 2,
        italic = 3,
        underline = 4,
        slow_blink = 5,
        rapid_blink = 6,
        invert = 7,
        hide = 8,
        strikethrough = 9,
        
        default_font = 10,
        font_1 = 11,
        font_2 = 12,
        font_3 = 13,
        font_4 = 14,
        font_5 = 15,
        font_6 = 16,
        font_7 = 17,
        font_8 = 18,
        font_9 = 19,
        blackletter = 20,
        
        doubly_underlined = 21,
        normal_weight = 22,
        
        no_italic_no_blackletter = 23,
        no_underline = 24,
        no_blink = 25,
        
        proportional_spacing = 26,
        
        not_reverse = 27,
        reveal = 28,
        not_strikethrough = 29,
        
        default_fg = 39,
        deault_bg = 49,
        
        no_proportional_spacing = 50,
        
        framed = 51,
        encircled = 52,
        overline = 53,
        
        no_frame_or_circle = 54,
        no_overline = 55
    };
    
    using Attr = Attributes;

    class Color {
    public:
        static Color RESET;
        std::string operator!() const;
        Color brighten() const;
        Color darken() const;
        Color fg() const;
        Color bg() const;
        Color attr(const Attributes& attr) const;
        Color reset() const;
        Color(const Colors& color);
        
    private:
        std::vector<int> numbers; // [CODE, BG/FG, BRIGHT/0...]
        Color(const std::vector<int> numbers);
    };
    
    namespace _internal {
        static const int BG = 40;
        static const int FG = 30;
        static const int BRIGHT = 60;
    }
}

std::ostream& operator<<(std::ostream&, colors::Color);

#endif /* LIB_LIBCOLORS_H */
