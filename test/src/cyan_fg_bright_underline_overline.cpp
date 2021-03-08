#include "Commons.h"

int main() {
    return !Color(Colors::cyan).fg().brighten().attr(Attr::underline).attr(Attr::overline) == codes("96;4;53") ? SUCCESS : FAILURE;
}
